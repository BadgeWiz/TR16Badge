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
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * $Id: badge-eeprom.h,v 1.1 2006/06/18 07:49:33 shuckc Exp $
 *
 * Author: Christopher Scheuring <cschering@ernw.de> 
 *
 */

#ifndef TROOPERS_EEPROM_H_
#define TROOPERS_EEPROM_H_


#define PAGE_SIZE    128  // 128 byte
#define PAGE_NUMBER  500  // 500 pages


typedef unsigned short eeprom_addr_t;

void eeprom_config( void );
void eeprom_unconfig( void );

/**
 * Reads a character value from EEPROM.
 * EEPROM Page: 0 - 299
 *
 * \param charID The char value to read from EEPROM.
 *
 * \param buf A pointer to the buffer from which data is to be read.
 *
 *
 */
bool badge_eeprom_read_char(uint8_t charID, unsigned char *buf);

/**
 * Reads the BadgeName from EEPROM.
 * EEPROM Page: 300
 *
 * \param buf A pointer to the buffer from which data is to be read.
 *
 *
 */
bool badge_eeprom_read_BadgeName(unsigned char *buf);

/**
 * Reads the Badge-ID from EEPROM.
 * EEPROM Page: 301
 *
 * \param buf A pointer to the buffer from which data is to be read.
 *
 *
 */
bool badge_eeprom_read_ID(unsigned char *buf);

/**
 * Reads the FakeName from EEPROM.
 * EEPROM Page: 302
 *
 * \param buf A pointer to the buffer from which data is to be read.
 *
 *
 */
bool badge_eeprom_read_FakeName(unsigned char *buf);

/**
 * Reads the Group-ID from EEPROM.
 * EEPROM Page: 303
 *
 * \param buf A pointer to the buffer from which data is to be read.
 *
 *
 */
bool badge_eeprom_read_GroupID(unsigned char *buf);

/**
 * Fill Badge EEPROM.
 *
 * This function writes the data for the Badge into the EEPROM.
 * The start address needs to be a multible of 128, wich is the page size
 * of the EEPROM
 *
 * \param addr The address in EEPROM to which the buffer should be written.
 *
 * \param buf A pointer to the buffer from which data is to be read.
 *
 *
 */
bool badge_eeprom_fillEEPROM(eeprom_addr_t addr, unsigned char *buf);

/**
 * Fill Badge EEPROM complet for testing.
 *
 * This function writes Test-Date into the complet EEPROM
 *
 */
bool badge_eeprom_FullTestWrite();

/**
 * Read complete Badge EEPROM content for testing.
 *
 * This function reads the complete EEPROM content and dumps into out
 * to seriell console.
 *
 */
bool badge_eeprom_FullTestRead();

/**
 * Write a page size into EEPROM.
 *
 * This function writes a complete page size into EEPROM.
 * The start address needs to be a multible of 128, wich is the page size
 * of the EEPROM
 *
 * \param addr The address in EEPROM to which the buffer should be written.
 *
 * \param buf A pointer to the buffer from which data is to be read.
 *
 *
 */
bool badge_eeprom_writePage(uint8_t page, unsigned char *buf);
bool badge_eeprom_writePageN(uint16_t page, unsigned char *buf, uint8_t bufsize);
bool badge_eeprom_write(eeprom_addr_t addr, unsigned char *buf);

/**
 * Read data from the EEPROM (one page size from startin address).
 *
 * This function reads a complet page size from the specified address in
 * EEPROM and into a buffer in memory.
 * The start address needs to be a multible of 128, wich is the page size
 * of the EEPROM
 *
 * \param addr The address in EEPROM from which the data should be read.
 *
 * \param buf A pointer to the buffer to which the data should be stored.
 *
 *
 */
bool badge_eeprom_readPage(uint8_t page, unsigned char *buf);
bool badge_eeprom_readPageN(uint16_t page, unsigned char *buf, uint8_t bufsize);
bool badge_eeprom_read(eeprom_addr_t addr, unsigned char *buf);


/**
 * Initialize the BADGE-EEPROM module
 *
 */ 
void badge_eeprom_init(void);

 
void badge_eeprom_unconfig(void);

#endif /* BADGE_EEPROM_H_ */

/** @} */
/** @} */
