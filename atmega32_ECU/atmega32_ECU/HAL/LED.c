

#include "LED.h"


extern void LED1_On()
{
	DIO_WritePin(LED1, HIGH);
}

extern void LED1_Off()
{
	DIO_WritePin(LED1, LOW);
}

extern void LED1_Toggle ()
{
	DIO_TogglePin(LED1);
}

extern led_status_type LED1_Read ()
{
	return DIO_ReadPortRegister(LED1);
}
