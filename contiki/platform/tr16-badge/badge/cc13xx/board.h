/*
 * Copyright (c) 2014, Texas Instruments Incorporated - http://www.ti.com/
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*---------------------------------------------------------------------------*/
/** \addtogroup tr16-badge-tag
 * @{
 *
 * \defgroup badge-cc13xx-peripherals Peripherals for the Troopers 2016 Badge
 *
 * Defines related to the Troopers 2016 Badge with a CC1310EM
 *
 * This file provides connectivity information on LEDs, Buttons, UART and
 * other peripherals
 *
 * This file can be used as the basis to configure other boards using the
 * CC13xx/CC26xx code as their basis.
 *
 * This file is not meant to be modified by the user.
 * @{
 *
 * \file
 * Header file with definitions related to the I/O connections on the TI
 * SmartRF06 Evaluation Board with a CC1310EM
 *
 * \note   Do not include this file directly. It gets included by contiki-conf
 *         after all relevant directives have been set.
 */

// file modified to fit Troopers 2016 Badge /ski

/*---------------------------------------------------------------------------*/
#ifndef BOARD_H_
#define BOARD_H_
/*---------------------------------------------------------------------------*/
#include "ioc.h"
/*---------------------------------------------------------------------------*/

/* Notify various examples that we don't have LEDs /ski */
#define PLATFORM_HAS_LEDS        0
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name UART IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
// maybe we have to swap RX/TX /ski 
#define BOARD_IOID_UART_RX        IOID_2
#define BOARD_IOID_UART_TX        IOID_3
#define BOARD_IOID_UART_CTS       IOID_UNUSED
#define BOARD_IOID_UART_RTS       IOID_UNUSED
#define BOARD_UART_RX             (1 << BOARD_IOID_UART_RX)
#define BOARD_UART_TX             (1 << BOARD_IOID_UART_TX)
#define BOARD_UART_CTS            (1 << BOARD_IOID_UART_CTS)
#define BOARD_UART_RTS            (1 << BOARD_IOID_UART_RTS)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name Button IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
// add UART backdoor! /ski
#define BOARD_IOID_KEY_BACKDOOR   IOID_20
#define BOARD_KEY_BACKDOOR        (1 << BOARD_IOID_KEY_BACKDOOR)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name SPI IOID mapping
 *
 * /ski
 * @{
 */
#define BOARD_IOID_SPI_SCK        IOID_6
#define BOARD_IOID_SPI_MOSI       IOID_7
#define BOARD_IOID_SPI_MISO       IOID_5
#define BOARD_SPI_SCK             (1 << BOARD_IOID_SPI_SCK)
#define BOARD_SPI_MOSI            (1 << BOARD_IOID_SPI_MOSI)
#define BOARD_SPI_MISO            (1 << BOARD_IOID_SPI_MISO)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name External SPI EEPROM IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_SPI_FLASH_CS       IOID_9
#define BOARD_SPI_FLASH_CS            (1 << BOARD_IOID_SPI_FLASH_CS)
#define BOARD_IOID_SPI_FLASH_CLK      BOARD_IOID_SPI_SCK
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name LCD IOID mapping
 *
 * /ski
 * @{
 */
#define BOARD_IOID_LCD_BL         IOID_15                     // backlight sw
#define BOARD_IOID_LCD_BL_PWR_ON  IOID_23                     // PWR ON BL
#define BOARD_IOID_LCD_RST        IOID_14
#define BOARD_IOID_LCD_CS         IOID_13
#define BOARD_IOID_LCD_SCK        BOARD_IOID_SPI_SCK
#define BOARD_IOID_LCD_MOSI       BOARD_IOID_SPI_MOSI
#define BOARD_LCD_BL              (1 << BOARD_IOID_LCD_BL)
#define BOARD_LCD_BL_PWR_ON       (1 << BOARD_IOID_LCD_BL_PWR_ON)
#define BOARD_LCD_RST             (1 << BOARD_IOID_LCD_RST)
#define BOARD_LCD_CS              (1 << BOARD_IOID_LCD_CS)
#define BOARD_LCD_SCK             BOARD_SPI_SCK
#define BOARD_LCD_MOSI            BOARD_SPI_MOSI
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name pwm configuration
 * @{
 */
#define BOARD_IOID_LCD_PWM        BOARD_IOID_LCD_BL  // pwm Pin
 	                                                 // => BOARD_IOID_LCD_PWM
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name Touch IOID mapping
 *
 * /ski
 * @{
 */
#define BOARD_IOID_TOUCH_IRQ        IOID_11
#define BOARD_IOID_TOUCH_BUSY       IOID_10
#define BOARD_IOID_TOUCH_CS         IOID_12
#define BOARD_IOID_TOUCH_SCK        BOARD_IOID_SPI_SCK
#define BOARD_IOID_TOUCH_MOSI       BOARD_IOID_SPI_MOSI
#define BOARD_IOID_TOUCH_MISO       BOARD_IOID_SPI_MISO
#define BOARD_TOUCH_IRQ             (1 << BOARD_IOID_TOUCH_IRQ)
#define BOARD_TOUCH_BUSY            (1 << BOARD_IOID_TOUCH_BUSY)
#define BOARD_TOUCH_CS              (1 << BOARD_IOID_TOUCH_CS)
#define BOARD_TOUCH_SCK             BOARD_SPI_SCK
#define BOARD_TOUCH_MOSI            BOARD_SPI_MOSI
#define BOARD_TOUCH_MISO            BOARD_MISO
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name SD Card IOID mapping
 *
 * /ski
 * @{
 */
#define BOARD_IOID_SDCARD_CS      IOID_4
#define BOARD_SDCARD_CS           (1 << BOARD_IOID_SDCARD_CS)
#define BOARD_IOID_SDCARD_SCK     BOARD_IOID_SPI_SCK
#define BOARD_SDCARD_SCK          BOARD_SPI_SCK
#define BOARD_IOID_SDCARD_MOSI    BOARD_IOID_SPI_MOSI
#define BOARD_SDCARD_MOSI         BOARD_SPI_MOSI
#define BOARD_IOID_SDCARD_MISO    BOARD_IOID_SPI_MISO
#define BOARD_SDCARD_MISO         BOARD_SPI_MISO
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name Device string used on startup
 * @{
 */
#define BOARD_STRING "TROOPERS 2016 - Make the world a safer place."
/** @} */
/*---------------------------------------------------------------------------*/
#endif /* BOARD_H_ */
/*---------------------------------------------------------------------------*/
/**
 * @}
 * @}
 */
