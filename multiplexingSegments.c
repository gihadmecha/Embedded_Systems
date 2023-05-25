

#include "SEGMENTS.h"

int main ()
{
	SEGMENTS4_2_Init ();
	
	while (1)
	{
		for (u8 number = 0; number <= 99; number++)
		{
			for (u8 count = 0; count <= 100; count++)
			{
				SEGMENTS4_2 (number);
			}
		}
	}
}