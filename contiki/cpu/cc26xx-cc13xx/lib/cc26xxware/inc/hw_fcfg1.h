/******************************************************************************
*  Filename:       hw_fcfg1_h
*  Revised:        2015-06-18 17:11:10 +0200 (Thu, 18 Jun 2015)
*  Revision:       43982
*
* Copyright (c) 2015, Texas Instruments Incorporated
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1) Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
* 2) Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
* 3) Neither the name of the ORGANIZATION nor the names of its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************/

#ifndef __HW_FCFG1_H__
#define __HW_FCFG1_H__

//*****************************************************************************
//
// This section defines the register offsets of
// FCFG1 component
//
//*****************************************************************************
// Misc configurations
#define FCFG1_O_MISC_CONF_1                                         0x000000A0

#define FCFG1_O_BAW_MEAS_5                                          0x000000B0

#define FCFG1_O_BAW_MEAS_4                                          0x000000B4

#define FCFG1_O_BAW_MEAS_3                                          0x000000B8

#define FCFG1_O_BAW_MEAS_2                                          0x000000BC

#define FCFG1_O_BAW_MEAS_1                                          0x000000C0

// Configuration of RF Frontend in Divide-by-5 Mode
#define FCFG1_O_CONFIG_RF_FRONTEND_DIV5                             0x000000C4

// Configuration of RF Frontend in Divide-by-6 Mode
#define FCFG1_O_CONFIG_RF_FRONTEND_DIV6                             0x000000C8

// Configuration of RF Frontend in Divide-by-10 Mode
#define FCFG1_O_CONFIG_RF_FRONTEND_DIV10                            0x000000CC

// Configuration of RF Frontend in Divide-by-12 Mode
#define FCFG1_O_CONFIG_RF_FRONTEND_DIV12                            0x000000D0

// Configuration of RF Frontend in Divide-by-15 Mode
#define FCFG1_O_CONFIG_RF_FRONTEND_DIV15                            0x000000D4

// Configuration of RF Frontend in Divide-by-30 Mode
#define FCFG1_O_CONFIG_RF_FRONTEND_DIV30                            0x000000D8

// Configuration of Synthesizer in Divide-by-5 Mode
#define FCFG1_O_CONFIG_SYNTH_DIV5                                   0x000000DC

// Configuration of Synthesizer in Divide-by-6 Mode
#define FCFG1_O_CONFIG_SYNTH_DIV6                                   0x000000E0

// Configuration of Synthesizer in Divide-by-10 Mode
#define FCFG1_O_CONFIG_SYNTH_DIV10                                  0x000000E4

// Configuration of Synthesizer in Divide-by-12 Mode
#define FCFG1_O_CONFIG_SYNTH_DIV12                                  0x000000E8

// Configuration of Synthesizer in Divide-by-15 Mode
#define FCFG1_O_CONFIG_SYNTH_DIV15                                  0x000000EC

// Configuration of Synthesizer in Divide-by-30 Mode
#define FCFG1_O_CONFIG_SYNTH_DIV30                                  0x000000F0

// Configuration of IFADC in Divide-by-5 Mode
#define FCFG1_O_CONFIG_MISC_ADC_DIV5                                0x000000F4

// Configuration of IFADC in Divide-by-6 Mode
#define FCFG1_O_CONFIG_MISC_ADC_DIV6                                0x000000F8

// Configuration of IFADC in Divide-by-10 Mode
#define FCFG1_O_CONFIG_MISC_ADC_DIV10                               0x000000FC

// Configuration of IFADC in Divide-by-12 Mode
#define FCFG1_O_CONFIG_MISC_ADC_DIV12                               0x00000100

// Configuration of IFADC in Divide-by-15 Mode
#define FCFG1_O_CONFIG_MISC_ADC_DIV15                               0x00000104

// Configuration of IFADC in Divide-by-30 Mode
#define FCFG1_O_CONFIG_MISC_ADC_DIV30                               0x00000108

// Shadow of EFUSE:DIE_ID_0
#define FCFG1_O_SHDW_DIE_ID_0                                       0x00000118

// Shadow of EFUSE:DIE_ID_1
#define FCFG1_O_SHDW_DIE_ID_1                                       0x0000011C

// Shadow of EFUSE:DIE_ID_2
#define FCFG1_O_SHDW_DIE_ID_2                                       0x00000120

// Shadow of EFUSE:DIE_ID_3
#define FCFG1_O_SHDW_DIE_ID_3                                       0x00000124

// Shadow of EFUSE:OSC_BIAS_LDO_TRIM
#define FCFG1_O_SHDW_OSC_BIAS_LDO_TRIM                              0x00000138

// Shadow of EFUSE:ANA_TRIM
#define FCFG1_O_SHDW_ANA_TRIM                                       0x0000013C

#define FCFG1_O_FLASH_NUMBER                                        0x00000164

#define FCFG1_O_FLASH_COORDINATE                                    0x0000016C

// Flash Erase and Program Setup Time
#define FCFG1_O_FLASH_E_P                                           0x00000170

// Flash Compaction, Execute, Program and Read
#define FCFG1_O_FLASH_C_E_P_R                                       0x00000174

// Flash Program, Read, and Program Verify
#define FCFG1_O_FLASH_P_R_PV                                        0x00000178

// Flash Erase Hold and Sequence
#define FCFG1_O_FLASH_EH_SEQ                                        0x0000017C

// Flash VHV Erase
#define FCFG1_O_FLASH_VHV_E                                         0x00000180

// Flash Program Pulse
#define FCFG1_O_FLASH_PP                                            0x00000184

// Flash Program and Erase Pulse
#define FCFG1_O_FLASH_PROG_EP                                       0x00000188

// Flash Erase Pulse Width
#define FCFG1_O_FLASH_ERA_PW                                        0x0000018C

// Flash VHV
#define FCFG1_O_FLASH_VHV                                           0x00000190

// Flash VHV Program Verify
#define FCFG1_O_FLASH_VHV_PV                                        0x00000194

// Flash Voltages
#define FCFG1_O_FLASH_V                                             0x00000198

// User Identification.
#define FCFG1_O_USER_ID                                             0x00000294

// Flash OTP Data 3
#define FCFG1_O_FLASH_OTP_DATA3                                     0x000002B0

// Misc Analog Trim
#define FCFG1_O_ANA2_TRIM                                           0x000002B4

// LDO Trim
#define FCFG1_O_LDO_TRIM                                            0x000002B8

// MAC BLE Address 0
#define FCFG1_O_MAC_BLE_0                                           0x000002E8

// MAC BLE Address 1
#define FCFG1_O_MAC_BLE_1                                           0x000002EC

// MAC IEEE 802.15.4 Address 0
#define FCFG1_O_MAC_15_4_0                                          0x000002F0

// MAC IEEE 802.15.4 Address 1
#define FCFG1_O_MAC_15_4_1                                          0x000002F4

// Flash OTP Data 4
#define FCFG1_O_FLASH_OTP_DATA4                                     0x00000308

// Miscellaneous Trim  Parameters
#define FCFG1_O_MISC_TRIM                                           0x0000030C

// RCOSC HF Temperature Compensation
#define FCFG1_O_RCOSC_HF_TEMPCOMP                                   0x00000310

// IcePick Device Identification
#define FCFG1_O_ICEPICK_DEVICE_ID                                   0x00000318

// Factory Configuration (FCFG1) Revision
#define FCFG1_O_FCFG1_REVISION                                      0x0000031C

// Misc OTP Data
#define FCFG1_O_MISC_OTP_DATA                                       0x00000320

// IO Configuration
#define FCFG1_O_IOCONF                                              0x00000344

// Configuration of IF_ADC
#define FCFG1_O_CONFIG_IF_ADC                                       0x0000034C

// Configuration of OSC
#define FCFG1_O_CONFIG_OSC_TOP                                      0x00000350

// Configuration of RF Frontend in Divide-by-2 Mode
#define FCFG1_O_CONFIG_RF_FRONTEND                                  0x00000354

// Configuration of Synthesizer in Divide-by-2 Mode
#define FCFG1_O_CONFIG_SYNTH                                        0x00000358

// AUX_ADC Gain in Absolute Reference Mode
#define FCFG1_O_SOC_ADC_ABS_GAIN                                    0x0000035C

// AUX_ADC Gain in Relative Reference Mode
#define FCFG1_O_SOC_ADC_REL_GAIN                                    0x00000360

// AUX_ADC Temperature Offsets in Absolute Reference Mode
#define FCFG1_O_SOC_ADC_OFFSET_INT                                  0x00000368

// AUX_ADC Reference Trim and Offset for External Reference Mode
#define FCFG1_O_SOC_ADC_REF_TRIM_AND_OFFSET_EXT                     0x0000036C

// Ampltude Compensation Threashold 1
#define FCFG1_O_AMPCOMP_TH1                                         0x00000370

// Ampltude Compensation Threashold 2
#define FCFG1_O_AMPCOMP_TH2                                         0x00000374

// Amplitude Compensation Control
#define FCFG1_O_AMPCOMP_CTRL1                                       0x00000378

// Analog Bypass Value for OSC
#define FCFG1_O_ANABYPASS_VALUE2                                    0x0000037C

// Configuration of IFADC in Divide-by-2 Mode
#define FCFG1_O_CONFIG_MISC_ADC                                     0x00000380

// Voltage Trim
#define FCFG1_O_VOLT_TRIM                                           0x00000388

// OSC Configuration
#define FCFG1_O_OSC_CONF                                            0x0000038C

// Capasitor Trim
#define FCFG1_O_CAP_TRIM                                            0x00000394

// Misc OSC Control
#define FCFG1_O_MISC_OTP_DATA_1                                     0x00000398

// Power Down Current Control 20C
#define FCFG1_O_PWD_CURR_20C                                        0x0000039C

// Power Down Current Control 35C
#define FCFG1_O_PWD_CURR_35C                                        0x000003A0

// Power Down Current Control 50C
#define FCFG1_O_PWD_CURR_50C                                        0x000003A4

// Power Down Current Control 65C
#define FCFG1_O_PWD_CURR_65C                                        0x000003A8

// Power Down Current Control 80C
#define FCFG1_O_PWD_CURR_80C                                        0x000003AC

// Power Down Current Control 95C
#define FCFG1_O_PWD_CURR_95C                                        0x000003B0

// Power Down Current Control 110C
#define FCFG1_O_PWD_CURR_110C                                       0x000003B4

// Power Down Current Control 125C
#define FCFG1_O_PWD_CURR_125C                                       0x000003B8

//*****************************************************************************
//
// Register: FCFG1_O_MISC_CONF_1
//
//*****************************************************************************
// Field:   [7:0] DEVICE_MINOR_REV
//
// HW minor revision number (a value of 0xFF shall be treated equally to 0x00).
// Any test of this field by SW should be implemented as a 'greater or equal'
// comparison as signed integer.
// Value may change without warning.
#define FCFG1_MISC_CONF_1_DEVICE_MINOR_REV_M                        0x000000FF
#define FCFG1_MISC_CONF_1_DEVICE_MINOR_REV_S                                 0

//*****************************************************************************
//
// Register: FCFG1_O_BAW_MEAS_5
//
//*****************************************************************************
// Field: [31:16] BAW_D5
//
// Insertion 5 BAW delta frequency:
// D = round((f/48e6-1)*2^22)
#define FCFG1_BAW_MEAS_5_BAW_D5_M                                   0xFFFF0000
#define FCFG1_BAW_MEAS_5_BAW_D5_S                                           16

// Field:  [15:8] BAW_T5
//
// Insertion 5 BAW temp sensor readout, in degrees C, relative to 27C:
// T = round(t-27)
#define FCFG1_BAW_MEAS_5_BAW_T5_M                                   0x0000FF00
#define FCFG1_BAW_MEAS_5_BAW_T5_S                                            8

// Field:   [7:0] BAW_DT5
//
// Insertion 5 BAW delta T readout over VDDS, in 0.25 degrees C steps:
// DT = round ((4*(t at VDDS=3.8V))-round((4*(t at VDDS=1.8V))
#define FCFG1_BAW_MEAS_5_BAW_DT5_M                                  0x000000FF
#define FCFG1_BAW_MEAS_5_BAW_DT5_S                                           0

//*****************************************************************************
//
// Register: FCFG1_O_BAW_MEAS_4
//
//*****************************************************************************
// Field: [31:16] BAW_D4
//
// Insertion 4 BAW delta frequency:
// D = round((f/48e6-1)*2^22)
#define FCFG1_BAW_MEAS_4_BAW_D4_M                                   0xFFFF0000
#define FCFG1_BAW_MEAS_4_BAW_D4_S                                           16

// Field:  [15:8] BAW_T4
//
// Insertion 4 BAW temp sensor readout, in degrees C, relative to 27C:
// T = round(t-27)
#define FCFG1_BAW_MEAS_4_BAW_T4_M                                   0x0000FF00
#define FCFG1_BAW_MEAS_4_BAW_T4_S                                            8

// Field:   [7:0] BAW_DT4
//
// Insertion 4 BAW delta T readout over VDDS, in 0.25 degrees C steps:
// DT = round ((4*(t at VDDS=3.8V))-round((4*(t at VDDS=1.8V))
#define FCFG1_BAW_MEAS_4_BAW_DT4_M                                  0x000000FF
#define FCFG1_BAW_MEAS_4_BAW_DT4_S                                           0

//*****************************************************************************
//
// Register: FCFG1_O_BAW_MEAS_3
//
//*****************************************************************************
// Field: [31:16] BAW_D3
//
// Insertion 3 BAW delta frequency:
// D = round((f/48e6-1)*2^22)
#define FCFG1_BAW_MEAS_3_BAW_D3_M                                   0xFFFF0000
#define FCFG1_BAW_MEAS_3_BAW_D3_S                                           16

// Field:  [15:8] BAW_T3
//
// Insertion 3 BAW temp sensor readout, in degrees C, relative to 27C:
// T = round(t-27)
#define FCFG1_BAW_MEAS_3_BAW_T3_M                                   0x0000FF00
#define FCFG1_BAW_MEAS_3_BAW_T3_S                                            8

// Field:   [7:0] BAW_DT3
//
// Insertion 3 BAW delta T readout over VDDS, in 0.25 degrees C steps:
// DT = round ((4*(t at VDDS=3.8V))-round((4*(t at VDDS=1.8V))
#define FCFG1_BAW_MEAS_3_BAW_DT3_M                                  0x000000FF
#define FCFG1_BAW_MEAS_3_BAW_DT3_S                                           0

//*****************************************************************************
//
// Register: FCFG1_O_BAW_MEAS_2
//
//*****************************************************************************
// Field: [31:16] BAW_D2
//
// Insertion 2 BAW delta frequency:
// D = round((f/48e6-1)*2^22)
#define FCFG1_BAW_MEAS_2_BAW_D2_M                                   0xFFFF0000
#define FCFG1_BAW_MEAS_2_BAW_D2_S                                           16

// Field:  [15:8] BAW_T2
//
// Insertion 2 BAW temp sensor readout, in degrees C, relative to 27C:
// T = round(t-27)
#define FCFG1_BAW_MEAS_2_BAW_T2_M                                   0x0000FF00
#define FCFG1_BAW_MEAS_2_BAW_T2_S                                            8

// Field:   [7:0] BAW_DT2
//
// Insertion 2 BAW delta T readout over VDDS, in 0.25 degrees C steps:
// DT = round ((4*(t at VDDS=3.8V))-round((4*(t at VDDS=1.8V))
#define FCFG1_BAW_MEAS_2_BAW_DT2_M                                  0x000000FF
#define FCFG1_BAW_MEAS_2_BAW_DT2_S                                           0

//*****************************************************************************
//
// Register: FCFG1_O_BAW_MEAS_1
//
//*****************************************************************************
// Field: [31:16] BAW_D1
//
// Insertion 1 BAW delta frequency:
// D = round((f/48e6-1)*2^22)
#define FCFG1_BAW_MEAS_1_BAW_D1_M                                   0xFFFF0000
#define FCFG1_BAW_MEAS_1_BAW_D1_S                                           16

// Field:  [15:8] BAW_T1
//
// Insertion 1 BAW temp sensor readout, in degrees C, relative to 27C:
// T = round(t-27)
#define FCFG1_BAW_MEAS_1_BAW_T1_M                                   0x0000FF00
#define FCFG1_BAW_MEAS_1_BAW_T1_S                                            8

// Field:   [7:0] BAW_DT1
//
// Insertion 1 BAW delta T readout over VDDS, in 0.25 degrees C steps:
// DT = round ((4*(t at VDDS=3.8V))-round((4*(t at VDDS=1.8V))
#define FCFG1_BAW_MEAS_1_BAW_DT1_M                                  0x000000FF
#define FCFG1_BAW_MEAS_1_BAW_DT1_S                                           0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_RF_FRONTEND_DIV5
//
//*****************************************************************************
// Field: [31:28] IFAMP_IB
//
// Trim value used for ADI_0_RF:IFAMPCTL3.IB.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV5_IFAMP_IB_M                    0xF0000000
#define FCFG1_CONFIG_RF_FRONTEND_DIV5_IFAMP_IB_S                            28

