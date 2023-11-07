
#include "STEPPER_MOTOR.h"

//Full Step
void STEPPER1_Forward ()
{
	DIO_WritePin(coilA1_STEPPER1, LOW);
	DIO_WritePin(coilA2_STEPPER1, LOW);
	DIO_WritePin(coilB1_STEPPER1, HIGH);
	DIO_WritePin(coilB2_STEPPER1, LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER1, LOW);
	DIO_WritePin(coilA2_STEPPER1, HIGH);
	DIO_WritePin(coilB1_STEPPER1, LOW);
	DIO_WritePin(coilB2_STEPPER1, LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER1, LOW);
	DIO_WritePin(coilA2_STEPPER1, LOW);
	DIO_WritePin(coilB1_STEPPER1, LOW);
	DIO_WritePin(coilB2_STEPPER1, HIGH);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER1, HIGH);
	DIO_WritePin(coilA2_STEPPER1, LOW);
	DIO_WritePin(coilB1_STEPPER1, LOW);
	DIO_WritePin(coilB2_STEPPER1, LOW);
	_delay_ms(DELAY);
}

//Half Step
void STEPPER1_Backward ()
{
	DIO_WritePin(coilA1_STEPPER1, LOW);
	DIO_WritePin(coilA2_STEPPER1, LOW);
	DIO_WritePin(coilB1_STEPPER1, LOW);
	DIO_WritePin(coilB2_STEPPER1, HIGH);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER1, LOW);
	DIO_WritePin(coilA2_STEPPER1, HIGH);
	DIO_WritePin(coilB1_STEPPER1, LOW);
	DIO_WritePin(coilB2_STEPPER1, LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER1, LOW);
	DIO_WritePin(coilA2_STEPPER1, LOW);
	DIO_WritePin(coilB1_STEPPER1, HIGH);
	DIO_WritePin(coilB2_STEPPER1, LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER1, HIGH);
	DIO_WritePin(coilA2_STEPPER1, LOW);
	DIO_WritePin(coilB1_STEPPER1, LOW);
	DIO_WritePin(coilB2_STEPPER1, LOW);
	_delay_ms(DELAY);
}

void STEPPER1_Stop ()
{
	DIO_WritePin(coilA1_STEPPER1, LOW);
	DIO_WritePin(coilA2_STEPPER1, LOW);
	DIO_WritePin(coilB1_STEPPER1, LOW);
	DIO_WritePin(coilB2_STEPPER1, LOW);
}

//unipoler Stepper Motor
//full Step
void STEPPER2_Forward ()
{
	DIO_WritePin(coilA1_STEPPER2, LOW);
	DIO_WritePin(coilA2_STEPPER2, HIGH);
	DIO_WritePin(coilB1_STEPPER2, LOW);
	DIO_WritePin(coilB2_STEPPER2, LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER2, LOW);
	DIO_WritePin(coilA2_STEPPER2, LOW);
	DIO_WritePin(coilB1_STEPPER2, HIGH);
	DIO_WritePin(coilB2_STEPPER2, LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER2, LOW);
	DIO_WritePin(coilA2_STEPPER2, LOW);
	DIO_WritePin(coilB1_STEPPER2, LOW);
	DIO_WritePin(coilB2_STEPPER2, HIGH);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER2, HIGH);
	DIO_WritePin(coilA2_STEPPER2, LOW);
	DIO_WritePin(coilB1_STEPPER2, LOW);
	DIO_WritePin(coilB2_STEPPER2, LOW);
	_delay_ms(DELAY);
}

void STEPPER2_Backward ()
{
	DIO_WritePin(coilA1_STEPPER2, HIGH);
	DIO_WritePin(coilA2_STEPPER2, LOW);
	DIO_WritePin(coilB1_STEPPER2, LOW);
	DIO_WritePin(coilB2_STEPPER2, LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER2, LOW);
	DIO_WritePin(coilA2_STEPPER2, LOW);
	DIO_WritePin(coilB1_STEPPER2, LOW);
	DIO_WritePin(coilB2_STEPPER2, HIGH);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER2, LOW);
	DIO_WritePin(coilA2_STEPPER2, LOW);
	DIO_WritePin(coilB1_STEPPER2, HIGH);
	DIO_WritePin(coilB2_STEPPER2, LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER2, LOW);
	DIO_WritePin(coilA2_STEPPER2, HIGH);
	DIO_WritePin(coilB1_STEPPER2, LOW);
	DIO_WritePin(coilB2_STEPPER2, LOW);
	_delay_ms(DELAY);
}

