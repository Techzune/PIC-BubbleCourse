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

#include "eeprom.h"

#define EEPROM_ADDR 0xA2

// FILE SPECIFIC FUNCTIONS
static void split_address(uint16_t u16_addr, uint8_t* u8_addrHi, uint8_t* u8_addrLo);

/**
 * Split a 16-bit address into two 8-bit parts
 */
static void split_address(uint16_t u16_addr, uint8_t* u8_addrHi, uint8_t* u8_addrLo) {
  *u8_addrHi = u16_addr >> 8;      // shift 8 to remove bottom 8 bits
  *u8_addrLo = u16_addr & 0x00FF;  // remove/zero top 8 bits
}

/**
 * Enables I2C1 on the PIC to 400 KHz (LC515)
 */
void CONFIG_EEPROM(void) {
  configI2C1(400);
}

/**
 * Returns 16-bit address with EEPROM 
 * sets BLK bit if address > 0x7FFFF
 * (level shifting)
 */
uint16_t EEPROM_GET_ADDR(uint16_t u16_addr) {
  return (u16_addr & 0x8000) ? EEPROM_ADDR | 0x08 : EEPROM_ADDR;
}

/**
 * Reads one byte from the specified address
 */
uint8_t EEPROM_READ_SPECIFIC(uint16_t u16_addr) {
  uint8_t u8_addrHi, u8_addrLo, u8_IC2Addr, u8_byte;
  
  // split the address; using pointers
  split_address(u16_addr, &u8_addrHi, &u8_addrLo);

  // get the I2C address
  u8_IC2Addr = EEPROM_GET_ADDR(u16_addr);

  // define the address
  startI2C1();                 // start I2C transaction
  putI2C1(u8_IC2Addr);         // send the I2C device address
  putI2C1(u8_addrHi);          // send first half
  putI2C1(u8_addrLo);          // send second half

  // read from address
  rstartI2C1();                // restart I2C transaction
  putI2C1(u8_IC2Addr | 0x01);  // send I2C device address; set LSb for READ
  u8_byte = getI2C1(1);        // read; send NAK to indicate READ finished
  stopI2C1();                  // end I2C transaction
  
  // return byte that was read
  return u8_byte;
}

/**
 * Writes one byte to the specified address
 */
void EEPROM_WRITE_SPECIFIC(uint16_t u16_addr, uint8_t u8_byte) {
  uint8_t u8_addrHi, u8_addrLo, u8_IC2Addr;

  // split the address; using pointers
  split_address(u16_addr, &u8_addrHi, &u8_addrLo);
  
  // get the I2C address
  u8_IC2Addr = EEPROM_GET_ADDR(u16_addr);

  // send data
  startI2C1();          // start I2C transaction
  putI2C1(u8_IC2Addr);  // send the I2C device address
  putI2C1(u8_addrHi);   // send 1st half
  putI2C1(u8_addrLo);   // send 2nd half
  putI2C1(u8_byte);     // send data
  stopI2C1();           // end I2C transaction
}

/**
 * Writes a char (array) to a specific address
 * ends with a 0x00 byte
 */
void EEPROM_WRITESTR_SPECIFIC(uint16_t u16_addr, const char *data) {
  uint8_t u8_i, u8_len, u8_char;
  u8_len = strlen(data);
  
  // loop through string
  for (u8_i = 0; u8_i < u8_len; u8_i++, u16_addr++) {
    // get current byte
    u8_char = data[u8_i] & 0xFF;
    if (u8_char == '\0') break;
    
    // write the byte
    EEPROM_WRITE_SPECIFIC(u16_addr, u8_char);
    DELAY_MS(5);
  }
  
  // end of string blank
  EEPROM_WRITE_SPECIFIC(u16_addr, 0x00);
}

/**
 * Reads a char array from between two addresses
 */
char* EEPROM_READSTR_BETWEEN(uint16_t u16_fromAddr, uint16_t u16_toAddr) {
  uint8_t u8_curChar = EEPROM_READ_SPECIFIC(u16_fromAddr);
  uint8_t u8_i;
  u8_i = 0;
  
  // dynamic char string
  char *returnChars;
  returnChars = (char *) malloc(sizeof(char));
  
  // read in the string
  while (u16_fromAddr < u16_toAddr) {
    realloc(returnChars, u8_i++);
    returnChars[u8_i] = u8_curChar;
    u8_curChar = EEPROM_READ_SPECIFIC(u16_fromAddr++);
    DELAY_MS(5);
  }
  
  // end the string
  returnChars[u8_i] = '\0';
  
  return returnChars;
}

/**
 * Reads a char array from an address
 * until a null char is returned
 */
char* EEPROM_READSTR_UNTILNULL(uint16_t u16_addr) {
  uint8_t u8_byte = EEPROM_READ_SPECIFIC(u16_addr);
  uint8_t u8_i;
  u8_i = 0;
  
  // dynamic char string
  char *returnChars;
  returnChars = (char *) malloc(sizeof(char));
    
  while (u8_byte != 0xFF && u8_byte != 0x00) { 
    realloc(returnChars, u8_i++);
    returnChars[u8_i] = u8_byte; 
    
    // increment
    u16_addr++;
    u8_byte = EEPROM_READ_SPECIFIC(u16_addr);
    DELAY_MS(5);
  };
  
  // end the string
  returnChars[u8_i] = '\0';
  
  return returnChars;
}

/**
 * Writes zeroes between two addresses
 * Effectively erasing the data
 */
void EEPROM_ZERO_BETWEEN(uint16_t u16_fromAddr, uint16_t u16_toAddr) {  
  while (u16_fromAddr < u16_toAddr) {
    // output
    EEPROM_WRITE_SPECIFIC(u16_fromAddr, 0x00);
    DELAY_MS(5);
    
    // increment
    u16_fromAddr++;
  };
}