// Field: [27:24] LNA_IB
//
// Trim value for ADI_0_RF:LNACTL2.IB.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV5_LNA_IB_M                      0x0F000000
#define FCFG1_CONFIG_RF_FRONTEND_DIV5_LNA_IB_S                              24

// Field: [23:19] IFAMP_TRIM
//
// Trim value for ADI_0_RF:IFAMPCTL0.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV5_IFAMP_TRIM_M                  0x00F80000
#define FCFG1_CONFIG_RF_FRONTEND_DIV5_IFAMP_TRIM_S                          19

// Field: [18:14] CTL_PA0_TRIM
//
// Trim value for ADI_0_RF:PACTL0.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV5_CTL_PA0_TRIM_M                0x0007C000
#define FCFG1_CONFIG_RF_FRONTEND_DIV5_CTL_PA0_TRIM_S                        14

// Field:   [6:0] RFLDO_TRIM_OUTPUT
//
// Trim value for ADI_0_RF:RFLDO1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV5_RFLDO_TRIM_OUTPUT_M           0x0000007F
#define FCFG1_CONFIG_RF_FRONTEND_DIV5_RFLDO_TRIM_OUTPUT_S                    0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_RF_FRONTEND_DIV6
//
//*****************************************************************************
// Field: [31:28] IFAMP_IB
//
// Trim value used for ADI_0_RF:IFAMPCTL3.IB.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV6_IFAMP_IB_M                    0xF0000000
#define FCFG1_CONFIG_RF_FRONTEND_DIV6_IFAMP_IB_S                            28

// Field: [27:24] LNA_IB
//
// Trim value for ADI_0_RF:LNACTL2.IB.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV6_LNA_IB_M                      0x0F000000
#define FCFG1_CONFIG_RF_FRONTEND_DIV6_LNA_IB_S                              24

// Field: [23:19] IFAMP_TRIM
//
// Trim value for ADI_0_RF:IFAMPCTL0.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV6_IFAMP_TRIM_M                  0x00F80000
#define FCFG1_CONFIG_RF_FRONTEND_DIV6_IFAMP_TRIM_S                          19

// Field: [18:14] CTL_PA0_TRIM
//
// Trim value for ADI_0_RF:PACTL0.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV6_CTL_PA0_TRIM_M                0x0007C000
#define FCFG1_CONFIG_RF_FRONTEND_DIV6_CTL_PA0_TRIM_S                        14

// Field:   [6:0] RFLDO_TRIM_OUTPUT
//
// Trim value for ADI_0_RF:RFLDO1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV6_RFLDO_TRIM_OUTPUT_M           0x0000007F
#define FCFG1_CONFIG_RF_FRONTEND_DIV6_RFLDO_TRIM_OUTPUT_S                    0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_RF_FRONTEND_DIV10
//
//*****************************************************************************
// Field: [31:28] IFAMP_IB
//
// Trim value used for ADI_0_RF:IFAMPCTL3.IB.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV10_IFAMP_IB_M                   0xF0000000
#define FCFG1_CONFIG_RF_FRONTEND_DIV10_IFAMP_IB_S                           28

// Field: [27:24] LNA_IB
//
// Trim value for ADI_0_RF:LNACTL2.IB.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV10_LNA_IB_M                     0x0F000000
#define FCFG1_CONFIG_RF_FRONTEND_DIV10_LNA_IB_S                             24

// Field: [23:19] IFAMP_TRIM
//
// Trim value for ADI_0_RF:IFAMPCTL0.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV10_IFAMP_TRIM_M                 0x00F80000
#define FCFG1_CONFIG_RF_FRONTEND_DIV10_IFAMP_TRIM_S                         19

// Field: [18:14] CTL_PA0_TRIM
//
// Trim value for ADI_0_RF:PACTL0.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV10_CTL_PA0_TRIM_M               0x0007C000
#define FCFG1_CONFIG_RF_FRONTEND_DIV10_CTL_PA0_TRIM_S                       14

// Field:   [6:0] RFLDO_TRIM_OUTPUT
//
// Trim value for ADI_0_RF:RFLDO1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV10_RFLDO_TRIM_OUTPUT_M          0x0000007F
#define FCFG1_CONFIG_RF_FRONTEND_DIV10_RFLDO_TRIM_OUTPUT_S                   0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_RF_FRONTEND_DIV12
//
//*****************************************************************************
// Field: [31:28] IFAMP_IB
//
// Trim value used for ADI_0_RF:IFAMPCTL3.IB.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV12_IFAMP_IB_M                   0xF0000000
#define FCFG1_CONFIG_RF_FRONTEND_DIV12_IFAMP_IB_S                           28

// Field: [27:24] LNA_IB
//
// Trim value for ADI_0_RF:LNACTL2.IB.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV12_LNA_IB_M                     0x0F000000
#define FCFG1_CONFIG_RF_FRONTEND_DIV12_LNA_IB_S                             24

// Field: [23:19] IFAMP_TRIM
//
// Trim value for ADI_0_RF:IFAMPCTL0.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV12_IFAMP_TRIM_M                 0x00F80000
#define FCFG1_CONFIG_RF_FRONTEND_DIV12_IFAMP_TRIM_S                         19

// Field: [18:14] CTL_PA0_TRIM
//
// Trim value for ADI_0_RF:PACTL0.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV12_CTL_PA0_TRIM_M               0x0007C000
#define FCFG1_CONFIG_RF_FRONTEND_DIV12_CTL_PA0_TRIM_S                       14

// Field:   [6:0] RFLDO_TRIM_OUTPUT
//
// Trim value for ADI_0_RF:RFLDO1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV12_RFLDO_TRIM_OUTPUT_M          0x0000007F
#define FCFG1_CONFIG_RF_FRONTEND_DIV12_RFLDO_TRIM_OUTPUT_S                   0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_RF_FRONTEND_DIV15
//
//*****************************************************************************
// Field: [31:28] IFAMP_IB
//
// Trim value used for ADI_0_RF:IFAMPCTL3.IB.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV15_IFAMP_IB_M                   0xF0000000
#define FCFG1_CONFIG_RF_FRONTEND_DIV15_IFAMP_IB_S                           28

// Field: [27:24] LNA_IB
//
// Trim value for ADI_0_RF:LNACTL2.IB.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV15_LNA_IB_M                     0x0F000000
#define FCFG1_CONFIG_RF_FRONTEND_DIV15_LNA_IB_S                             24

// Field: [23:19] IFAMP_TRIM
//
// Trim value for ADI_0_RF:IFAMPCTL0.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV15_IFAMP_TRIM_M                 0x00F80000
#define FCFG1_CONFIG_RF_FRONTEND_DIV15_IFAMP_TRIM_S                         19

// Field: [18:14] CTL_PA0_TRIM
//
// Trim value for ADI_0_RF:PACTL0.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV15_CTL_PA0_TRIM_M               0x0007C000
#define FCFG1_CONFIG_RF_FRONTEND_DIV15_CTL_PA0_TRIM_S                       14

// Field:   [6:0] RFLDO_TRIM_OUTPUT
//
// Trim value for ADI_0_RF:RFLDO1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV15_RFLDO_TRIM_OUTPUT_M          0x0000007F
#define FCFG1_CONFIG_RF_FRONTEND_DIV15_RFLDO_TRIM_OUTPUT_S                   0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_RF_FRONTEND_DIV30
//
//*****************************************************************************
// Field: [31:28] IFAMP_IB
//
// Trim value used for ADI_0_RF:IFAMPCTL3.IB.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV30_IFAMP_IB_M                   0xF0000000
#define FCFG1_CONFIG_RF_FRONTEND_DIV30_IFAMP_IB_S                           28

// Field: [27:24] LNA_IB
//
// Trim value for ADI_0_RF:LNACTL2.IB.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV30_LNA_IB_M                     0x0F000000
#define FCFG1_CONFIG_RF_FRONTEND_DIV30_LNA_IB_S                             24

// Field: [23:19] IFAMP_TRIM
//
// Trim value for ADI_0_RF:IFAMPCTL0.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV30_IFAMP_TRIM_M                 0x00F80000
#define FCFG1_CONFIG_RF_FRONTEND_DIV30_IFAMP_TRIM_S                         19

// Field: [18:14] CTL_PA0_TRIM
//
// Trim value for ADI_0_RF:PACTL0.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV30_CTL_PA0_TRIM_M               0x0007C000
#define FCFG1_CONFIG_RF_FRONTEND_DIV30_CTL_PA0_TRIM_S                       14

// Field:   [6:0] RFLDO_TRIM_OUTPUT
//
// Trim value for ADI_0_RF:RFLDO1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_DIV30_RFLDO_TRIM_OUTPUT_M          0x0000007F
#define FCFG1_CONFIG_RF_FRONTEND_DIV30_RFLDO_TRIM_OUTPUT_S                   0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_SYNTH_DIV5
//
//*****************************************************************************
// Field: [27:12] RFC_MDM_DEMIQMC0
//
// Trim value for RFC_MDM:DEMIQMC0.GAINFACTOR and RFC_MDM:DEMIQMC0.PHASEFACTOR
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_DIV5_RFC_MDM_DEMIQMC0_M                  0x0FFFF000
#define FCFG1_CONFIG_SYNTH_DIV5_RFC_MDM_DEMIQMC0_S                          12

// Field:  [11:6] LDOVCO_TRIM_OUTPUT
//
// Trim value for ADI_1_SYNTH:VCOLDOCTL1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_DIV5_LDOVCO_TRIM_OUTPUT_M                0x00000FC0
#define FCFG1_CONFIG_SYNTH_DIV5_LDOVCO_TRIM_OUTPUT_S                         6

// Field:   [5:0] SLDO_TRIM_OUTPUT
//
// Trim value for ADI_1_SYNTH:SLDOCTL1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_DIV5_SLDO_TRIM_OUTPUT_M                  0x0000003F
#define FCFG1_CONFIG_SYNTH_DIV5_SLDO_TRIM_OUTPUT_S                           0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_SYNTH_DIV6
//
//*****************************************************************************
// Field: [27:12] RFC_MDM_DEMIQMC0
//
// Trim value for RFC_MDM:DEMIQMC0.GAINFACTOR and RFC_MDM:DEMIQMC0.PHASEFACTOR
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_DIV6_RFC_MDM_DEMIQMC0_M                  0x0FFFF000
#define FCFG1_CONFIG_SYNTH_DIV6_RFC_MDM_DEMIQMC0_S                          12

// Field:  [11:6] LDOVCO_TRIM_OUTPUT
//
// Trim value for ADI_1_SYNTH:VCOLDOCTL1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_DIV6_LDOVCO_TRIM_OUTPUT_M                0x00000FC0
#define FCFG1_CONFIG_SYNTH_DIV6_LDOVCO_TRIM_OUTPUT_S                         6

// Field:   [5:0] SLDO_TRIM_OUTPUT
//
// Trim value for ADI_1_SYNTH:SLDOCTL1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_DIV6_SLDO_TRIM_OUTPUT_M                  0x0000003F
#define FCFG1_CONFIG_SYNTH_DIV6_SLDO_TRIM_OUTPUT_S                           0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_SYNTH_DIV10
//
//*****************************************************************************
// Field: [27:12] RFC_MDM_DEMIQMC0
//
// Trim value for RFC_MDM:DEMIQMC0.GAINFACTOR and RFC_MDM:DEMIQMC0.PHASEFACTOR
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_DIV10_RFC_MDM_DEMIQMC0_M                 0x0FFFF000
#define FCFG1_CONFIG_SYNTH_DIV10_RFC_MDM_DEMIQMC0_S                         12

// Field:  [11:6] LDOVCO_TRIM_OUTPUT
//
// Trim value for ADI_1_SYNTH:VCOLDOCTL1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_DIV10_LDOVCO_TRIM_OUTPUT_M               0x00000FC0
#define FCFG1_CONFIG_SYNTH_DIV10_LDOVCO_TRIM_OUTPUT_S                        6

// Field:   [5:0] SLDO_TRIM_OUTPUT
//
// Trim value for ADI_1_SYNTH:SLDOCTL1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_DIV10_SLDO_TRIM_OUTPUT_M                 0x0000003F
#define FCFG1_CONFIG_SYNTH_DIV10_SLDO_TRIM_OUTPUT_S                          0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_SYNTH_DIV12
//
//*****************************************************************************
// Field: [27:12] RFC_MDM_DEMIQMC0
//
// Trim value for RFC_MDM:DEMIQMC0.GAINFACTOR and RFC_MDM:DEMIQMC0.PHASEFACTOR
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_DIV12_RFC_MDM_DEMIQMC0_M                 0x0FFFF000
#define FCFG1_CONFIG_SYNTH_DIV12_RFC_MDM_DEMIQMC0_S                         12

// Field:  [11:6] LDOVCO_TRIM_OUTPUT
//
// Trim value for ADI_1_SYNTH:VCOLDOCTL1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_DIV12_LDOVCO_TRIM_OUTPUT_M               0x00000FC0
#define FCFG1_CONFIG_SYNTH_DIV12_LDOVCO_TRIM_OUTPUT_S                        6

// Field:   [5:0] SLDO_TRIM_OUTPUT
//
// Trim value for ADI_1_SYNTH:SLDOCTL1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_DIV12_SLDO_TRIM_OUTPUT_M                 0x0000003F
#define FCFG1_CONFIG_SYNTH_DIV12_SLDO_TRIM_OUTPUT_S                          0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_SYNTH_DIV15
//
//*****************************************************************************
// Field: [27:12] RFC_MDM_DEMIQMC0
//
// Trim value for RFC_MDM:DEMIQMC0.GAINFACTOR and RFC_MDM:DEMIQMC0.PHASEFACTOR
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_DIV15_RFC_MDM_DEMIQMC0_M                 0x0FFFF000
#define FCFG1_CONFIG_SYNTH_DIV15_RFC_MDM_DEMIQMC0_S                         12

// Field:  [11:6] LDOVCO_TRIM_OUTPUT
//
// Trim value for ADI_1_SYNTH:VCOLDOCTL1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_DIV15_LDOVCO_TRIM_OUTPUT_M               0x00000FC0
#define FCFG1_CONFIG_SYNTH_DIV15_LDOVCO_TRIM_OUTPUT_S                        6

// Field:   [5:0] SLDO_TRIM_OUTPUT
//
// Trim value for ADI_1_SYNTH:SLDOCTL1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_DIV15_SLDO_TRIM_OUTPUT_M                 0x0000003F
#define FCFG1_CONFIG_SYNTH_DIV15_SLDO_TRIM_OUTPUT_S                          0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_SYNTH_DIV30
//
//*****************************************************************************
// Field: [27:12] RFC_MDM_DEMIQMC0
//
// Trim value for RFC_MDM:DEMIQMC0.GAINFACTOR and RFC_MDM:DEMIQMC0.PHASEFACTOR
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_DIV30_RFC_MDM_DEMIQMC0_M                 0x0FFFF000
#define FCFG1_CONFIG_SYNTH_DIV30_RFC_MDM_DEMIQMC0_S                         12

// Field:  [11:6] LDOVCO_TRIM_OUTPUT
//
// Trim value for ADI_1_SYNTH:VCOLDOCTL1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_DIV30_LDOVCO_TRIM_OUTPUT_M               0x00000FC0
#define FCFG1_CONFIG_SYNTH_DIV30_LDOVCO_TRIM_OUTPUT_S                        6

// Field:   [5:0] SLDO_TRIM_OUTPUT
//
// Trim value for ADI_1_SYNTH:SLDOCTL1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_DIV30_SLDO_TRIM_OUTPUT_M                 0x0000003F
#define FCFG1_CONFIG_SYNTH_DIV30_SLDO_TRIM_OUTPUT_S                          0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_MISC_ADC_DIV5
//
//*****************************************************************************
// Field:  [16:9] RSSI_OFFSET
//
// Value for RSSI measured in production test.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_DIV5_RSSI_OFFSET_M                    0x0001FE00
#define FCFG1_CONFIG_MISC_ADC_DIV5_RSSI_OFFSET_S                             9

// Field:   [8:6] QUANTCTLTHRES
//
// Trim value for ADI_0_RF:IFADCQUANT0.TH.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_DIV5_QUANTCTLTHRES_M                  0x000001C0
#define FCFG1_CONFIG_MISC_ADC_DIV5_QUANTCTLTHRES_S                           6

// Field:   [5:0] DACTRIM
//
// Trim value for ADI_0_RF:IFADCDAC.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_DIV5_DACTRIM_M                        0x0000003F
#define FCFG1_CONFIG_MISC_ADC_DIV5_DACTRIM_S                                 0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_MISC_ADC_DIV6
//
//*****************************************************************************
// Field:  [16:9] RSSI_OFFSET
//
// Value for RSSI measured in production test.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_DIV6_RSSI_OFFSET_M                    0x0001FE00
#define FCFG1_CONFIG_MISC_ADC_DIV6_RSSI_OFFSET_S                             9

