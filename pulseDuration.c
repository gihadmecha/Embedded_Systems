
#include "DIO_interface.h"
#include "EXI.h"
#include "TIMER0.h"
#include "LCD.h"

static void INT0Function();
static void timer0OverflowFunction();

static u64 overflowCounter = 0;
static u8 TCNT0Value = 0;
static u64 overflowCounterValue = 0;

int main()
{
	DIO_Init();
	INT0_Init(INT0_ANY_LOGICAL_CHANGE);
	TIMER0_Init( TIMER0_PRESCALER_8, TIMER0_NORMAL, TIMER0_OC0_DISCONNECTED);
	LCD_Init();
	
	SEI();
	INT0_Enable();
	TIMER0_overflow_interruptEnable();
	
	INT0_Interrupt(INT0Function);
	TIMER0_overflowInterruptSet(timer0OverflowFunction);
	
	u64 noOfTicks = 0;
	s32 time = 0;
	u8 counter = 0;

	while(1)
	{
		noOfTicks = TCNT0Value + overflowCounterValue * TIMER0_OVERFLOW_TICKS;
		time = noOfTicks * TIMER0_TICK_TIME * 1000.0;                                    //msec
		LCD_GoTo(0, 0);
		LCD_WriteNumber(time);
		
		LCD_GoTo(1,0);
		LCD_WriteNumber(counter);
		_delay_ms(200);
		counter++;
		if (counter == 10)
		{
			counter = 0;
		}
	}
}

static void INT0Function()
{
	static u8 edgeFlag = 0;
	
	if (edgeFlag == 0)
	{
		TIMER0_TCNT0_WRITE (0);
		overflowCounter = 0;
		DIO_WritePin( PINA0, HIGH);
		edgeFlag = 1;
	}
	else
	{
		TCNT0Value = TIMER0_TCNT0_READ();
		overflowCounterValue = overflowCounter;
		DIO_WritePin( PINA0, LOW);
		edgeFlag = 0;
	}
}

static void timer0OverflowFunction()
{
	overflowCounter++;
}