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
 * NOKIA 5110 LCD DRIVER
 **/

#include "nokia_5110.h"

// PRIVATE FUNCTIONS ////////////////////////////
static void ROTATE_LEFT(uint8_t* u8_data, uint8_t u8_shift);
static void configSPI1(void);


// VIDEO MEMORY MAP (504 bytes, 84x6) ///////////
static uint8_t NOK_MEM[84][6];         // DATA
static uint8_t NOK_CX = 0, NOK_CY = 0; // INDEXES


// ASCII CHARACTERS /////////////////////////////
const char NOK_ASCII[][5] = {
   {0x00, 0x00, 0x00, 0x00, 0x00} // 0x20 SPACE
  ,{0x00, 0x00, 0x5f, 0x00, 0x00} // 0x21 !
  ,{0x00, 0x07, 0x00, 0x07, 0x00} // 0x22 "
  ,{0x14, 0x7f, 0x14, 0x7f, 0x14} // 0x23 #
  ,{0x24, 0x2a, 0x7f, 0x2a, 0x12} // 0x24 $
  ,{0x23, 0x13, 0x08, 0x64, 0x62} // 0x25 %
  ,{0x36, 0x49, 0x55, 0x22, 0x50} // 0x26 &
  ,{0x00, 0x05, 0x03, 0x00, 0x00} // 0x27 '
  ,{0x00, 0x1c, 0x22, 0x41, 0x00} // 0x28 (
  ,{0x00, 0x41, 0x22, 0x1c, 0x00} // 0x29 )
  ,{0x14, 0x08, 0x3e, 0x08, 0x14} // 0x2a *
  ,{0x08, 0x08, 0x3e, 0x08, 0x08} // 0x2b +
  ,{0x00, 0x50, 0x30, 0x00, 0x00} // 0x2c ,
  ,{0x08, 0x08, 0x08, 0x08, 0x08} // 0x2d -
  ,{0x00, 0x60, 0x60, 0x00, 0x00} // 0x2e .
  ,{0x20, 0x10, 0x08, 0x04, 0x02} // 0x2f /
  ,{0x3e, 0x51, 0x49, 0x45, 0x3e} // 0x30 0
  ,{0x00, 0x42, 0x7f, 0x40, 0x00} // 0x31 1
  ,{0x42, 0x61, 0x51, 0x49, 0x46} // 0x32 2
  ,{0x21, 0x41, 0x45, 0x4b, 0x31} // 0x33 3
  ,{0x18, 0x14, 0x12, 0x7f, 0x10} // 0x34 4
  ,{0x27, 0x45, 0x45, 0x45, 0x39} // 0x35 5
  ,{0x3c, 0x4a, 0x49, 0x49, 0x30} // 0x36 6
  ,{0x01, 0x71, 0x09, 0x05, 0x03} // 0x37 7
  ,{0x36, 0x49, 0x49, 0x49, 0x36} // 0x38 8
  ,{0x06, 0x49, 0x49, 0x29, 0x1e} // 0x39 9
  ,{0x00, 0x36, 0x36, 0x00, 0x00} // 0x3a :
  ,{0x00, 0x56, 0x36, 0x00, 0x00} // 0x3b ;
  ,{0x08, 0x14, 0x22, 0x41, 0x00} // 0x3c <
  ,{0x14, 0x14, 0x14, 0x14, 0x14} // 0x3d =
  ,{0x00, 0x41, 0x22, 0x14, 0x08} // 0x3e >
  ,{0x02, 0x01, 0x51, 0x09, 0x06} // 0x3f ?
  ,{0x32, 0x49, 0x79, 0x41, 0x3e} // 0x40 @
  ,{0x7e, 0x11, 0x11, 0x11, 0x7e} // 0x41 A
  ,{0x7f, 0x49, 0x49, 0x49, 0x36} // 0x42 B
  ,{0x3e, 0x41, 0x41, 0x41, 0x22} // 0x43 C
  ,{0x7f, 0x41, 0x41, 0x22, 0x1c} // 0x44 D
  ,{0x7f, 0x49, 0x49, 0x49, 0x41} // 0x45 E
  ,{0x7f, 0x09, 0x09, 0x09, 0x01} // 0x46 F
  ,{0x3e, 0x41, 0x49, 0x49, 0x7a} // 0x47 G
  ,{0x7f, 0x08, 0x08, 0x08, 0x7f} // 0x48 H
  ,{0x00, 0x41, 0x7f, 0x41, 0x00} // 0x49 I
  ,{0x20, 0x40, 0x41, 0x3f, 0x01} // 0x4a J
  ,{0x7f, 0x08, 0x14, 0x22, 0x41} // 0x4b K
  ,{0x7f, 0x40, 0x40, 0x40, 0x40} // 0x4c L
  ,{0x7f, 0x02, 0x0c, 0x02, 0x7f} // 0x4d M
  ,{0x7f, 0x04, 0x08, 0x10, 0x7f} // 0x4e N
  ,{0x3e, 0x41, 0x41, 0x41, 0x3e} // 0x4f O
  ,{0x7f, 0x09, 0x09, 0x09, 0x06} // 0x50 P
  ,{0x3e, 0x41, 0x51, 0x21, 0x5e} // 0x51 Q
  ,{0x7f, 0x09, 0x19, 0x29, 0x46} // 0x52 R
  ,{0x46, 0x49, 0x49, 0x49, 0x31} // 0x53 S
  ,{0x01, 0x01, 0x7f, 0x01, 0x01} // 0x54 T
  ,{0x3f, 0x40, 0x40, 0x40, 0x3f} // 0x55 U
  ,{0x1f, 0x20, 0x40, 0x20, 0x1f} // 0x56 V
  ,{0x3f, 0x40, 0x38, 0x40, 0x3f} // 0x57 W
  ,{0x63, 0x14, 0x08, 0x14, 0x63} // 0x58 X
  ,{0x07, 0x08, 0x70, 0x08, 0x07} // 0x59 Y
  ,{0x61, 0x51, 0x49, 0x45, 0x43} // 0x5a Z
  ,{0x00, 0x7f, 0x41, 0x41, 0x00} // 0x5b [
  ,{0x02, 0x04, 0x08, 0x10, 0x20} // 0x5c \ (keep this to escape the backslash)
  ,{0x00, 0x41, 0x41, 0x7f, 0x00} // 0x5d ]
  ,{0x04, 0x02, 0x01, 0x02, 0x04} // 0x5e ^
  ,{0x40, 0x40, 0x40, 0x40, 0x40} // 0x5f _
  ,{0x00, 0x01, 0x02, 0x04, 0x00} // 0x60 `
  ,{0x20, 0x54, 0x54, 0x54, 0x78} // 0x61 a
  ,{0x7f, 0x48, 0x44, 0x44, 0x38} // 0x62 b
  ,{0x38, 0x44, 0x44, 0x44, 0x20} // 0x63 c
  ,{0x38, 0x44, 0x44, 0x48, 0x7f} // 0x64 d
  ,{0x38, 0x54, 0x54, 0x54, 0x18} // 0x65 e
  ,{0x08, 0x7e, 0x09, 0x01, 0x02} // 0x66 f
  ,{0x0c, 0x52, 0x52, 0x52, 0x3e} // 0x67 g
  ,{0x7f, 0x08, 0x04, 0x04, 0x78} // 0x68 h
  ,{0x00, 0x44, 0x7d, 0x40, 0x00} // 0x69 i
  ,{0x20, 0x40, 0x44, 0x3d, 0x00} // 0x6a j
  ,{0x7f, 0x10, 0x28, 0x44, 0x00} // 0x6b k
  ,{0x00, 0x41, 0x7f, 0x40, 0x00} // 0x6c l
  ,{0x7c, 0x04, 0x18, 0x04, 0x78} // 0x6d m
  ,{0x7c, 0x08, 0x04, 0x04, 0x78} // 0x6e n
  ,{0x38, 0x44, 0x44, 0x44, 0x38} // 0x6f o
  ,{0x7c, 0x14, 0x14, 0x14, 0x08} // 0x70 p
  ,{0x08, 0x14, 0x14, 0x18, 0x7c} // 0x71 q
  ,{0x7c, 0x08, 0x04, 0x04, 0x08} // 0x72 r
  ,{0x48, 0x54, 0x54, 0x54, 0x20} // 0x73 s
  ,{0x04, 0x3f, 0x44, 0x40, 0x20} // 0x74 t
  ,{0x3c, 0x40, 0x40, 0x20, 0x7c} // 0x75 u
  ,{0x1c, 0x20, 0x40, 0x20, 0x1c} // 0x76 v
  ,{0x3c, 0x40, 0x30, 0x40, 0x3c} // 0x77 w
  ,{0x44, 0x28, 0x10, 0x28, 0x44} // 0x78 x
  ,{0x0c, 0x50, 0x50, 0x50, 0x3c} // 0x79 y
  ,{0x44, 0x64, 0x54, 0x4c, 0x44} // 0x7a z
  ,{0x00, 0x08, 0x36, 0x41, 0x00} // 0x7b {
  ,{0x00, 0x00, 0x7f, 0x00, 0x00} // 0x7c |
  ,{0x00, 0x41, 0x36, 0x08, 0x00} // 0x7d }
  ,{0x10, 0x08, 0x08, 0x10, 0x08} // 0x7e ~
  ,{0x78, 0x46, 0x41, 0x46, 0x78} // 0x7f DEL
};