// Field:   [8:6] QUANTCTLTHRES
//
// Trim value for ADI_0_RF:IFADCQUANT0.TH.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_DIV6_QUANTCTLTHRES_M                  0x000001C0
#define FCFG1_CONFIG_MISC_ADC_DIV6_QUANTCTLTHRES_S                           6

// Field:   [5:0] DACTRIM
//
// Trim value for ADI_0_RF:IFADCDAC.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_DIV6_DACTRIM_M                        0x0000003F
#define FCFG1_CONFIG_MISC_ADC_DIV6_DACTRIM_S                                 0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_MISC_ADC_DIV10
//
//*****************************************************************************
// Field:  [16:9] RSSI_OFFSET
//
// Value for RSSI measured in production test.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_DIV10_RSSI_OFFSET_M                   0x0001FE00
#define FCFG1_CONFIG_MISC_ADC_DIV10_RSSI_OFFSET_S                            9

// Field:   [8:6] QUANTCTLTHRES
//
// Trim value for ADI_0_RF:IFADCQUANT0.TH.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_DIV10_QUANTCTLTHRES_M                 0x000001C0
#define FCFG1_CONFIG_MISC_ADC_DIV10_QUANTCTLTHRES_S                          6

// Field:   [5:0] DACTRIM
//
// Trim value for ADI_0_RF:IFADCDAC.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_DIV10_DACTRIM_M                       0x0000003F
#define FCFG1_CONFIG_MISC_ADC_DIV10_DACTRIM_S                                0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_MISC_ADC_DIV12
//
//*****************************************************************************
// Field:  [16:9] RSSI_OFFSET
//
// Value for RSSI measured in production test.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_DIV12_RSSI_OFFSET_M                   0x0001FE00
#define FCFG1_CONFIG_MISC_ADC_DIV12_RSSI_OFFSET_S                            9

// Field:   [8:6] QUANTCTLTHRES
//
// Trim value for ADI_0_RF:IFADCQUANT0.TH.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_DIV12_QUANTCTLTHRES_M                 0x000001C0
#define FCFG1_CONFIG_MISC_ADC_DIV12_QUANTCTLTHRES_S                          6

// Field:   [5:0] DACTRIM
//
// Trim value for ADI_0_RF:IFADCDAC.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_DIV12_DACTRIM_M                       0x0000003F
#define FCFG1_CONFIG_MISC_ADC_DIV12_DACTRIM_S                                0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_MISC_ADC_DIV15
//
//*****************************************************************************
// Field:  [16:9] RSSI_OFFSET
//
// Value for RSSI measured in production test.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_DIV15_RSSI_OFFSET_M                   0x0001FE00
#define FCFG1_CONFIG_MISC_ADC_DIV15_RSSI_OFFSET_S                            9

// Field:   [8:6] QUANTCTLTHRES
//
// Trim value for ADI_0_RF:IFADCQUANT0.TH.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_DIV15_QUANTCTLTHRES_M                 0x000001C0
#define FCFG1_CONFIG_MISC_ADC_DIV15_QUANTCTLTHRES_S                          6

// Field:   [5:0] DACTRIM
//
// Trim value for ADI_0_RF:IFADCDAC.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_DIV15_DACTRIM_M                       0x0000003F
#define FCFG1_CONFIG_MISC_ADC_DIV15_DACTRIM_S                                0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_MISC_ADC_DIV30
//
//*****************************************************************************
// Field:  [16:9] RSSI_OFFSET
//
// Value for RSSI measured in production test.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_DIV30_RSSI_OFFSET_M                   0x0001FE00
#define FCFG1_CONFIG_MISC_ADC_DIV30_RSSI_OFFSET_S                            9

// Field:   [8:6] QUANTCTLTHRES
//
// Trim value for ADI_0_RF:IFADCQUANT0.TH.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_DIV30_QUANTCTLTHRES_M                 0x000001C0
#define FCFG1_CONFIG_MISC_ADC_DIV30_QUANTCTLTHRES_S                          6

// Field:   [5:0] DACTRIM
//
// Trim value for ADI_0_RF:IFADCDAC.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_DIV30_DACTRIM_M                       0x0000003F
#define FCFG1_CONFIG_MISC_ADC_DIV30_DACTRIM_S                                0

//*****************************************************************************
//
// Register: FCFG1_O_SHDW_DIE_ID_0
//
//*****************************************************************************
// Field:  [31:0] ID_31_0
//
// Shadow of EFUSE:DIE_ID_0, ie efuse row number 3
#define FCFG1_SHDW_DIE_ID_0_ID_31_0_M                               0xFFFFFFFF
#define FCFG1_SHDW_DIE_ID_0_ID_31_0_S                                        0

//*****************************************************************************
//
// Register: FCFG1_O_SHDW_DIE_ID_1
//
//*****************************************************************************
// Field:  [31:0] ID_63_32
//
// Shadow of EFUSE:DIE_ID_1, ie efuse row number 4
#define FCFG1_SHDW_DIE_ID_1_ID_63_32_M                              0xFFFFFFFF
#define FCFG1_SHDW_DIE_ID_1_ID_63_32_S                                       0

//*****************************************************************************
//
// Register: FCFG1_O_SHDW_DIE_ID_2
//
//*****************************************************************************
// Field:  [31:0] ID_95_64
//
// Shadow of EFUSE:DIE_ID_2, ie efuse row number 5
#define FCFG1_SHDW_DIE_ID_2_ID_95_64_M                              0xFFFFFFFF
#define FCFG1_SHDW_DIE_ID_2_ID_95_64_S                                       0

//*****************************************************************************
//
// Register: FCFG1_O_SHDW_DIE_ID_3
//
//*****************************************************************************
// Field:  [31:0] ID_127_96
//
// Shadow of EFUSE:DIE_ID_3, ie efuse row number 6
#define FCFG1_SHDW_DIE_ID_3_ID_127_96_M                             0xFFFFFFFF
#define FCFG1_SHDW_DIE_ID_3_ID_127_96_S                                      0

//*****************************************************************************
//
// Register: FCFG1_O_SHDW_OSC_BIAS_LDO_TRIM
//
//*****************************************************************************
// Field: [28:27] SET_RCOSC_HF_COARSE_RESISTOR
//
// Shadow of EFUSE:OSC_BIAS_LDO_TRIM.SET_RCOSC_HF_COARSE_RESISTOR, ie in efuse
// row number 11
#define FCFG1_SHDW_OSC_BIAS_LDO_TRIM_SET_RCOSC_HF_COARSE_RESISTOR_M  \
                                                                    0x18000000
#define FCFG1_SHDW_OSC_BIAS_LDO_TRIM_SET_RCOSC_HF_COARSE_RESISTOR_S  \
                                                                            27

// Field: [26:23] TRIMMAG
//
// Shadow of EFUSE:OSC_BIAS_LDO_TRIM.TRIMMAG, ie in efuse row number 11
#define FCFG1_SHDW_OSC_BIAS_LDO_TRIM_TRIMMAG_M                      0x07800000
#define FCFG1_SHDW_OSC_BIAS_LDO_TRIM_TRIMMAG_S                              23

// Field: [22:18] TRIMIREF
//
// Shadow of EFUSE:OSC_BIAS_LDO_TRIM.TRIMIREF, ie in efuse row number 11
#define FCFG1_SHDW_OSC_BIAS_LDO_TRIM_TRIMIREF_M                     0x007C0000
#define FCFG1_SHDW_OSC_BIAS_LDO_TRIM_TRIMIREF_S                             18

// Field: [17:16] ITRIM_DIG_LDO
//
// Shadow of EFUSE:OSC_BIAS_LDO_TRIM.ITRIM_DIG_LDO, ie in efuse row number 11
#define FCFG1_SHDW_OSC_BIAS_LDO_TRIM_ITRIM_DIG_LDO_M                0x00030000
#define FCFG1_SHDW_OSC_BIAS_LDO_TRIM_ITRIM_DIG_LDO_S                        16

// Field: [15:12] VTRIM_DIG
//
// Shadow of EFUSE:OSC_BIAS_LDO_TRIM.VTRIM_DIG, ie in efuse row number 11
#define FCFG1_SHDW_OSC_BIAS_LDO_TRIM_VTRIM_DIG_M                    0x0000F000
#define FCFG1_SHDW_OSC_BIAS_LDO_TRIM_VTRIM_DIG_S                            12

// Field:  [11:8] VTRIM_COARSE
//
// Shadow of EFUSE:OSC_BIAS_LDO_TRIM.VTRIM_COARSE, ie in efuse row number 11
#define FCFG1_SHDW_OSC_BIAS_LDO_TRIM_VTRIM_COARSE_M                 0x00000F00
#define FCFG1_SHDW_OSC_BIAS_LDO_TRIM_VTRIM_COARSE_S                          8

// Field:   [7:0] RCOSCHF_CTRIM
//
// Shadow of EFUSE:OSC_BIAS_LDO_TRIM.RCOSCHF_CTRIM, ie in efuse row number 11
#define FCFG1_SHDW_OSC_BIAS_LDO_TRIM_RCOSCHF_CTRIM_M                0x000000FF
#define FCFG1_SHDW_OSC_BIAS_LDO_TRIM_RCOSCHF_CTRIM_S                         0

//*****************************************************************************
//
// Register: FCFG1_O_SHDW_ANA_TRIM
//
//*****************************************************************************
// Field: [26:25] BOD_BANDGAP_TRIM_CNF
//
// Shadow of EFUSE:ANA_TRIM.BOD_BANDGAP_TRIM_CNF, ie in efuse row number 12
#define FCFG1_SHDW_ANA_TRIM_BOD_BANDGAP_TRIM_CNF_M                  0x06000000
#define FCFG1_SHDW_ANA_TRIM_BOD_BANDGAP_TRIM_CNF_S                          25

// Field:    [24] VDDR_ENABLE_PG1
//
// Shadow of EFUSE:ANA_TRIM.VDDR_ENABLE_PG1, ie in efuse row number 12
#define FCFG1_SHDW_ANA_TRIM_VDDR_ENABLE_PG1                         0x01000000
#define FCFG1_SHDW_ANA_TRIM_VDDR_ENABLE_PG1_BITN                            24
#define FCFG1_SHDW_ANA_TRIM_VDDR_ENABLE_PG1_M                       0x01000000
#define FCFG1_SHDW_ANA_TRIM_VDDR_ENABLE_PG1_S                               24

// Field:    [23] VDDR_OK_HYS
//
// Shadow of EFUSE:ANA_TRIM.VDDR_OK_HYS, ie in efuse row number 12
#define FCFG1_SHDW_ANA_TRIM_VDDR_OK_HYS                             0x00800000
#define FCFG1_SHDW_ANA_TRIM_VDDR_OK_HYS_BITN                                23
#define FCFG1_SHDW_ANA_TRIM_VDDR_OK_HYS_M                           0x00800000
#define FCFG1_SHDW_ANA_TRIM_VDDR_OK_HYS_S                                   23

// Field: [22:21] IPTAT_TRIM
//
// Shadow of EFUSE:ANA_TRIM.IPTAT_TRIM, ie in efuse row number 12
#define FCFG1_SHDW_ANA_TRIM_IPTAT_TRIM_M                            0x00600000
#define FCFG1_SHDW_ANA_TRIM_IPTAT_TRIM_S                                    21

// Field: [20:16] VDDR_TRIM
//
// Shadow of EFUSE:ANA_TRIM.VDDR_TRIM, ie in efuse row number 12
#define FCFG1_SHDW_ANA_TRIM_VDDR_TRIM_M                             0x001F0000
#define FCFG1_SHDW_ANA_TRIM_VDDR_TRIM_S                                     16

// Field: [15:11] TRIMBOD_INTMODE
//
// Shadow of EFUSE:ANA_TRIM.TRIMBOD_INTMODE, ie in efuse row number 12
#define FCFG1_SHDW_ANA_TRIM_TRIMBOD_INTMODE_M                       0x0000F800
#define FCFG1_SHDW_ANA_TRIM_TRIMBOD_INTMODE_S                               11

// Field:  [10:6] TRIMBOD_EXTMODE
//
// Shadow of EFUSE:ANA_TRIM.TRIMBOD_EXTMODE, ie in efuse row number 12
#define FCFG1_SHDW_ANA_TRIM_TRIMBOD_EXTMODE_M                       0x000007C0
#define FCFG1_SHDW_ANA_TRIM_TRIMBOD_EXTMODE_S                                6

// Field:   [5:0] TRIMTEMP
//
// Shadow of EFUSE:ANA_TRIM.TRIMTEMP, ie in efuse row number 12
#define FCFG1_SHDW_ANA_TRIM_TRIMTEMP_M                              0x0000003F
#define FCFG1_SHDW_ANA_TRIM_TRIMTEMP_S                                       0

//*****************************************************************************
//
// Register: FCFG1_O_FLASH_NUMBER
//
//*****************************************************************************
// Field:  [31:0] LOT_NUMBER
//
// Number of the manufacturing lot that produced this unit.
#define FCFG1_FLASH_NUMBER_LOT_NUMBER_M                             0xFFFFFFFF
#define FCFG1_FLASH_NUMBER_LOT_NUMBER_S                                      0

//*****************************************************************************
//
// Register: FCFG1_O_FLASH_COORDINATE
//
//*****************************************************************************
// Field: [31:16] XCOORDINATE
//
// X coordinate of this unit on the wafer.
#define FCFG1_FLASH_COORDINATE_XCOORDINATE_M                        0xFFFF0000
#define FCFG1_FLASH_COORDINATE_XCOORDINATE_S                                16

// Field:  [15:0] YCOORDINATE
//
// Y coordinate of this unit on the wafer.
#define FCFG1_FLASH_COORDINATE_YCOORDINATE_M                        0x0000FFFF
#define FCFG1_FLASH_COORDINATE_YCOORDINATE_S                                 0

//*****************************************************************************
//
// Register: FCFG1_O_FLASH_E_P
//
//*****************************************************************************
// Field: [31:24] PSU
//
// Program setup time in cycles. Value will be written to
// FLASH:FSM_PE_OSU.PGM_OSU by the flash device driver when an erase/program
// operation is initiated.
#define FCFG1_FLASH_E_P_PSU_M                                       0xFF000000
#define FCFG1_FLASH_E_P_PSU_S                                               24

// Field: [23:16] ESU
//
// Erase setup time in cycles. Value will be written to
// FLASH:FSM_PE_OSU.ERA_OSU by the flash device driver when an erase/program
// operation is initiated.
#define FCFG1_FLASH_E_P_ESU_M                                       0x00FF0000
#define FCFG1_FLASH_E_P_ESU_S                                               16

// Field:  [15:8] PVSU
//
// Program verify setup time in cycles. Value will be written to
// FLASH:FSM_PE_VSU.PGM_VSU by the flash device driver when an erase/program
// operation is initiated.
#define FCFG1_FLASH_E_P_PVSU_M                                      0x0000FF00
#define FCFG1_FLASH_E_P_PVSU_S                                               8

// Field:   [7:0] EVSU
//
// Erase verify setup time in cycles. Value will be written to
// FLASH:FSM_PE_VSU.ERA_VSU by the flash device driver when an erase/program
// operation is initiated.
#define FCFG1_FLASH_E_P_EVSU_M                                      0x000000FF
#define FCFG1_FLASH_E_P_EVSU_S                                               0

//*****************************************************************************
//
// Register: FCFG1_O_FLASH_C_E_P_R
//
//*****************************************************************************
// Field: [31:24] RVSU
//
// Repeat verify setup time in cycles. Used for repeated verifies during
// program and erase. Value will be written to FLASH:FSM_EX_VAL.REP_VSU by the
// flash device driver when an erase/program operation is initiated.
#define FCFG1_FLASH_C_E_P_R_RVSU_M                                  0xFF000000
#define FCFG1_FLASH_C_E_P_R_RVSU_S                                          24

// Field: [23:16] PV_ACCESS
//
// Program verify EXECUTEZ->data valid time in half-microseconds. Value will be
// converted to number of FCLK cycles by by flash device driver and the
// converted value is written to FLASH:FSM_EX_VAL.EXE_VALD when an
// erase/program operation is initiated..
#define FCFG1_FLASH_C_E_P_R_PV_ACCESS_M                             0x00FF0000
#define FCFG1_FLASH_C_E_P_R_PV_ACCESS_S                                     16

// Field: [15:12] A_EXEZ_SETUP
//
// Address->EXECUTEZ setup time in cycles. Value will be written to
// FLASH:FSM_CMP_VSU.ADD_EXZ by the flash device driver when an erase/program
// operation is initiated..
#define FCFG1_FLASH_C_E_P_R_A_EXEZ_SETUP_M                          0x0000F000
#define FCFG1_FLASH_C_E_P_R_A_EXEZ_SETUP_S                                  12

// Field:  [11:0] CVSU
//
// Compaction verify setup time in cycles.
#define FCFG1_FLASH_C_E_P_R_CVSU_M                                  0x00000FFF
#define FCFG1_FLASH_C_E_P_R_CVSU_S                                           0

