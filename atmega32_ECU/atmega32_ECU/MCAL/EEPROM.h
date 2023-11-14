/*
 * EEPROM.h
 *
 * Created: 11/13/2023 4:58:31 PM
 *  Author: Gihad
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"

void EEPROM_write(unsigned int uiAddress, unsigned char ucData);
unsigned char EEPROM_read(unsigned int uiAddress);


#endif /* EEPROM_H_ */