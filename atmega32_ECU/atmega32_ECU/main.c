
#include "DIO_interface.h"
#include "EXI.h"
#include "LCD.h"


static u8 INT0_read = 0;
static u8 INT1_read = 0;
static u8 INT2_read = 0;

void INT0_InterruptFunction ()
{
	INT0_read ^= 1;
}

void INT1_InterruptFunction ()
{
	INT1_read ^= 1;
}

void INT2_InterruptFunction ()
{
	INT2_read ^= 1;
}

int main ()
{
	DIO_Init();
	INT0_Init(INT0_FALLING_EDGE);
	INT1_Init(INT0_FALLING_EDGE);
	INT2_Init(INT0_FALLING_EDGE);
	LCD_Init();
	SEI();
	INT0_Enable();
	INT1_Enable();
	INT2_Enable();
	INT0_Interrupt(INT0_InterruptFunction);
	INT1_Interrupt(INT1_InterruptFunction);
	INT2_Interrupt(INT2_InterruptFunction);
	while (1)
	{
		LCD_GoTo(0, 0);
		LCD_WriteNumber(INT0_read);
		
		LCD_GoTo(0, 6);
		LCD_WriteNumber(INT1_read);
		
		LCD_GoTo(0, 11);
		LCD_WriteNumber(INT2_read);
	}
}