void STEPPER2_Stop ();

//unipoler Stepper Motor
//Half Step
void STEPPER3_Forward ()
{
	DIO_WritePin(coilA1_STEPPER3, LOW);
	DIO_WritePin(coilA2_STEPPER3, HIGH);
	DIO_WritePin(coilB1_STEPPER3, LOW);
	DIO_WritePin(coilB2_STEPPER3, LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER3, LOW);
	DIO_WritePin(coilA2_STEPPER3, HIGH);
	DIO_WritePin(coilB1_STEPPER3, HIGH);
	DIO_WritePin(coilB2_STEPPER3, LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER3, LOW);
	DIO_WritePin(coilA2_STEPPER3, LOW);
	DIO_WritePin(coilB1_STEPPER3, HIGH);
	DIO_WritePin(coilB2_STEPPER3, LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER3, LOW);
	DIO_WritePin(coilA2_STEPPER3, LOW);
	DIO_WritePin(coilB1_STEPPER3, HIGH);
	DIO_WritePin(coilB2_STEPPER3, HIGH);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER3, LOW);
	DIO_WritePin(coilA2_STEPPER3, LOW);
	DIO_WritePin(coilB1_STEPPER3, LOW);
	DIO_WritePin(coilB2_STEPPER3, HIGH);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER3, HIGH);
	DIO_WritePin(coilA2_STEPPER3, LOW);
	DIO_WritePin(coilB1_STEPPER3, LOW);
	DIO_WritePin(coilB2_STEPPER3, HIGH);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER3, HIGH);
	DIO_WritePin(coilA2_STEPPER3, LOW);
	DIO_WritePin(coilB1_STEPPER3, LOW);
	DIO_WritePin(coilB2_STEPPER3, LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER3, HIGH);
	DIO_WritePin(coilA2_STEPPER3, HIGH);
	DIO_WritePin(coilB1_STEPPER3, LOW);
	DIO_WritePin(coilB2_STEPPER3, LOW);
	_delay_ms(DELAY);
}
void STEPPER3_Backward ()
{
	DIO_WritePin(coilA1_STEPPER3, HIGH);
	DIO_WritePin(coilA2_STEPPER3, HIGH);
	DIO_WritePin(coilB1_STEPPER3, LOW);
	DIO_WritePin(coilB2_STEPPER3, LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER3, HIGH);
	DIO_WritePin(coilA2_STEPPER3, LOW);
	DIO_WritePin(coilB1_STEPPER3, LOW);
	DIO_WritePin(coilB2_STEPPER3, LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER3, HIGH);
	DIO_WritePin(coilA2_STEPPER3, LOW);
	DIO_WritePin(coilB1_STEPPER3, LOW);
	DIO_WritePin(coilB2_STEPPER3, HIGH);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER3, LOW);
	DIO_WritePin(coilA2_STEPPER3, LOW);
	DIO_WritePin(coilB1_STEPPER3, LOW);
	DIO_WritePin(coilB2_STEPPER3, HIGH);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER3, LOW);
	DIO_WritePin(coilA2_STEPPER3, LOW);
	DIO_WritePin(coilB1_STEPPER3, HIGH);
	DIO_WritePin(coilB2_STEPPER3, HIGH);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER3, LOW);
	DIO_WritePin(coilA2_STEPPER3, LOW);
	DIO_WritePin(coilB1_STEPPER3, HIGH);
	DIO_WritePin(coilB2_STEPPER3, LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER3, LOW);
	DIO_WritePin(coilA2_STEPPER3, HIGH);
	DIO_WritePin(coilB1_STEPPER3, HIGH);
	DIO_WritePin(coilB2_STEPPER3, LOW);
	_delay_ms(DELAY);
	
	DIO_WritePin(coilA1_STEPPER3, LOW);
	DIO_WritePin(coilA2_STEPPER3, HIGH);
	DIO_WritePin(coilB1_STEPPER3, LOW);
	DIO_WritePin(coilB2_STEPPER3, LOW);
	_delay_ms(DELAY);
}
void STEPPER3_Stop ();