/*
* File Name     :
* Purpose       :
* Creation Date : 08-03-2016
* Last Modified : Sun 20 Mar 2016 12:56:03 PM CET
* Created By    :
*
*/

#include "contiki.h"
#include <stdint.h>
#include <stdio.h>		/* For printf() */
#include <string.h>
#include "lpm.h"
#include "dev/radio.h"
#include "dev/oscillators.h"
#include "dev/serial-line.h"
#include "button-sensor.h"
#include "ti-lib.h"
#include "pwm.h"
#include "net/packetbuf.h"
#include "ext-flash.h"
#include "rf-core/dot-15-4g.h"
#include "rf-core/rf-core.h"
#include "sys/clock.h"
#include "sys/rtimer.h"
/*---------------------------------------------------------------------------*/
/* RF core and RF HAL API */
#include "hw_rfc_dbell.h"
#include "hw_rfc_pwr.h"
/* RF Core Mailbox API */
#include "rf-core/api/mailbox.h"
#include "rf-core/api/common_cmd.h"
#include "rf-core/api/data_entry.h"
#include "rf-core/api/prop_mailbox.h"
#include "rf-core/api/prop_cmd.h"
/*---------------------------------------------------------------------------*/
/* CC13xxware patches */
#include "rf_patches/rf_patch_cpe_genfsk.h"
/*---------------------------------------------------------------------------*/
#include "rf-core/smartrf-settings.h"
/*---------------------------------------------------------------------------*/
#include "troopers_rfc_cmd.h"
#include "troopers_rfc_settings.h"
#include "troopers_helpers.h"
#include "troopers_config.h"

void troopers_rfc_init_queue(dataQueue_t * q, uint8_t * buf)
{
	//memset(buf, 0x00, MESSAGELENGTH);
	rfc_dataEntry_t *entry;
	entry = (rfc_dataEntry_t *) buf;
	entry->status = DATA_ENTRY_STATUS_PENDING;
	entry->config.type = DATA_ENTRY_TYPE_GEN;
	entry->config.lenSz = 2;	//DATA_ENTRY_LENSZ_WORD;
	entry->length = MESSAGELENGTH - 8;
	q->pCurrEntry = buf;
	q->pLastEntry = NULL;
}

void troopers_rfc_get_fw_info(void)
{
	uint32_t cmd_status;
	rfc_CMD_GET_FW_INFO_t cmd;
	cmd.commandNo = CMD_GET_FW_INFO;

	if (rf_core_send_cmd((uint32_t) & cmd, &cmd_status) != RF_CORE_CMD_OK) {
		PRINTF("Version No.: 0x%04x\n", cmd.versionNo);
		PRINTF("Free RAM: 0x%04x\n", cmd.freeRamSz);
	} else {
		PRINTF("status: 0x%08lx\n", cmd_status);
	}
}

int8_t troopers_rfc_get_rssi(void)
{
	int8_t rssi;
	uint32_t cmd_status;
	uint8_t attempts = 0;
	rfc_CMD_GET_RSSI_t cmd;

	rssi = RF_CMD_CCA_REQ_RSSI_UNKNOWN;

	while ((rssi == RF_CMD_CCA_REQ_RSSI_UNKNOWN || rssi == 0)
	       && ++attempts < 10) {
		memset(&cmd, 0x00, sizeof(cmd));
		cmd.commandNo = CMD_GET_RSSI;
		if (rf_core_send_cmd((uint32_t) & cmd, &cmd_status) !=
		    RF_CORE_CMD_OK) {
			PRINTF("status: 0x%08lx\n", cmd_status);
			break;
		} else {
			rssi = (cmd_status >> 16) & 0xFF;
			PRINTF("RSSI: 0x%02x\n", rssi);
		}
	}
	return rssi;
}