//*****************************************************************************
//
// Register: FCFG1_O_FLASH_P_R_PV
//
//*****************************************************************************
// Field: [31:24] PH
//
// Program hold time in half-microseconds after SAFELV goes low. Value will be
// converted to number of FCLK cycles by the flash device driver and the
// converted value is written to FLASH:FSM_P_OH.PGM_OH when an erase/program
// operation is initiated.
#define FCFG1_FLASH_P_R_PV_PH_M                                     0xFF000000
#define FCFG1_FLASH_P_R_PV_PH_S                                             24

// Field: [23:16] RH
//
// Read hold/mode transition time in cycles. Value will be written to the RD_H
// field bits[7:0] of the FSM_RD_H register in the flash module by the flash
// device driver when an erase/program operation is initiated.
#define FCFG1_FLASH_P_R_PV_RH_M                                     0x00FF0000
#define FCFG1_FLASH_P_R_PV_RH_S                                             16

// Field:  [15:8] PVH
//
// Program verify hold time in half-microseconds after SAFELV goes low. Value
// will be converted to number of FCLK cycles by the flash device driver and
// the converted value is written to FLASH:FSM_PE_VH.PGM_VH when an
// erase/program operation is initiated.
#define FCFG1_FLASH_P_R_PV_PVH_M                                    0x0000FF00
#define FCFG1_FLASH_P_R_PV_PVH_S                                             8

// Field:   [7:0] PVH2
//
// Program verify row switch time in half-microseconds.
#define FCFG1_FLASH_P_R_PV_PVH2_M                                   0x000000FF
#define FCFG1_FLASH_P_R_PV_PVH2_S                                            0

//*****************************************************************************
//
// Register: FCFG1_O_FLASH_EH_SEQ
//
//*****************************************************************************
// Field: [31:24] EH
//
// Erase hold time in half-microseconds after SAFELV goes low. Value will be
// converted to number of FCLK cycles by the flash device driver and the
// converted value is written to FLASH:FSM_ERA_OH.ERA_OH when an erase/program
// operation is initiated.
#define FCFG1_FLASH_EH_SEQ_EH_M                                     0xFF000000
#define FCFG1_FLASH_EH_SEQ_EH_S                                             24

// Field: [23:16] SEQ
//
// Pump sequence control.
#define FCFG1_FLASH_EH_SEQ_SEQ_M                                    0x00FF0000
#define FCFG1_FLASH_EH_SEQ_SEQ_S                                            16

// Field: [15:12] VSTAT
//
// Max number of HCLK cycles allowed for pump brown-out. Value will be written
// to FLASH:FSM_VSTAT.VSTAT_CNT when an erase/program operation is initiated.
#define FCFG1_FLASH_EH_SEQ_VSTAT_M                                  0x0000F000
#define FCFG1_FLASH_EH_SEQ_VSTAT_S                                          12

// Field:  [11:0] SM_FREQUENCY
//
// Max FCLK frequency allowed for program, erase, and verify reads.
#define FCFG1_FLASH_EH_SEQ_SM_FREQUENCY_M                           0x00000FFF
#define FCFG1_FLASH_EH_SEQ_SM_FREQUENCY_S                                    0

//*****************************************************************************
//
// Register: FCFG1_O_FLASH_VHV_E
//
//*****************************************************************************
// Field: [31:16] VHV_E_START
//
// Starting VHV-Erase CT for stairstep erase. Value will be written to
// FLASH:FSM_PRG_PUL.BEG_EC_LEVEL when an erase/program operation is initiated.
#define FCFG1_FLASH_VHV_E_VHV_E_START_M                             0xFFFF0000
#define FCFG1_FLASH_VHV_E_VHV_E_START_S                                     16

// Field:  [15:0] VHV_E_STEP_HIGHT
//
// Number of VHV CTs to step after each erase pulse (up to the max). The actual
// FMC register value should be one less than this since the FMC starts
// counting from zero. Value will be written to
// FLASH:FSM_EC_STEP_HEIGHT.EC_STEP_HEIGHT when an erase/program operation is
// initiated.
#define FCFG1_FLASH_VHV_E_VHV_E_STEP_HIGHT_M                        0x0000FFFF
#define FCFG1_FLASH_VHV_E_VHV_E_STEP_HIGHT_S                                 0

//*****************************************************************************
//
// Register: FCFG1_O_FLASH_PP
//
//*****************************************************************************
// Field: [31:24] PUMP_SU
//
// Pump read->non-read mode transition time in half-microseconds (mainly for
// FPES).
#define FCFG1_FLASH_PP_PUMP_SU_M                                    0xFF000000
#define FCFG1_FLASH_PP_PUMP_SU_S                                            24

// Field:  [15:0] MAX_PP
//
// Max program pulse limit per program operation. Value will be written to
// FLASH:FSM_PRG_PUL.MAX_PRG_PUL when an erase/program operation is initiated.
#define FCFG1_FLASH_PP_MAX_PP_M                                     0x0000FFFF
#define FCFG1_FLASH_PP_MAX_PP_S                                              0

//*****************************************************************************
//
// Register: FCFG1_O_FLASH_PROG_EP
//
//*****************************************************************************
// Field: [31:16] MAX_EP
//
// Max erase pulse limit per erase operation. Value will be written to
// FLASH:FSM_ERA_PUL.MAX_ERA_PUL when an erase/program operation is initiated.
#define FCFG1_FLASH_PROG_EP_MAX_EP_M                                0xFFFF0000
#define FCFG1_FLASH_PROG_EP_MAX_EP_S                                        16

// Field:  [15:0] PROGRAM_PW
//
// Program pulse width in half-microseconds. Value will be converted to number
// of FCLK cycles by the flash device driver and the converted value is written
// to FLASH:FSM_PRG_PW.PROG_PUL_WIDTH when a erase/program operation is
// initiated.
#define FCFG1_FLASH_PROG_EP_PROGRAM_PW_M                            0x0000FFFF
#define FCFG1_FLASH_PROG_EP_PROGRAM_PW_S                                     0

//*****************************************************************************
//
// Register: FCFG1_O_FLASH_ERA_PW
//
//*****************************************************************************
// Field:  [31:0] ERASE_PW
//
// Erase pulse width in half-microseconds. Value will be converted to number of
// FCLK cycles by the flash device driver and the converted value is written to
// FLASH:FSM_ERA_PW.FSM_ERA_PW when a erase/program operation is initiated.
#define FCFG1_FLASH_ERA_PW_ERASE_PW_M                               0xFFFFFFFF
#define FCFG1_FLASH_ERA_PW_ERASE_PW_S                                        0

//*****************************************************************************
//
// Register: FCFG1_O_FLASH_VHV
//
//*****************************************************************************
// Field: [27:24] TRIM13_P
//
// Value will be written to FLASH:FVHVCT2.TRIM13_P by the flash device driver
// when an erase/program operation is initiated.
#define FCFG1_FLASH_VHV_TRIM13_P_M                                  0x0F000000
#define FCFG1_FLASH_VHV_TRIM13_P_S                                          24

// Field: [19:16] VHV_P
//
// Value will be written to FLASH:FVHVCT2.VHVCT_P by the flash device driver
// when an erase/program operation is initiated.
#define FCFG1_FLASH_VHV_VHV_P_M                                     0x000F0000
#define FCFG1_FLASH_VHV_VHV_P_S                                             16

// Field:  [11:8] TRIM13_E
//
// Value will be written to FLASH:FVHVCT1.TRIM13_E by the flash device driver
// when an erase/program operation is initiated.
#define FCFG1_FLASH_VHV_TRIM13_E_M                                  0x00000F00
#define FCFG1_FLASH_VHV_TRIM13_E_S                                           8

// Field:   [3:0] VHV_E
//
// Value will be written to FLASH:FVHVCT1.VHVCT_E by the flash device driver
// when an erase/program operation is initiated
#define FCFG1_FLASH_VHV_VHV_E_M                                     0x0000000F
#define FCFG1_FLASH_VHV_VHV_E_S                                              0

//*****************************************************************************
//
// Register: FCFG1_O_FLASH_VHV_PV
//
//*****************************************************************************
// Field: [27:24] TRIM13_PV
//
// Value will be written to FLASH:FVHVCT1.TRIM13_PV by the flash device driver
// when an erase/program operation is initiated.
#define FCFG1_FLASH_VHV_PV_TRIM13_PV_M                              0x0F000000
#define FCFG1_FLASH_VHV_PV_TRIM13_PV_S                                      24

// Field: [19:16] VHV_PV
//
// Value will be written to FLASH:FVHVCT1.VHVCT_PV by the flash device driver
// when an erase/program operation is initiated.
#define FCFG1_FLASH_VHV_PV_VHV_PV_M                                 0x000F0000
#define FCFG1_FLASH_VHV_PV_VHV_PV_S                                         16

// Field:  [15:8] VCG2P5
//
// Control gate voltage during read, read margin, and erase verify. Value will
// be written to FLASH:FVNVCT.VCG2P5CT by the flash device driver when an
// erase/program operation is initiated.
#define FCFG1_FLASH_VHV_PV_VCG2P5_M                                 0x0000FF00
#define FCFG1_FLASH_VHV_PV_VCG2P5_S                                          8

// Field:   [7:0] VINH
//
// Inhibit voltage applied to unselected columns during programming.
#define FCFG1_FLASH_VHV_PV_VINH_M                                   0x000000FF
#define FCFG1_FLASH_VHV_PV_VINH_S                                            0

//*****************************************************************************
//
// Register: FCFG1_O_FLASH_V
//
//*****************************************************************************
// Field: [31:24] VSL_P
//
// Sourceline voltage applied to the selected block during programming. Value
// will be written to FLASH:FVSLP.VSL_P by the flash device driver when an
// erase/program operation is initiated.
#define FCFG1_FLASH_V_VSL_P_M                                       0xFF000000
#define FCFG1_FLASH_V_VSL_P_S                                               24

// Field: [23:16] VWL_P
//
// Wordline voltage applied to the selected half-row during programming. Value
// will be written to  FLASH:FVWLCT.VWLCT_P by the flash device driver when an
// erase/program operation is initiated.
#define FCFG1_FLASH_V_VWL_P_M                                       0x00FF0000
#define FCFG1_FLASH_V_VWL_P_S                                               16

// Field:  [15:8] V_READ
//
// Wordline voltage applied to the selected block during reads and verifies.
// Value will be written to FLASH:FVREADCT.VREADCT by the flash device driver
// when an erase/program operation is initiated.
#define FCFG1_FLASH_V_V_READ_M                                      0x0000FF00
#define FCFG1_FLASH_V_V_READ_S                                               8

//*****************************************************************************
//
// Register: FCFG1_O_USER_ID
//
//*****************************************************************************
// Field: [31:28] PG_REV
//
// Field used to distinguish revisions of the device.
#define FCFG1_USER_ID_PG_REV_M                                      0xF0000000
#define FCFG1_USER_ID_PG_REV_S                                              28

// Field: [27:26] VER
//
// Version number.
//
// 0x0: Bits [25:12] of this register has the stated meaning.
//
// Any other setting indicate a different encoding of these bits.
#define FCFG1_USER_ID_VER_M                                         0x0C000000
#define FCFG1_USER_ID_VER_S                                                 26

// Field: [22:19] SEQUENCE
//
// Sequence.
//
// Used to differentiate between marketing/orderable product where other fields
// of USER_ID is the same (temp range, flash size, voltage range etc)
#define FCFG1_USER_ID_SEQUENCE_M                                    0x00780000
#define FCFG1_USER_ID_SEQUENCE_S                                            19

// Field: [18:16] PKG
//
// Package type.
//
// 0x0: 4x4mm
// 0x1: 5x5mm
// 0x2: 7x7mm
//
// Others values are reserved for future use.
#define FCFG1_USER_ID_PKG_M                                         0x00070000
#define FCFG1_USER_ID_PKG_S                                                 16

// Field: [15:12] PROTOCOL
//
// Protocols supported.
//
// 0x1: BLE
// 0x2: RF4CE
// 0x4: Zigbee/6lowpan
// 0x8: Proprietary
//
// More than one protocol can be supported on same device - values above are
// then combined.
#define FCFG1_USER_ID_PROTOCOL_M                                    0x0000F000
#define FCFG1_USER_ID_PROTOCOL_S                                            12

//*****************************************************************************
//
// Register: FCFG1_O_FLASH_OTP_DATA3
//
//*****************************************************************************
// Field: [31:23] EC_STEP_SIZE
//
// Value will be written to FLASH:FSM_STEP_SIZE.EC_STEP_SIZE by the flash
// device driver when a erase/program operation is initiated.
#define FCFG1_FLASH_OTP_DATA3_EC_STEP_SIZE_M                        0xFF800000
#define FCFG1_FLASH_OTP_DATA3_EC_STEP_SIZE_S                                23

// Field:    [22] DO_PRECOND
//
// Value will be written to FLASH:FSM_ST_MACHINE.DO_PRECOND by the flash device
// driver when a erase/program operation is initiated.
//
// Note that during a Total Erase operation the flash bank will always be
// erased with Precondition enabled independent of the value of this FCFG1 bit
// field.
#define FCFG1_FLASH_OTP_DATA3_DO_PRECOND                            0x00400000
#define FCFG1_FLASH_OTP_DATA3_DO_PRECOND_BITN                               22
#define FCFG1_FLASH_OTP_DATA3_DO_PRECOND_M                          0x00400000
#define FCFG1_FLASH_OTP_DATA3_DO_PRECOND_S                                  22

// Field: [21:18] MAX_EC_LEVEL
//
// Value will be written to FLASH:FSM_ERA_PUL.MAX_EC_LEVEL by the flash device
// driver when a erase/program operation is initiated.
#define FCFG1_FLASH_OTP_DATA3_MAX_EC_LEVEL_M                        0x003C0000
#define FCFG1_FLASH_OTP_DATA3_MAX_EC_LEVEL_S                                18

// Field: [17:16] TRIM_1P7
//
// Value will be written to FLASH:FSEQPMP.TRIM_1P7 by the flash device driver
// when a erase/program operation is initiated.
#define FCFG1_FLASH_OTP_DATA3_TRIM_1P7_M                            0x00030000
#define FCFG1_FLASH_OTP_DATA3_TRIM_1P7_S                                    16

// Field:  [15:8] FLASH_SIZE
//
// Value will be written to FLASH:FLASH_SIZE.SECTORS by the boot FW while in
// safe zone.
//
// This register will be write protected by the boot FW by setting
// FLASH:CFG.CONFIGURED.
#define FCFG1_FLASH_OTP_DATA3_FLASH_SIZE_M                          0x0000FF00
#define FCFG1_FLASH_OTP_DATA3_FLASH_SIZE_S                                   8

// Field:   [7:0] WAIT_SYSCODE
//
// Value will be written to FLASH:WAIT_SYSCODE.WAIT_SYSCODE by boot FW code
// while in safezone.
#define FCFG1_FLASH_OTP_DATA3_WAIT_SYSCODE_M                        0x000000FF
#define FCFG1_FLASH_OTP_DATA3_WAIT_SYSCODE_S                                 0

//*****************************************************************************
//
// Register: FCFG1_O_ANA2_TRIM
//
//*****************************************************************************
// Field:    [31] RCOSCHFCTRIMFRACT_EN
//
// Value will be written to  DDI_0_OSC:CTL1.RCOSCHFCTRIMFRACT_EN by boot FW
// while in safezone.
#define FCFG1_ANA2_TRIM_RCOSCHFCTRIMFRACT_EN                        0x80000000
#define FCFG1_ANA2_TRIM_RCOSCHFCTRIMFRACT_EN_BITN                           31
#define FCFG1_ANA2_TRIM_RCOSCHFCTRIMFRACT_EN_M                      0x80000000
#define FCFG1_ANA2_TRIM_RCOSCHFCTRIMFRACT_EN_S                              31

// Field: [30:26] RCOSCHFCTRIMFRACT
//
// Value will be written to DDI_0_OSC:CTL1.RCOSCHFCTRIMFRACT by boot FW while
// in safezone.
#define FCFG1_ANA2_TRIM_RCOSCHFCTRIMFRACT_M                         0x7C000000
#define FCFG1_ANA2_TRIM_RCOSCHFCTRIMFRACT_S                                 26

// Field: [24:23] SET_RCOSC_HF_FINE_RESISTOR
//
// Value will be written to DDI_0_OSC:ATESTCTL.SET_RCOSC_HF_FINE_RESISTOR by
// boot FW while in safezone.
#define FCFG1_ANA2_TRIM_SET_RCOSC_HF_FINE_RESISTOR_M                0x01800000
#define FCFG1_ANA2_TRIM_SET_RCOSC_HF_FINE_RESISTOR_S                        23

