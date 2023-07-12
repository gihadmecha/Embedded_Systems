
#include "DIO_interface.h"
#include "TIMER1.h"
#include "ADC.h"
#include "LCD.h"
#include "POTONTIOMETER.h"
#include "SERVO.h"

int main ()
{
	DIO_Init();
	TIMER1_Init(TIMER1_PRESCALER_8, TIMER1_FAST_PWM_ICR1_TOP, TIMER1_OC1_DISCONNECTED, TIMER1_OC1_CLEAR_ON_COMPARE_MATCH);
	ADC_Init(ADC_VCC, ADC_PRESCALER_64);
	LCD_Init();
	
	ADC_Enable();
	
	//u16 top = 1.0/(50*0.000001);
	//u16 compareMatch = 0;
	//u8 pot_read = 0;
	
	while (1)
	{
		////50 HZ
		//TIMER1_ICR1_WRITE (top);
		//
		////pot_read = POTONTIOMETER1();
		//
		//compareMatch = 1000 + (1000 * (pot_read / 100.0));
		//
		//TIMER1_OCR1B_WRITE (compareMatch);
		
		SERVO_setAngle (90);
		
		//LCD_GoTo(0, 0);
		//LCD_WriteNumber_4Digit(pot_read);
		//
		//LCD_GoTo(1, 0);
		//LCD_WriteNumber_4Digit(compareMatch);
		//
		//LCD_GoTo(1, 6);
		//LCD_WriteNumber(top);
	}
}