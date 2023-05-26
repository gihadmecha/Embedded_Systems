
#include "BUTTON.h"



void BUTTON1_Init ()
{
	CLR_BIT(BUTTON1_PORT_DDR, BUTTON1_PIN);
	
	//PULL UP
	SET_BIT(BUTTON1_PORT_PORT, BUTTON1_PIN);
}

void BUTTON1 (void (*fun_ptr)(void))
{
	static u8 pressedCounter = 0;
	if (READ_BIT(BUTTON1_PORT_PIN, BUTTON1_PIN) == PULL_UP_PRESSED)
	{
		if (pressedCounter == 0)
		{
			pressedCounter = 1;
			fun_ptr();
		}
	}
	else
	{
		pressedCounter = 0;
	}
}