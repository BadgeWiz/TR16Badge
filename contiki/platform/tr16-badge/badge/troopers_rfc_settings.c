/*
* File Name     :
* Purpose       :
* Creation Date : 08-03-2016
* Last Modified : Sun 20 Mar 2016 12:56:26 PM CET
* Created By    :
*
*/

#include "rf-core/api/mailbox.h"
#include "rf-core/api/common_cmd.h"
#include "rf-core/api/data_entry.h"
#include "rf-core/api/prop_mailbox.h"
#include "rf-core/api/prop_cmd.h"
#include "rf_patches/rf_patch_cpe_genfsk.h"
#include "troopers_rfc_settings.h"
#include "troopers_config.h"

// Overrides for CMD_PROP_RADIO_DIV_SETUP
uint32_t pOverrides[] = {
	// override_synth_prop_863_970_div5.xml
	HW_REG_OVERRIDE(0x4038, 0x003A),
	HW_REG_OVERRIDE(0x4020, 0x7F00),
	HW_REG_OVERRIDE(0x4064, 0x0040),
	(uint32_t) 0x000684A3,
	(uint32_t) 0xC0040141,
	(uint32_t) 0x0533B107,
	(uint32_t) 0x0A480583,
	(uint32_t) 0x7AB80603,
	ADI_REG_OVERRIDE(1, 4, 0x9F),
	ADI_HALFREG_OVERRIDE(1, 7, 0x4, 0x4),
	(uint32_t) 0x02010403,
	(uint32_t) 0x00108463,
	(uint32_t) 0x04B00243,
	// override_phy_gfsk_rx_rssi.xml
	HW_REG_OVERRIDE(0x6084, 0x35F1),
	(uint32_t) 0x00038883,
	(uint32_t) 0x00FB88A3,
	// override_phy_agc_reflevel_0x1a.xml
	HW_REG_OVERRIDE(0x6088, 0x001A),
	// override_phy_rx_aaf_bw_0xd.xml
	ADI_HALFREG_OVERRIDE(0, 61, 0xF, 0xD),
	// TX power override
	ADI_REG_OVERRIDE(0, 12, 0xF8),
	(uint32_t) 0xFFFFFFFF,
};

// CMD_PROP_RADIO_DIV_SETUP
rfc_CMD_PROP_RADIO_DIV_SETUP_t RF_cmdPropRadioDivSetup = {
	.commandNo = CMD_PROP_RADIO_DIV_SETUP,
	.status = 0x0000,
	.pNextOp = 0,		// INSERT APPLICABLE POINTER: (uint8_t*)&xxx
	.startTime = 0x00000000,
	.startTrigger.triggerType = 0x0,	// TRIG_NOW P.1483 ff
	.startTrigger.bEnaCmd = 0x0,
	.startTrigger.triggerNo = 0x0,
	.startTrigger.pastTrig = 0x0,
	.condition.rule = 0x1,
	.condition.nSkip = 0x0,
	.modulation.modType = 0x1,
	.modulation.deviation = 0x64,
	.symbolRate.preScale = 0xf,
	.symbolRate.rateWord = 0x8000,
	.rxBw = 0x24,
	.preamConf.nPreamBytes = 0x4,
	.preamConf.preamMode = 0x0,
	.formatConf.nSwBits = 0x20,
	.formatConf.bBitReversal = 0x0,
	.formatConf.bMsbFirst = 0x1,
	.formatConf.fecMode = 0x0,
	.formatConf.whitenMode = 0x0,
	.config.frontEndMode = 0x0,
	.config.biasMode = 0x1,
	.config.bNoFsPowerUp = 0x0,
	.txPower = 0x20c9,
	.pRegOverride = pOverrides,
	.centerFreq = 0x0364,
	.intFreq = 0x8000,
	.loDivider = 0x05,
};

