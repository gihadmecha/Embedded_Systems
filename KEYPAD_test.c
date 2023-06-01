
#include "DIO_interface.h"
#include "LCD.h"
#include "KEYPAD.h"

int main()
{
	DIO_Init();
	LCD_Init();
	
	char key = NO_KEY;
	while (1)
	{
		key = KEYPAD_GetKey();
		if (key != NO_KEY)
		{
			LCD_WriteChar(key);
		}
		
	}
}