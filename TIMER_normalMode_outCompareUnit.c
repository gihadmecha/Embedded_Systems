
#include "DIO_interface.h"
#include "TIMER0.h"
#include "LCD.h"

static void timer0CompareMatchFunction();

int main()
{
	DIO_Init();
	TIMER0_Init( TIMER0_PRESCALER_8, TIMER0_NORMAL, TIMER0_OC0_TOGGLE_ON_COMPARE_MATCH);
	LCD_Init();
	
	SEI();
	TIMER0_OCM_interruptEnable();
	
	TIMER0_compareMatchInterruptSet(timer0CompareMatchFunction);

	while(1)
	{
		LCD_GoTo(0, 0);
		LCD_WriteNumber(TIMER0_OCR0_READ());
	}
}

static void timer0CompareMatchFunction()
{
	TIMER0_OCR0_WRITE (TIMER0_OCR0_READ() + 10);
	DIO_TogglePin(PINA0);
}


//#include "DIO_interface.h"
//#include "TIMER0_SERVICES.h"
//#include "LCD.h"
//
//void timer0CompareMatchISR ()
//{
	//OCR0 = OCR0 + 10;
	//DIO_TogglePin(PINA0);
//}
//
//int main()
//{
	//DIO_Init();
	//TIMER0_Init ( TIMER0_PRESCALER_8, TIMER0_NORMAL, TIMER0_OC0_TOGGLE_ON_COMPARE_MATCH);
	//LCD_Init();
	//
	//SEI();
	//TIMER0_OCM_interruptEnable();
	//
	//TIMER0_compareMatchInterruptSet (timer0CompareMatchISR);
	//
	//OCR0 = 0;
	//
	//while (1)
	//{
		//LCD_GoTo(0,0);
		//LCD_WriteNumber_4Digit(OCR0);
	//}
//}