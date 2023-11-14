
#include "ALARM_slave.h"

int main ()
{
	ALARM_slave_Init();
	
	while (1)
	{
		ALARM_slave_Run();
	}
}