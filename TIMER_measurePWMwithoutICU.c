
#include "DIO_interface.h"
#include "TIMER1.h"
#include "LCD.h"
#include "EXI.h"

static u64 timer1OverflowCounter = 0;
static u64 timer1OverflowCounterValueON = 0;
static u64 timer1OverflowCounterValueOFF = 0;
static u16 timer1TCNTValueON = 0;
static u16 timer1TCNTValueOFF = 0;
static u8 edgeCounter = 1;

void INT0Function ();
void timer1OverflowInterruptFunction ();

int main ()
{
	DIO_Init();
	TIMER1_Init(TIMER1_PRESCALER_8, TIMER1_NORMAL, TIMER1_OC1_DISCONNECTED, TIMER1_OC1_DISCONNECTED);
	LCD_Init();
	INT0_Init(INT0_ANY_LOGICAL_CHANGE);
	
	SEI();
	INT0_Enable();
	TIMER1_overflow_interruptEnable ();
	
	INT0_Interrupt(INT0Function);
	TIMER1_overflowInterruptSet(timer1OverflowInterruptFunction);
	
	u64 timer1NoOfTicksON = 0;
	u64 timer1NoOfTicksOFF = 0;
	
	u32 Ton = 0;
	u32 Toff = 0;
	u32 T = 0;
	double frequency = 0;
	double dutyCycle = 0;
		
	while (1)
	{
		timer1NoOfTicksON = timer1TCNTValueON + timer1OverflowCounterValueON * TIMER1_NO_OF_TICKS;
		timer1NoOfTicksOFF = timer1TCNTValueOFF + timer1OverflowCounterValueOFF * TIMER1_NO_OF_TICKS;
		
		// in msec
		Ton = timer1NoOfTicksON * TIMER1_TICK_TIME * 1000;
		Toff = timer1NoOfTicksOFF * TIMER1_TICK_TIME * 1000;
		T = Ton + Toff;
		
		dutyCycle = ((Ton * 0.1) / T) * 100;
		
		frequency = 1.0 / (T * 0.001);
		
		LCD_GoTo(0, 0);
		LCD_WriteNumber((double)frequency);
		
		LCD_GoTo(0, 6);
		LCD_WriteNumber((double)Ton);
		
		LCD_GoTo(1, 0);
		LCD_WriteNumber((double)T);
		
		LCD_GoTo(1, 6);
		LCD_WriteNumber((double)dutyCycle);
	}
}

void INT0Function ()
{
	
	if (DIO_ReadPin(PIND2) == 1 && edgeCounter == 1)
	{
		timer1OverflowCounter = 0;
		TIMER1_TCNT1_WRITE (0);
		
		edgeCounter = 2;
	}
	else if (DIO_ReadPin(PIND2) == 0 && edgeCounter == 2)
	{
		timer1TCNTValueON = TIMER1_TCNT1_READ ();
		timer1OverflowCounterValueON = timer1OverflowCounter;
		
		timer1OverflowCounter = 0;
		TIMER1_TCNT1_WRITE (0);
		
		edgeCounter = 3;
	}
	else if (DIO_ReadPin(PIND2) == 1 && edgeCounter == 3)
	{
		timer1TCNTValueOFF = TIMER1_TCNT1_READ ();
		timer1OverflowCounterValueOFF = timer1OverflowCounter;
		
		timer1OverflowCounter = 0;
		TIMER1_TCNT1_WRITE (0);
		
		edgeCounter = 1;
	}
}

void timer1OverflowInterruptFunction ()
{
	timer1OverflowCounter++;
}