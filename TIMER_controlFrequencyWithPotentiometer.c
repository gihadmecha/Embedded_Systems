
#include "DIO_interface.h"
#include "ADC.h"
#include "TIMER0_SERVICES.h"
#include "POTONTIOMETER.h"
#include "LCD.h"

int main ()
{
	DIO_Init();
	ADC_Init( ADC_VCC, ADC_PRESCALER_64);
	TIMER0_Init(TIMER0_PRESCALER_8, TIMER0_CTC, TIMER0_OC0_TOGGLE_ON_COMPARE_MATCH);
	LCD_Init();
	
	ADC_Enable();
	
	u8 pot_read = 0;
	
	while (1)
	{
		pot_read = POTONTIOMETER();
		TIMER0_OCR0_WRITE (255.0 * ((100.0 - pot_read) / 100.0));
		LCD_GoTo (0, 0);
		LCD_WriteNumber_4Digit((int)pot_read);
		LCD_GoTo(1, 0);
		LCD_WriteNumber_4Digit((int)TIMER0_OCR0_READ());
	}
}