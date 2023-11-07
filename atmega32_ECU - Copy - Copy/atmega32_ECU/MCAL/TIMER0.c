
#include "TIMER0.h"

void TIMER0_Init (timer0_prescaler_type prescaler, timer0_mode_type timerMode, timer0_OC0_mode_type OC0Mode)
{
	switch (prescaler)
	{
		case TIMER0_PRESCALER_NO_CLOCK:
		CLR_BIT(TCCR0, CS02);
		CLR_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS00);
		break;
		case TIMER0_PRESCALER_1:
		CLR_BIT(TCCR0, CS02);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS00);
		break;
		case TIMER0_PRESCALER_8:
		CLR_BIT(TCCR0, CS02);
		SET_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS00);
		break;
		case TIMER0_PRESCALER_64:
		CLR_BIT(TCCR0, CS02);
		SET_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS00);
		break;
		case TIMER0_PRESCALER_256:
		SET_BIT(TCCR0, CS02);
		CLR_BIT(TCCR0, CS01);
		CLR_BIT(TCCR0, CS00);
		break;
		case TIMER0_PRESCALER_1024:
		SET_BIT(TCCR0, CS02);
		CLR_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS00);
		break;
	}
	
	switch (timerMode)
	{
		case TIMER0_NORMAL:
		CLR_BIT(TCCR0, WGM01);
		CLR_BIT(TCCR0, WGM00);
		break;
		case TIMER0_PHASE_CORRECT_PWM:
		CLR_BIT(TCCR0, WGM01);
		SET_BIT(TCCR0, WGM00);
		break;
		case TIMER0_CTC:
		SET_BIT(TCCR0, WGM01);
		CLR_BIT(TCCR0, WGM00);
		break;
		case TIMER0_FAST_PWM:
		SET_BIT(TCCR0, WGM01);
		SET_BIT(TCCR0, WGM00);
		break;
	}
	
	switch (OC0Mode)
	{
		case TIMER0_OC0_DISCONNECTED:
		CLR_BIT(TCCR0, COM01);
		CLR_BIT(TCCR0, COM00);
		break;
		case TIMER0_OC0_TOGGLE_ON_COMPARE_MATCH:
		CLR_BIT(TCCR0, COM01);
		SET_BIT(TCCR0, COM00);
		break;
		case TIMER0_OC0_CLEAR_ON_COMPARE_MATCH:
		SET_BIT(TCCR0, COM01);
		CLR_BIT(TCCR0, COM00);
		break;
		case TIMER0_OC0_SET_ON_COMPARE_MATCH:
		SET_BIT(TCCR0, COM01);
		SET_BIT(TCCR0, COM00);
		break;
	}
}

void TIMER0_OCM_interruptEnable ()
{
	SET_BIT (TIMSK, OCIE0);
}

void TIMER0_OCM_interruptDisable ()
{
	CLR_BIT (TIMSK, OCIE0);
}

void TIMER0_overflow_interruptEnable ()
{
	SET_BIT (TIMSK, TOIE0);
}

void TIMER0_overflow_interruptDisable ()
{
	CLR_BIT (TIMSK, TOIE0);
}


static void (*funcPtrCompareMatch)(void) = NULL; 
static void (*funcPtrOverflow)(void) = NULL;

void TIMER0_compareMatchInterruptSet (void (*func)(void))
{
	funcPtrCompareMatch = func;
}

void TIMER0_overflowInterruptSet (void (*func)(void))
{
	funcPtrOverflow = func;
}

ISR (TIMER0_compareMatch_vect)
{
	if (funcPtrCompareMatch != NULLPTR)
	{
		funcPtrCompareMatch();
	}
}

ISR (TIMER0_overflow_vect)
{
	if (funcPtrOverflow != NULLPTR)
	{
		funcPtrOverflow();
	}
}

