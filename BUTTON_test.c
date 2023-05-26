
#include "DIO_interface.h"
#include "BUTTON.h"
#include "LED.h"

int main()
{
	DIO_Init();
	
	while (1)
	{
		BUTTON1_IfPressed_PeriodicCheck(LED1_Toggle);
	}
}