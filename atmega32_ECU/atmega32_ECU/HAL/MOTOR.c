

#include "MOTOR.h"

void MOTOR1_Forward ()
{
	DIO_WritePin(IN1_M1, HIGH);
	DIO_WritePin(IN2_M1, LOW);
	DIO_WritePin(EN1_M1, HIGH);
}

void MOTOR1_backward ()
{
	DIO_WritePin(IN1_M1, LOW);
	DIO_WritePin(IN2_M1, HIGH);
	DIO_WritePin(EN1_M1, HIGH);
}

void MOTOR_Stop ()
{
	DIO_WritePin(IN1_M1, LOW);
	DIO_WritePin(IN2_M1, LOW);
	DIO_WritePin(EN1_M1, LOW);
}
