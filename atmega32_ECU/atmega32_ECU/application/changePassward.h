


#ifndef CHANGEPASSWARD_H_
#define CHANGEPASSWARD_H_

#include "DIO_interface.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "EEPROM.h"

#include "changePassward_Lcfg.h"

extern void changePassward_Init (u8 passward[], u8 passwardSize);
extern u8 changePassward_Run (u8 passward[], u8 passwardSize);



#endif /* CHANGEPASSWARD_H_ */