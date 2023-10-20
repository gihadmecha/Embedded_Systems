
#include "STEPPER_MOTOR_Private.h"
#include "STEPPER_MOTOR.h"


static u8 phaseFlag;
static u8 startFlag = 0;
static u8 presentState;
static u8 previousState;

//Full Step
void STEPPER1_Forward (void (*FUNC)(void))
{
	DIO_WritePin(coilA1_STEPPER1, LOW);
	DIO_WritePin(coilA2_STEPPER1, LOW);
	DIO_WritePin(coilB1_STEPPER1, HIGH);
	DIO_WritePin(coilB2_STEPPER1, LOW);
	STEPPER_MOTOR_delay_ms(FUNC);
	
	DIO_WritePin(coilA1_STEPPER1, LOW);
	DIO_WritePin(coilA2_STEPPER1, HIGH);
	DIO_WritePin(coilB1_STEPPER1, LOW);
	DIO_WritePin(coilB2_STEPPER1, LOW);
	STEPPER_MOTOR_delay_ms(FUNC);
	
	DIO_WritePin(coilA1_STEPPER1, LOW);
	DIO_WritePin(coilA2_STEPPER1, LOW);
	DIO_WritePin(coilB1_STEPPER1, LOW);
	DIO_WritePin(coilB2_STEPPER1, HIGH);
	STEPPER_MOTOR_delay_ms(FUNC);
	
	DIO_WritePin(coilA1_STEPPER1, HIGH);
	DIO_WritePin(coilA2_STEPPER1, LOW);
	DIO_WritePin(coilB1_STEPPER1, LOW);
	DIO_WritePin(coilB2_STEPPER1, LOW);
	STEPPER_MOTOR_delay_ms(FUNC);
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
void STEPPER3 (s32 angle)
{
	if (angle >= 0)
	{
		if (startFlag == 0)
		{
			presentState = STEPPER3_POSITIVE_DIRECTION;
			previousState = STEPPER3_POSITIVE_DIRECTION;
			startFlag = 1;
			phaseFlag = 1;
		}
		else
		{
			previousState = presentState;
			presentState = STEPPER3_POSITIVE_DIRECTION;
		}
		
		if (previousState == STEPPER3_NEGATIVE_DIRECTION)
		{
			if (phaseFlag == 6)
			{
				phaseFlag = 8;
			}
			else if (phaseFlag == 5)
			{
				phaseFlag = 7;
			}
			else if (phaseFlag == 4)
			{
				phaseFlag = 6;
			}
			else if (phaseFlag == 3)
			{
				phaseFlag = 5;
			}
			else if (phaseFlag == 2)
			{
				phaseFlag = 4;
			}
			else if (phaseFlag == 1)
			{
				phaseFlag = 3;
			}
			else if (phaseFlag == 8)
			{
				phaseFlag = 2;
			}
			else if (phaseFlag == 7)
			{
				phaseFlag = 1;
			}
		}
		
		while (angle >= (STEPPER3_STEP_ANGLE/2) )
		{
			if (phaseFlag == 1)
			{
				DIO_WritePin(coilA1_STEPPER3, LOW);
				DIO_WritePin(coilA2_STEPPER3, LOW);
				DIO_WritePin(coilB1_STEPPER3, LOW);
				DIO_WritePin(coilB2_STEPPER3, HIGH);
				_delay_ms(DELAY);
				
				phaseFlag = 2;
				
				angle -= (STEPPER3_STEP_ANGLE/2);
				if (angle < (STEPPER3_STEP_ANGLE/2))
				{
					break;
				}
			}
			
			if (phaseFlag == 2)
			{
				DIO_WritePin(coilA1_STEPPER3, LOW);
				DIO_WritePin(coilA2_STEPPER3, LOW);
				DIO_WritePin(coilB1_STEPPER3, HIGH);
				DIO_WritePin(coilB2_STEPPER3, HIGH);
				_delay_ms(DELAY);
				
				phaseFlag = 3;
				
				angle -= (STEPPER3_STEP_ANGLE/2);
				if (angle < (STEPPER3_STEP_ANGLE/2))
				{
					break;
				}
			}
			
			if (phaseFlag == 3)
			{
				DIO_WritePin(coilA1_STEPPER3, LOW);
				DIO_WritePin(coilA2_STEPPER3, LOW);
				DIO_WritePin(coilB1_STEPPER3, HIGH);
				DIO_WritePin(coilB2_STEPPER3, LOW);
				_delay_ms(DELAY);
				
				phaseFlag = 4;
				
				angle -= (STEPPER3_STEP_ANGLE/2);
				if (angle < (STEPPER3_STEP_ANGLE/2))
				{
					break;
				}
			}
			
			if (phaseFlag == 4)
			{
				DIO_WritePin(coilA1_STEPPER3, LOW);
				DIO_WritePin(coilA2_STEPPER3, HIGH);
				DIO_WritePin(coilB1_STEPPER3, HIGH);
				DIO_WritePin(coilB2_STEPPER3, LOW);
				_delay_ms(DELAY);
				
				phaseFlag = 5;
				
				angle -= (STEPPER3_STEP_ANGLE/2);
				if (angle < (STEPPER3_STEP_ANGLE/2))
				{
					break;
				}
			}
			
			if (phaseFlag == 5)
			{
				DIO_WritePin(coilA1_STEPPER3, LOW);
				DIO_WritePin(coilA2_STEPPER3, HIGH);
				DIO_WritePin(coilB1_STEPPER3, LOW);
				DIO_WritePin(coilB2_STEPPER3, LOW);
				_delay_ms(DELAY);
				
				phaseFlag = 6;
				
				angle -= (STEPPER3_STEP_ANGLE/2);
				if (angle < (STEPPER3_STEP_ANGLE/2))
				{
					break;
				}
			}
			
			if (phaseFlag == 6)
			{
				DIO_WritePin(coilA1_STEPPER3, HIGH);
				DIO_WritePin(coilA2_STEPPER3, HIGH);
				DIO_WritePin(coilB1_STEPPER3, LOW);
				DIO_WritePin(coilB2_STEPPER3, LOW);
				_delay_ms(DELAY);
				
				phaseFlag = 7;
				
				angle -= (STEPPER3_STEP_ANGLE/2);
				if (angle < (STEPPER3_STEP_ANGLE/2))
				{
					break;
				}
			}
			
			if (phaseFlag == 7)
			{
				DIO_WritePin(coilA1_STEPPER3, HIGH);
				DIO_WritePin(coilA2_STEPPER3, LOW);
				DIO_WritePin(coilB1_STEPPER3, LOW);
				DIO_WritePin(coilB2_STEPPER3, LOW);
				_delay_ms(DELAY);
				
				phaseFlag = 8;
				
				angle -= (STEPPER3_STEP_ANGLE/2);
				if (angle < (STEPPER3_STEP_ANGLE/2))
				{
					break;
				}
			}
			
			if (phaseFlag == 8)
			{
				DIO_WritePin(coilA1_STEPPER3, HIGH);
				DIO_WritePin(coilA2_STEPPER3, LOW);
				DIO_WritePin(coilB1_STEPPER3, LOW);
				DIO_WritePin(coilB2_STEPPER3, HIGH);
				_delay_ms(DELAY);
				
				phaseFlag = 1;
				
				angle -= (STEPPER3_STEP_ANGLE/2);
				if (angle < (STEPPER3_STEP_ANGLE/2))
				{
					break;
				}
			}
		}
	}
	else if (angle < 0)
	{
		if (startFlag == 0)
		{
			presentState = STEPPER3_NEGATIVE_DIRECTION;
			previousState = STEPPER3_NEGATIVE_DIRECTION;
			startFlag = 1;
			phaseFlag = 7;
		}
		else
		{
			previousState = presentState;
			presentState = STEPPER3_NEGATIVE_DIRECTION;
		}
		
		if (previousState == STEPPER3_POSITIVE_DIRECTION)
		{
			if (phaseFlag == 2)
			{
				phaseFlag = 8;
			}
			else if (phaseFlag == 3)
			{
				phaseFlag = 1;
			}
			else if (phaseFlag == 4)
			{
				phaseFlag = 2;
			}
			else if (phaseFlag == 5)
			{
				phaseFlag = 3;
			}
			else if (phaseFlag == 6)
			{
				phaseFlag = 4;
			}
			else if (phaseFlag == 7)
			{
				phaseFlag = 5;
			}
			else if (phaseFlag == 8)
			{
				phaseFlag = 6;
			}
			else if (phaseFlag == 1)
			{
				phaseFlag = 7;
			}
		}
		
		angle = -angle;
		
		while (angle >= (STEPPER3_STEP_ANGLE/2) )
		{
			if (phaseFlag == 7)
			{
				DIO_WritePin(coilA1_STEPPER3, HIGH);
				DIO_WritePin(coilA2_STEPPER3, LOW);
				DIO_WritePin(coilB1_STEPPER3, LOW);
				DIO_WritePin(coilB2_STEPPER3, LOW);
				_delay_ms(DELAY);
				
				phaseFlag = 6;
				
				angle -= (STEPPER3_STEP_ANGLE/2);
				if (angle < (STEPPER3_STEP_ANGLE/2))
				{
					break;
				}
			}
			
			if (phaseFlag == 6)
			{
				DIO_WritePin(coilA1_STEPPER3, HIGH);
				DIO_WritePin(coilA2_STEPPER3, HIGH);
				DIO_WritePin(coilB1_STEPPER3, LOW);
				DIO_WritePin(coilB2_STEPPER3, LOW);
				_delay_ms(DELAY);
				
				phaseFlag = 5;
				
				angle -= (STEPPER3_STEP_ANGLE/2);
				if (angle < (STEPPER3_STEP_ANGLE/2))
				{
					break;
				}
			}
			
			if (phaseFlag == 5)
			{
				DIO_WritePin(coilA1_STEPPER3, LOW);
				DIO_WritePin(coilA2_STEPPER3, HIGH);
				DIO_WritePin(coilB1_STEPPER3, LOW);
				DIO_WritePin(coilB2_STEPPER3, LOW);
				_delay_ms(DELAY);
				
				phaseFlag = 4;
				
				angle -= (STEPPER3_STEP_ANGLE/2);
				if (angle < (STEPPER3_STEP_ANGLE/2))
				{
					break;
				}
			}
			
			if (phaseFlag == 4)
			{
				DIO_WritePin(coilA1_STEPPER3, LOW);
				DIO_WritePin(coilA2_STEPPER3, HIGH);
				DIO_WritePin(coilB1_STEPPER3, HIGH);
				DIO_WritePin(coilB2_STEPPER3, LOW);
				_delay_ms(DELAY);
				
				phaseFlag = 3;
				
				angle -= (STEPPER3_STEP_ANGLE/2);
				if (angle < (STEPPER3_STEP_ANGLE/2))
				{
					break;
				}
			}
			
			if (phaseFlag == 3)
			{
				DIO_WritePin(coilA1_STEPPER3, LOW);
				DIO_WritePin(coilA2_STEPPER3, LOW);
				DIO_WritePin(coilB1_STEPPER3, HIGH);
				DIO_WritePin(coilB2_STEPPER3, LOW);
				_delay_ms(DELAY);
				
				phaseFlag = 2;
				
				angle -= (STEPPER3_STEP_ANGLE/2);
				if (angle < (STEPPER3_STEP_ANGLE/2))
				{
					break;
				}
			}
			
			if (phaseFlag == 2)
			{
				DIO_WritePin(coilA1_STEPPER3, LOW);
				DIO_WritePin(coilA2_STEPPER3, LOW);
				DIO_WritePin(coilB1_STEPPER3, HIGH);
				DIO_WritePin(coilB2_STEPPER3, HIGH);
				_delay_ms(DELAY);
				
				phaseFlag = 1;
				
				angle -= (STEPPER3_STEP_ANGLE/2);
				if (angle < (STEPPER3_STEP_ANGLE/2))
				{
					break;
				}
			}
			
			if (phaseFlag == 1)
			{
				DIO_WritePin(coilA1_STEPPER3, LOW);
				DIO_WritePin(coilA2_STEPPER3, LOW);
				DIO_WritePin(coilB1_STEPPER3, LOW);
				DIO_WritePin(coilB2_STEPPER3, HIGH);
				_delay_ms(DELAY);
				
				phaseFlag = 8;
				
				angle -= (STEPPER3_STEP_ANGLE/2);
				if (angle < (STEPPER3_STEP_ANGLE/2))
				{
					break;
				}
			}
			
			if (phaseFlag == 8)
			{
				DIO_WritePin(coilA1_STEPPER3, HIGH);
				DIO_WritePin(coilA2_STEPPER3, LOW);
				DIO_WritePin(coilB1_STEPPER3, LOW);
				DIO_WritePin(coilB2_STEPPER3, HIGH);
				_delay_ms(DELAY);
				
				phaseFlag = 7;
				
				angle -= (STEPPER3_STEP_ANGLE/2);
				if (angle < (STEPPER3_STEP_ANGLE/2))
				{
					break;
				}
			}
		}	
	}
	
}

static void STEPPER_MOTOR_delay_ms (void (*FUNC)(void))
{
	for (u32 index = 0; index < DELAY; index++)
	{
		if (FUNC != NULL)
		{
			FUNC ();
		}
		
		_delay_ms(1);
	}
}