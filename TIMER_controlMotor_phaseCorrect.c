
#include "DIO_interface.h"
#include "TIMER1.h"
#include "MOTOR.h"
#include "POTONTIOMETER.h"
#include "LCD.h"

int main ()
{
	DIO_Init();
	TIMER1_Init(TIMER1_PRESCALER_8, TIMER1_PHASE_CORRECT_PWM_ICR1_TOP, TIMER1_OC1_SET_ON_COMPARE_MATCH, TIMER1_OC1_DISCONNECTED);
	ADC_Init(ADC_VCC, ADC_PRESCALER_64);
	LCD_Init();
	
	ADC_Enable();
	
	u32 frequency = 50;
	u32 top = 0;
	u32 compareMatch = 0;
	u8 pot_read = 0;
	
	while (1)
	{
		LCD_GoTo(0, 0);
		LCD_WriteNumber_4Digit(pot_read);
		
		LCD_GoTo(1, 0);
		LCD_WriteNumber_4Digit(compareMatch);
		
		LCD_GoTo(1, 6);
		LCD_WriteNumber(top);
		
		// 50 HZ
		top = 1.0/(2*frequency*0.000001);
		
		pot_read = POTONTIOMETER1();
		compareMatch = (top * (100.0 - pot_read)) / 100.0;
		TIMER1_ICR1_WRITE (top);
		TIMER1_OCR1A_WRITE(compareMatch);
		
		MOTOR2_Forward();
	}
}