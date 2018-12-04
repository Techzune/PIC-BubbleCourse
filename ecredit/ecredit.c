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
 * MAIN PROGRAM
 **/

#include "pic24_all.h"
#include <stdio.h>
#include "eeprom.h"
#include "nokia_5110.h"
#include "pDot.h"
#include "entity_gap.h"

// FILE SPECIFIC FUNCTIONS
static void CONFIG_PB();
static void animation_hello();
static void draw_and_update_gap(struct entity_gap*);
static uint8_t check_for_collision(struct player_dot *pDot, struct entity_gap *gaps, uint8_t u8_cnt);
static void DELAY_MS_PB(uint16_t ms);

// FILE SPECIFIC VARIABLES
static uint8_t u8_bootrun = 1;
static uint8_t u8_running = 1;
static uint8_t u8_player_score = 0;
static uint8_t u8_ingap = 99;
static uint8_t u8_high_score = 0;

/**
 * Enables PB pins (RB3)
 */
#define PB_PRESSED() _RB3 == 0
static void CONFIG_PB()  {
  CONFIG_RB3_AS_DIG_INPUT();
  ENABLE_RB3_PULLUP();
  DELAY_US(1);
}

/**
 * Delays for MS but allows PB to break
 */
static void DELAY_MS_PB(uint16_t ms) {
  // if the button is on, ignore until release
  uint8_t waiting;
  
  while (--ms > 0) {
    // update waiting
    if (waiting) waiting = (!PB_PRESSED());
    
    // if button pressed and not waiting
    if (!PB_PRESSED() && !waiting) {
      break;
    }
    DELAY_MS(1);
  }
}

/**
 * Main Program
 * @return 
 */
int main(void) {  
  // init general
  configBasic(HELLO_MSG);
  CONFIG_EEPROM();
  
  // read the high score from EEPROM
  DELAY_MS(20);
  u8_high_score = EEPROM_READ_SPECIFIC(0x1337);
  DELAY_MS(20);
  I2C1CONbits.I2CEN = 0;
  DELAY_MS(20);
  
  init:
  CONFIG_NOK();
  CONFIG_PB();
  
  // randomizer seed
  srand(20);

  // init screen
  NOK_BACKLIGHT(1);
  NOK_INIT();
  animation_hello();
  NOK_CLEAR();
  // floor line
  NOK_LINE(0, 48, 84, 48, 1);
  
  // store and init the player dot
  struct player_dot pDot;
  player_dot_init(&pDot, 6, 20, 0, 0, 2);
  NOK_CIRCLE(pDot.x, pDot.y, pDot.radius, 1, 1);
  
  // store the gaps for traveling through
  struct entity_gap gaps[5];
  
  // times the release of gaps
  uint8_t release_timer;
  release_timer = 35;
  
  // counts the number of gaps
  // keeps track of open indexes
  uint8_t count, idx;
  count = 0;
  idx = 0;
  
  // generic count for looping
  uint8_t u8_i;
  
  // convert score to string
  char score[6];
  
  // ask if ready
  NOK_MOVE_CURSOR(0, 0);
  NOK_STR("READY?\n\n\n\nPress button\nto fly!");
  NOK_UPDATE();
  
  // wait for button press
  while (!PB_PRESSED()) doHeartbeat();
  
  // game loop
  while (u8_running) {
    // clear and draw floor
    NOK_CLEAR();
    NOK_LINE(0, 47, 83, 47, 1);
    
    // draw and update gaps
    for (u8_i = 0; u8_i < count; u8_i++) {
      draw_and_update_gap(&gaps[u8_i]);
      
      // if out, open for overwrite
      if (gaps[u8_i].x < -6) idx = u8_i;
    }
    
    // if not full, make gaps
    if (count < 4) {
      
      // check if time to release new gap
      if (release_timer >= 20) {
        // set gap position
        entity_gap_init_randy(&gaps[idx], 84);
        
        // clear the timer
        release_timer = 0;
        
        // increment
        count = max(idx, count);
        idx++;
      } else {
        // increment time
        release_timer++;
      }
      
    }
    
    // draw and update the player dot
    NOK_CIRCLE(pDot.x, pDot.y, pDot.radius, 1, 1);
    
    // convert score to string and show
    sprintf(score, "%d", u8_player_score); 
    NOK_MOVE_CURSOR(42-5, 0);
    NOK_STR(score);
    
    // update screen
    NOK_UPDATE();
    
    // check for collision with gap or floor
    if (check_for_collision(&pDot, gaps, count) ||
        (pDot.y >= 43 && pDot.dy == 0)) {
      
      // white dot
      NOK_CIRCLE(pDot.x, pDot.y, pDot.radius, 1, 0);
      NOK_CIRCLE(pDot.x, pDot.y, pDot.radius, 0, 1);
      // GAME OVER!
      u8_running = 0;
    }
    
    // update player's physics
    player_dot_update(&pDot, PB_PRESSED());
    
    // delay
    DELAY_MS(80);
  }
  
  // flash the LCD back light
  for (u8_i = 0; u8_i < 4; u8_i++) {
    NOK_BACKLIGHT_TOGGLE();
    DELAY_MS(50);
  }
  
  // show "game over"
  NOK_MOVE_CURSOR(6, 2);
  NOK_STR("game over :(");
  
  // save the high score
  if (u8_player_score > u8_high_score) {
    NOK_STR("\nNEW HIGH SCORE");
    NOK_UPDATE();
    DELAY_MS_PB(5000);
    
    SPI1STATbits.SPIEN = 0;
    DELAY_MS(20);
    u8_high_score = u8_player_score;
    I2C1CONbits.I2CEN = 1;
    EEPROM_WRITE_SPECIFIC(0x1337, u8_high_score);
    DELAY_MS(20);
    I2C1CONbits.I2CEN = 0;
  } else {
    NOK_UPDATE();
    DELAY_MS_PB(5000);
  }
  
  // reset the score and running bit
  u8_player_score = 0;
  u8_running = 1; 
  goto init;
}

