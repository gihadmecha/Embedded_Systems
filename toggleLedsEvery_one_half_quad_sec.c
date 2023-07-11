

#include "DIO_interface.h"
#include "LCD.h"
#include "LED.h"
#include "TIMER0.h"

void timer0OverflowInterrupt();

int main ()
{
	DIO_Init();
	LCD_Init();
	TIMER0_Init(TIMER0_PRESCALER_8, TIMER0_NORMAL, TIMER0_OC0_DISCONNECTED);
	
	TIMER0_TCNT0_WRITE (112);
	
	SEI();
	TIMER0_overflow_interruptEnable();
	TIMER0_overflowInterruptSet(timer0OverflowInterrupt);
	
	u8 counter = 0;
	
	while (1)
	{
		LCD_GoTo(1, 0);
		LCD_WriteNumber(counter);
		_delay_ms(200);
		counter++;
		if (counter == 10)
		{
			counter = 0;
		}
	}
}

void timer0OverflowInterrupt()
{
	static u16 timer0OverflowCounter = 0;
	static u8 quadSecCounter = 0;
	timer0OverflowCounter++;
	
	if (timer0OverflowCounter == 977)
	{
		LED1_Toggle();
		
		quadSecCounter++;
		
		if (quadSecCounter%2 == 0)
		{
			LED2_Toggle();
		}
		
		if (quadSecCounter%4 == 0)
		{
			LED3_Toggle();
			quadSecCounter = 0;
		}
		
		timer0OverflowCounter = 0;
		TIMER0_TCNT0_WRITE (112);
	}
}