// BIG CHARACTERS (numerical) ///////////////////
char const NOK_LARGENUM[13][20] = { 
   {0xC0, 0x01, 0xC0, 0x01, 0xC0, 0x01, 0xC0, 0x01, 0xC0, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} // 0x2d -
  ,{0x00, 0x00, 0x00, 0x0E, 0x00, 0x0E, 0x00, 0x0E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} // 0x2e .
  ,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} // 0x20 SPACE
  ,{0x00, 0x00, 0xFC, 0x03, 0xFE, 0x07, 0xFF, 0x0F, 0x03, 0x0C,
    0x03, 0x0C, 0xFF, 0x0F, 0xFE, 0x07, 0xFC, 0x03, 0x00, 0x00} // 0x30 0
  ,{0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x38, 0x00, 0x1C, 0x00,
    0xFF, 0x0F, 0xFF, 0x0F, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00} // 0x31 1
  ,{0x00, 0x00, 0x0C, 0x0C, 0x0E, 0x0E, 0x0F, 0x0F, 0x83, 0x0F,
    0xC3, 0x0D, 0xFF, 0x0C, 0x7E, 0x0C, 0x3C, 0x0C, 0x00, 0x00} // 0x32 2
  ,{0x00, 0x00, 0x04, 0x03, 0x0E, 0x07, 0x0F, 0x0F, 0x63, 0x0C,
    0x63, 0x0C, 0xFF, 0x0F, 0xFE, 0x07, 0x9C, 0x03, 0x00, 0x00} // 0x33 3
  ,{0x00, 0x00, 0xC0, 0x01, 0xE0, 0x01, 0xF8, 0x01, 0x9C, 0x01,
    0x8E, 0x01, 0xFF, 0x0F, 0xFF, 0x0F, 0xFF, 0x0F, 0x80, 0x01} // 0x34 4
  ,{0x00, 0x00, 0x78, 0x03, 0x7F, 0x07, 0x7F, 0x0F, 0x33, 0x0C,
    0x33, 0x0C, 0xF3, 0x0F, 0xE3, 0x07, 0xC3, 0x03, 0x00, 0x00} // 0x35 5
  ,{0x00, 0x00, 0xF8, 0x01, 0xFE, 0x07, 0xFF, 0x0F, 0x23, 0x0C,
    0x33, 0x0C, 0xF7, 0x0F, 0xE7, 0x07, 0xC6, 0x03, 0x00, 0x00} // 0x36 6
  ,{0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x0E, 0xC3, 0x0F,
    0xF3, 0x0F, 0xFB, 0x00, 0x0F, 0x00, 0x03, 0x00, 0x00, 0x00} // 0x37 7
  ,{0x00, 0x00, 0x9C, 0x03, 0xFE, 0x07, 0xFF, 0x0F, 0x63, 0x0C,
    0x63, 0x0C, 0xFF, 0x0F, 0xFE, 0x07, 0x9C, 0x03, 0x00, 0x00} // 0x38 8
  ,{0x00, 0x00, 0x3C, 0x06, 0x7E, 0x0E, 0xFF, 0x0E, 0xC3, 0x0C,
    0x43, 0x0C, 0xFF, 0x0F, 0xFE, 0x07, 0xF8, 0x01, 0x00, 0x00} // 0x39 9
};


