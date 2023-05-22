
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
	DDRB = 0xFF;
	SET_BIT(PORTA, 2);
	
	unsigned char index =  0;
	int directionFlag = 0;
	int buttonPressedFlag = 0;
	
	SET_BIT(PORTB, index);
	for (int count = 0; count < 100; count++)
	{
		_delay_ms(10);
		if (READ_BIT(PINA, 2) == 0)
		{
			if (buttonPressedFlag == 0)
			{
				directionFlag ^= 1;
			}
			buttonPressedFlag = 1;
		}
		else
		{
			buttonPressedFlag = 0;
		}
	}
	
	while (1)
	{
		if (directionFlag == 0)
		{
			CLR_BIT(PORTB, index);
			
			index++;
			if (index == 8)
			index = 0;
			
			SET_BIT(PORTB, index);
			for (int count = 0; count < 100; count++)
			{
				_delay_ms(10);
				if (READ_BIT(PINA, 2) == 0)
				{
					if (buttonPressedFlag == 0)
					{
						directionFlag ^= 1;
					}
					buttonPressedFlag = 1;
				}
				else
				{
					buttonPressedFlag = 0;
				}
		   }
		}	
		
		if (directionFlag == 1)
		{
			CLR_BIT(PORTB, index);
			
			index--;
			if (index == 255)
			index = 7;
			
			SET_BIT(PORTB, index);
			for (int count = 0; count < 100; count++)
			{
				_delay_ms(10);
				if (READ_BIT(PINA, 2) == 0)
				{
					if (buttonPressedFlag == 0)
					{
						directionFlag ^= 1;
					}
					buttonPressedFlag = 1;
				}
				else
				{
					buttonPressedFlag = 0;
				}
			}
		}
	}
}