// Field:    [22] ATESTLF_UDIGLDO_IBIAS_TRIM
//
// Value will be written DDI_0_OSC:ATESTCTL.ATESTLF_UDIGLDO_IBIAS_TRIM by boot
// FW while in safezone.
#define FCFG1_ANA2_TRIM_ATESTLF_UDIGLDO_IBIAS_TRIM                  0x00400000
#define FCFG1_ANA2_TRIM_ATESTLF_UDIGLDO_IBIAS_TRIM_BITN                     22
#define FCFG1_ANA2_TRIM_ATESTLF_UDIGLDO_IBIAS_TRIM_M                0x00400000
#define FCFG1_ANA2_TRIM_ATESTLF_UDIGLDO_IBIAS_TRIM_S                        22

// Field: [21:16] NANOAMP_RES_TRIM
//
// Value will be written to DDI_0_OSC:ADCDOUBLERNANOAMPCTL.NANOAMP_RES_TRIM by
// boot FW while in safezone.
#define FCFG1_ANA2_TRIM_NANOAMP_RES_TRIM_M                          0x003F0000
#define FCFG1_ANA2_TRIM_NANOAMP_RES_TRIM_S                                  16

// Field:    [11] DITHER_EN
//
// Value will be written to ADI_3_REFSYS:DCDCCTL5.DITHER_EN by boot FW while in
// safezone.
#define FCFG1_ANA2_TRIM_DITHER_EN                                   0x00000800
#define FCFG1_ANA2_TRIM_DITHER_EN_BITN                                      11
#define FCFG1_ANA2_TRIM_DITHER_EN_M                                 0x00000800
#define FCFG1_ANA2_TRIM_DITHER_EN_S                                         11

// Field:  [10:8] DCDC_IPEAK
//
// Value will be written to ADI_3_REFSYS:DCDCCTL5.IPEAK by boot FW while in
// safezone.
#define FCFG1_ANA2_TRIM_DCDC_IPEAK_M                                0x00000700
#define FCFG1_ANA2_TRIM_DCDC_IPEAK_S                                         8

// Field:   [7:6] DEAD_TIME_TRIM
//
// Value will be written to ADI_3_REFSYS:DCDCCTL4.DEADTIME_TRIM by boot FW
// while in safezone.
#define FCFG1_ANA2_TRIM_DEAD_TIME_TRIM_M                            0x000000C0
#define FCFG1_ANA2_TRIM_DEAD_TIME_TRIM_S                                     6

// Field:   [5:3] DCDC_LOW_EN_SEL
//
// Value will be written to  ADI_3_REFSYS:DCDCCTL4.LOW_EN_SEL by boot FW while
// in safezone.
#define FCFG1_ANA2_TRIM_DCDC_LOW_EN_SEL_M                           0x00000038
#define FCFG1_ANA2_TRIM_DCDC_LOW_EN_SEL_S                                    3

// Field:   [2:0] DCDC_HIGH_EN_SEL
//
// Value will be written to  ADI_3_REFSYS:DCDCCTL4.HIGH_EN_SEL by boot FW while
// in safezone.
#define FCFG1_ANA2_TRIM_DCDC_HIGH_EN_SEL_M                          0x00000007
#define FCFG1_ANA2_TRIM_DCDC_HIGH_EN_SEL_S                                   0

//*****************************************************************************
//
// Register: FCFG1_O_LDO_TRIM
//
//*****************************************************************************
// Field: [28:24] VDDR_TRIM_SLEEP
//
// Value will be written to ADI_3_REFSYS:DCDCCTL1.VDDR_TRIM_SLEEP by boot FW
// while in safezone.
#define FCFG1_LDO_TRIM_VDDR_TRIM_SLEEP_M                            0x1F000000
#define FCFG1_LDO_TRIM_VDDR_TRIM_SLEEP_S                                    24

// Field: [18:16] GLDO_CURSRC
//
// Value will be written to ADI_3_REFSYS:DCDCCTL0.GLDO_ISRC by boot FW while in
// safezone.
#define FCFG1_LDO_TRIM_GLDO_CURSRC_M                                0x00070000
#define FCFG1_LDO_TRIM_GLDO_CURSRC_S                                        16

// Field: [12:11] ITRIM_DIGLDO_LOAD
//
// Value will be written to ADI_2_REFSYS:SOCLDOCTL3.ITRIM_DIGLDO_LOAD by boot
// FW while in safezone.
#define FCFG1_LDO_TRIM_ITRIM_DIGLDO_LOAD_M                          0x00001800
#define FCFG1_LDO_TRIM_ITRIM_DIGLDO_LOAD_S                                  11

// Field:  [10:8] ITRIM_UDIGLDO
//
// Value will be written to ADI_2_REFSYS:SOCLDOCTL3.ITRIM_UDIGLDO by boot FW
// while in safezone.
#define FCFG1_LDO_TRIM_ITRIM_UDIGLDO_M                              0x00000700
#define FCFG1_LDO_TRIM_ITRIM_UDIGLDO_S                                       8

// Field:   [2:0] VTRIM_DELTA
//
// Value will be written to ADI_2_REFSYS:SOCLDOCTL2.VTRIM_DELTA by boot FW
// while in safezone.
#define FCFG1_LDO_TRIM_VTRIM_DELTA_M                                0x00000007
#define FCFG1_LDO_TRIM_VTRIM_DELTA_S                                         0

//*****************************************************************************
//
// Register: FCFG1_O_MAC_BLE_0
//
//*****************************************************************************
// Field:  [31:0] ADDR_0_31
//
// The first 32-bits of the 64-bit MAC BLE address
#define FCFG1_MAC_BLE_0_ADDR_0_31_M                                 0xFFFFFFFF
#define FCFG1_MAC_BLE_0_ADDR_0_31_S                                          0

//*****************************************************************************
//
// Register: FCFG1_O_MAC_BLE_1
//
//*****************************************************************************
// Field:  [31:0] ADDR_32_63
//
// The last 32-bits of the 64-bit MAC BLE address
#define FCFG1_MAC_BLE_1_ADDR_32_63_M                                0xFFFFFFFF
#define FCFG1_MAC_BLE_1_ADDR_32_63_S                                         0

//*****************************************************************************
//
// Register: FCFG1_O_MAC_15_4_0
//
//*****************************************************************************
// Field:  [31:0] ADDR_0_31
//
// The first 32-bits of the 64-bit MAC 15.4 address
#define FCFG1_MAC_15_4_0_ADDR_0_31_M                                0xFFFFFFFF
#define FCFG1_MAC_15_4_0_ADDR_0_31_S                                         0

//*****************************************************************************
//
// Register: FCFG1_O_MAC_15_4_1
//
//*****************************************************************************
// Field:  [31:0] ADDR_32_63
//
// The last 32-bits of the 64-bit MAC 15.4 address
#define FCFG1_MAC_15_4_1_ADDR_32_63_M                               0xFFFFFFFF
#define FCFG1_MAC_15_4_1_ADDR_32_63_S                                        0

//*****************************************************************************
//
// Register: FCFG1_O_FLASH_OTP_DATA4
//
//*****************************************************************************
// Field:    [31] STANDBY_MODE_SEL_INT_WRT
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 0, this value will be written to
// FLASH:CFG.STANDBY_MODE_SEL by flash device driver FW when a flash write
// operation is initiated.
#define FCFG1_FLASH_OTP_DATA4_STANDBY_MODE_SEL_INT_WRT              0x80000000
#define FCFG1_FLASH_OTP_DATA4_STANDBY_MODE_SEL_INT_WRT_BITN                 31
#define FCFG1_FLASH_OTP_DATA4_STANDBY_MODE_SEL_INT_WRT_M            0x80000000
#define FCFG1_FLASH_OTP_DATA4_STANDBY_MODE_SEL_INT_WRT_S                    31

// Field: [30:29] STANDBY_PW_SEL_INT_WRT
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 0, this value will be written to
// FLASH:CFG.STANDBY_PW_SEL by flash device driver FW when a flash write
// operation is initiated.
#define FCFG1_FLASH_OTP_DATA4_STANDBY_PW_SEL_INT_WRT_M              0x60000000
#define FCFG1_FLASH_OTP_DATA4_STANDBY_PW_SEL_INT_WRT_S                      29

// Field:    [28] DIS_STANDBY_INT_WRT
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 0, this value will be written to
// FLASH:CFG.DIS_STANDBY by flash device driver FW when a flash write operation
// is initiated.
#define FCFG1_FLASH_OTP_DATA4_DIS_STANDBY_INT_WRT                   0x10000000
#define FCFG1_FLASH_OTP_DATA4_DIS_STANDBY_INT_WRT_BITN                      28
#define FCFG1_FLASH_OTP_DATA4_DIS_STANDBY_INT_WRT_M                 0x10000000
#define FCFG1_FLASH_OTP_DATA4_DIS_STANDBY_INT_WRT_S                         28

// Field:    [27] DIS_IDLE_INT_WRT
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 0, this value will be written to
// FLASH:CFG.DIS_IDLE by flash device driver FW when a flash write operation is
// initiated.
#define FCFG1_FLASH_OTP_DATA4_DIS_IDLE_INT_WRT                      0x08000000
#define FCFG1_FLASH_OTP_DATA4_DIS_IDLE_INT_WRT_BITN                         27
#define FCFG1_FLASH_OTP_DATA4_DIS_IDLE_INT_WRT_M                    0x08000000
#define FCFG1_FLASH_OTP_DATA4_DIS_IDLE_INT_WRT_S                            27

// Field: [26:24] VIN_AT_X_INT_WRT
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 0, this value will be written to
// FLASH:FSEQPMP.VIN_AT_X by flash device driver FW when a flash write
// operation is initiated.
#define FCFG1_FLASH_OTP_DATA4_VIN_AT_X_INT_WRT_M                    0x07000000
#define FCFG1_FLASH_OTP_DATA4_VIN_AT_X_INT_WRT_S                            24

// Field:    [23] STANDBY_MODE_SEL_EXT_WRT
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 1, this value will be written to
// FLASH:CFG.STANDBY_MODE_SEL by flash device driver FW when a flash write
// operation is initiated.
#define FCFG1_FLASH_OTP_DATA4_STANDBY_MODE_SEL_EXT_WRT              0x00800000
#define FCFG1_FLASH_OTP_DATA4_STANDBY_MODE_SEL_EXT_WRT_BITN                 23
#define FCFG1_FLASH_OTP_DATA4_STANDBY_MODE_SEL_EXT_WRT_M            0x00800000
#define FCFG1_FLASH_OTP_DATA4_STANDBY_MODE_SEL_EXT_WRT_S                    23

// Field: [22:21] STANDBY_PW_SEL_EXT_WRT
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 1, this value will be written to
// FLASH:CFG.STANDBY_PW_SEL by flash device driver FW when a flash write
// operation is initiated.
#define FCFG1_FLASH_OTP_DATA4_STANDBY_PW_SEL_EXT_WRT_M              0x00600000
#define FCFG1_FLASH_OTP_DATA4_STANDBY_PW_SEL_EXT_WRT_S                      21

// Field:    [20] DIS_STANDBY_EXT_WRT
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 1, this value will be written to
// FLASH:CFG.DIS_STANDBY by flash device driver FW when a flash write operation
// is initiated.
#define FCFG1_FLASH_OTP_DATA4_DIS_STANDBY_EXT_WRT                   0x00100000
#define FCFG1_FLASH_OTP_DATA4_DIS_STANDBY_EXT_WRT_BITN                      20
#define FCFG1_FLASH_OTP_DATA4_DIS_STANDBY_EXT_WRT_M                 0x00100000
#define FCFG1_FLASH_OTP_DATA4_DIS_STANDBY_EXT_WRT_S                         20

// Field:    [19] DIS_IDLE_EXT_WRT
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 1, this value will be written to
// FLASH:CFG.DIS_IDLE by flash device driver FW when a flash write operation is
// initiated.
#define FCFG1_FLASH_OTP_DATA4_DIS_IDLE_EXT_WRT                      0x00080000
#define FCFG1_FLASH_OTP_DATA4_DIS_IDLE_EXT_WRT_BITN                         19
#define FCFG1_FLASH_OTP_DATA4_DIS_IDLE_EXT_WRT_M                    0x00080000
#define FCFG1_FLASH_OTP_DATA4_DIS_IDLE_EXT_WRT_S                            19

// Field: [18:16] VIN_AT_X_EXT_WRT
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 1, this value will be written to
// FLASH:FSEQPMP.VIN_AT_X by flash device driver FW when a flash write
// operation is initiated.
#define FCFG1_FLASH_OTP_DATA4_VIN_AT_X_EXT_WRT_M                    0x00070000
#define FCFG1_FLASH_OTP_DATA4_VIN_AT_X_EXT_WRT_S                            16

// Field:    [15] STANDBY_MODE_SEL_INT_RD
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 0, this value will be written to
// FLASH:CFG.STANDBY_MODE_SEL both by boot FW while in safezone, and by flash
// device driver FW after completion of a flash write operation.
#define FCFG1_FLASH_OTP_DATA4_STANDBY_MODE_SEL_INT_RD               0x00008000
#define FCFG1_FLASH_OTP_DATA4_STANDBY_MODE_SEL_INT_RD_BITN                  15
#define FCFG1_FLASH_OTP_DATA4_STANDBY_MODE_SEL_INT_RD_M             0x00008000
#define FCFG1_FLASH_OTP_DATA4_STANDBY_MODE_SEL_INT_RD_S                     15

// Field: [14:13] STANDBY_PW_SEL_INT_RD
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 0, this value will be written to
// FLASH:CFG.STANDBY_PW_SEL both by boot FW while in safezone, and by flash
// device driver FW after completion of a flash write operation.
#define FCFG1_FLASH_OTP_DATA4_STANDBY_PW_SEL_INT_RD_M               0x00006000
#define FCFG1_FLASH_OTP_DATA4_STANDBY_PW_SEL_INT_RD_S                       13

// Field:    [12] DIS_STANDBY_INT_RD
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 0, this value will be written to
// FLASH:CFG.DIS_STANDBY both by boot FW while in safezone, and by flash device
// driver FW after completion of a flash write operation.
#define FCFG1_FLASH_OTP_DATA4_DIS_STANDBY_INT_RD                    0x00001000
#define FCFG1_FLASH_OTP_DATA4_DIS_STANDBY_INT_RD_BITN                       12
#define FCFG1_FLASH_OTP_DATA4_DIS_STANDBY_INT_RD_M                  0x00001000
#define FCFG1_FLASH_OTP_DATA4_DIS_STANDBY_INT_RD_S                          12

// Field:    [11] DIS_IDLE_INT_RD
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 0, this value will be written to
// FLASH:CFG.DIS_IDLE both by boot FW while in safezone, and by flash device
// driver FW after completion of a flash write operation.
#define FCFG1_FLASH_OTP_DATA4_DIS_IDLE_INT_RD                       0x00000800
#define FCFG1_FLASH_OTP_DATA4_DIS_IDLE_INT_RD_BITN                          11
#define FCFG1_FLASH_OTP_DATA4_DIS_IDLE_INT_RD_M                     0x00000800
#define FCFG1_FLASH_OTP_DATA4_DIS_IDLE_INT_RD_S                             11

// Field:  [10:8] VIN_AT_X_INT_RD
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 0, this value will be written to
// FLASH:FSEQPMP.VIN_AT_X both by boot FW while in safezone, and by flash
// device driver FW after completion of a flash write operation.
#define FCFG1_FLASH_OTP_DATA4_VIN_AT_X_INT_RD_M                     0x00000700
#define FCFG1_FLASH_OTP_DATA4_VIN_AT_X_INT_RD_S                              8

// Field:     [7] STANDBY_MODE_SEL_EXT_RD
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 1, this value will be written to
// FLASH:CFG.STANDBY_MODE_SEL both by boot FW while in safezone, and by flash
// device driver FW after completion of a flash write operation.
#define FCFG1_FLASH_OTP_DATA4_STANDBY_MODE_SEL_EXT_RD               0x00000080
#define FCFG1_FLASH_OTP_DATA4_STANDBY_MODE_SEL_EXT_RD_BITN                   7
#define FCFG1_FLASH_OTP_DATA4_STANDBY_MODE_SEL_EXT_RD_M             0x00000080
#define FCFG1_FLASH_OTP_DATA4_STANDBY_MODE_SEL_EXT_RD_S                      7

// Field:   [6:5] STANDBY_PW_SEL_EXT_RD
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 1, this value will be written to
// FLASH:CFG.STANDBY_PW_SEL both by boot FW while in safezone, and by flash
// device driver FW after completion of a flash write operation.
#define FCFG1_FLASH_OTP_DATA4_STANDBY_PW_SEL_EXT_RD_M               0x00000060
#define FCFG1_FLASH_OTP_DATA4_STANDBY_PW_SEL_EXT_RD_S                        5

// Field:     [4] DIS_STANDBY_EXT_RD
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 1, this value will be written to
// FLASH:CFG.DIS_STANDBY both by boot FW while in safezone, and by flash device
// driver FW after completion of a flash write operation.
#define FCFG1_FLASH_OTP_DATA4_DIS_STANDBY_EXT_RD                    0x00000010
#define FCFG1_FLASH_OTP_DATA4_DIS_STANDBY_EXT_RD_BITN                        4
#define FCFG1_FLASH_OTP_DATA4_DIS_STANDBY_EXT_RD_M                  0x00000010
#define FCFG1_FLASH_OTP_DATA4_DIS_STANDBY_EXT_RD_S                           4

