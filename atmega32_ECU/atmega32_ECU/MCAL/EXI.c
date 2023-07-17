
#include "EXI.h"


void INT0_Init (INT0_Event_type event)
{
	MCUCR = MCUCR & 0b11111100;
	MCUCR = MCUCR | event;
}

void INT0_Enable ()
{
	SET_BIT(GICR, INT0);
}

void INT0_Disable ()
{
	CLR_BIT(GICR, INT0);
}

static void (*FUNC_PTR0)(void) = NULL;
void INT0_Interrupt (void (*func)(void))
{
	FUNC_PTR0 = func;
}

ISR(INT0_vect)
{
	if (FUNC_PTR0 != NULLPTR)
	{
		FUNC_PTR0();
	}
}
//////////////////////////////////////////////////////////////////////////

void INT1_Init (INT1_Event_type event)
{
	MCUCR = MCUCR & 0b11110011;
	event = event<<2;
	MCUCR = MCUCR & event;
}

void INT1_Enable ()
{
	SET_BIT(GICR, INT1);
}

void INT1_Disable ()
{
	CLR_BIT(GICR, INT1);
}

static void (*FUNC_PTR1)(void) = NULL;
void INT1_Interrupt (void (*func)(void))
{
	FUNC_PTR1 = func;
}

ISR(INT1_vect)
{
	if (FUNC_PTR1 != NULLPTR)
	{
		FUNC_PTR1();
	}
}
/////////////////////////////////////////////////////////////

void INT2_Init (INT2_Event_type event)
{
	if (INT2_FALLING_EDGE)
	{
		CLR_BIT (MCUCSR, ISC2);
	}
	else if (INT2_RISING_EDGE)
	{
		SET_BIT (MCUCSR, ISC2);
	}
}

void INT2_Enable ()
{
	SET_BIT(GICR, INT2);
}

void INT2_Disable ()
{
	CLR_BIT(GICR, INT2);
}

static void (*FUNC_PTR2)(void) = NULL;
void INT2_Interrupt (void (*func)(void))
{
	FUNC_PTR2 = func;
}

ISR(INT2_vect)
{
	if (FUNC_PTR2 != NULLPTR)
	{
		FUNC_PTR2();
	}
}