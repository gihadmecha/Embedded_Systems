
#include "LED.h"

int main ()
{
	DIO_Init();
	
	while (1)
	{
		LED1_On();
		_delay_ms(1000);
		//LED1_Off();
		//_delay_ms(1000);
		
		if (LED1_Read())
		{
			LED1_Toggle();
			_delay_ms(1000);
		}
		else
		{
			LED1_On();
			_delay_ms(200);
		}
	}
}