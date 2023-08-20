
#include "Fire_System_Private.h"
#include "Fire_System.h"

extern void Fire_System_Init ()
{
	DIO_Init();
	ADC_Init(ADC_VCC, ADC_PRESCALER_64);
	LCD_Init();
	
	ADC_Enable();
}

extern void Fire_System_Run ()
{
	
}
