
#include "TIMER_SERVICES.h"

static void timeStampFunction ();
static void overflowFunction ();

static volatile u8 edgeFlag = 1;
static u16 TCNT1ON = 0;
static u16 TCNT1OFF = 0;
static u32 overflowInterruptCounter = 0;
static u32 overflowInterruptCounterTon = 0;
static u32 overflowInterruptCounterToff = 0;
static u32 noOfTicksON = 0;
static u32 noOfTicksOFF = 0;

u8 TIMER0_generatePWM_CTC_50dutyCycle (double frequency)
{
	double OCR0Value = (1.0/(2.0*frequency*TIMER0_TICK_TIME))-1.0;
	
	if (0 <= OCR0Value && OCR0Value <=255)
	{
		TIMER0_OCR0_WRITE (OCR0Value);
		return 1;
	}
	
	return 0;
}



void PWM_measure (u32* frequency, u8* dutyCycle)
{
	SEI();
	TIMER1_timeStamp_interruptEnable ();
	TIMER1_overflow_interruptEnable ();
	
	TIMER1_overflowInterruptSet (overflowFunction);
	TIMER1_timeStampInterruptSet (timeStampFunction);
	
	u16 Ton = 0;
	u16 Toff = 0;
	u16 T = 0;
	
	if (edgeFlag == 5)
	{
		edgeFlag = 3;
		
		noOfTicksON = TCNT1ON + TIMER1_NO_OF_TICKS * overflowInterruptCounterTon;
		noOfTicksOFF = TCNT1OFF + TIMER1_NO_OF_TICKS * overflowInterruptCounterToff;
		
		// in mSec
		Ton = noOfTicksON * TIMER1_TICK_TIME * 1000;
		Toff = noOfTicksOFF * TIMER1_TICK_TIME * 1000;
		T = Ton + Toff;
		
		*frequency = 1.0 / (T * 0.001);
		
		*dutyCycle = ((Ton*1.0) / T) * 100;
	}
}

static void timeStampFunction ()
{
	if (edgeFlag == 1)
	{
		edgeFlag = 2;
		TIMER1_ICPedgeMode (TIMER1_ICU_RAISING_EDGE);
	}
	else if (edgeFlag == 2)
	{
		edgeFlag = 3;
		TIMER1_ICPedgeMode (TIMER1_ICU_FALLING_EDGE);
		
		TIMER1_TCNT1_WRITE(0);
		overflowInterruptCounter = 0;
	}
	else if (edgeFlag == 3)
	{
		edgeFlag = 4;
		TIMER1_ICPedgeMode (TIMER1_ICU_RAISING_EDGE);
		
		TCNT1ON = TIMER1_TCNT1_READ();
		overflowInterruptCounterTon = overflowInterruptCounter;
		
		TIMER1_TCNT1_WRITE(0);
		overflowInterruptCounter = 0;
	}
	else if (edgeFlag == 4)
	{
		edgeFlag = 5;
		TIMER1_ICPedgeMode (TIMER1_ICU_FALLING_EDGE);
		
		TCNT1OFF = TIMER1_TCNT1_READ();
		overflowInterruptCounterToff = overflowInterruptCounter;
		
		TIMER1_TCNT1_WRITE(0);
		overflowInterruptCounter = 0;
	}
}

static void overflowFunction ()
{
	overflowInterruptCounter++;
}