// Field:     [3] DIS_IDLE_EXT_RD
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 1, this value will be written to
// FLASH:CFG.DIS_IDLE both by boot FW while in safezone, and by flash device
// driver FW after completion of a flash write operation.
#define FCFG1_FLASH_OTP_DATA4_DIS_IDLE_EXT_RD                       0x00000008
#define FCFG1_FLASH_OTP_DATA4_DIS_IDLE_EXT_RD_BITN                           3
#define FCFG1_FLASH_OTP_DATA4_DIS_IDLE_EXT_RD_M                     0x00000008
#define FCFG1_FLASH_OTP_DATA4_DIS_IDLE_EXT_RD_S                              3

// Field:   [2:0] VIN_AT_X_EXT_RD
//
// If AON_SYSCTL:PWRCTL.EXT_REG_MODE = 1, this value will be written to
// FLASH:FSEQPMP.VIN_AT_X both by boot FW while in safezone, and by flash
// device driver FW after completion of a flash write operation.
#define FCFG1_FLASH_OTP_DATA4_VIN_AT_X_EXT_RD_M                     0x00000007
#define FCFG1_FLASH_OTP_DATA4_VIN_AT_X_EXT_RD_S                              0

//*****************************************************************************
//
// Register: FCFG1_O_MISC_TRIM
//
//*****************************************************************************
// Field:   [7:0] TEMPVSLOPE
//
// Signed byte value representing the TEMP slope with battery voltage, in
// degrees C / V, with four fractional bits.
#define FCFG1_MISC_TRIM_TEMPVSLOPE_M                                0x000000FF
#define FCFG1_MISC_TRIM_TEMPVSLOPE_S                                         0

//*****************************************************************************
//
// Register: FCFG1_O_RCOSC_HF_TEMPCOMP
//
//*****************************************************************************
// Field: [31:24] FINE_RESISTOR
//
// Change in FINE_RESISTOR trim
#define FCFG1_RCOSC_HF_TEMPCOMP_FINE_RESISTOR_M                     0xFF000000
#define FCFG1_RCOSC_HF_TEMPCOMP_FINE_RESISTOR_S                             24

// Field: [23:16] CTRIM
//
// Change in CTRIM trim
#define FCFG1_RCOSC_HF_TEMPCOMP_CTRIM_M                             0x00FF0000
#define FCFG1_RCOSC_HF_TEMPCOMP_CTRIM_S                                     16

// Field:  [15:8] CTRIMFRACT_QUAD
//
// Temp compensation quadratic CTRIMFRACT
#define FCFG1_RCOSC_HF_TEMPCOMP_CTRIMFRACT_QUAD_M                   0x0000FF00
#define FCFG1_RCOSC_HF_TEMPCOMP_CTRIMFRACT_QUAD_S                            8

// Field:   [7:0] CTRIMFRACT_SLOPE
//
// Number of CTRIMFRACT codes per 20 degrees C from default temperature
#define FCFG1_RCOSC_HF_TEMPCOMP_CTRIMFRACT_SLOPE_M                  0x000000FF
#define FCFG1_RCOSC_HF_TEMPCOMP_CTRIMFRACT_SLOPE_S                           0

//*****************************************************************************
//
// Register: FCFG1_O_ICEPICK_DEVICE_ID
//
//*****************************************************************************
// Field: [31:28] PG_REV
//
// Field used to distinguish revisions of the device.
#define FCFG1_ICEPICK_DEVICE_ID_PG_REV_M                            0xF0000000
#define FCFG1_ICEPICK_DEVICE_ID_PG_REV_S                                    28

// Field: [27:12] WAFER_ID
//
// Field used to identify silicon die.
#define FCFG1_ICEPICK_DEVICE_ID_WAFER_ID_M                          0x0FFFF000
#define FCFG1_ICEPICK_DEVICE_ID_WAFER_ID_S                                  12

// Field:  [11:0] MANUFACTURER_ID
//
// Manufacturer code.
//
// 0x02F: Texas Instruments
#define FCFG1_ICEPICK_DEVICE_ID_MANUFACTURER_ID_M                   0x00000FFF
#define FCFG1_ICEPICK_DEVICE_ID_MANUFACTURER_ID_S                            0

//*****************************************************************************
//
// Register: FCFG1_O_FCFG1_REVISION
//
//*****************************************************************************
// Field:  [31:0] REV
//
// The revision number of the FCFG1 layout. This value will be read by
// application SW in order to determine which FCFG1 parameters that have valid
// values. This revision number must be incremented by 1 before any devices are
// to be produced if the FCFG1 layout has changed since the previous production
// of devices.
// Value migth change without warning.
#define FCFG1_FCFG1_REVISION_REV_M                                  0xFFFFFFFF
#define FCFG1_FCFG1_REVISION_REV_S                                           0

//*****************************************************************************
//
// Register: FCFG1_O_MISC_OTP_DATA
//
//*****************************************************************************
// Field: [31:28] RCOSC_HF_ITUNE
//
// Trim value that migth become into use for cc26xx PG2.2 and cc13xx PG2.0.
// Trim value for DDI_0_OSC:RCOSCHFCTL.RCOSCHF_ITUNE_TRIM.
#define FCFG1_MISC_OTP_DATA_RCOSC_HF_ITUNE_M                        0xF0000000
#define FCFG1_MISC_OTP_DATA_RCOSC_HF_ITUNE_S                                28

// Field: [27:20] RCOSC_HF_CRIM
//
// Trim value that migth become into use for cc26xx PG2.2 and cc13xx PG2.0.
// Trim value for DDI_0_OSC:RCOSCHFCTL.RCOSCHF_CTRIM.
#define FCFG1_MISC_OTP_DATA_RCOSC_HF_CRIM_M                         0x0FF00000
#define FCFG1_MISC_OTP_DATA_RCOSC_HF_CRIM_S                                 20

// Field: [19:15] PER_M
//
// Trim value for AON_WUC:OSCCFG.PER_M.
#define FCFG1_MISC_OTP_DATA_PER_M_M                                 0x000F8000
#define FCFG1_MISC_OTP_DATA_PER_M_S                                         15

// Field: [14:12] PER_E
//
// Trim value for AON_WUC:OSCCFG.PER_E.
#define FCFG1_MISC_OTP_DATA_PER_E_M                                 0x00007000
#define FCFG1_MISC_OTP_DATA_PER_E_S                                         12

// Field:  [11:8] PO_TAIL_RES_TRIM
//
// Trim value for DLO_DTX:PLLCTL1.PO_TAIL_RES_TRIM.
#define FCFG1_MISC_OTP_DATA_PO_TAIL_RES_TRIM_M                      0x00000F00
#define FCFG1_MISC_OTP_DATA_PO_TAIL_RES_TRIM_S                               8

// Field:   [7:0] TEST_PROGRAM_REV
//
// The revision of the test program used in the production process when FCFG1
// was programmed.
// Value migth change without warning.
#define FCFG1_MISC_OTP_DATA_TEST_PROGRAM_REV_M                      0x000000FF
#define FCFG1_MISC_OTP_DATA_TEST_PROGRAM_REV_S                               0

//*****************************************************************************
//
// Register: FCFG1_O_IOCONF
//
//*****************************************************************************
// Field:   [6:0] GPIO_CNT
//
// This value is written to IOC:CFG.GPIO_CNT by boot FW while in safezone.
#define FCFG1_IOCONF_GPIO_CNT_M                                     0x0000007F
#define FCFG1_IOCONF_GPIO_CNT_S                                              0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_IF_ADC
//
//*****************************************************************************
// Field: [31:28] FF2ADJ
//
// Trim value for ADI_0_RF:IFADCLFCFG1.FF2ADJ.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_IF_ADC_FF2ADJ_M                                0xF0000000
#define FCFG1_CONFIG_IF_ADC_FF2ADJ_S                                        28

// Field: [27:24] FF3ADJ
//
// Trim value for ADI_0_RF:IFADCLFCFG1.FF3ADJ.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_IF_ADC_FF3ADJ_M                                0x0F000000
#define FCFG1_CONFIG_IF_ADC_FF3ADJ_S                                        24

// Field: [23:20] INT3ADJ
//
// Trim value for ADI_0_RF:IFADCLFCFG0.INT3ADJ.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_IF_ADC_INT3ADJ_M                               0x00F00000
#define FCFG1_CONFIG_IF_ADC_INT3ADJ_S                                       20

// Field: [19:16] FF1ADJ
//
// Trim value for ADI_0_RF:IFADCLFCFG0.FF1ADJ.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_IF_ADC_FF1ADJ_M                                0x000F0000
#define FCFG1_CONFIG_IF_ADC_FF1ADJ_S                                        16

// Field: [15:14] AAFCAP
//
// Trim value for ADI_0_RF:IFADCCTL0.AAFCAP.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_IF_ADC_AAFCAP_M                                0x0000C000
#define FCFG1_CONFIG_IF_ADC_AAFCAP_S                                        14

// Field: [13:10] INT2ADJ
//
// Trim value for ADI_0_RF:IFADCCTL0.INT2ADJ.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_IF_ADC_INT2ADJ_M                               0x00003C00
#define FCFG1_CONFIG_IF_ADC_INT2ADJ_S                                       10

// Field:   [9:5] IFDIGLDO_TRIM_OUTPUT
//
// Trim value for ADI_0_RF:IFDLDO2.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_IF_ADC_IFDIGLDO_TRIM_OUTPUT_M                  0x000003E0
#define FCFG1_CONFIG_IF_ADC_IFDIGLDO_TRIM_OUTPUT_S                           5

// Field:   [4:0] IFANALDO_TRIM_OUTPUT
//
// Trim value for ADI_0_RF:IFALDO2.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_IF_ADC_IFANALDO_TRIM_OUTPUT_M                  0x0000001F
#define FCFG1_CONFIG_IF_ADC_IFANALDO_TRIM_OUTPUT_S                           0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_OSC_TOP
//
//*****************************************************************************
// Field: [29:26] XOSC_HF_ROW_Q12
//
// Trim value for DDI_0_OSC:ANABYPASSVAL1.XOSC_HF_ROW_Q12.
#define FCFG1_CONFIG_OSC_TOP_XOSC_HF_ROW_Q12_M                      0x3C000000
#define FCFG1_CONFIG_OSC_TOP_XOSC_HF_ROW_Q12_S                              26

// Field: [25:10] XOSC_HF_COLUMN_Q12
//
// Trim value for DDI_0_OSC:ANABYPASSVAL1.XOSC_HF_COLUMN_Q12.
#define FCFG1_CONFIG_OSC_TOP_XOSC_HF_COLUMN_Q12_M                   0x03FFFC00
#define FCFG1_CONFIG_OSC_TOP_XOSC_HF_COLUMN_Q12_S                           10

// Field:   [9:2] RCOSCLF_CTUNE_TRIM
//
// Trim value for DDI_0_OSC:LFOSCCTL.RCOSCLF_CTUNE_TRIM.
#define FCFG1_CONFIG_OSC_TOP_RCOSCLF_CTUNE_TRIM_M                   0x000003FC
#define FCFG1_CONFIG_OSC_TOP_RCOSCLF_CTUNE_TRIM_S                            2

// Field:   [1:0] RCOSCLF_RTUNE_TRIM
//
// Trim value for DDI_0_OSC:LFOSCCTL.RCOSCLF_RTUNE_TRIM.
#define FCFG1_CONFIG_OSC_TOP_RCOSCLF_RTUNE_TRIM_M                   0x00000003
#define FCFG1_CONFIG_OSC_TOP_RCOSCLF_RTUNE_TRIM_S                            0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_RF_FRONTEND
//
//*****************************************************************************
// Field: [31:28] IFAMP_IB
//
// Trim value for ADI_0_RF:IFAMPCTL3.IB.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_IFAMP_IB_M                         0xF0000000
#define FCFG1_CONFIG_RF_FRONTEND_IFAMP_IB_S                                 28

// Field: [27:24] LNA_IB
//
// Trim value for ADI_0_RF:LNACTL2.IB.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_LNA_IB_M                           0x0F000000
#define FCFG1_CONFIG_RF_FRONTEND_LNA_IB_S                                   24

// Field: [23:19] IFAMP_TRIM
//
// Trim value for ADI_0_RF:IFAMPCTL0.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_IFAMP_TRIM_M                       0x00F80000
#define FCFG1_CONFIG_RF_FRONTEND_IFAMP_TRIM_S                               19

// Field: [18:14] CTL_PA0_TRIM
//
// Trim value for ADI_0_RF:PACTL0.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_CTL_PA0_TRIM_M                     0x0007C000
#define FCFG1_CONFIG_RF_FRONTEND_CTL_PA0_TRIM_S                             14

// Field:    [13] PATRIMCOMPLETE_N
//
// Status of PA trim
// 0: Trimmed
// 1: Not trimmed
#define FCFG1_CONFIG_RF_FRONTEND_PATRIMCOMPLETE_N                   0x00002000
#define FCFG1_CONFIG_RF_FRONTEND_PATRIMCOMPLETE_N_BITN                      13
#define FCFG1_CONFIG_RF_FRONTEND_PATRIMCOMPLETE_N_M                 0x00002000
#define FCFG1_CONFIG_RF_FRONTEND_PATRIMCOMPLETE_N_S                         13

// Field:   [6:0] RFLDO_TRIM_OUTPUT
//
// Trim value for ADI_0_RF:RFLDO1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_RF_FRONTEND_RFLDO_TRIM_OUTPUT_M                0x0000007F
#define FCFG1_CONFIG_RF_FRONTEND_RFLDO_TRIM_OUTPUT_S                         0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_SYNTH
//
//*****************************************************************************
// Field: [27:12] RFC_MDM_DEMIQMC0
//
// Trim value for RFC_MDM:DEMIQMC0.GAINFACTOR and RFC_MDM:DEMIQMC0.PHASEFACTOR
// Value is read by RF Core ROM FW during RF Core initialization only on
// cc13xx.
#define FCFG1_CONFIG_SYNTH_RFC_MDM_DEMIQMC0_M                       0x0FFFF000
#define FCFG1_CONFIG_SYNTH_RFC_MDM_DEMIQMC0_S                               12

// Field:  [11:6] LDOVCO_TRIM_OUTPUT
//
// Trim value for ADI_1_SYNTH:VCOLDOCTL1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_LDOVCO_TRIM_OUTPUT_M                     0x00000FC0
#define FCFG1_CONFIG_SYNTH_LDOVCO_TRIM_OUTPUT_S                              6

// Field:   [5:0] SLDO_TRIM_OUTPUT
//
// Trim value for ADI_1_SYNTH:SLDOCTL1.TRIM_OUT.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_SYNTH_SLDO_TRIM_OUTPUT_M                       0x0000003F
#define FCFG1_CONFIG_SYNTH_SLDO_TRIM_OUTPUT_S                                0

//*****************************************************************************
//
// Register: FCFG1_O_SOC_ADC_ABS_GAIN
//
//*****************************************************************************
// Field:  [15:0] SOC_ADC_ABS_GAIN_TEMP1
//
// SOC_ADC gain in absolute reference mode at temperature 1 (30C). Calculated
// in production test..
#define FCFG1_SOC_ADC_ABS_GAIN_SOC_ADC_ABS_GAIN_TEMP1_M             0x0000FFFF
#define FCFG1_SOC_ADC_ABS_GAIN_SOC_ADC_ABS_GAIN_TEMP1_S                      0

//*****************************************************************************
//
// Register: FCFG1_O_SOC_ADC_REL_GAIN
//
//*****************************************************************************
// Field:  [15:0] SOC_ADC_REL_GAIN_TEMP1
//
// SOC_ADC gain in relative reference mode at temperature 1 (30C). Calculated
// in production test..
#define FCFG1_SOC_ADC_REL_GAIN_SOC_ADC_REL_GAIN_TEMP1_M             0x0000FFFF
#define FCFG1_SOC_ADC_REL_GAIN_SOC_ADC_REL_GAIN_TEMP1_S                      0

//*****************************************************************************
//
// Register: FCFG1_O_SOC_ADC_OFFSET_INT
//
//*****************************************************************************
// Field: [23:16] SOC_ADC_REL_OFFSET_TEMP1
//
// SOC_ADC offset in relative reference mode at temperature 1 (30C). Signed
// 8-bit number. Calculated in production test..
#define FCFG1_SOC_ADC_OFFSET_INT_SOC_ADC_REL_OFFSET_TEMP1_M         0x00FF0000
#define FCFG1_SOC_ADC_OFFSET_INT_SOC_ADC_REL_OFFSET_TEMP1_S                 16

// Field:   [7:0] SOC_ADC_ABS_OFFSET_TEMP1
//
// SOC_ADC offset in absolute reference mode at temperature 1 (30C). Signed
// 8-bit number. Calculated in production test..
#define FCFG1_SOC_ADC_OFFSET_INT_SOC_ADC_ABS_OFFSET_TEMP1_M         0x000000FF
#define FCFG1_SOC_ADC_OFFSET_INT_SOC_ADC_ABS_OFFSET_TEMP1_S                  0