/**
 * Title animation
 * Shows title, if first boot
 * Shows high score
 */
static void animation_hello() {
  NOK_CLEAR();
  uint8_t u8_i;
  
  // fill the screen up
  for (u8_i = 0; u8_i < 48; u8_i++) {
    NOK_LINE(0, u8_i, 84, u8_i, 1);
    NOK_UPDATE();
    DELAY_MS(4);
  }
  
  // circle explosion from center
  for (u8_i = 1; u8_i < 84; u8_i++) {
    NOK_CIRCLE(84/2, 48/2, u8_i, 0, 0);
    NOK_UPDATE();
    DELAY_MS(4);
  }
  
  // show title if first boot
  if (u8_bootrun == 1) {
    u8_bootrun = 0;
    
    NOK_CLEAR();
    NOK_MOVE_CURSOR(0, 0);
    NOK_STR("BUBBLE COURSE\n"
            "v1.0\n\n"
            "BY:\n"
            "Jordan S.\n"
            "Elisabeth A.");  
    NOK_UPDATE();
    DELAY_MS_PB(3000);

    NOK_CLEAR();
    NOK_MOVE_CURSOR(0, 0);
    NOK_STR("inspired by\n\n"
            "FLAPPY BIRD\n\n\n"
            "R.I.P. 2014");  
    NOK_UPDATE();
    DELAY_MS_PB(3000);
  }
  
  // convert high score to string
  char score[6];
  sprintf(score, "%d", u8_high_score);
  
  // display high score
  NOK_CLEAR();
  NOK_MOVE_CURSOR(0, 0);
  NOK_STR("highest score:\n");
  NOK_STR(score);
  NOK_UPDATE();
  DELAY_MS_PB(3000);
}

/**
 * Draws gap entity and calls update function
 */
static void draw_and_update_gap(struct entity_gap *entity) {
  // store the x, y of gap
  int8_t x, y;
  x = entity->x;
  y = entity->y;
  
  // check if in range to draw
  if (x > -6 && x < 84) {
    // draw full rectangle (BLACK)
    NOK_RECT(max(min(x, 84), 0), 0, max(min(x+6, 84), 0), 48  , 1, 1);
    
    // draw gap (WHITE)
    NOK_RECT(max(min(x, 84), 0), y, max(min(x+6, 84), 0), y+15, 1, 0);
  }
  
  // update
  entity_gap_update(entity);
}

/**
 * Checks for collision of player_dot with any entity_gaps
 * @param pDot player_dot
 * @param gaps array of entity_gaps
 * @param u8_cnt number of gaps
 * @return 1, if collision; otherwise, 0
 */
static uint8_t check_for_collision(struct player_dot *pDot, struct entity_gap *gaps, uint8_t u8_cnt) {
  uint8_t u8_i, px, py, pr;
  struct entity_gap cur_gap;
  
  // store the x,y,r of player
  px = pDot->x;
  py = pDot->y;
  pr = pDot->radius;
  
  // loop through all gaps
  for (u8_i = 0; u8_i < u8_cnt; u8_i++) {
    // get current gap
    cur_gap = gaps[u8_i];
    
    // if player is in x of gap
    if (cur_gap.x <= px - pr && cur_gap.x + 6 >= px + pr) {
      // if player is above or below gap
      if (cur_gap.y > py - pr || cur_gap.y + 15 < py + pr) {
        // COLLISION!
        return 1;
      } else {
        // note in gap
        u8_ingap = u8_i;
      }
    } else {
      // exited gap safely
      if (u8_ingap == u8_i) {
        // up the score
        u8_player_score++;
        u8_ingap = 99;
      } 
    }
  }
  
  // no collisions
  return 0;
}