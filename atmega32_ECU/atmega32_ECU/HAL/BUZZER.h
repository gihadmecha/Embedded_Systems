

#ifndef BUZZER_H_
#define BUZZER_H_

#include "DIO_interface.h"
#include "BUZZER_Lcfg.h"

typedef	enum {
	BUZZER_OFF,
	BUZZER_ON
}buzzer_status_type;

extern void BUZZER_On();
extern void BUZZER_Off();
extern void BUZZER_Toggle();
extern buzzer_status_type BUZZER_Read ();



#endif /* BUZZER_H_ */