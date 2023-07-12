
#include "DIO_interface.h"
#include "ADC.h"
#include "TIMER1.h"
#include "POTONTIOMETER.h"

void compareMatch1BFuntion ();
void overflowInterruptFunction ();

int main ()
{
	DIO_Init();
	ADC_Init( ADC_VCC, ADC_PRESCALER_64);
	TIMER1_Init(TIMER1_PRESCALER_8, TIMER1_FAST_PWM_ICR1_TOP, TIMER1_OC1_DISCONNECTED, TIMER1_OC1_CLEAR_ON_COMPARE_MATCH);
	LCD_Init();
	
	ADC_Enable();
	
	SEI();
	TIMER1_OCM1B_interruptEnable();
	TIMER1_overflow_interruptEnable();
	
	TIMER1_compareMatch1BInterruptSet(compareMatch1BFuntion);
	TIMER1_overflowInterruptSet (overflowInterruptFunction);
	
	u8 frequency_pot = 0;
	u8 dutyCycle_pot = 0;
	u16 top = 0;
	u16 compareMatch = 0;
	
	while (1)
	{
		frequency_pot = POTONTIOMETER1();
		dutyCycle_pot = POTONTIOMETER2();
		
		LCD_GoTo(0, 0);
		LCD_WriteNumber_4Digit(frequency_pot);
		
		LCD_GoTo(0, 6);
		LCD_WriteNumber_4Digit(dutyCycle_pot);
		
		top = TIMER1_NO_OF_TICKS * ((100.0 - frequency_pot)/ 100.0);
		compareMatch = top * (dutyCycle_pot/ 100.0);
		
		TIMER1_ICR1_WRITE (top);
		TIMER1_OCR1B_WRITE(compareMatch);
	}
}

void compareMatch1BFuntion ()
{
	DIO_WritePin(PINB0, LOW);
}

void overflowInterruptFunction ()
{
	DIO_WritePin(PINB0, HIGH);
}