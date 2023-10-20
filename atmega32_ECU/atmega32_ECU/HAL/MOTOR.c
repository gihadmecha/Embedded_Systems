

#include "MOTOR.h"

#if (EN_M1 == OC1A_PIN) || (EN_M1 == OC1B_PIN)

void MOTOR1_Init ()
{
	// 50 HZ
	//T(periodic time) = NO. of ticks * TIMER_TICK_TIME
	//F(frequency) = 1 / (NO. of ticks * TIMER_TICK_TIME)
	
	//NO. of ticks = 1 / (F * TIMER_TICK_TIME)
	switch (TOP)
	{
		case TIMER1_ICR:
		//TIMER1_ICR1_WRITE(1.0/(50*TIMER1_TICK_TIME));
		TIMER1_ICR1_WRITE(1.0/(50*TIMER1_TICK_TIME * 2.0));
		break;
	}
}

void MOTOR1_Forward (u8 dutyCycle)
{
	DIO_WritePin(IN1_M1, HIGH);
	DIO_WritePin(IN2_M1, LOW);
	
	switch (TOP)
	{
		case TIMER1_ICR:
			switch(EN_M1)
			{
				case OC1A_PIN:
				//inverting
				//duty cycle/100 = (2 * ((TIMER1_NO_OF_TICKS - 1) - compareMatch)) / (2 * (TIMER1_NO_OF_TICKS - 1))
				//compareMatch = (TIMER1_NO_OF_TICKS - 1) * (1 - (duty cycle/100))
				TIMER1_OCR1A_WRITE( (u16)((TIMER1_ICR1_READ() - 1.0) * (1.0 - (dutyCycle/100.0))) );
				break;
			}
		break;
	}
}

void MOTOR1_backward (u8 dutyCycle)
{
	dutyCycle = dutyCycle / 100.0;
	
	DIO_WritePin(IN1_M1, LOW);
	DIO_WritePin(IN2_M1, HIGH);
	
	switch(EN_M1)
	{
		case OC1A_PIN:
		//inverting
		//duty cycle/100 = (2 * ((TIMER1_NO_OF_TICKS - 1) - compareMatch)) / (2 * (TIMER1_NO_OF_TICKS - 1))
		//compareMatch = (TIMER1_NO_OF_TICKS - 1) * (1 - (duty cycle/100))
		TIMER1_OCR1A_WRITE((TIMER1_ICR1_READ() - 1.0) * (1.0 - (dutyCycle/100.0)));
		break;
	}
}

void MOTOR1_Stop ()
{
	DIO_WritePin(IN1_M1, LOW);
	DIO_WritePin(IN2_M1, LOW);
	TIMER1_OCR1A_WRITE((TIMER1_ICR1_READ() - 1.0));
}

#elif (EN_M1 == OC0_PIN) || (EN_M1 == OC2_PIN)

void MOTOR1_Forward (u8 dutyCycle)
{
	DIO_WritePin(IN1_M1, HIGH);
	DIO_WritePin(IN2_M1, LOW);
	
	switch(EN_M1)
	{
		case OC0_PIN:
		//phase correct PWM
		//SET_ON_COMPARE_MATCH
		//duty cycle/100 = (2 * ((TIMER1_NO_OF_TICKS - 1) - compareMatch)) / (2 * (TIMER1_NO_OF_TICKS - 1))
		//compareMatch = (TIMER1_NO_OF_TICKS - 1) * (1 - (duty cycle/100))
		TIMER0_OCR0_WRITE( (u16)((TIMER0_NO_OF_TICKS - 1.0) * (1.0 - (dutyCycle/100.0))) );
		break;
	}
}

void MOTOR1_backward (u8 dutyCycle)
{
	dutyCycle = dutyCycle / 100.0;
	
	DIO_WritePin(IN1_M1, LOW);
	DIO_WritePin(IN2_M1, HIGH);
	
	switch(EN_M1)
	{
		case OC1A_PIN:
		//phase correct PWM
		//SET_ON_COMPARE_MATCH
		//duty cycle/100 = (2 * ((TIMER1_NO_OF_TICKS - 1) - compareMatch)) / (2 * (TIMER1_NO_OF_TICKS - 1))
		//compareMatch = (TIMER1_NO_OF_TICKS - 1) * (1 - (duty cycle/100))
		TIMER0_OCR0_WRITE( (u16)((TIMER0_NO_OF_TICKS - 1.0) * (1.0 - (dutyCycle/100.0))) );
		break;
	}
}

#else

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

#endif

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