// PIC CONFIGURATION ////////////////////////////
/**
 * Configure SPI1
 */
static void configSPI1(void) {
  SPI1CON1 = PRI_PRESCAL_1_1     | // 1:1 pri prescale
             SEC_PRESCAL_6_1     | // 6:1 sec prescale
             CLK_POL_ACTIVE_HIGH | // clock active high
             SPI_CKE_ON          | // out -> active to inactive
             SPI_MODE8_ON        | // 8-bit mode
             MASTER_ENABLE_ON;     // master mode

  //enable SPI mode
  SPI1STATbits.SPIEN = 1;  
}


// INIT /////////////////////////////////////////
/**
 * Configures PINs and SPI
 */
void CONFIG_NOK() {
  // config output pins
  CONFIG_RB6_AS_DIG_OUTPUT();
  CONFIG_RB12_AS_DIG_OUTPUT();
  CONFIG_RB13_AS_DIG_OUTPUT();
  CONFIG_RB14_AS_DIG_OUTPUT();
  
  // config SPI1
  configSPI1();
}

/**
 * Initializes the LCD
 */
void NOK_INIT() {
  NOK_MODE_DATA();
  NOK_CS_DISABLE();
  
  DELAY_US(200);
  
  NOK_RESET_ENABLE();
  DELAY_MS(1);
  NOK_RESET_DISABLE();
  
  NOK_SPI_CMD(0x21); //Extended instructions set
  NOK_SPI_CMD(0xc2); //Vop
  NOK_SPI_CMD(0x13); //Bias
  NOK_SPI_CMD(0x20); //Horizontal mode from Left to Right, X coordinate increments automatically,

  //0x22 for vertical addressing, also normal instructions set again
  //Everything ON
  NOK_SPI_CMD(0x09);
  DELAY_MS(1);

  NOK_CLEAR();
  NOK_MOVE_CURSOR(0, 0);
  NOK_UPDATE();

  // Everything OFF
  NOK_SPI_CMD(0x08);
  DELAY_MS(1);
  
  // normal mode
  NOK_SPI_CMD(0x0c);
  DELAY_MS(1);
}

