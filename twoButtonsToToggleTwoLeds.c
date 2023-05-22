

#define		DDRB	(*(volatile unsigned char*)0x37)
#define		PORTB	(*(volatile unsigned char*)0x38)
#define		PINB	(*(volatile unsigned char*)0x36)

#define		F_CPU	8000000
#include <util/delay.h>

#define		SET_BIT(reg, bit)				(reg = reg | (1<<bit))
#define		CLR_BIT(reg, bit)				(reg = reg & (~(1<<bit)))
#define		READ_BIT(reg, bit)				(reg & (1<<bit))
#define		WRITE_BIT(reg, bit, value)		(reg = (reg & (~(1<<bit))) | (1<<bit))

int main ()
{
	SET_BIT(DDRB, 0);
	WRITE_BIT(DDRB, 1, 1);
	SET_BIT(PORTB, 2);
	WRITE_BIT(PORTB, 3, 1);
	
	while (1)
	{
		if (READ_BIT(PINB, 2)==0)
		{
			SET_BIT (PORTB, 0);
			CLR_BIT(PORTB, 1);
		}
		if (READ_BIT(PINB, 3)==0)
		{
			SET_BIT (PORTB, 1);
			CLR_BIT(PORTB, 0);
		}
	}
}

