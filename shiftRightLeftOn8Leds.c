

#define		DDRB	(*(volatile unsigned char*)0x37)
#define		PORTB	(*(volatile unsigned char*)0x38)

#define		F_CPU	8000000
#include <util/delay.h>

int main ()
{
	DDRB = 0xFF;
	
	char index = 0;
	
	while (1)
	{
		for (index = 0; index <= 7; index++)
		{
			PORTB = 1<<index;
			_delay_ms(500);
		}
		
		for (index = 6; index >= 1; index--)
		{
			PORTB = 1<<index;
			_delay_ms(500);
		}
	}
}

