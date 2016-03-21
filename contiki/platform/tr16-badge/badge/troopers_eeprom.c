/**
 * \file
 * Support for Troopers 16 Badge Accessing the EEPROM from Application Level
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
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * $Id: badge-eeprom.c,v 1.1 2006/06/18 07:49:33 shuckc Exp $
 *
 * Author: Christopher Scheuring <cschering@ernw.de> 
 *
 */

#include "contiki.h"
#include "ti-lib.h"
#include "dev/eeprom.h"
#include "troopers_eeprom.h"
#include "rtimer-arch.h"
#include "board.h"
#include "board-spi.h"
#include <stdio.h>
#include <string.h>

void badge_eeprom_init(void)
{
	eeprom_config();
}

void badge_eeprom_unconfig(void)
{
	eeprom_unconfig();
}

/**
 * Reads a character value from EEPROM.
 * EEPROM Page: 0 - 299
 */
bool badge_eeprom_read_char(uint8_t charID, unsigned char *buf)
{
	return badge_eeprom_read(charID * 128, buf);
}

/**
 * Reads the BadgeName from EEPROM.
 * EEPROM Page: 300
 */
bool badge_eeprom_read_BadgeName(unsigned char *buf)
{
	return badge_eeprom_read(300, buf);
}

/**
 * Reads the Badge-ID from EEPROM.
 * EEPROM Page: 301
 */
bool badge_eeprom_read_ID(unsigned char *buf)
{
	return badge_eeprom_read(301, buf);
}

/**
 * Reads the FakeName from EEPROM.
 * EEPROM Page: 302
 */
bool badge_eeprom_read_FakeName(unsigned char *buf)
{
	return badge_eeprom_read(302, buf);
}

/**
 * Reads the Group-ID from EEPROM.
 * EEPROM Page: 303
 */
bool badge_eeprom_read_GroupID(unsigned char *buf)
{
	return badge_eeprom_read(303, buf);
}

/**
 * Fill Badge EEPROM content.
 *
 */
bool badge_eeprom_fillEEPROM(unsigned short addr, unsigned char *buf)
{
	return false;
}

/**
 * Fill Badge EEPROM complet for testing.
 */
bool badge_eeprom_FullTestWrite()
{

	bool status = false;
	unsigned char spibufeeprom[PAGE_SIZE];

	for (uint16_t i = 0; i <= PAGE_NUMBER; i++) {
		printf("BADGER-EEPROM-FullWriteTest page-number %03d\n", i);
		for (uint8_t k = 0; k < PAGE_SIZE; k++) {
			spibufeeprom[k] = 0x00;
		}
		status = badge_eeprom_writePage(i, spibufeeprom);
	}
	return status;
}

/**
 * Read complete Badge EEPROM content for testing.
 */
bool badge_eeprom_FullTestRead()
{

	bool status = false;
	unsigned char spibufeeprom[PAGE_SIZE];

	for (uint16_t i = 0; i <= PAGE_NUMBER; i++) {
		printf("BADGER-EEPROM-FullReadTest page-number %03d\n", i);
		for (uint8_t k = 0; k < PAGE_SIZE; k++) {
			spibufeeprom[k] = i;
		}
		status = badge_eeprom_readPage(i, spibufeeprom);
		for (uint8_t k = 0; k < PAGE_SIZE; k++) {
			printf("0x%02x ", spibufeeprom[k]);
		}
		printf("\n");
	}
	return status;
}

/**
 * Reads a page from the EEPROM
 */
bool badge_eeprom_readPage(uint8_t page, unsigned char *buf)
{

	unsigned short addr = page * PAGE_SIZE;
	// check start addresse is beginning of a page
	if (addr == 0 || (addr % PAGE_SIZE) == 0) {
		// read data
		eeprom_read(addr, buf, PAGE_SIZE);
		return true;
	} else {
		printf("BADGE_EEPROM_READ: Wrong start addresse %04x\n", addr);
		return false;
	}
}

bool badge_eeprom_readPageN(uint16_t page, unsigned char *buf, uint8_t bufsize)
{

	unsigned short addr = page * PAGE_SIZE;
	// check start addresse is beginning of a page
	if (addr == 0 || (addr % PAGE_SIZE) == 0) {
		// read data
		eeprom_read(addr, buf, bufsize % PAGE_SIZE);
		return true;
	} else {
		printf("BADGE_EEPROM_READ: Wrong start addresse %04x\n", addr);
		return false;
	}
}

bool badge_eeprom_read(unsigned short addr, unsigned char *buf)
{
	return false;
}

/**
 * Writes a page to EEPROM
 */
bool badge_eeprom_writePage(uint8_t page, unsigned char *buf)
{

	unsigned short addr = page * PAGE_SIZE;
	// check start addresse is beginning of a page
	if (addr == 0 || (addr % PAGE_SIZE) == 0) {
		eeprom_write(addr, buf, PAGE_SIZE);
		return true;
	} else {
		printf("BADGE_EEPROM_WRITE: Wrong start addresse %04x\n", addr);
		return false;
	}
}

bool badge_eeprom_writePageN(uint16_t page, unsigned char *buf, uint8_t bufsize)
{
	unsigned short addr = page * PAGE_SIZE;
	// check start addresse is beginning of a page
	if (addr == 0 || (addr % PAGE_SIZE) == 0) {
		eeprom_write(addr, buf, bufsize % PAGE_SIZE);
		return true;
	} else {
		printf("BADGE_EEPROM_WRITE: Wrong start addresse %04x\n", addr);
		return false;
	}
}

bool badge_eeprom_write(unsigned short addr, unsigned char *buf)
{
	return false;
}