/**
 * Sets all video memory to 0x00 
 */
void NOK_CLEAR() {
  uint8_t i, j;
  for (j = 0; j < 6; j++) {
    for (i = 0; i < 84; i++) {
      NOK_MEM[i][j] = 0x00;
    }
  }
}

/**
 * Dumps video memory map to LCD
 */
void NOK_UPDATE() {
  uint8_t i, j;
  NOK_CX = 0;
  NOK_CY = 0;
  for (j = 0; j < 6; j++) { //Sends memory map to LCD
    for (i = 0; i < 84; i++) {
      NOK_SPI_DATA(NOK_MEM[i][j]);
    }
  }
}

// SPI DATA /////////////////////////////////////
/**
 * Writes byte as command to LCD
 */
void NOK_SPI_CMD(uint8_t byte) {
  NOK_MODE_CMD();
  NOK_CS_ENABLE();
  NOK_SPI(byte);
  NOK_CS_DISABLE();
}

/**
 * Writes byte as data to LCD
 */
void NOK_SPI_DATA(uint8_t byte) {
  NOK_MODE_DATA();
  NOK_CS_ENABLE();
  NOK_SPI(byte);
  NOK_CS_DISABLE();
}

/**
 * Writes byte to LCD over SPI1
 */
void NOK_SPI(uint8_t byte) {
  ioMasterSPI1(byte);
}


