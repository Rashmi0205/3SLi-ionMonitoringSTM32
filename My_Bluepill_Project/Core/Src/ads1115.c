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

void ADS1115_Init(void)
{
   // your init code
}

uint16_t ADS1115_ReadADC(uint8_t channel)
{
   // your read code
}

#endif
