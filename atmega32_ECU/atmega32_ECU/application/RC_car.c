
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
	MOTOR1_Stop();
	MOTOR3_Stop();
	MOTOR2_Forward();
	MOTOR4_Forward();
}

void RC_right ()
{
	MOTOR2_Stop();
	MOTOR4_Stop();
	MOTOR1_Forward();
	MOTOR3_Forward();
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
	MOTOR2_Forward();
	MOTOR4_Forward();
	MOTOR1_backward();
	MOTOR3_backward();
}

void RC_turnRight ()
{
	MOTOR1_Forward();
	MOTOR3_Forward();
	MOTOR2_backward();
	MOTOR4_backward();
}