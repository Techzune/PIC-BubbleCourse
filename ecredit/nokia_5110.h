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

#ifndef NOKIA_5110_H
#define NOKIA_5110_H

#include "pic24_all.h"
#include <stdlib.h>
#include <stdio.h>


// PIN CONFIGURATION
#define NOK_SCE  _LATB14   // NOKIA 5110 SCE
#define NOK_RST  _LATB13   // NOKIA 5110 RST
#define NOK_DC   _LATB12   // NOKIA 5110 D/C
#define NOK_LED  _LATB6    // NOKIA 5110 LED

#define NOK_MODE_CMD()      NOK_DC  = 0;
#define NOK_MODE_DATA()     NOK_DC  = 1;
#define NOK_CS_ENABLE()     NOK_SCE = 0;
#define NOK_CS_DISABLE()    NOK_SCE = 1;
#define NOK_RESET_ENABLE()  NOK_RST = 0;
#define NOK_RESET_DISABLE() NOK_RST = 1;


// INIT
void CONFIG_NOK();
void NOK_INIT();
void NOK_CLEAR();
void NOK_UPDATE();


// SPI DATA
void NOK_SPI_CMD(uint8_t byte);
void NOK_SPI_DATA(uint8_t byte);
void NOK_SPI(uint8_t byte);


// LCD
void NOK_CONTRAST(uint8_t contrast);
void NOK_BACKLIGHT_TOGGLE();
void NOK_BACKLIGHT(uint8_t u8_val);


// VIDEO MEMORY: GENERAL
void NOK_INVERT();
void NOK_MOVE_CURSOR(uint8_t x, uint8_t y);
void NOK_BACKSPACE();


// VIDEO MEMORY: CHARACTERS
void NOK_CHAR(uint8_t c);
void NOK_STR(char* message);
void NOK_BIG_NUM(uint8_t u8_char);


// VIDEO MEMORY: GEOMETRY
void NOK_PLOT(uint8_t x, uint8_t y, uint8_t color);
void NOK_LINE(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color);
void NOK_RECT(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t fill, uint8_t color);
void NOK_BAR(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t width, uint8_t color);
void NOK_CIRCLE(uint8_t x, uint8_t y, uint8_t radius, uint8_t fill, uint8_t color);
void NOK_EMPTY_CIRCLE(uint8_t x0, uint8_t y0, uint8_t radius, uint8_t color, uint8_t thickness);
void NOK_BITMAP(char *bitmap);

#endif