void troopers_rfc_init(void)
{
	uint32_t cmd_status;
	rf_core_set_modesel();

	rfc_CMD_PROP_RADIO_DIV_SETUP_t *cmdOpt = NULL;
	rfc_radioOp_t *cmdFs = NULL;

	if (rf_core_power_up() != RF_CORE_CMD_OK) {
		PRINTF("init_rf: rf_core_power_up() failed\n");
	}
	if (!rf_core_is_accessible()) {
		PRINTF("after power_up not accessible\n");
	}

	rf_patch_cpe_genfsk();

	if (rf_core_start_rat() != RF_CORE_CMD_OK) {
		PRINTF("init_rf: rf_core_start_rat() failed\n");
	}

	oscillators_request_hf_xosc();

	rf_core_setup_interrupts();

	oscillators_switch_to_hf_xosc();

	cmdOpt = &RF_cmdPropRadioDivSetup;
	cmdOpt->pRegOverride = pOverrides;
	/* radio setup */
	if (rf_core_send_cmd((uint32_t) cmdOpt, &cmd_status) != RF_CORE_CMD_OK) {
		PRINTF("rf_cmdPropDivSetup: CMD_ABORT status=0x%08lx\n",
		       cmd_status);
	} else {
		PRINTF("rf_cmdPropDivSetup: CMD_OK status=0x%08lx\n",
		       cmd_status);
	}

	if (rf_core_wait_cmd_done(cmdOpt) != RF_CORE_CMD_OK) {
		PRINTF
		    ("divsetup: CMD_ABORT div_setup wait, CMDSTA=0x%08lx, status=0x%04x\n",
		     cmd_status, cmdOpt->status);
	} else {
		PRINTF
		    ("divsetup: OK div_setup wait, CMDSTA=0x%08lx, status=0x%04x\n",
		     cmd_status, cmdOpt->status);
	}

	cmdFs = (rfc_radioOp_t *) & RF_cmdFs;
	/* freq synthesizer */
	if (rf_core_send_cmd((uint32_t) cmdFs, &cmd_status) != RF_CORE_CMD_OK) {
		PRINTF
		    ("prop_fs: CMD_FS, CMD_ABORT CMDSTA=0x%08lx, status=0x%04x\n",
		     cmd_status, cmdFs->status);
	} else {
		PRINTF("prop_fs: OK CMD_FS, CMDSTA=0x%08lx, status=0x%04x\n",
		       cmd_status, cmdFs->status);
	}

	if (rf_core_wait_cmd_done(cmdFs) != RF_CORE_CMD_OK) {
		PRINTF
		    ("prop_fs: cmd_fs wait, CMD_ABORT CMDSTA=0x%08lx, status=0x%04x\n",
		     cmd_status, cmdFs->status);
	} else {
		PRINTF
		    ("prop_fs: OK cmd_fs wait, CMDSTA=0x%08lx, status=0x%04x\n",
		     cmd_status, cmdFs->status);
	}

	if (!rf_core_is_accessible()) {
		PRINTF("not accessible\n");
	}
}

void troopers_rfc_send(uint8_t * message)
{
	uint32_t cmd_status, ret;

	rfc_CMD_PROP_TX_t *cmdTx = NULL;
	cmdTx = &RF_cmdPropTx;

	RF_cmdPropTx.status = 0x00;
	RF_cmdPropTx.pPkt = message;

	ret = rf_core_send_cmd((uint32_t) cmdTx, &cmd_status);
	if (ret != RF_CORE_CMD_OK) {
		PRINTF("rf_send: CMD_ABORT RF_prop_tx, ret=0x%08lx\n", ret);
		PRINTF
		    ("rf_send: CMD_ABORT RF_prop_tx, CMDSTA=0x%08lx, status=0x%04x\n",
		     cmd_status, cmdTx->status);
	} else {
		PRINTF
		    ("rf_send: CMD_OK RF_prop_tx, CMDSTA=0x%08lx, status=0x%04x\n",
		     cmd_status, cmdTx->status);
	}

	rtimer_clock_t t0;
	t0 = RTIMER_NOW();

	while (cmdTx->status != RF_CORE_RADIO_OP_STATUS_ACTIVE &&
	       (RTIMER_CLOCK_LT(RTIMER_NOW(), t0 + ENTER_RX_WAIT_TIMEOUT))) ;

	/* Wait to enter TX */
	if (cmdTx->status != RF_CORE_RADIO_OP_STATUS_ACTIVE) {
		PRINTF("rf_tx: CMDSTA=0x%08lx, status=0x%04x\n",
		       cmd_status, cmdTx->status);
	}

}

void troopers_rfc_receive(dataQueue_t * q, rfc_propRxOutput_t * rx_stats)
{
	uint32_t cmd_status, ret;
	rtimer_clock_t t0;

	rfc_CMD_PROP_RX_t *cmdRx = NULL;
	cmdRx = &RF_cmdPropRx;

	RF_cmdPropRx.pOutput = (uint8_t *) rx_stats;
	RF_cmdPropRx.status = RF_CORE_RADIO_OP_STATUS_IDLE;
	RF_cmdPropRx.pQueue = q;

	ret = rf_core_send_cmd((uint32_t) cmdRx, &cmd_status);
	if (ret != RF_CORE_CMD_OK) {
		PRINTF("rf_receive: CMD_ABORT RF_prop_rx, ret=0x%08lx\n", ret);
		PRINTF
		    ("rf_receive: CMD_ABORT RF_prop_rx, CMDSTA=0x%08lx, status=0x%04x\n",
		     cmd_status, cmdRx->status);
	} else {
		PRINTF
		    ("rf_receive: CMD_OK RF_prop_rx, CMDSTA=0x%08lx, status=0x%04x\n",
		     cmd_status, cmdRx->status);
		PRINTF("receive\n");
		t0 = RTIMER_NOW();

		while (cmdRx->status != RF_CORE_RADIO_OP_STATUS_ACTIVE &&
		       (RTIMER_CLOCK_LT
			(RTIMER_NOW(), t0 + ENTER_RX_WAIT_TIMEOUT))) ;

		/* Wait to enter RX */
		if (cmdRx->status != RF_CORE_RADIO_OP_STATUS_ACTIVE) {
			PRINTF("rf_rx: CMDSTA=0x%08lx, status=0x%04x\n",
			       cmd_status, cmdRx->status);
		}
		if (ret) {
			ENERGEST_ON(ENERGEST_TYPE_LISTEN);
		}
	}

}

