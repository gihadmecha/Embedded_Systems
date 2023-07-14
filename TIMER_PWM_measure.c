
#include "DIO_interface.h"
#include "TIMER1.h"
#include "LCD.h"
#include "TIMER_SERVICES.h"

//void timeStampFunction ();
//void overflowFunction ();
//
//static volatile u8 edgeFlag = 1;
//static u16 TCNT1ON = 0;
//static u16 TCNT1OFF = 0;
//static u32 overflowInterruptCounter = 0;
//static u32 overflowInterruptCounterTon = 0;
//static u32 overflowInterruptCounterToff = 0;
//static u32 noOfTicksON = 0;
//static u32 noOfTicksOFF = 0;

int main ()
{
	DIO_Init();
	TIMER1_Init(TIMER1_PRESCALER_8, TIMER1_NORMAL, TIMER1_OC1_DISCONNECTED, TIMER1_OC1_DISCONNECTED);
	//TIMER1_ICPedgeMode (TIMER1_ICU_RAISING_EDGE);
	LCD_Init();
	
	SEI();
	//TIMER1_timeStamp_interruptEnable ();
	//TIMER1_overflow_interruptEnable ();
//
	//TIMER1_overflowInterruptSet (overflowFunction);
	//TIMER1_timeStampInterruptSet (timeStampFunction);
	
	//u16 Ton = 0;
	//u16 Toff = 0;
	//u16 T = 0;
	//u16 frequency = 0;
	//u16 dutyCycle = 0;
	
	u32 frequency = 0;
	u8 dutyCycle = 0;
	
	while (1)
	{
		//_delay_ms(700);
		
		//if (edgeFlag == 4)
		//{
			//edgeFlag = 2;
			//
			//noOfTicksON = TCNT1ON + TIMER1_NO_OF_TICKS * overflowInterruptCounterTon;
			//noOfTicksOFF = TCNT1OFF + TIMER1_NO_OF_TICKS * overflowInterruptCounterToff;
			//
			//// in mSec
			//Ton = noOfTicksON * TIMER1_TICK_TIME * 1000;
			//Toff = noOfTicksOFF * TIMER1_TICK_TIME * 1000;
			//T = Ton + Toff;
			//
			//frequency = 1.0 / (T * 0.001);
			//
			//dutyCycle = ((Ton*1.0) / T) * 100;
			//
			//LCD_GoTo(0, 0);
			//LCD_WriteNumber(frequency);
			//
			//LCD_GoTo(1, 0);
			//LCD_WriteNumber_4Digit(T);
			//
			//LCD_GoTo(0, 6);
			//LCD_WriteNumber_4Digit(dutyCycle);
			//
			//LCD_GoTo(1, 6);
			//LCD_WriteNumber(Ton);
		//}
		//
		
		PWM_measure (&frequency, &dutyCycle);

		LCD_GoTo(0, 0);
		LCD_WriteNumber_4Digit(frequency);
		
		LCD_GoTo(1, 0);
		LCD_WriteNumber_4Digit(dutyCycle);
	}
}

//void timeStampFunction ()
//{
	//if (edgeFlag == 1)
	//{
		//edgeFlag = 2;
		//TIMER1_ICPedgeMode (TIMER1_ICU_FALLING_EDGE);
		//
		//TIMER1_TCNT1_WRITE(0);
		//overflowInterruptCounter = 0;
	//}
	//else if (edgeFlag == 2)
	//{
		//edgeFlag = 3;
		//TIMER1_ICPedgeMode (TIMER1_ICU_RAISING_EDGE);
		//
		//TCNT1ON = TIMER1_TCNT1_READ();
		//overflowInterruptCounterTon = overflowInterruptCounter;
		//
		//TIMER1_TCNT1_WRITE(0);
		//overflowInterruptCounter = 0;
	//}
	//else if (edgeFlag == 3)
	//{
		//edgeFlag = 4;
		//TIMER1_ICPedgeMode (TIMER1_ICU_FALLING_EDGE);
		//
		//TCNT1OFF = TIMER1_TCNT1_READ();
		//overflowInterruptCounterToff = overflowInterruptCounter;
		//
		//TIMER1_TCNT1_WRITE(0);
		//overflowInterruptCounter = 0;
	//}
//}
//
//void overflowFunction ()
//{
	//overflowInterruptCounter++;
//}