//*****************************************************************************
//
// Register: FCFG1_O_SOC_ADC_REF_TRIM_AND_OFFSET_EXT
//
//*****************************************************************************
// Field:   [5:0] SOC_ADC_REF_VOLTAGE_TRIM_TEMP1
//
// Value to write in ADI_4_AUX:ADCREF1.VTRIM at temperature 1 (30C).
#define FCFG1_SOC_ADC_REF_TRIM_AND_OFFSET_EXT_SOC_ADC_REF_VOLTAGE_TRIM_TEMP1_M \
                                                                    0x0000003F
#define FCFG1_SOC_ADC_REF_TRIM_AND_OFFSET_EXT_SOC_ADC_REF_VOLTAGE_TRIM_TEMP1_S \
                                                                             0

//*****************************************************************************
//
// Register: FCFG1_O_AMPCOMP_TH1
//
//*****************************************************************************
// Field: [23:18] HPMRAMP3_LTH
//
// HPM Ramp3 low amplitude threshhold.
// In HPM_RAMP3, if amp > HPMRAMP3_LTH && amp < HPMRAMP3_HTH then move on
// HPM_UPDATE.
#define FCFG1_AMPCOMP_TH1_HPMRAMP3_LTH_M                            0x00FC0000
#define FCFG1_AMPCOMP_TH1_HPMRAMP3_LTH_S                                    18

// Field: [15:10] HPMRAMP3_HTH
//
// In HPM_RAMP3, if amp > HPMRAMP3_LTH && amp < HPMRAMP3_HTH then move on to
// HPM_UPDATE.
#define FCFG1_AMPCOMP_TH1_HPMRAMP3_HTH_M                            0x0000FC00
#define FCFG1_AMPCOMP_TH1_HPMRAMP3_HTH_S                                    10

// Field:   [9:6] IBIASCAP_LPTOHP_OL_CNT
//
// During XOSC mode transition, CAP trim and IBIAS trim should be modified by
// this amount. IBIAS and CAP trim open loop count. CAP_REM is remainder of the
// CAP that is left to reach the final cap value.
#define FCFG1_AMPCOMP_TH1_IBIASCAP_LPTOHP_OL_CNT_M                  0x000003C0
#define FCFG1_AMPCOMP_TH1_IBIASCAP_LPTOHP_OL_CNT_S                           6

// Field:   [5:0] HPMRAMP1_TH
//
// During XOSC mode transition, CAP trim and IBIAS trim should be modified by
// this amount. IBIAS and CAP trim open loop count. CAP_REM is remainder of the
// CAP that is left to reach the final cap value.
#define FCFG1_AMPCOMP_TH1_HPMRAMP1_TH_M                             0x0000003F
#define FCFG1_AMPCOMP_TH1_HPMRAMP1_TH_S                                      0

//*****************************************************************************
//
// Register: FCFG1_O_AMPCOMP_TH2
//
//*****************************************************************************
// Field: [31:26] LPMUPDATE_LTH
//
// LPM Update low amplitude threshhold.
// if amp > LPMUPDATE_LTH && amp < LPMUPDATE_HTH then move on.
#define FCFG1_AMPCOMP_TH2_LPMUPDATE_LTH_M                           0xFC000000
#define FCFG1_AMPCOMP_TH2_LPMUPDATE_LTH_S                                   26

// Field: [23:18] LPMUPDATE_HTM
//
// LPM Update high amplitude threshhold.
// if amp > LPMUPDATE_LTH && amp < LPMUPDATE_HTH then move on.
#define FCFG1_AMPCOMP_TH2_LPMUPDATE_HTM_M                           0x00FC0000
#define FCFG1_AMPCOMP_TH2_LPMUPDATE_HTM_S                                   18

// Field: [15:10] ADC_COMP_AMPTH_LPM
//
// When ADC is forced in comparator mode, this value is used as OPAMP's
// threshold during LPM_UPDATE mode. Actual amplitude is compared against this
// threshhold to generate 1-bit adc_threshholdmet indicator output.
#define FCFG1_AMPCOMP_TH2_ADC_COMP_AMPTH_LPM_M                      0x0000FC00
#define FCFG1_AMPCOMP_TH2_ADC_COMP_AMPTH_LPM_S                              10

// Field:   [7:2] ADC_COMP_AMPTH_HPM
//
// When ADC is forced in comparator mode, this value is used as OPAMP's
// threshold during HPM_UPDATE mode. Actual amplitude is compared against this
// threshhold to generate 1-bit adc_threshholdmet indicator output.
#define FCFG1_AMPCOMP_TH2_ADC_COMP_AMPTH_HPM_M                      0x000000FC
#define FCFG1_AMPCOMP_TH2_ADC_COMP_AMPTH_HPM_S                               2

//*****************************************************************************
//
// Register: FCFG1_O_AMPCOMP_CTRL1
//
//*****************************************************************************
// Field:    [30] AMPCOMP_REQ_MODE
//
// Trim value for DDI_0_OSC:AMPCOMPCTL.AMPCOMP_REQ_MODE.
#define FCFG1_AMPCOMP_CTRL1_AMPCOMP_REQ_MODE                        0x40000000
#define FCFG1_AMPCOMP_CTRL1_AMPCOMP_REQ_MODE_BITN                           30
#define FCFG1_AMPCOMP_CTRL1_AMPCOMP_REQ_MODE_M                      0x40000000
#define FCFG1_AMPCOMP_CTRL1_AMPCOMP_REQ_MODE_S                              30

// Field: [23:20] IBIAS_OFFSET
//
// Offset values of XOSC IBIAS trim. IBIAS trim value would always be greater
// than or equal to this offset in both HPM and LPM.
#define FCFG1_AMPCOMP_CTRL1_IBIAS_OFFSET_M                          0x00F00000
#define FCFG1_AMPCOMP_CTRL1_IBIAS_OFFSET_S                                  20

// Field: [19:16] IBIAS_INIT
//
// Initial value of XOSC IBIAS trim. During ramping up, IBIAS is set to
// IBIAS_OFFSET + IBIAS_INIT.
#define FCFG1_AMPCOMP_CTRL1_IBIAS_INIT_M                            0x000F0000
#define FCFG1_AMPCOMP_CTRL1_IBIAS_INIT_S                                    16

// Field:  [15:8] LPM_IBIAS_WAIT_CNT_FINAL
//
// FSM waits for ddi_lpm_ibias_wait_cnt_final clock cycles in
// IDAC_DECREMENT_WITH_MEASURE states in order to compensate slow response of
// the xtal. 8-bits.
#define FCFG1_AMPCOMP_CTRL1_LPM_IBIAS_WAIT_CNT_FINAL_M              0x0000FF00
#define FCFG1_AMPCOMP_CTRL1_LPM_IBIAS_WAIT_CNT_FINAL_S                       8

// Field:   [7:4] CAP_STEP
//
// Step size of XOSC CAP trim (both Q1 and Q2) during XOSC mode transition. Can
// vary from 6 to 12. Other values are possible but not valid.
#define FCFG1_AMPCOMP_CTRL1_CAP_STEP_M                              0x000000F0
#define FCFG1_AMPCOMP_CTRL1_CAP_STEP_S                                       4

// Field:   [3:0] IBIASCAP_HPTOLP_OL_CNT
//
// During HPM to LPM transition, CAP trim and IBIAS trim should be modified by
// this amount. IBIAS and CAP trim open loop count. CAP_REM is remainder of the
// CAP that is left to reach the final cap value. Do not need to program this.
// CAP_TRIM = CAP_INIT - CAP_STEP*IBIASCAP_HPTOLP_OL_CNT - CAP_REM;
// IBIAS_TRIM = IBIAS_INIT - 1*IBIASCAP_HPTOLP_OL_CNT;
// Here, cap_init is decimal conversion of cap_init_col and cap_init_row.
#define FCFG1_AMPCOMP_CTRL1_IBIASCAP_HPTOLP_OL_CNT_M                0x0000000F
#define FCFG1_AMPCOMP_CTRL1_IBIASCAP_HPTOLP_OL_CNT_S                         0

//*****************************************************************************
//
// Register: FCFG1_O_ANABYPASS_VALUE2
//
//*****************************************************************************
// Field:  [13:0] XOSC_HF_IBIASTHERM
//
// Value of xosc_hf_ibiastherm when oscdig is bypassed.
#define FCFG1_ANABYPASS_VALUE2_XOSC_HF_IBIASTHERM_M                 0x00003FFF
#define FCFG1_ANABYPASS_VALUE2_XOSC_HF_IBIASTHERM_S                          0

//*****************************************************************************
//
// Register: FCFG1_O_CONFIG_MISC_ADC
//
//*****************************************************************************
// Field:    [17] RSSITRIMCOMPLETE_N
//
// Status of RSSI trim
// 0: Trimmed
// 1: Not trimmed
#define FCFG1_CONFIG_MISC_ADC_RSSITRIMCOMPLETE_N                    0x00020000
#define FCFG1_CONFIG_MISC_ADC_RSSITRIMCOMPLETE_N_BITN                       17
#define FCFG1_CONFIG_MISC_ADC_RSSITRIMCOMPLETE_N_M                  0x00020000
#define FCFG1_CONFIG_MISC_ADC_RSSITRIMCOMPLETE_N_S                          17

// Field:  [16:9] RSSI_OFFSET
//
// Value for RSSI measured in production test.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_RSSI_OFFSET_M                         0x0001FE00
#define FCFG1_CONFIG_MISC_ADC_RSSI_OFFSET_S                                  9

// Field:   [8:6] QUANTCTLTHRES
//
// Trim value for ADI_0_RF:IFADCQUANT0.TH.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_QUANTCTLTHRES_M                       0x000001C0
#define FCFG1_CONFIG_MISC_ADC_QUANTCTLTHRES_S                                6

// Field:   [5:0] DACTRIM
//
// Trim value for ADI_0_RF:IFADCDAC.TRIM.
// Value is read by RF Core ROM FW during RF Core initialization.
#define FCFG1_CONFIG_MISC_ADC_DACTRIM_M                             0x0000003F
#define FCFG1_CONFIG_MISC_ADC_DACTRIM_S                                      0

//*****************************************************************************
//
// Register: FCFG1_O_VOLT_TRIM
//
//*****************************************************************************
// Field: [28:24] VDDR_TRIM_HH
//
// Trim value for 1.94V VDDR found in production test (for CC13xx high PA
// output power only).
#define FCFG1_VOLT_TRIM_VDDR_TRIM_HH_M                              0x1F000000
#define FCFG1_VOLT_TRIM_VDDR_TRIM_HH_S                                      24

// Field: [20:16] VDDR_TRIM_H
//
// Trim value for 1.85V VDDR found in production test (for external VDDR load
// mode)
#define FCFG1_VOLT_TRIM_VDDR_TRIM_H_M                               0x001F0000
#define FCFG1_VOLT_TRIM_VDDR_TRIM_H_S                                       16

// Field:  [12:8] VDDR_TRIM_SLEEP_H
//
// Trim value for 1.75V VDDR recharge target found in production test (for
// external VDDR load mode).
#define FCFG1_VOLT_TRIM_VDDR_TRIM_SLEEP_H_M                         0x00001F00
#define FCFG1_VOLT_TRIM_VDDR_TRIM_SLEEP_H_S                                  8

// Field:   [4:0] TRIMBOD_H
//
// Trim value for 2.0V VDDS BOD target found in production test.
#define FCFG1_VOLT_TRIM_TRIMBOD_H_M                                 0x0000001F
#define FCFG1_VOLT_TRIM_TRIMBOD_H_S                                          0

//*****************************************************************************
//
// Register: FCFG1_O_OSC_CONF
//
//*****************************************************************************
// Field:    [29] ADC_SH_VBUF_EN
//
// Trim value for DDI_0_OSC:ADCDOUBLERNANOAMPCTL.ADC_SH_VBUF_EN.
#define FCFG1_OSC_CONF_ADC_SH_VBUF_EN                               0x20000000
#define FCFG1_OSC_CONF_ADC_SH_VBUF_EN_BITN                                  29
#define FCFG1_OSC_CONF_ADC_SH_VBUF_EN_M                             0x20000000
#define FCFG1_OSC_CONF_ADC_SH_VBUF_EN_S                                     29

// Field:    [28] ADC_SH_MODE_EN
//
// Trim value for DDI_0_OSC:ADCDOUBLERNANOAMPCTL.ADC_SH_MODE_EN.
#define FCFG1_OSC_CONF_ADC_SH_MODE_EN                               0x10000000
#define FCFG1_OSC_CONF_ADC_SH_MODE_EN_BITN                                  28
#define FCFG1_OSC_CONF_ADC_SH_MODE_EN_M                             0x10000000
#define FCFG1_OSC_CONF_ADC_SH_MODE_EN_S                                     28

// Field:    [27] ATESTLF_RCOSCLF_IBIAS_TRIM
//
// Trim value for DDI_0_OSC:ATESTCTL.ATESTLF_RCOSCLF_IBIAS_TRIM.
#define FCFG1_OSC_CONF_ATESTLF_RCOSCLF_IBIAS_TRIM                   0x08000000
#define FCFG1_OSC_CONF_ATESTLF_RCOSCLF_IBIAS_TRIM_BITN                      27
#define FCFG1_OSC_CONF_ATESTLF_RCOSCLF_IBIAS_TRIM_M                 0x08000000
#define FCFG1_OSC_CONF_ATESTLF_RCOSCLF_IBIAS_TRIM_S                         27

// Field: [26:25] XOSCLF_REGULATOR_TRIM
//
// Trim value for DDI_0_OSC:LFOSCCTL.XOSCLF_REGULATOR_TRIM.
#define FCFG1_OSC_CONF_XOSCLF_REGULATOR_TRIM_M                      0x06000000
#define FCFG1_OSC_CONF_XOSCLF_REGULATOR_TRIM_S                              25

// Field: [24:21] XOSCLF_CMIRRWR_RATIO
//
// Trim value for DDI_0_OSC:LFOSCCTL.XOSCLF_CMIRRWR_RATIO.
#define FCFG1_OSC_CONF_XOSCLF_CMIRRWR_RATIO_M                       0x01E00000
#define FCFG1_OSC_CONF_XOSCLF_CMIRRWR_RATIO_S                               21

// Field: [20:19] XOSC_HF_FAST_START
//
// Trim value for DDI_0_OSC:CTL1.XOSC_HF_FAST_START.
// This trim value is not relevant for PG1 devices.
#define FCFG1_OSC_CONF_XOSC_HF_FAST_START_M                         0x00180000
#define FCFG1_OSC_CONF_XOSC_HF_FAST_START_S                                 19

// Field:    [18] XOSC_OPTION
//
// 0: XOSC_HF unavailable (may not be bonded out)
// 1: XOSC_HF available (default)
#define FCFG1_OSC_CONF_XOSC_OPTION                                  0x00040000
#define FCFG1_OSC_CONF_XOSC_OPTION_BITN                                     18
#define FCFG1_OSC_CONF_XOSC_OPTION_M                                0x00040000
#define FCFG1_OSC_CONF_XOSC_OPTION_S                                        18

// Field:    [17] BAW_OPTION
//
// 0: BAW available
// 1: BAW unavailable (default)
#define FCFG1_OSC_CONF_BAW_OPTION                                   0x00020000
#define FCFG1_OSC_CONF_BAW_OPTION_BITN                                      17
#define FCFG1_OSC_CONF_BAW_OPTION_M                                 0x00020000
#define FCFG1_OSC_CONF_BAW_OPTION_S                                         17

// Field:    [16] BAW_BIAS_HOLD_MODE_EN
//
// Enable signal for bias sample and hold mode. Written to
// ADI_2_REFSYS:BAWCTL2.BIAS_HOLD_MODE_EN.
#define FCFG1_OSC_CONF_BAW_BIAS_HOLD_MODE_EN                        0x00010000
#define FCFG1_OSC_CONF_BAW_BIAS_HOLD_MODE_EN_BITN                           16
#define FCFG1_OSC_CONF_BAW_BIAS_HOLD_MODE_EN_M                      0x00010000
#define FCFG1_OSC_CONF_BAW_BIAS_HOLD_MODE_EN_S                              16

// Field: [15:12] BAW_CURRMIRR_RATIO
//
// Set current mirror ratio in BAW. Controls amount of current flowing in BAW
// oscillator core. Written to ADI_2_REFSYS:BAWCTL2.CURRMIRR_RATIO.
#define FCFG1_OSC_CONF_BAW_CURRMIRR_RATIO_M                         0x0000F000
#define FCFG1_OSC_CONF_BAW_CURRMIRR_RATIO_S                                 12

// Field:  [11:8] BAW_BIAS_RES_SET
//
// Adjust the BAW bias resistor to set the current in the BAW core. Two's
// complement encoding.  Written to ADI_2_REFSYS:BAWCTL1.BIAS_RES_SET.
#define FCFG1_OSC_CONF_BAW_BIAS_RES_SET_M                           0x00000F00
#define FCFG1_OSC_CONF_BAW_BIAS_RES_SET_S                                    8

