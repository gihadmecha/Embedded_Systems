


#ifndef LED_H_
#define LED_H_

#include "LED_Lcfg.h"
#include "DIO_interface.h"


typedef	enum {
	LED_OFF,
	LED_ON
	}led_status_type;

extern void LED1_On();
extern void LED1_Off();
extern void LED1_Toggle();
extern led_status_type LED1_Read ();


#endif /* LED_H_ */