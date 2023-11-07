
//Master

#include "DIO_interface.h"
#include "SPI_SERVICES.h"
#include "LCD.h"

int main ()
{
	DIO_Init();
	SPI_InitMaster(SPI_PRESCALAR_4);
	LCD_Init();
	
	SPI_Enable();
	
	LCD_WriteString("Master");
	
	u8 counter = 0;
	
	u8 arraySend[] = "master";
	u8 arrayRecieve[] = "salve";
	
	while (1)
	{
		SPI_sendRecieveArray (arraySend, arrayRecieve, 6, 1);
		
		LCD_GoTo (1, 0);
		LCD_WriteString(arrayRecieve);
		
		LCD_GoTo(0, 11);
		LCD_WriteNumber(counter);
		_delay_ms(200);
		counter++;
		if (counter == 10)
		{
			counter = 0;
		}
		
	}
}