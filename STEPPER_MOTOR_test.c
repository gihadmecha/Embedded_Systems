
#include "DIO_interface.h"
#include "STEPPER_MOTOR.h"

int main()
{
	DIO_Init();
	
	while (1)
	{
		//STEPPER3_Forward();
		STEPPER3_Backward();
		//for (u8 count = 0; count < 9; count++)
		//{
			//STEPPER1_Forward();
			//STEPPER2_Forward ();
		//}
		//for (u8 count = 0; count < 9; count++)
		//{
			//STEPPER1_Backward();
			//STEPPER2_Backward ();
		//}
	}
}