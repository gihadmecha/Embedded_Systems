
#include "RGB_LED.h"

int main ()
{
	DIO_Init();
	TIMER0_Init(TIMER0_PRESCALER_8, TIMER0_FAST_PWM, TIMER0_OC0_CLEAR_ON_COMPARE_MATCH);
	TIMER1_Init(TIMER1_PRESCALER_8, TIMER1_FAST_PWM_8BIT, TIMER1_OC1A_CLEAR_ON_COMPARE_MATCH, TIMER1_OC1B_CLEAR_ON_COMPARE_MATCH);
	
	while (1)
	{
		RGB_LED (0, 0, 255);
	}
}