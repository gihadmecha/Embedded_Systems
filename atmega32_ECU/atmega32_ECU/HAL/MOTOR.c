

#include "MOTOR.h"

void MOTOR1_Forward ()
{
	DIO_WritePin(IN1_M1, HIGH);
	DIO_WritePin(IN2_M1, LOW);
}

void MOTOR1_backward ()
{
	DIO_WritePin(IN1_M1, LOW);
	DIO_WritePin(IN2_M1, HIGH);
}

void MOTOR1_Stop ()
{
	DIO_WritePin(IN1_M1, LOW);
	DIO_WritePin(IN2_M1, LOW);
}
///////////////////////////////////////////////////////

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
/////////////////////////////////////////////////////

void MOTOR3_Forward ()
{
	DIO_WritePin(IN1_M3, HIGH);
	DIO_WritePin(IN2_M3, LOW);
}

void MOTOR3_backward ()
{
	DIO_WritePin(IN1_M3, LOW);
	DIO_WritePin(IN2_M3, HIGH);
}

void MOTOR3_Stop ()
{
	DIO_WritePin(IN1_M3, LOW);
	DIO_WritePin(IN2_M3, LOW);
}
//////////////////////////////////////////////////////////

void MOTOR4_Forward ()
{
	DIO_WritePin(IN1_M4, HIGH);
	DIO_WritePin(IN2_M4, LOW);
}

void MOTOR4_backward ()
{
	DIO_WritePin(IN1_M4, LOW);
	DIO_WritePin(IN2_M4, HIGH);
}

void MOTOR4_Stop ()
{
	DIO_WritePin(IN1_M4, LOW);
	DIO_WritePin(IN2_M4, LOW);
}
