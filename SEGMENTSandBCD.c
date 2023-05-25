

#include "SEGMENTS.h"

int main ()
{
	SEGMENTS3_2_Init ();
	
	while (1)
	{
		for (u8 number = 0; number <= 15; number++)
		{
			SEGMENTS3_2 (number);
			_delay_ms(1000);
		}
	}
}