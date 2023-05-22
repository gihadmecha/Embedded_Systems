

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
		PORTB = 1<<index;
		
		index++;
		
		if (index == 8)
			index = 0;
		
		_delay_ms(500);
	}
}

