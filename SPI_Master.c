
//Master

#include "DIO_interface.h"
#include "SPI.h"
#include "LCD.h"

int main ()
{
	DIO_Init();
	SPI_InitMaster(SPI_PRESCALAR_4);
	LCD_Init();
	
	SPI_Enable();
	
	LCD_WriteString("Master");
	
	u8 counter = 0;
	
	u8 data_send = 'a';
	u8 data_recieve;
	
	while (1)
	{
		data_recieve = SPI_SendRecieve(data_send);
		
		//LCD_GoTo(1, 0);
		//LCD_WriteChar(data_send);
		LCD_GoTo(1, 6);
		LCD_WriteNumber_4Digit(data_recieve - '0');
		
		if (data_send > 'z')
			data_send = 'a';
		
		data_send++;
		
		
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