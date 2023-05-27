
#include "DIO_interface.h"
#include "SEGMENTS.h"

int main()
{
	DIO_Init();
	
	while (1)
	{
		for (u8 number = 0; number <= 15; number++)
		{
			SEGMENTS1(number);
			SEGMENTS2 (number);
			SEGMENTS3 (number);
			for (u8 count = 0; count <= 100; count++)
			{
				SEGMENTS4(0);
			}
		}
		
		for (u8 number = 0; number <= 99; number++)
		{
			for (u8 count = 0; count <= 100; count++)
			{
				SEGMENTS1(number/10);
				SEGMENTS2 (number%10);
				SEGMENTS4(number);
			}
		}
	}
}