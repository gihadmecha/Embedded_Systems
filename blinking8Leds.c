

#define		DDRB	(*(volatile unsigned char*)0x37)
#define		PORTB	(*(volatile unsigned char*)0x38)

#define		F_CPU	8000000
#include <util/delay.h>

int main ()
{
	DDRB = 0xFF;
	
	while (1)
	{
		for (int count = 0; count <= 10; count++)
		{
			PORTB = 0xFF;
			_delay_ms(300);
			PORTB = 0x00;
			_delay_ms(300);
		}
		
		for (int count = 0; count <= 10; count++)
		{
			PORTB = 0x0F;
			_delay_ms(300);
			PORTB = 0xF0;
			_delay_ms(300);
		}
		
		for (int count = 0; count <= 10; count++)
		{
			PORTB = 0b11001100;
			_delay_ms(300);
			PORTB = 0b00110011;
			_delay_ms(300);
		}
		
		for (int count = 0; count <= 10; count++)
		{
			PORTB = 0b10101010;
			_delay_ms(300);
			PORTB = 0b01010101;
			_delay_ms(300);
		}
	}
}