// LCD //////////////////////////////////////////
/**
 * Sets LCD contrast
 */
void NOK_CONTRAST(uint8_t contrast) {
  NOK_SPI_CMD(0x21);            // extended commands
  NOK_SPI_CMD(0x80 | contrast); // set Vop (Contrast)
  NOK_SPI_CMD(0x20);            // display mode
}

/**
 * Toggles LCD LED
 */
void NOK_BACKLIGHT_TOGGLE() {
  NOK_LED = !NOK_LED;
}

/**
 * Sets the LCD LED on/off
 */
void NOK_BACKLIGHT(uint8_t u8_val) {
  NOK_LED = u8_val;
}


// VIDEO MEMORY: GENERAL ////////////////////////

/**
 * Inverts all pixels in video memory
 */
void NOK_INVERT() {
  uint8_t i, j;
  for (j = 0; j < 6; j++) {
    for (i = 0; i < 84; i++) {
      NOK_MEM[i][j] = ~NOK_MEM[i][j] & 0xFF;
    }
  }
}

/**
 * Sets cursor position
 */
void NOK_MOVE_CURSOR(uint8_t x, uint8_t y) {
  if (x > 83)
    x = 83;
  if (y > 5)
    y = 5;
  NOK_CX = x;
  NOK_CY = y;
}

/**
 * Moves cursor back by one char
 */
void NOK_BACKSPACE() {
  if (NOK_CX == 0) {
    NOK_CX = 78;
    if (NOK_CY == 0) {
      NOK_CY = 5;
    } else { 
      NOK_CY--;
    }
  } else {
    NOK_CX -= 6;
  }
}


// VIDEO MEMORY: CHARACTERS /////////////////////
/**
 * Inserts character at current position
 */
void NOK_CHAR(uint8_t c) {

  // enter key
  if (c == 0xd || c == '\n') {
    NOK_CY++;
    NOK_CX = 0;
    if (NOK_CY > 5) NOK_CY = 0;
    return;
  }
  
  // backspace key
  if (c == 0x8) {
    
    NOK_BACKSPACE();
    
    NOK_MEM[NOK_CX][NOK_CY] = 0x00;
    NOK_MEM[NOK_CX + 1][NOK_CY] = 0x00;
    NOK_MEM[NOK_CX + 2][NOK_CY] = 0x00;
    NOK_MEM[NOK_CX + 3][NOK_CY] = 0x00;
    NOK_MEM[NOK_CX + 4][NOK_CY] = 0x00;
    NOK_MEM[NOK_CX + 5][NOK_CY] = 0x00;
    return;
  }
  
  // verify character is valid
  if (c < 0x20) return;
  if (c > 0x7f) return;
  
  // draw character
  uint8_t u8_i;
  for (u8_i = 0; u8_i < 5; u8_i++) {
    
    // overlap, if necessary
    if (NOK_CX > 83) {
      NOK_CX = 0;
      NOK_CY++;
      if (NOK_CY > 5)
        NOK_CY = 0;
    }
    
    NOK_MEM[NOK_CX][NOK_CY] = NOK_ASCII[c - 0x20][u8_i];
    NOK_CX++;
  }
  
  NOK_MEM[NOK_CX][NOK_CY] = 0x00; //Leaves 1 byte empty to separate characters
  NOK_CX++;
}

/**
 * Inserts char array into video memory
 */
void NOK_STR(char* message) {
  for (; *message != '\0'; message++) {
    NOK_CHAR(*message);
  }
}

/**
 * Inserts numerical characters (10px by 12px) in video memory
 * (-. 0123456789)
 */
