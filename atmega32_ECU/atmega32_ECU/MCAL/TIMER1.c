
#include "TIMER1.h"

void TIMER1_Init (timer1_prescaler_type prescaler, timer1_mode_type timerMode, timer1_OC1A_mode_type OC1AMode, timer1_OC1B_mode_type OC1BMode)
{
	switch (prescaler)
	{
		case TIMER1_PRESCALER_NO_CLOCK:
		CLR_BIT(TCCR1B, CS12);
		CLR_BIT(TCCR1B, CS11);
		CLR_BIT(TCCR1B, CS10);
		break;
		case TIMER1_PRESCALER_1:
		CLR_BIT(TCCR1B, CS12);
		CLR_BIT(TCCR1B, CS11);
		SET_BIT(TCCR1B, CS10);
		break;
		case TIMER1_PRESCALER_8:
		CLR_BIT(TCCR1B, CS12);
		SET_BIT(TCCR1B, CS11);
		CLR_BIT(TCCR1B, CS10);
		break;
		case TIMER1_PRESCALER_64:
		CLR_BIT(TCCR1B, CS12);
		SET_BIT(TCCR1B, CS11);
		SET_BIT(TCCR1B, CS10);
		break;
		case TIMER1_PRESCALER_256:
		SET_BIT(TCCR1B, CS12);
		CLR_BIT(TCCR1B, CS11);
		CLR_BIT(TCCR1B, CS10);
		break;
		case TIMER1_PRESCALER_1024:
		SET_BIT(TCCR1B, CS12);
		CLR_BIT(TCCR1B, CS11);
		SET_BIT(TCCR1B, CS10);
		break;
	}
	
	switch (timerMode)
	{
		case TIMER1_NORMAL:
		CLR_BIT(TCCR1B, WGM13);
		CLR_BIT(TCCR1B, WGM12);
		CLR_BIT(TCCR1A, WGM11);
		CLR_BIT(TCCR1A, WGM10);
		break;
		case TIMER1_PHASE_CORRECT_PWM_8BIT:
		CLR_BIT(TCCR1B, WGM13);
		CLR_BIT(TCCR1B, WGM12);
		CLR_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1A, WGM10);
		break;
		case TIMER1_PHASE_CORRECT_PWM_9BIT:
		CLR_BIT(TCCR1B, WGM13);
		CLR_BIT(TCCR1B, WGM12);
		SET_BIT(TCCR1A, WGM11);
		CLR_BIT(TCCR1A, WGM10);
		break;
		case TIMER1_PHASE_CORRECT_PWM_10BIT:
		CLR_BIT(TCCR1B, WGM13);
		CLR_BIT(TCCR1B, WGM12);
		SET_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1A, WGM10);
		break;
		case TIMER1_CTC_OCR1A_TOP:
		CLR_BIT(TCCR1B, WGM13);
		SET_BIT(TCCR1B, WGM12);
		CLR_BIT(TCCR1A, WGM11);
		CLR_BIT(TCCR1A, WGM10);
		break;
		case TIMER1_FAST_PWM_8BIT:
		CLR_BIT(TCCR1B, WGM13);
		SET_BIT(TCCR1B, WGM12);
		CLR_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1A, WGM10);
		break;
		case TIMER1_FAST_PWM_9BIT:
		CLR_BIT(TCCR1B, WGM13);
		SET_BIT(TCCR1B, WGM12);
		SET_BIT(TCCR1A, WGM11);
		CLR_BIT(TCCR1A, WGM10);
		break;
		case TIMER1_FAST_PWM_10BIT:
		CLR_BIT(TCCR1B, WGM13);
		SET_BIT(TCCR1B, WGM12);
		SET_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1A, WGM10);
		break;
		case TIMER1_PHASE_FREQUENCY_CORRECT_PWM_ICR1_TOP:
		SET_BIT(TCCR1B, WGM13);
		CLR_BIT(TCCR1B, WGM12);
		CLR_BIT(TCCR1A, WGM11);
		CLR_BIT(TCCR1A, WGM10);
		break;
		case TIMER1_PHASE_FREQUENCY_CORRECT_PWM_OCR1A_TOP:
		SET_BIT(TCCR1B, WGM13);
		CLR_BIT(TCCR1B, WGM12);
		CLR_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1A, WGM10);
		break;
		case TIMER1_PHASE_CORRECT_PWM_ICR1_TOP:
		SET_BIT(TCCR1B, WGM13);
		CLR_BIT(TCCR1B, WGM12);
		SET_BIT(TCCR1A, WGM11);
		CLR_BIT(TCCR1A, WGM10);
		break;
		case TIMER1_PHASE_CORRECT_PWM_OCR1A_TOP:
		SET_BIT(TCCR1B, WGM13);
		CLR_BIT(TCCR1B, WGM12);
		SET_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1A, WGM10);
		break;
		case TIMER1_CTC_ICR1_TOP:
		SET_BIT(TCCR1B, WGM13);
		SET_BIT(TCCR1B, WGM12);
		CLR_BIT(TCCR1A, WGM11);
		CLR_BIT(TCCR1A, WGM10);
		break;
		case TIMER1_FAST_PWM_ICR1_TOP:
		SET_BIT(TCCR1B, WGM13);
		SET_BIT(TCCR1B, WGM12);
		SET_BIT(TCCR1A, WGM11);
		CLR_BIT(TCCR1A, WGM10);
		break;
		case TIMER1_FAST_PWM_OCR1A_TOP:
		SET_BIT(TCCR1B, WGM13);
		SET_BIT(TCCR1B, WGM12);
		SET_BIT(TCCR1A, WGM11);
		SET_BIT(TCCR1A, WGM10);
		break;
	}
	
	switch (OC1AMode)
	{
		case TIMER1_OC1A_DISCONNECTED:
		CLR_BIT(TCCR1A, COM1A1);
		CLR_BIT(TCCR1A, COM1A0);
		break;
		case TIMER1_OC1A_TOGGLE_ON_COMPARE_MATCH:
		CLR_BIT(TCCR1A, COM1A1);
		SET_BIT(TCCR1A, COM1A0);
		break;
		case TIMER1_OC1A_CLEAR_ON_COMPARE_MATCH:
		SET_BIT(TCCR1A, COM1A1);
		CLR_BIT(TCCR1A, COM1A0);
		break;
		case TIMER1_OC1A_SET_ON_COMPARE_MATCH:
		SET_BIT(TCCR1A, COM1A1);
		SET_BIT(TCCR1A, COM1A0);
		break;
	}
	
	switch (OC1BMode)
	{
		case TIMER1_OC1B_DISCONNECTED:
		CLR_BIT(TCCR1A, COM1B1);
		CLR_BIT(TCCR1A, COM1B0);
		break;
		case TIMER1_OC1B_TOGGLE_ON_COMPARE_MATCH:
		CLR_BIT(TCCR1A, COM1B1);
		SET_BIT(TCCR1A, COM1B0);
		break;
		case TIMER1_OC1B_CLEAR_ON_COMPARE_MATCH:
		SET_BIT(TCCR1A, COM1B1);
		CLR_BIT(TCCR1A, COM1B0);
		break;
		case TIMER1_OC1B_SET_ON_COMPARE_MATCH:
		SET_BIT(TCCR1A, COM1B1);
		SET_BIT(TCCR1A, COM1B0);
		break;
	}
}

