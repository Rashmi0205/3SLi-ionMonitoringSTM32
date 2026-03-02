/*
 * ssd1306.h
 *
 *  Created on: Feb 27, 2026
 *      Author: HP
 */

#ifndef __SSD1306_H
#define __SSD1306_H

#include "stm32f1xx_hal.h"

/* OLED size */
#define SSD1306_WIDTH   128
#define SSD1306_HEIGHT  64

/* 7-bit I2C address */
#define SSD1306_I2C_ADDR  0x3C

void SSD1306_Init(I2C_HandleTypeDef *hi2c);
void SSD1306_UpdateScreen(void);
void SSD1306_Fill(uint8_t color);
void SSD1306_SetCursor(uint8_t x, uint8_t y);
void SSD1306_WriteString(char* str);

#endif
