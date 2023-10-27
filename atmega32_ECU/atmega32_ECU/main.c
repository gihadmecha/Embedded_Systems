
#include "ultrasonics_and_servo.h"

int main ()
{
	ultrasonics_and_servo_Init ();
	
	while (1)
	{
		ultrasonics_and_servo_Run ();
	}
}