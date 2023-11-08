
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
	
	u8 arraySend1[] = "slave1";
	u8 arraySend1Size = sizeof (arraySend1)/sizeof(arraySend1[0]);
	u8 arraySend2[] = "slave2";
	u8 arraySend2Size = sizeof (arraySend2)/sizeof(arraySend2[0]);
	u8 arraySend3[] = "slave3";
	u8 arraySend3Size = sizeof (arraySend3)/sizeof(arraySend3[0]);
	
	u8 arrayRecieve[20] = {0};
	
	SPI_sendRecieveArray (arraySend1, arrayRecieve, arraySend1Size, 1);
	LCD_GoTo (1, 0);
	LCD_WriteString(arrayRecieve);
	
	SPI_sendRecieveArray (arraySend2, arrayRecieve, arraySend2Size, 2);
	LCD_GoTo (1, 0);
	LCD_WriteString(arrayRecieve);
	
	SPI_sendRecieveArray (arraySend3, arrayRecieve, arraySend3Size, 3);
	LCD_GoTo (1, 0);
	LCD_WriteString(arrayRecieve);
	
	while (1)
	{
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