

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

void MOTOR1_Stop ()
{
	DIO_WritePin(IN1_M1, LOW);
	DIO_WritePin(IN2_M1, LOW);
	DIO_WritePin(EN1_M1, LOW);
}


void MOTOR2_Forward ()
{
	DIO_WritePin(IN1_M2, HIGH);
	DIO_WritePin(IN2_M2, LOW);
}

void MOTOR2_backward ()
{
	DIO_WritePin(IN1_M2, LOW);
	DIO_WritePin(IN2_M2, HIGH);
}

void MOTOR2_Stop ()
{
	DIO_WritePin(IN1_M2, LOW);
	DIO_WritePin(IN2_M2, LOW);
}
