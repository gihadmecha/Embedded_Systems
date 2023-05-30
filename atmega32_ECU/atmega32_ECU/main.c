
#include "DIO_interface.h"
#include "LCD.h"

int main()
{
	DIO_Init();
	LCD_Init();
	
	LCD_WriteChar('A');
	LCD_WriteChar('B');
	LCD_WriteChar('C');
	LCD_WriteChar('D');
	
	_delay_ms(1000);
	LCD_GoToClear(0, 1);
	_delay_ms(1000);
	LCD_Clear();
	
	LCD_WriteString("Ahmed");
	
	LCD_GoTo(0, 6);
	LCD_WriteBinary(9);
	LCD_GoTo(1, 13);
	LCD_WriteNumber(-1540);
	LCD_GoTo(0, 13);
	LCD_WriteNumber_4Digit(45);
	LCD_GoTo(1, 6);
	LCD_WriteHex(0x1F);
	LCD_GoTo(1, 0);
	LCD_GoToWritString(1, 0, "alaa");

	
	for (int countLine = 0; countLine <= 1; countLine++)
	{
		for (int countColumn = 0; countColumn <= 19; countColumn++)
		{
			LCD_GoTo(countLine, countColumn);
			_delay_ms(1000);
		}
	}
}