// CMD_FS
rfc_CMD_FS_t RF_cmdFs = {
	.commandNo = 0x0803,
	.status = 0x0000,
	.pNextOp = 0,		// INSERT APPLICABLE POINTER: (uint8_t*)&xxx
	.startTime = 0x00000000,
	.startTrigger.triggerType = 0x0,
	.startTrigger.bEnaCmd = 0x0,
	.startTrigger.triggerNo = 0x0,
	.startTrigger.pastTrig = 0x0,
	.condition.rule = 0x1,
	.condition.nSkip = 0x0,
	.frequency = 0x0364,
	.fractFreq = 0x0000,
	.synthConf.bTxMode = 0x0,
	.synthConf.refFreq = 0x0,
	.__dummy0 = 0x00,
	.midPrecal = 0x00,
	.ktPrecal = 0x00,
	.tdcPrecal = 0x0000,
};

// CMD_PROP_TX
rfc_CMD_PROP_TX_t RF_cmdPropTx = {
	.commandNo = 0x3801,
	.status = 0x0000,
	.pNextOp = 0,		// INSERT APPLICABLE POINTER: (uint8_t*)&xxx
	.startTime = 0x00000000,
	.startTrigger.triggerType = 0x0,
	.startTrigger.bEnaCmd = 0x0,
	.startTrigger.triggerNo = 0x0,
	.startTrigger.pastTrig = 0x0,
	.condition.rule = 0x1,
	.condition.nSkip = 0x0,
	.pktConf.bFsOff = 0x0,
	.pktConf.bUseCrc = 0x1,
	.pktConf.bVarLen = 0x0,
	.pktLen = PACKETLENGTH,	// SET APPLICATION PAYLOAD LENGTH
	.syncWord = 0xaabbaabb,
	.pPkt = 0,		// INSERT APPLICABLE POINTER: (uint8_t*)&xxx
};

// CMD_PROP_RX
rfc_CMD_PROP_RX_t RF_cmdPropRx = {
	.commandNo = 0x3802,
	.status = 0x0000,
	.pNextOp = 0,		// INSERT APPLICABLE POINTER: (uint8_t*)&xxx
	.startTime = 0x00000000,
	.startTrigger.triggerType = 0x0,
	.startTrigger.bEnaCmd = 0x0,
	.startTrigger.triggerNo = 0x0,
	.startTrigger.pastTrig = 0x0,
	.condition.rule = 0x1,
	.condition.nSkip = 0x0,
	.pktConf.bFsOff = 0x0,
	.pktConf.bRepeatOk = 0x0,
	.pktConf.bRepeatNok = 0x0,
	.pktConf.bUseCrc = 0x1,
	.pktConf.bVarLen = 0x0,
	.pktConf.bChkAddress = 0x0,
	.pktConf.endType = 0x0,
	.pktConf.filterOp = 0x0,
	.rxConf.bAutoFlushIgnored = 0x0,
	.rxConf.bAutoFlushCrcErr = 0x0,
	.rxConf.bIncludeHdr = 0x1,
	.rxConf.bIncludeCrc = 0x0,
	.rxConf.bAppendRssi = 0x0,
	.rxConf.bAppendTimestamp = 0x0,
	.rxConf.bAppendStatus = 0x1,
	.syncWord = 0xaabbaabb,
	.maxPktLen = PACKETLENGTH,	// MAKE SURE DATA ENTRY IS LARGE ENOUGH
	.address0 = 0xaa,
	.address1 = 0xbb,
	.endTrigger.triggerType = 0x1,
	.endTrigger.bEnaCmd = 0x0,
	.endTrigger.triggerNo = 0x0,
	.endTrigger.pastTrig = 0x0,
	.endTime = 0x00000000,
	.pQueue = 0,		// INSERT APPLICABLE POINTER: (dataQueue_t*)&xxx
	.pOutput = 0,		// INSERT APPLICABLE POINTER: (uint8_t*)&xxx
};