void troopers_rfc_update_fs(uint16_t freq, uint16_t fract)
{
	uint32_t cmd_status;
	uint32_t i = 50000;
	rfc_CMD_UPDATE_FS_t cmd;
	memset(&cmd, 0x00, sizeof(cmd));
	cmd.commandNo = CMD_UPDATE_FS;
	cmd.frequency = freq;
	cmd.fractFreq = fract;

	if (rf_core_send_cmd((uint32_t) & cmd, &cmd_status) != RF_CORE_CMD_OK) {
		PRINTF("update_fs failed\n");
	}
	PRINTF("update_fs status: 0x%08lx\n", cmd_status);
	while (--i) ;
}

// initialize and tune to a specified frequency
void troopers_rfc_init_tune(uint16_t freq, uint16_t fract)
{
	uint32_t cmd_status;
	rf_core_set_modesel();

	rfc_CMD_PROP_RADIO_DIV_SETUP_t *cmdOpt = NULL;
	rfc_radioOp_t *cmdFs = NULL;

	if (rf_core_power_up() != RF_CORE_CMD_OK) {
		PRINTF("init_rf: rf_core_power_up() failed\n");
	}
	if (!rf_core_is_accessible()) {
		PRINTF("after power_up not accessible\n");
	}

	rf_patch_cpe_genfsk();

	//if(rf_core_start_rat() != RF_CORE_CMD_OK) {
	//PRINTF("init_rf: rf_core_start_rat() failed\n");
	//}

	oscillators_request_hf_xosc();

	rf_core_setup_interrupts();

	oscillators_switch_to_hf_xosc();

	cmdOpt = &RF_cmdPropRadioDivSetup;
	cmdOpt->pRegOverride = pOverrides;
	/* radio setup */
	if (rf_core_send_cmd((uint32_t) cmdOpt, &cmd_status) != RF_CORE_CMD_OK) {
		PRINTF("rf_cmdPropDivSetup: CMD_ABORT status=0x%08lx\n",
		       cmd_status);
	} else {
		PRINTF("rf_cmdPropDivSetup: CMD_OK status=0x%08lx\n",
		       cmd_status);
	}

	if (rf_core_wait_cmd_done(cmdOpt) != RF_CORE_CMD_OK) {
		PRINTF
		    ("divsetup: CMD_ABORT div_setup wait, CMDSTA=0x%08lx, status=0x%04x\n",
		     cmd_status, cmdOpt->status);
	} else {
		PRINTF
		    ("divsetup: OK div_setup wait, CMDSTA=0x%08lx, status=0x%04x\n",
		     cmd_status, cmdOpt->status);
	}

	RF_cmdFs.frequency = freq;
	RF_cmdFs.fractFreq = fract;
	cmdFs = (rfc_radioOp_t *) & RF_cmdFs;
	/* freq synthesizer */
	if (rf_core_send_cmd((uint32_t) cmdFs, &cmd_status) != RF_CORE_CMD_OK) {
		PRINTF
		    ("prop_fs: CMD_FS, CMD_ABORT CMDSTA=0x%08lx, status=0x%04x\n",
		     cmd_status, cmdFs->status);
	} else {
		PRINTF("prop_fs: OK CMD_FS, CMDSTA=0x%08lx, status=0x%04x\n",
		       cmd_status, cmdFs->status);
	}

	if (rf_core_wait_cmd_done(cmdFs) != RF_CORE_CMD_OK) {
		PRINTF
		    ("prop_fs: cmd_fs wait, CMD_ABORT CMDSTA=0x%08lx, status=0x%04x\n",
		     cmd_status, cmdFs->status);
	} else {
		PRINTF
		    ("prop_fs: OK cmd_fs wait, CMDSTA=0x%08lx, status=0x%04x\n",
		     cmd_status, cmdFs->status);
	}

	if (!rf_core_is_accessible()) {
		PRINTF("not accessible\n");
	}
}

void troopers_rfc_abort(void)
{
	uint32_t cmd_status;
	rfc_CMD_ABORT_t cmd;
	memset(&cmd, 0x00, sizeof(cmd));
	cmd.commandNo = CMD_ABORT;
	if (rf_core_send_cmd((uint32_t) & cmd, &cmd_status) != RF_CORE_CMD_OK) {
		PRINTF("abort status: 0x%08lx\n", cmd_status);
	}
}

void troopers_rfc_stop(void)
{
	uint32_t cmd_status;
	rfc_CMD_STOP_t cmd;
	memset(&cmd, 0x00, sizeof(cmd));
	cmd.commandNo = CMD_STOP;
	if (rf_core_send_cmd((uint32_t) & cmd, &cmd_status) != RF_CORE_CMD_OK) {
		PRINTF("stop status: 0x%08lx\n", cmd_status);
	}
}
