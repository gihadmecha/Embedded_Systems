
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

int main ()
{
	PORTA = 0b00001100;
	DDRB = 0xFF;
	
	unsigned char index = 0;
	int button1PressedFlag = 0;
	int button2PressedFlag = 0;
	
	SET_BIT(PORTB, index);
	while (1)
	{
		if (READ_BIT(PINA, 2) == 0)
		{
			if (button1PressedFlag == 0)
			{
				button1PressedFlag = 1;
				
				CLR_BIT (PORTB, index);
				
				index++;
				
				if (index == 8)
				index = 0;
				
				SET_BIT(PORTB, index);
				//while (READ_BIT(PINA, 2) == 0);
			}
		}
		else
		{
			button1PressedFlag = 0;
		}
		
		if (READ_BIT(PINA, 3) == 0)
		{
			if (button2PressedFlag == 0)
			{
				button2PressedFlag = 1;
				
				CLR_BIT (PORTB, index);
				
				index--;
				
				if (index == 255)
				index = 7;
				
				SET_BIT(PORTB, index);
				//while (READ_BIT(PINA, 3) == 0);
			}
		}
		else
		{
			button2PressedFlag = 0;
		}
	}
}

