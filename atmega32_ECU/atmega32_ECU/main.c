
#include "DIO_interface.h"
#include "MOTOR.h"


#include "Motors_Dashboard.h"
#include "STEPPER_MOTOR.h"

int main()
{
	//Motors_Dashboard_Init();
	DIO_Init();

	//while (1)
	//{
		//Motors_Dashboard_Run();
	//}
	
	//
	
	STEPPER3 (50);
	_delay_ms(1000);
	STEPPER3 (50);
	_delay_ms(1000);
	STEPPER3 (50);
	_delay_ms(1000);
	STEPPER3 (-50);
	_delay_ms(1000);
	STEPPER3 (-20);
}