void NOK_BIG_NUM(uint8_t u8_char) {
  uint8_t u8_pos, u8_i, u8_i_max;

  if (u8_char == 32)
    u8_char = 47;
  if (u8_char == 46)
    u8_i_max = 5;
  else
    u8_i_max = 10;
  u8_pos = (u8_char - 45);

  for (u8_i = 0; u8_i < u8_i_max; u8_i++) {
    NOK_MEM[NOK_CX][NOK_CY] = NOK_LARGENUM[u8_pos][2 * u8_i];
    NOK_MEM[NOK_CX][NOK_CY + 1] = NOK_LARGENUM[u8_pos][2 * u8_i + 1];
    NOK_CX++;
  }
}


// VIDEO MEMORY: GEOMETRY ///////////////////////
/**
 * Draws a pixel in video memory
 * @param x X-coordinate
 * @param y Y-coordinate
 * @param color 1 for ON, 0 for OFF
 */
void NOK_PLOT(uint8_t x, uint8_t y, uint8_t color) {
  uint16_t offset;
  uint8_t data;

  if (x > 83) return;
  if (y > 47) return;

  offset = y - ((y / 8) * 8);
  
  if (color)
    data = (0x01 << offset);
  else {
    data = 0xFE;
    while (offset) {
      ROTATE_LEFT(&data, 1);
      --offset;
    }
  }
  
  NOK_MOVE_CURSOR(x, (y / 8));
  
  if (color) NOK_MEM[NOK_CX][NOK_CY] = NOK_MEM[NOK_CX][NOK_CY] | data;
  else NOK_MEM[NOK_CX][NOK_CY] = NOK_MEM[NOK_CX][NOK_CY] & data;
}

/**
 * Draws a line in video memory
 * @param x1 start X-coordinate
 * @param y1 start Y-coordinate
 * @param x2 end X-coordinate
 * @param y2 end Y-coordinate
 * @param color 1 for ON, 0 for OFF
 */
void NOK_LINE(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color) {
  uint16_t dy, dx;
  int8_t addx = 1, addy = 1;
  int16_t P, diff;

  uint8_t i = 0;
  dx = abs((int8_t) (x2 - x1));
  dy = abs((int8_t) (y2 - y1));

  if (x1 > x2)
    addx = -1;
  if (y1 > y2)
    addy = -1;

  if (dx >= dy) {
    dy *= 2;
    P = dy - dx;
    diff = P - dx;

    for (; i <= dx; ++i) {
      NOK_PLOT(x1, y1, color);

      if (P < 0) {
        P += dy;
        x1 += addx;
      } else {
        P += diff;
        x1 += addx;
        y1 += addy;
      }
    }
  } else {
    dx *= 2;
    P = dx - dy;
    diff = P - dy;

    for (; i <= dy; ++i) {
      NOK_PLOT(x1, y1, color);

      if (P < 0) {
        P += dx;
        y1 += addy;
      } else {
        P += diff;
        x1 += addx;
        y1 += addy;
      }
    }
  }
}

/**
 * Draws a rectangle in video memory
 * @param x1 start X-coordinate
 * @param y1 start Y-coordinate
 * @param x2 end X-coordinate
 * @param y2 end Y-coordinate
 * @param fill 1 for ON, 0 for OFF
 * @param color 1 for ON, 0 for OFF
 */
void NOK_RECT(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t fill, uint8_t color) {
  if (fill) {
    uint8_t i, xmin, xmax, ymin, ymax;

    if (x1 < x2) //Finds min and max X
    {
      xmin = x1;
      xmax = x2;
    } else {
      xmin = x2;
      xmax = x1;
    }

    if (y1 < y2) //Finds min and max Y
    {
      ymin = y1;
      ymax = y2;
    } else {
      ymin = y2;
      ymax = y1;
    }

    for (; xmin <= xmax; ++xmin) {
      for (i = ymin; i <= ymax; ++i) {
        NOK_PLOT(xmin, i, color);
      }
    }
  } else {
    NOK_LINE(x1, y1, x2, y1, color); //Draws 4 sides
    NOK_LINE(x1, y2, x2, y2, color);
    NOK_LINE(x1, y1, x1, y2, color);
    NOK_LINE(x2, y1, x2, y2, color);
  }
}

