
#define		DDRA	(*(volatile unsigned char*)0x3A)
#define		PORTA	(*(volatile unsigned char*)0x3B)
#define		PINA	(*(volatile unsigned char*)0x39)

#define		DDRB	(*(volatile unsigned char*)0x37)
#define		PORTB	(*(volatile unsigned char*)0x38)
#define		PINB	(*(volatile unsigned char*)0x36)

#define		F_CPU	8000000
#include <util/delay.h>

#define		SET_BIT(reg, bit)				(reg = reg | (1<<bit))
#define		CLR_BIT(reg, bit)				(reg = reg & (~(1<<bit)))
#define		READ_BIT(reg, bit)				(reg & (1<<bit))
#define		WRITE_BIT(reg, bit, value)		(reg = (reg & (~(1<<bit))) | (1<<bit))
#define		TOG_BIT(reg, bit)				(reg = reg ^ (1<<bit))

int main ()
{
	SET_BIT(DDRB, 0);
	SET_BIT(PORTB, 2);
	
	int buttonPressedFlag = 0;
	
	while (1)
	{
		if (READ_BIT(PINB, 2) == 0)
		{
			if (buttonPressedFlag == 0)
			{
				buttonPressedFlag = 1;
				TOG_BIT(PORTB, 0);
				//while(READ_BIT(PINB, 2) == 0);
			}	
		}
		else
		{
			buttonPressedFlag = 0;
		}
	}
}

