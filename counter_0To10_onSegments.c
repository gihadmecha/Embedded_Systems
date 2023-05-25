
#include "SEGMENTS.h"

int main ()
{
	SEGMENTS1_Init();
	SEGMENTS2_Init();
	
	SEGMENTS1 (0);
	
	while (1)
	{
		for (u8 number = 0; number <= 15; number++)
		{
			SEGMENTS1(number);
			SEGMENTS2(number);
			_delay_ms(1000);
		}
	}
}