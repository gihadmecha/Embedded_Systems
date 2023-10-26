
#include "ultrasonic.h"

#include "ultrasonic.h"
#include "DIO_interface.h"
#include "TIMER1.h"
#include "LCD.h"

static void ICUFunction ();
static void overflowFunction ();

static u32 overflowCounter = 0;
static u8 edgeCounter = 1;
static u32 overflowCounterValue = 0;
static u16 TIMER1_TCNT1_value = 0;

void ultrasonic_Init ()
{
	DIO_Init();
	TIMER1_Init(TIMER1_PRESCALER_8, TIMER1_NORMAL, TIMER1_OC1A_DISCONNECTED, TIMER1_OC1B_DISCONNECTED);
	TIMER1_ICPedgeMode(TIMER1_ICU_RAISING_EDGE);
	
	
	SEI();
	TIMER1_timeStamp_interruptEnable();
	TIMER1_overflow_interruptEnable();
	
	TIMER1_timeStampInterruptSet(ICUFunction);
	TIMER1_overflowInterruptSet(overflowFunction);
}

double ultrasonic ()
{
	u32 noOfTicks = 0;
	double pulseDuration = 0;
	double time = 0;
	double distance = 0;
	double soundSpeed = (340.0 * 100) / 1000000.0;             //  centimeter/usec
	
	DIO_WritePin(PINB0, HIGH);
	_delay_us(10);
	DIO_WritePin(PINB0, LOW);
		
	_delay_us(8.0 * ( (1.0 / (40.0 * 1000)) * 1000000.0 ));
		
	noOfTicks = TIMER1_TCNT1_value + TIMER1_NO_OF_TICKS * overflowCounterValue;
		
	// in usec
	pulseDuration = TIMER1_TICK_TIME * 1000000.0 * noOfTicks;
		
	//LCD_GoTo(0, 0);
	//LCD_WriteNumber(pulseDuration);
	//LCD_WriteNumber_4Digit((u16)pulseDuration);
		
	time = pulseDuration / 2.0;
		
	return distance = time * soundSpeed;
}

void ICUFunction ()
{
	if (edgeCounter == 1)
	{
		edgeCounter = 2;
		TIMER1_TCNT1_WRITE (0);
		overflowCounter = 0;
		TIMER1_ICPedgeMode(TIMER1_ICU_FALLING_EDGE);
	}
	else if (edgeCounter == 2)
	{
		edgeCounter = 1;
		TIMER1_TCNT1_value = TIMER1_TCNT1_READ ();
		overflowCounterValue = overflowCounter;
		TIMER1_ICPedgeMode(TIMER1_ICU_RAISING_EDGE);
	}
}

void overflowFunction ()
{
	overflowCounter++;
}
