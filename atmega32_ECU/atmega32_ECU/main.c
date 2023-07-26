
#include "DIO_interface.h"
#include "BUTTON.h"
#include "RC_car.h"

int main ()
{
	DIO_Init();
	
	while (1)
	{
		BUTTON1_IfPressed_PeriodicCheck(RC_forward);
		BUTTON2_IfPressed_PeriodicCheck(RC_left);
		BUTTON3_IfPressed_PeriodicCheck(RC_right);
		BUTTON4_IfPressed_PeriodicCheck(RC_backward);
		
		BUTTON5_IfPressed_PeriodicCheck(RC_stop);
		BUTTON6_IfPressed_PeriodicCheck(RC_turnLeft);
		BUTTON7_IfPressed_PeriodicCheck(RC_turnRight);
	}
}