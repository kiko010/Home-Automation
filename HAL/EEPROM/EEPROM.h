/*
 * EEPROM.h
 *
 *  Created on: Oct 23, 2016
 *      Author: ahmed
 */

#ifndef EEPROM_H_
#define EEPROM_H_
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "c:\users\kiko0\Documents\Atmel Studio\7.0\Home Automation\Home Automation\HAL\DIO.h"
#include "c:\users\kiko0\Documents\Atmel Studio\7.0\Home Automation\Home Automation\HAL\PLATFORM_TYPES.h"

void EEPROM_write(uint16 Address,uint8 Data);
uint8 EEPROM_read(uint16 Address);

#endif /* EEPROM_H_ */
