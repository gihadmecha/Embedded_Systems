
#include "ultrasonic.h"
#include "DIO_interface.h"
#include "TIMER1.h"

//from HCSR04 ultrasonic dataSheet
#define		kHZ_TO_HZ											1000.0
#define		SEC_TO_USEC											1000000.0
#define		NO_OF_CYCLES_BURST_OF_ULTRASOUND					8.0
#define		FREQUENCY_OF_CYCLE_BURST_OF_ULTRASOUND_kHZ			40.0         //kHZ
#define	    TIME_OF_8_CYCLES_BURST_OF_ULTRASOUND_USEC			( (NO_OF_CYCLES_BURST_OF_ULTRASOUND * (1.0 / (FREQUENCY_OF_CYCLE_BURST_OF_ULTRASOUND_kHZ * kHZ_TO_HZ))) * SEC_TO_USEC  )		//usec

#define		SOUND_SPEED_M_SEC									340.29
#define		M_TO_CM												100.0
#define		SOUND_SPEED_CM_SEC									(SOUND_SPEED_M_SEC * M_TO_CM)		//  centimeter/sec

static u32 overflowCounter = 0;
volatile static u8 edgeCounter = 1;
static u32 overflowCounterValue = 0;
static u16 TIMER1_TCNT1_firstValue = 0;
static u16 TIMER1_TCNT1_secondValue = 0;

void ultrasonic_Init ()
{
	TIMER1_ICPedgeMode(TIMER1_ICU_RAISING_EDGE);
	
	SEI();
	TIMER1_timeStamp_interruptEnable();
	TIMER1_overflow_interruptEnable();
	
	TIMER1_timeStampInterruptSet(ICUFunction);
	TIMER1_overflowInterruptSet(overflowFunction);
}

double ultrasonic1 ()
{
	u32 noOfTicks = 0;
	double pulseDuration = 0;
	double time = 0;
	double distance = 0;
	
	DIO_WritePin(ULTRASONIC1_TRIGGER_PIN, HIGH);
	_delay_us(10);
	DIO_WritePin(ULTRASONIC1_TRIGGER_PIN, LOW);
	
	_delay_us(TIME_OF_8_CYCLES_BURST_OF_ULTRASOUND_USEC);
	
	while (edgeCounter == 2);
	
	noOfTicks = (TIMER1_TCNT1_secondValue + TIMER1_TOP_VALUE * overflowCounterValue) - TIMER1_TCNT1_firstValue;
	
	// in sec
	pulseDuration = TIMER1_TICK_TIME * noOfTicks;
	
	time = pulseDuration / 2.0;
	
	return distance = time * SOUND_SPEED_CM_SEC;
}

double ultrasonic2 ()
{
	u32 noOfTicks = 0;
	double pulseDuration = 0;
	double time = 0;
	double distance = 0;
	
	DIO_WritePin(ULTRASONIC2_TRIGGER_PIN, HIGH);
	_delay_us(10);
	DIO_WritePin(ULTRASONIC2_TRIGGER_PIN, LOW);
	
	_delay_us(TIME_OF_8_CYCLES_BURST_OF_ULTRASOUND_USEC);
	
	while (edgeCounter == 2);
	
	noOfTicks = (TIMER1_TCNT1_secondValue + TIMER1_TOP_VALUE * overflowCounterValue) - TIMER1_TCNT1_firstValue;
	
	// in sec
	pulseDuration = TIMER1_TICK_TIME * noOfTicks;
	
	time = pulseDuration / 2.0;
	
	return distance = time * SOUND_SPEED_CM_SEC;
}

double ultrasonic3 ()
{
	u32 noOfTicks = 0;
	double pulseDuration = 0;
	double time = 0;
	double distance = 0;
	
	DIO_WritePin(ULTRASONIC3_TRIGGER_PIN, HIGH);
	_delay_us(10);
	DIO_WritePin(ULTRASONIC3_TRIGGER_PIN, LOW);
	
	_delay_us(TIME_OF_8_CYCLES_BURST_OF_ULTRASOUND_USEC);
	
	while (edgeCounter == 2);
	
	noOfTicks = (TIMER1_TCNT1_secondValue + TIMER1_TOP_VALUE * overflowCounterValue) - TIMER1_TCNT1_firstValue;
	
	// in sec
	pulseDuration = TIMER1_TICK_TIME * noOfTicks;
	
	time = pulseDuration / 2.0;
	
	return distance = time * SOUND_SPEED_CM_SEC;
}

double ultrasonic4 ()
{
	u32 noOfTicks = 0;
	double pulseDuration = 0;
	double time = 0;
	double distance = 0;
	
	DIO_WritePin(ULTRASONIC4_TRIGGER_PIN, HIGH);
	_delay_us(10);
	DIO_WritePin(ULTRASONIC4_TRIGGER_PIN, LOW);
	
	_delay_us(TIME_OF_8_CYCLES_BURST_OF_ULTRASOUND_USEC);
	
	while (edgeCounter == 2);
	
	noOfTicks = (TIMER1_TCNT1_secondValue + TIMER1_TOP_VALUE * overflowCounterValue) - TIMER1_TCNT1_firstValue;
	
	// in sec
	pulseDuration = TIMER1_TICK_TIME * noOfTicks;
	
	time = pulseDuration / 2.0;
	
	return distance = time * SOUND_SPEED_CM_SEC;
}

void ICUFunction ()
{
	if (edgeCounter == 1)
	{
		edgeCounter = 2;
		TIMER1_TCNT1_firstValue = TIMER1_TCNT1_READ ();
		overflowCounter = 0;
		TIMER1_ICPedgeMode(TIMER1_ICU_FALLING_EDGE);
	}
	else if (edgeCounter == 2)
	{
		TIMER1_TCNT1_secondValue = TIMER1_TCNT1_READ ();
		overflowCounterValue = overflowCounter;
		TIMER1_ICPedgeMode(TIMER1_ICU_RAISING_EDGE);
		edgeCounter = 1;
	}
}

void overflowFunction ()
{
	overflowCounter++;
}
