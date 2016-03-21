#ifndef TROOPERS_RFC_SETTINGS_H_
#define TROOPERS_RFC_SETTINGS_H_

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

*/

#include "rf-core/api/mailbox.h"
#include "rf-core/api/common_cmd.h"
#include "rf-core/api/prop_cmd.h"

#define CMD_PROP_TX 				0x3801
#define CMD_PROP_RX 				0x3802
#define CMD_PROP_TX_ADV 			0x3803
#define CMD_PROP_RX_ADV 			0x3804
#define CMD_PROP_CS 				0x3805
#define CMD_PROP_RADIO_SETUP 	    0x3806
#define CMD_PROP_RADIO_DIV_SETUP    0x3807

extern rfc_CMD_PROP_RADIO_DIV_SETUP_t RF_cmdPropRadioDivSetup;
extern rfc_CMD_FS_t RF_cmdFs;
extern rfc_CMD_PROP_TX_t RF_cmdPropTx;
extern rfc_CMD_PROP_RX_t RF_cmdPropRx;
extern uint32_t pOverrides[];

#endif