void TIMER1_ICPedgeMode (timer1_ICP_EDGE_type edgeType)
{
	switch (edgeType)
	{
		case TIMER1_ICU_FALLING_EDGE:
		CLR_BIT (TCCR1B, ICES1);
		break;
		case TIMER1_ICU_RAISING_EDGE:
		SET_BIT (TCCR1B, ICES1);
		break;
	}
}

void TIMER1_OCM1A_interruptEnable ()
{
	SET_BIT (TIMSK, OCIE1A);
}

void TIMER1_OCM1A_interruptDisable ()
{
	CLR_BIT (TIMSK, OCIE1A);
}

void TIMER1_OCM1B_interruptEnable ()
{
	SET_BIT (TIMSK, OCIE1B);
}

void TIMER1_OCM1B_interruptDisable ()
{
	CLR_BIT (TIMSK, OCIE1B);
}

void TIMER1_overflow_interruptEnable ()
{
	SET_BIT (TIMSK, TOIE1);
}

void TIMER1_overflow_interruptDisable ()
{
	CLR_BIT (TIMSK, TOIE1);
}

void TIMER1_timeStamp_interruptEnable ()
{
	SET_BIT (TIMSK, TICIE1);
}

void TIMER1_timeStamp_interruptDisable ()
{
	CLR_BIT (TIMSK, TICIE1);
}


static void (*funcPtrCompareMatch1A)(void) = NULL;
static void (*funcPtrCompareMatch1B)(void) = NULL;
static void (*funcPtrOverflow)(void) = NULL;
static void (*funcPtrTimeStamp)(void) = NULL;

void TIMER1_compareMatch1AInterruptSet (void (*func)(void))
{
	funcPtrCompareMatch1A = func;
}

void TIMER1_compareMatch1BInterruptSet (void (*func)(void))
{
	funcPtrCompareMatch1B = func;
}

void TIMER1_overflowInterruptSet (void (*func)(void))
{
	funcPtrOverflow = func;
}

void TIMER1_timeStampInterruptSet (void (*func)(void))
{
	funcPtrTimeStamp = func;
}

ISR (TIMER1_compareMatch1A_vect)
{
	if (funcPtrCompareMatch1A != NULLPTR)
	{
		funcPtrCompareMatch1A();
	}
}

ISR (TIMER1_compareMatch1B_vect)
{
	if (funcPtrCompareMatch1B != NULLPTR)
	{
		funcPtrCompareMatch1B();
	}
}

ISR (TIMER1_overflow_vect)
{
	if (funcPtrOverflow != NULLPTR)
	{
		funcPtrOverflow();
	}
}

ISR (TIMER1_timeStamp_vect)
{
	if (funcPtrTimeStamp != NULLPTR)
	{
		funcPtrTimeStamp();
	}
}


