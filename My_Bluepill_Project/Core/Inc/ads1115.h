/*
 * ads1115.h
 *
 *  Created on: Feb 27, 2026
 *      Author: HP
 */
#ifndef ADS1115_H
#define ADS1115_H

#include "stm32f1xx_hal.h"

#define ADS1115_ADDRESS  (0x48 << 1)

void ADS1115_Init(I2C_HandleTypeDef *hi2c);
int16_t ADS1115_ReadADC(uint8_t channel);

#endif
