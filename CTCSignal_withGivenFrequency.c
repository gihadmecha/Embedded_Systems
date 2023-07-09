
#include "DIO_interface.h"
#include "TIMER0.h"
#include "TIMER0_SERVICES.h"
#include "LCD.h"

int main ()
{
	DIO_Init();
	TIMER0_Init(TIMER0_PRESCALER_8, TIMER0_CTC, TIMER0_OC0_TOGGLE_ON_COMPARE_MATCH);
	LCD_Init();
	
	LCD_GoTo(0,0);
	LCD_WriteNumber(TIMER0_generatePWM_CTC_50dutyCycle (5000));
	
	LCD_GoTo(1,0);
	LCD_WriteNumber(TIMER0_OCR0_READ());
	
	while (1)
	{
		
	}
}