

#define		DDRB	(*(volatile unsigned char*)0x37)
#define		PORTB	(*(volatile unsigned char*)0x38)

#define		F_CPU	8000000
#include <util/delay.h>

void setBit (volatile unsigned char* PPORT, int bit)
{
	*PPORT = *PPORT | (1<<bit);
}

int main ()
{
	DDRB = 0xFF;
	setBit(&PORTB, 0);
	setBit(&PORTB, 5);
}

