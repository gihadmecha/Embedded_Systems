

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


extern void LED2_On()
{
	DIO_WritePin(LED2, HIGH);
}

extern void LED2_Off()
{
	DIO_WritePin(LED2, LOW);
}

extern void LED2_Toggle ()
{
	DIO_TogglePin(LED2);
}

extern led_status_type LED2_Read ()
{
	return DIO_ReadPortRegister(LED2);
}


extern void LED3_On()
{
	DIO_WritePin(LED3, HIGH);
}

extern void LED3_Off()
{
	DIO_WritePin(LED3, LOW);
}

extern void LED3_Toggle ()
{
	DIO_TogglePin(LED3);
}

extern led_status_type LED3_Read ()
{
	return DIO_ReadPortRegister(LED3);
}