/* 
 * Copyright (c) 2018 Jordan Stremming, Elisabeth Ama
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/**
 * EEPROM DRIVER
 **/

#include "pic24_all.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef EEPROM_H
#define	EEPROM_H

// INIT
void CONFIG_EEPROM(void);
uint16_t EEPROM_GET_ADDR(uint16_t u16_addr);

// READ
uint8_t EEPROM_READ_CURRENT(void);
uint8_t EEPROM_READ_SPECIFIC(uint16_t u16_addr);
char* EEPROM_READSTR_UNTILNULL(uint16_t u16_addr);
char* EEPROM_READSTR_BETWEEN(uint16_t u16_fromAddr, uint16_t u16_toAddr);

// WRITE
void EEPROM_WRITE_SPECIFIC(uint16_t u16_addr, uint8_t u8_byte);
void EEPROM_WRITESTR_SPECIFIC(uint16_t u16_addr, const char *data);
void EEPROM_ZERO_BETWEEN(uint16_t u16_fromAddr, uint16_t u16_toAddr);


#endif	/* EEPROM_H */

