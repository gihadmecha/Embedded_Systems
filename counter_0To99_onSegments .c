

#include "SEGMENTS.h"

int main ()
{
	//SEGMENTS1_Init();
	SEGMENTS1_2_Init();
	//SEGMENTS2_Init();
	SEGMENTS2_2_Init();
	
	while (1)
	{
		for (u8 number = 0; number <= 99; number++)
		{
			if (0 <= number && number <= 99)
			{
				//SEGMENTS1(number/10);
				SEGMENTS1_2(number/10);
				//SEGMENTS2(number%10);
				SEGMENTS2_2(number%10);
				_delay_ms(200);
			}
		}
	}
}