
#include "DIO_interface.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "EEPROM.h"

void EEPROM_UARTinterrupt ();

int main ()
{
	DIO_Init();
	LCD_Init ();
	
	u8 key = NULL;
	u8 changeFlag = 0;
	u8 data = EEPROM_read(0);
	
	while (1)
	{
		key = KEYPAD_GetKey ();
		
		if (key == 'C')
		{
			changeFlag = 1;
		}
		
		if (changeFlag == 1)
		{
			if (key != NULL && key != 'C')
			{
				data = key;
				EEPROM_write (0, key);
				
				changeFlag = 0;
			}
		}
		
		LCD_GoTo(0, 0);
		LCD_WriteChar(data);
	}
}