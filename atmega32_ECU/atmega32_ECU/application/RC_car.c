
#include "RC_car.h"

void RC_forward ()
{
	MOTOR1_Forward();
	MOTOR2_Forward();
	MOTOR3_Forward();
	MOTOR4_Forward();
}

void RC_left ()
{
	
}

void RC_right ()
{
	
}

void RC_backward ()
{
	MOTOR1_backward();
	MOTOR2_backward();
	MOTOR3_backward();
	MOTOR4_backward();
}

void RC_stop ()
{
	MOTOR1_Stop();
	MOTOR2_Stop();
	MOTOR3_Stop();
	MOTOR4_Stop();
}

void RC_turnLeft ()
{
	
}

void RC_turnRight ()
{
	
}