/**
 * Draws a bar in video memory
 * @param x1 start X-coordinate
 * @param y1 start Y-coordinate
 * @param x2 end X-coordinate
 * @param y2 end Y-coordinate
 * @param width width in px
 * @param color 1 for ON, 0 for OFF
 */
void NOK_BAR(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t width, uint8_t color) {
  uint8_t half_width;
  int16_t dy, dx;
  int8_t addx = 1, addy = 1, j;
  int16_t P, diff, c1, c2;

  uint8_t i = 0;
  dx = abs((int8_t) (x2 - x1));
  dy = abs((int8_t) (y2 - y1));

  half_width = width / 2;
  c1 = -(dx * x1 + dy * y1);
  c2 = -(dx * x2 + dy * y2);

  if (x1 > x2) {
    int16_t temp;
    temp = c1;
    c1 = c2;
    c2 = temp;
    addx = -1;
  }
  if (y1 > y2) {
    int16_t temp;
    temp = c1;
    c1 = c2;
    c2 = temp;
    addy = -1;
  }

  if (dx >= dy) {
    P = 2 * dy - dx;
    diff = P - dx;

    for (i = 0; i <= dx; ++i) {
      for (j = -half_width; j < half_width + width % 2; ++j) {
        NOK_PLOT(x1, y1 + j, color);
      }
      if (P < 0) {
        P += 2 * dy;
        x1 += addx;
      } else {
        P += diff;
        x1 += addx;
        y1 += addy;
      }
    }
  } else {
    P = 2 * dx - dy;
    diff = P - dy;

    for (i = 0; i <= dy; ++i) {
      if (P < 0) {
        P += 2 * dx;
        y1 += addy;
      } else {
        P += diff;
        x1 += addx;
        y1 += addy;
      }
      for (j = -half_width; j < half_width + width % 2; ++j) {
        NOK_PLOT(x1 + j, y1, color);
      }
    }
  }
}

/**
 * Draws a circle in video memory
 * @param x center X-coordinate
 * @param y center Y-coordinate
 * @param radius radius in px
 * @param fill 1 for ON, 0 for OFF
 * @param color 1 for ON, 0 for OFF
 */
void NOK_CIRCLE(uint8_t x, uint8_t y, uint8_t radius, uint8_t fill, uint8_t color) {
  int8_t a, b, P;

  a = 0;
  b = radius;
  P = 1 - radius;

  do {
    if (fill) {
      NOK_LINE(x - a, y + b, x + a, y + b, color);
      NOK_LINE(x - a, y - b, x + a, y - b, color);
      NOK_LINE(x - b, y + a, x + b, y + a, color);
      NOK_LINE(x - b, y - a, x + b, y - a, color);
    } else {
      NOK_PLOT(a + x, b + y, color);
      NOK_PLOT(b + x, a + y, color);
      NOK_PLOT(x - a, b + y, color);
      NOK_PLOT(x - b, a + y, color);
      NOK_PLOT(b + x, y - a, color);
      NOK_PLOT(a + x, y - b, color);
      NOK_PLOT(x - a, y - b, color);
      NOK_PLOT(x - b, y - a, color);
    }

    if (P < 0)
      P += 3 + 2 * a++;
    else
      P += 5 + 2 * (a++ - b--);
  } while (a <= b);
}

/**
 * Draws a bitmap on the entire screen
 */
void NOK_BITMAP(char *bitmap) {
  int i, j, p;
  p = 0;
  for (j = 0; j < 6; j++) {
    for (i = 0; i < 84; i++) {
      NOK_MEM[i][j] = bitmap[p++];
    }
  }
}


// UTILITY //////////////////////////////////////
/**
 * [ Utility Function ]
 * Rotates bits to the left
 */
static void ROTATE_LEFT(uint8_t* u8_data, uint8_t u8_shift) {
  if ((u8_shift &= sizeof (*u8_data)*8 - 1) == 0) return;
  *u8_data = (*u8_data << u8_shift) | (*u8_data >> (sizeof (*u8_data)*8 - u8_shift));
}