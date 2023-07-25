
#include "BUTTON.h"

void BUTTON1_IfPressed_PeriodicCheck (void(*FUNC_PTR)(void))
{
	static u8 pressedFlag = 0;
	
	if (DIO_ReadPin(BUTTON1) == 0)
	{
		if (pressedFlag == 0)
		{
			pressedFlag = 1;
			FUNC_PTR();
		}
	}
	else
	{
		pressedFlag = 0;
	}
}

void BUTTON2_IfPressed_PeriodicCheck (void(*FUNC_PTR)(void))
{
	static u8 pressedFlag = 0;
	
	if (DIO_ReadPin(BUTTON2) == 0)
	{
		if (pressedFlag == 0)
		{
			pressedFlag = 1;
			FUNC_PTR();
		}
	}
	else
	{
		pressedFlag = 0;
	}
}

void BUTTON_mode_IfPressed_PeriodicCheck (void(*FUNC_PTR)(void))
{
	static u8 pressedFlag = 0;
	
	if (DIO_ReadPin(BUTTON_mode) == 0)
	{
		if (pressedFlag == 0)
		{
			pressedFlag = 1;
			FUNC_PTR();
		}
	}
	else
	{
		pressedFlag = 0;
	}
}
