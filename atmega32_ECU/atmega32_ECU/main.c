
#include "ultrasonic.h"
#include "LCD.h"

int main ()
{
	ultrasonic_Init ();
	LCD_Init();
	
	while (1)
	{
		LCD_GoTo(1, 0);
		LCD_WriteNumber_4Digit ((u16)ultrasonic ());
		//LCD_WriteNumber (distance);
		LCD_WriteString(" ");
		LCD_WriteString("cm");
	}
}

