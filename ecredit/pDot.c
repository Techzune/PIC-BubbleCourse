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
 * Player Dot Data & Physics
 **/

#include "pDot.h"

void player_dot_init(struct player_dot* pDot, int x, int y, float dx, float dy, int radius) {
  pDot->x = x;
  pDot->y = y;
  pDot->dx = dx;
  pDot->dy = dy;
  pDot->radius = radius;
}

#define GRAVITY 0.85;

void player_dot_update(struct player_dot* pDot, int goUp) {
  
  if (goUp == 1) {
    // if told to go up, negate gravity
    if (pDot->dy > 0) pDot->dy = 0;
    pDot->dy = -2;
  } else {
    // otherwise, gravity
    pDot->dy += GRAVITY;
  }

  // don't allow to go past 0
  if (pDot->y - pDot->radius < 0) {
    pDot->dy = GRAVITY;
  }
  
  // if too far down, stop
  if (pDot->y + pDot->radius > LCD_MAX_Y - 1) {
    pDot->dy = 0;
  }
  
  // don't allow to travel past screen
  if (pDot->x + pDot->radius > LCD_MAX_X - 1 || pDot->x - pDot->radius < 1) {
    pDot->dx = 0;
  }
  
  // append changes
  pDot->y += pDot->dy;
  pDot->x += pDot->dx;
  
  // prevent going past screen
  if (pDot->y + pDot->radius > LCD_MAX_Y) pDot->y = LCD_MAX_Y - pDot->radius;
  if (pDot->x + pDot->radius > LCD_MAX_X) pDot->x = LCD_MAX_X - pDot->radius;
  if (pDot->x - pDot->radius < 0) pDot->x = pDot->radius;
}
