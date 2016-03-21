#ifndef TROOPERS_RFC_CMD_H_
#define TROOPERS_RFC_CMD_H_

/*

Technical Reference S.1576 Proprietary Radio

Commands:

ID Command Name 				Supported Devices 	Description
0x3801 CMD_PROP_TX 				CC26xx, CC13xx 		Transmit packet
0x3802 CMD_PROP_RX 				CC26xx, CC13xx 		Receive packet or packets
0x3803 CMD_PROP_TX_ADV 			CC26xx, CC13xx 		Transmit packet with advanced modes
0x3804 CMD_PROP_RX_ADV 			CC26xx, CC13xx 		Receive packet or packets with advanced modes
0x3805 CMD_PROP_CS 				CC13xx 				Run carrier sense command
0x3806 CMD_PROP_RADIO_SETUP 	CC26xx 				Set up radio in proprietary mode
0x3807 CMD_PROP_RADIO_DIV_SETUP CC13xx 				Set up radio in proprietary mode for sub-1 GHz


0x3401 CMD_PROP_SET_LEN 		Set length of packet being received
0x3402 CMD_PROP_RESTART_RX 		Stop receiving a packet and go back to sync search

Setting the packet-format:

    CMD_PROP_RX_ADV
    CMD_PROP_TX_ADV


rfc_cmd_prop_radio_div_setup_t

rfc_cmd_fs_t

rfc_cmd_prop_{tx,rx}_adv_t

S.1506 23.3.4.3 CMD_GET_RSSI: Read RSSI Command
Command ID number: 0x0403
CMD_GET_RSSI is an immediate command that takes no parameters, and therefore, can be used as a
direct command.
On reception, the radio CPU reads the RSSI from an underlying receiver. The RSSI is returned in result
byte 2 (bit 23–16) of CMDSTA, see Figure 23-5. The RSSI is given on signed form in dBm. If no RSSI is
available, this is signaled with a special value of the RSSI (−128, or 0x80).
If no radio operation command is running, the radio CPU returns the result ContextError in CMDSTA.
Otherwise, the radio CPU returns Done along with the RSSI value.


23.3.4.6 CMD_GET_FW_INFO: Request Information on the Firmware Being Run
Command ID number: 0x0002

*/
#include "rf-core/api/prop_cmd.h"

#define CMD_PROP_TX 				0x3801
#define CMD_PROP_RX 				0x3802
#define CMD_PROP_TX_ADV 			0x3803
#define CMD_PROP_RX_ADV 			0x3804
#define CMD_PROP_CS 				0x3805
#define CMD_PROP_RADIO_SETUP 	    0x3806
#define CMD_PROP_RADIO_DIV_SETUP    0x3807
#define CMD_GET_RSSI                0x0403
#define CMD_GET_FW_INFO             0x0002
#define RF_CMD_CCA_REQ_RSSI_UNKNOWN -128
#define ENTER_RX_WAIT_TIMEOUT (RTIMER_SECOND >> 10)

#define DATA_ENTRY_STATUS_PENDING    0x00 /* Not in use by the Radio CPU */
#define DATA_ENTRY_STATUS_ACTIVE     0x01 /* Open for r/w by the radio CPU */
#define DATA_ENTRY_STATUS_BUSY       0x02 /* Ongoing r/w */
#define DATA_ENTRY_STATUS_FINISHED   0x03 /* Free to use and to free */
#define DATA_ENTRY_STATUS_UNFINISHED 0x04 /* Partial RX entry */

#define DEBUG 0
#if DEBUG
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif

void troopers_rfc_get_fw_info(void);
int8_t troopers_rfc_get_rssi(void);

void troopers_rfc_init(void);
void troopers_rfc_send(uint8_t *msg);
void troopers_rfc_receive(dataQueue_t *q, rfc_propRxOutput_t *rx_stats);
void troopers_rfc_update_fs(uint16_t freq, uint16_t fract);
void troopers_rfc_init_tune(uint16_t freq, uint16_t fract);
void troopers_rfc_abort(void);
void troopers_rfc_stop(void);

void troopers_rfc_init_queue(dataQueue_t *q, uint8_t *buf);

#endif