// Field:     [7] BAW_FILTER_EN
//
// Enables a low pass filter around 1 kHz in the bias. Written to
// ADI_2_REFSYS:BAWCTL0.FILTER_EN.
#define FCFG1_OSC_CONF_BAW_FILTER_EN                                0x00000080
#define FCFG1_OSC_CONF_BAW_FILTER_EN_BITN                                    7
#define FCFG1_OSC_CONF_BAW_FILTER_EN_M                              0x00000080
#define FCFG1_OSC_CONF_BAW_FILTER_EN_S                                       7

// Field:   [6:5] BAW_BIAS_RECHARGE_DELAY
//
// This field sets the recharge delay for sample and hold mode. Written to
// ADI_2_REFSYS:BAWCTL0.BIAS_RECHARGE_DLY.
#define FCFG1_OSC_CONF_BAW_BIAS_RECHARGE_DELAY_M                    0x00000060
#define FCFG1_OSC_CONF_BAW_BIAS_RECHARGE_DELAY_S                             5

// Field:   [2:1] BAW_SERIES_CAP
//
// Cap to set BAW into proper mode. Written to ADI_2_REFSYS:BAWCTL0.SERIES_CAP.
#define FCFG1_OSC_CONF_BAW_SERIES_CAP_M                             0x00000006
#define FCFG1_OSC_CONF_BAW_SERIES_CAP_S                                      1

// Field:     [0] BAW_DIV3_BYPASS
//
// Bypass div3 for divider, for divide ratio of 17.5. Written to
// ADI_2_REFSYS:BAWCTL0.DIV3_BYPASS.
// 0: Divide by 52.5 for use with 2520 MHz BAW
// 1: Divide by 17.5 for use with 840 MHz BAW
#define FCFG1_OSC_CONF_BAW_DIV3_BYPASS                              0x00000001
#define FCFG1_OSC_CONF_BAW_DIV3_BYPASS_BITN                                  0
#define FCFG1_OSC_CONF_BAW_DIV3_BYPASS_M                            0x00000001
#define FCFG1_OSC_CONF_BAW_DIV3_BYPASS_S                                     0

//*****************************************************************************
//
// Register: FCFG1_O_CAP_TRIM
//
//*****************************************************************************
// Field: [31:16] FLUX_CAP_0P28_TRIM
//
// Reserved storage of measurement value on 0.28um pitch FLUX CAP (measured in
// production test)
#define FCFG1_CAP_TRIM_FLUX_CAP_0P28_TRIM_M                         0xFFFF0000
#define FCFG1_CAP_TRIM_FLUX_CAP_0P28_TRIM_S                                 16

// Field:  [15:0] FLUX_CAP_0P4_TRIM
//
// Reserved storage of measurement value on 0.4um pitch FLUX CAP (measured in
// production test)
#define FCFG1_CAP_TRIM_FLUX_CAP_0P4_TRIM_M                          0x0000FFFF
#define FCFG1_CAP_TRIM_FLUX_CAP_0P4_TRIM_S                                   0

//*****************************************************************************
//
// Register: FCFG1_O_MISC_OTP_DATA_1
//
//*****************************************************************************
// Field: [28:27] PEAK_DET_ITRIM
//
// Trim value for DDI_0_OSC:XOSCHFCTL.PEAK_DET_ITRIM.
#define FCFG1_MISC_OTP_DATA_1_PEAK_DET_ITRIM_M                      0x18000000
#define FCFG1_MISC_OTP_DATA_1_PEAK_DET_ITRIM_S                              27

// Field: [26:24] HP_BUF_ITRIM
//
// Trim value for DDI_0_OSC:XOSCHFCTL.HP_BUF_ITRIM.
#define FCFG1_MISC_OTP_DATA_1_HP_BUF_ITRIM_M                        0x07000000
#define FCFG1_MISC_OTP_DATA_1_HP_BUF_ITRIM_S                                24

// Field: [23:22] LP_BUF_ITRIM
//
// Trim value for DDI_0_OSC:XOSCHFCTL.LP_BUF_ITRIM.
#define FCFG1_MISC_OTP_DATA_1_LP_BUF_ITRIM_M                        0x00C00000
#define FCFG1_MISC_OTP_DATA_1_LP_BUF_ITRIM_S                                22

// Field: [21:20] DBLR_LOOP_FILTER_RESET_VOLTAGE
//
// Trim value for
// DDI_0_OSC:ADCDOUBLERNANOAMPCTL.DBLR_LOOP_FILTER_RESET_VOLTAGE.
#define FCFG1_MISC_OTP_DATA_1_DBLR_LOOP_FILTER_RESET_VOLTAGE_M      0x00300000
#define FCFG1_MISC_OTP_DATA_1_DBLR_LOOP_FILTER_RESET_VOLTAGE_S              20

// Field: [19:10] HPM_IBIAS_WAIT_CNT
//
// Trim value for DDI_0_OSC:RADCEXTCFG.HPM_IBIAS_WAIT_CNT.
#define FCFG1_MISC_OTP_DATA_1_HPM_IBIAS_WAIT_CNT_M                  0x000FFC00
#define FCFG1_MISC_OTP_DATA_1_HPM_IBIAS_WAIT_CNT_S                          10

// Field:   [9:4] LPM_IBIAS_WAIT_CNT
//
// Trim value for DDI_0_OSC:RADCEXTCFG.LPM_IBIAS_WAIT_CNT.
#define FCFG1_MISC_OTP_DATA_1_LPM_IBIAS_WAIT_CNT_M                  0x000003F0
#define FCFG1_MISC_OTP_DATA_1_LPM_IBIAS_WAIT_CNT_S                           4

// Field:   [3:0] IDAC_STEP
//
// Trim value for DDI_0_OSC:RADCEXTCFG.IDAC_STEP.
#define FCFG1_MISC_OTP_DATA_1_IDAC_STEP_M                           0x0000000F
#define FCFG1_MISC_OTP_DATA_1_IDAC_STEP_S                                    0

//*****************************************************************************
//
// Register: FCFG1_O_PWD_CURR_20C
//
//*****************************************************************************
// Field: [31:24] DELTA_CACHE_REF
//
// Additional maximum current, in units of 1uA, with cache retention
#define FCFG1_PWD_CURR_20C_DELTA_CACHE_REF_M                        0xFF000000
#define FCFG1_PWD_CURR_20C_DELTA_CACHE_REF_S                                24

// Field: [23:16] DELTA_RFMEM_RET
//
// Additional maximum current, in 1uA units, with RF memory retention
#define FCFG1_PWD_CURR_20C_DELTA_RFMEM_RET_M                        0x00FF0000
#define FCFG1_PWD_CURR_20C_DELTA_RFMEM_RET_S                                16

// Field:  [15:8] DELTA_XOSC_LPM
//
// Additional maximum current, in units of 1uA, with XOSC_HF on in low-power
// mode
#define FCFG1_PWD_CURR_20C_DELTA_XOSC_LPM_M                         0x0000FF00
#define FCFG1_PWD_CURR_20C_DELTA_XOSC_LPM_S                                  8

// Field:   [7:0] BASELINE
//
// Worst-case baseline maximum powerdown current, in units of 0.5uA
#define FCFG1_PWD_CURR_20C_BASELINE_M                               0x000000FF
#define FCFG1_PWD_CURR_20C_BASELINE_S                                        0

//*****************************************************************************
//
// Register: FCFG1_O_PWD_CURR_35C
//
//*****************************************************************************
// Field: [31:24] DELTA_CACHE_REF
//
// Additional maximum current, in units of 1uA, with cache retention
#define FCFG1_PWD_CURR_35C_DELTA_CACHE_REF_M                        0xFF000000
#define FCFG1_PWD_CURR_35C_DELTA_CACHE_REF_S                                24

// Field: [23:16] DELTA_RFMEM_RET
//
// Additional maximum current, in 1uA units, with RF memory retention
#define FCFG1_PWD_CURR_35C_DELTA_RFMEM_RET_M                        0x00FF0000
#define FCFG1_PWD_CURR_35C_DELTA_RFMEM_RET_S                                16

// Field:  [15:8] DELTA_XOSC_LPM
//
// Additional maximum current, in units of 1uA, with XOSC_HF on in low-power
// mode
#define FCFG1_PWD_CURR_35C_DELTA_XOSC_LPM_M                         0x0000FF00
#define FCFG1_PWD_CURR_35C_DELTA_XOSC_LPM_S                                  8

// Field:   [7:0] BASELINE
//
// Worst-case baseline maximum powerdown current, in units of 0.5uA
#define FCFG1_PWD_CURR_35C_BASELINE_M                               0x000000FF
#define FCFG1_PWD_CURR_35C_BASELINE_S                                        0

//*****************************************************************************
//
// Register: FCFG1_O_PWD_CURR_50C
//
//*****************************************************************************
// Field: [31:24] DELTA_CACHE_REF
//
// Additional maximum current, in units of 1uA, with cache retention
#define FCFG1_PWD_CURR_50C_DELTA_CACHE_REF_M                        0xFF000000
#define FCFG1_PWD_CURR_50C_DELTA_CACHE_REF_S                                24

// Field: [23:16] DELTA_RFMEM_RET
//
// Additional maximum current, in 1uA units, with RF memory retention
#define FCFG1_PWD_CURR_50C_DELTA_RFMEM_RET_M                        0x00FF0000
#define FCFG1_PWD_CURR_50C_DELTA_RFMEM_RET_S                                16

// Field:  [15:8] DELTA_XOSC_LPM
//
// Additional maximum current, in units of 1uA, with XOSC_HF on in low-power
// mode
#define FCFG1_PWD_CURR_50C_DELTA_XOSC_LPM_M                         0x0000FF00
#define FCFG1_PWD_CURR_50C_DELTA_XOSC_LPM_S                                  8

// Field:   [7:0] BASELINE
//
// Worst-case baseline maximum powerdown current, in units of 0.5uA
#define FCFG1_PWD_CURR_50C_BASELINE_M                               0x000000FF
#define FCFG1_PWD_CURR_50C_BASELINE_S                                        0

//*****************************************************************************
//
// Register: FCFG1_O_PWD_CURR_65C
//
//*****************************************************************************
// Field: [31:24] DELTA_CACHE_REF
//
// Additional maximum current, in units of 1uA, with cache retention
#define FCFG1_PWD_CURR_65C_DELTA_CACHE_REF_M                        0xFF000000
#define FCFG1_PWD_CURR_65C_DELTA_CACHE_REF_S                                24

// Field: [23:16] DELTA_RFMEM_RET
//
// Additional maximum current, in 1uA units, with RF memory retention
#define FCFG1_PWD_CURR_65C_DELTA_RFMEM_RET_M                        0x00FF0000
#define FCFG1_PWD_CURR_65C_DELTA_RFMEM_RET_S                                16

// Field:  [15:8] DELTA_XOSC_LPM
//
// Additional maximum current, in units of 1uA, with XOSC_HF on in low-power
// mode
#define FCFG1_PWD_CURR_65C_DELTA_XOSC_LPM_M                         0x0000FF00
#define FCFG1_PWD_CURR_65C_DELTA_XOSC_LPM_S                                  8

// Field:   [7:0] BASELINE
//
// Worst-case baseline maximum powerdown current, in units of 0.5uA
#define FCFG1_PWD_CURR_65C_BASELINE_M                               0x000000FF
#define FCFG1_PWD_CURR_65C_BASELINE_S                                        0

//*****************************************************************************
//
// Register: FCFG1_O_PWD_CURR_80C
//
//*****************************************************************************
// Field: [31:24] DELTA_CACHE_REF
//
// Additional maximum current, in units of 1uA, with cache retention
#define FCFG1_PWD_CURR_80C_DELTA_CACHE_REF_M                        0xFF000000
#define FCFG1_PWD_CURR_80C_DELTA_CACHE_REF_S                                24

// Field: [23:16] DELTA_RFMEM_RET
//
// Additional maximum current, in 1uA units, with RF memory retention
#define FCFG1_PWD_CURR_80C_DELTA_RFMEM_RET_M                        0x00FF0000
#define FCFG1_PWD_CURR_80C_DELTA_RFMEM_RET_S                                16

// Field:  [15:8] DELTA_XOSC_LPM
//
// Additional maximum current, in units of 1uA, with XOSC_HF on in low-power
// mode
#define FCFG1_PWD_CURR_80C_DELTA_XOSC_LPM_M                         0x0000FF00
#define FCFG1_PWD_CURR_80C_DELTA_XOSC_LPM_S                                  8

// Field:   [7:0] BASELINE
//
// Worst-case baseline maximum powerdown current, in units of 0.5uA
#define FCFG1_PWD_CURR_80C_BASELINE_M                               0x000000FF
#define FCFG1_PWD_CURR_80C_BASELINE_S                                        0

//*****************************************************************************
//
// Register: FCFG1_O_PWD_CURR_95C
//
//*****************************************************************************
// Field: [31:24] DELTA_CACHE_REF
//
// Additional maximum current, in units of 1uA, with cache retention
#define FCFG1_PWD_CURR_95C_DELTA_CACHE_REF_M                        0xFF000000
#define FCFG1_PWD_CURR_95C_DELTA_CACHE_REF_S                                24

// Field: [23:16] DELTA_RFMEM_RET
//
// Additional maximum current, in 1uA units, with RF memory retention
#define FCFG1_PWD_CURR_95C_DELTA_RFMEM_RET_M                        0x00FF0000
#define FCFG1_PWD_CURR_95C_DELTA_RFMEM_RET_S                                16

// Field:  [15:8] DELTA_XOSC_LPM
//
// Additional maximum current, in units of 1uA, with XOSC_HF on in low-power
// mode
#define FCFG1_PWD_CURR_95C_DELTA_XOSC_LPM_M                         0x0000FF00
#define FCFG1_PWD_CURR_95C_DELTA_XOSC_LPM_S                                  8

// Field:   [7:0] BASELINE
//
// Worst-case baseline maximum powerdown current, in units of 0.5uA
#define FCFG1_PWD_CURR_95C_BASELINE_M                               0x000000FF
#define FCFG1_PWD_CURR_95C_BASELINE_S                                        0

//*****************************************************************************
//
// Register: FCFG1_O_PWD_CURR_110C
//
//*****************************************************************************
// Field: [31:24] DELTA_CACHE_REF
//
// Additional maximum current, in units of 1uA, with cache retention
#define FCFG1_PWD_CURR_110C_DELTA_CACHE_REF_M                       0xFF000000
#define FCFG1_PWD_CURR_110C_DELTA_CACHE_REF_S                               24

// Field: [23:16] DELTA_RFMEM_RET
//
// Additional maximum current, in 1uA units, with RF memory retention
#define FCFG1_PWD_CURR_110C_DELTA_RFMEM_RET_M                       0x00FF0000
#define FCFG1_PWD_CURR_110C_DELTA_RFMEM_RET_S                               16

// Field:  [15:8] DELTA_XOSC_LPM
//
// Additional maximum current, in units of 1uA, with XOSC_HF on in low-power
// mode
#define FCFG1_PWD_CURR_110C_DELTA_XOSC_LPM_M                        0x0000FF00
#define FCFG1_PWD_CURR_110C_DELTA_XOSC_LPM_S                                 8

// Field:   [7:0] BASELINE
//
// Worst-case baseline maximum powerdown current, in units of 0.5uA
#define FCFG1_PWD_CURR_110C_BASELINE_M                              0x000000FF
#define FCFG1_PWD_CURR_110C_BASELINE_S                                       0

//*****************************************************************************
//
// Register: FCFG1_O_PWD_CURR_125C
//
//*****************************************************************************
// Field: [31:24] DELTA_CACHE_REF
//
// Additional maximum current, in units of 1uA, with cache retention
#define FCFG1_PWD_CURR_125C_DELTA_CACHE_REF_M                       0xFF000000
#define FCFG1_PWD_CURR_125C_DELTA_CACHE_REF_S                               24

// Field: [23:16] DELTA_RFMEM_RET
//
// Additional maximum current, in 1uA units, with RF memory retention
#define FCFG1_PWD_CURR_125C_DELTA_RFMEM_RET_M                       0x00FF0000
#define FCFG1_PWD_CURR_125C_DELTA_RFMEM_RET_S                               16

// Field:  [15:8] DELTA_XOSC_LPM
//
// Additional maximum current, in units of 1uA, with XOSC_HF on in low-power
// mode
#define FCFG1_PWD_CURR_125C_DELTA_XOSC_LPM_M                        0x0000FF00
#define FCFG1_PWD_CURR_125C_DELTA_XOSC_LPM_S                                 8

// Field:   [7:0] BASELINE
//
// Worst-case baseline maximum powerdown current, in units of 0.5uA
#define FCFG1_PWD_CURR_125C_BASELINE_M                              0x000000FF
#define FCFG1_PWD_CURR_125C_BASELINE_S                                       0


#endif // __FCFG1__
