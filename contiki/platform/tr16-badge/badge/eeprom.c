/**
 * \file
 * Support for Troopers 16 Badge 25AA512 SPI eeprom
 * \author Christopher Scheuring <cschering@ernw.de> 
 */

/* Copyright (c) 2016 ERNW GmbH Heidelberg.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * $Id: eeprom.c,v 1.1 2006/06/18 07:49:33 shuckc Exp $
 *
 * Author: Christopher Scheuring <cschering@ernw.de> 
 *
 */

#include "contiki.h"
#include "ti-lib.h"
#include "dev/eeprom.h"
#include "rtimer-arch.h"
#include "board.h"
#include "board-spi.h"
#include <stdio.h>
#include <string.h>

#include "eeprom.h"

#define EEPROM_CS_LOW()  { ti_lib_gpio_pin_write(BOARD_SPI_FLASH_CS, 0); }
#define EEPROM_CS_HIGH() { ti_lib_gpio_pin_write(BOARD_SPI_FLASH_CS, 1); }

#define SPI_SPEED   10000000

#define INSTR_READ  0x03	// Read data from memory array beginning at selected address
#define INSTR_WRITE 0x02	// Write data to memory array beginning at selected address
#define INSTR_WREN  0x06	// Set the write enable latch (enable write operations)
#define INSTR_WRDI  0x04	// Reset the write enable latch (disable write operations)
#define INSTR_RDSR  0x05	// Read STATUS register
#define INSTR_WRSR  0x01	// Write STATUS register
#define INSTR_PE    0x42	// Page Erase erase one page in memory array
#define INSTR_SE    0xD8	// Sector Erase erase one sector in memory array
#define INSTR_CE    0xC7	// Chip Erase erase all sectors in memory array
#define INSTR_RDID  0xAB	// Release from Deep power-down and read electronic signature
#define INSTR_DPD   0xB9	// Deep Power-Down mode

static volatile uint8_t eeprom_configured = 0;

void eeprom_config(void)
{

	//printf("INIT EEPROM\n");
	if (eeprom_configured == 1)
		return;

	// set SPI EEPROM pin as output
	ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_SPI_FLASH_CS);

	//initialize SPI with bit rate and clock pin
	board_spi_open(SPI_SPEED, BOARD_IOID_SPI_SCK);

	// disable EEPROM
	EEPROM_CS_HIGH();

	eeprom_configured = 1;
}

void eeprom_unconfig(void)
{

	board_spi_flush();	//flush SPI lines
	board_spi_close();	//close SPI bus
	EEPROM_CS_HIGH();
	eeprom_configured = 0;
}

/**
 * Read bytes from the EEPROM using sequential read.
 */
void eeprom_read(unsigned short addr, unsigned char *buf, int size)
{

	if (size <= 0) {
		printf("eeprom_read: wrong size");
		return;
	}
	//printf("eeprom: read dev address %04x to buffer %08x sz %d\n", addr, (int)buf, size);

	eeprom_config();
	EEPROM_CS_LOW();

	// set read mode
	board_spi_write_byte(INSTR_READ);

	// set address stuff
	// set address stuff
	uint8_t address[] = { (addr >> 8), (addr & 0xff) };
	//printf("%02x\n", (addr >> 8));
	//printf("%02x\n", (addr & 0xff));
	board_spi_write(address, sizeof(address));

	// read data from EEPROM form SPI
	board_spi_read(buf, size);

	EEPROM_CS_HIGH();
}

/**
 * Write bytes to EEPROM using sequencial write.
 */
void eeprom_write(unsigned short addr, unsigned char *buf, int size)
{

	if (size <= 0) {
		printf("eeprom_write: wrong size");
		return;
	}
	//printf("eeprom: write dev address %04x to buffer %08x sz %d\n", addr, (int)buf, size);

	uint8_t address[] = { (addr >> 8) & 0xFF, (addr & 0xff) };
	//printf("%04x\n", *(uint16_t*)(address));
	//printf("%02x", ((addr >> 8) & 0xff));
	//printf("%02x\n", (addr & 0xff));

	eeprom_config();

	// disable write protection
	EEPROM_CS_LOW();
	board_spi_write_byte(INSTR_WREN);
	EEPROM_CS_HIGH();
	// wait for one millisecond
	clock_delay_usec(1000);

	// enable write mode
	EEPROM_CS_LOW();
	board_spi_write_byte(INSTR_WRITE);

	// set address stuff
	// ...
	board_spi_write(address, sizeof(address));

	// write data to EEPROM over SPI
	board_spi_write(buf, size);

	EEPROM_CS_HIGH();

	// wait 5 milliseconds to write data complete
	clock_delay_usec(5000);

	eeprom_unconfig();
}
