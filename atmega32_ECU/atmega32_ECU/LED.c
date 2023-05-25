
#include "LED.h"

void LED1_Init()
{
	SET_BIT (LED1_PORT_DDR, LED1_PIN);
}

void LED1_On()
{
	SET_BIT (LED1_PORT_PORT, LED1_PIN);
}

void LED1_Off()
{
	CLR_BIT (LED1_PORT_PORT, LED1_PIN);
}