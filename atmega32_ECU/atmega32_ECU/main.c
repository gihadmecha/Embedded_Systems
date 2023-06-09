

#include "DIO_interface.h"
#include "ADC.h"
#include "LCD.h"
#include "POTONTIOMETER.h"
#include "LM35.h"

int main()
{
	DIO_Init();
	ADC_Init(ADC_VCC, ADC_PRESCALER_64);
	ADC_Enable();
	LCD_Init ();
	
	u16 adc;
	u8 count = 0;
	while (1)
	{
		LCD_GoTo(0, 0);
		LCD_WriteNumber(count);
		count++;
		if (count == 10)
		{
			count = 0;
		}
		
		//LCD_WriteNumber_4Digit (ADC_Read_Polling(CHANNEL_0));
	
		
		LCD_GoTo(1, 0);
		ADC_StartConversion(CHANNEL_7);
		if (ADC_Read(&adc))
		{
			LCD_WriteNumber_4Digit(adc);
		}
		
		LCD_GoTo(1, 6);
		LCD_WriteNumber_4Digit(POTONTIOMETER());
		
		LCD_GoTo(1, 11);
		LCD_WriteNumber((s32)ADC_GetVolt (CHANNEL_7));
		LCD_WriteString("    ");
		
		LCD_GoTo(0, 6);
		LCD_WriteNumber(LM35()/10);
		LCD_WriteChar('.');
		LCD_WriteNumber(LM35()%10);
		
		LCD_GoTo(0, 11);
		LCD_WriteNumber(LM35());
		
		_delay_ms(600);
	}
}