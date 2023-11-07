
#include "KEYPAD.h"

static char key = NO_KEY;
static u8 PressedFlag[4][4] = {0};

// pull up / normal open button
static void KEYPAD_IsPressed (u8 outPin, u8 inputPin, u8 row, u8 col)
{
	DIO_WritePin(outPin, LOW);
	
	if (DIO_ReadPin(inputPin) == 0)
	{
		if (PressedFlag[row][col] == 0)
		{
			key = KEYPAD[row][col];
			PressedFlag[row][col] = 1;
		}
	}
	else
	{
		PressedFlag[row][col] = 0;
	}
	DIO_WritePin(outPin, HIGH);
}

char KEYPAD_GetKey ()
{
	DIO_WritePin(_1, HIGH);
	DIO_WritePin(_2, HIGH);
	DIO_WritePin(_3, HIGH);
	DIO_WritePin(_4, HIGH);
	
	key = NO_KEY;
	
	KEYPAD_IsPressed (_1, A, 0, 0);
	KEYPAD_IsPressed (_2, A, 0, 1);
	KEYPAD_IsPressed (_3, A, 0, 2);
	KEYPAD_IsPressed (_4, A, 0, 3);
	
	KEYPAD_IsPressed (_1, B, 1, 0);
	KEYPAD_IsPressed (_2, B, 1, 1);
	KEYPAD_IsPressed (_3, B, 1, 2);
	KEYPAD_IsPressed (_4, B, 1, 3);
	
	KEYPAD_IsPressed (_1, C, 2, 0);
	KEYPAD_IsPressed (_2, C, 2, 1);
	KEYPAD_IsPressed (_3, C, 2, 2);
	KEYPAD_IsPressed (_4, C, 2, 3);
	
	KEYPAD_IsPressed (_1, D, 3, 0);
	KEYPAD_IsPressed (_2, D, 3, 1);
	KEYPAD_IsPressed (_3, D, 3, 2);
	KEYPAD_IsPressed (_4, D, 3, 3);
	
	
	return key;
}

