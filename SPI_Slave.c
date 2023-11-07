

//Slave

#include "DIO_interface.h"
#include "SPI.h"
#include "LCD.h"

static void SPI_recieveInterrupt ();

static u8 data_recieve[20] = {0};
static u8 data_recieve_Index = 0;

int main ()
{
	DIO_Init();
	SPI_InitSlave(SPI_PRESCALAR_4);
	LCD_Init();
	
	
	SPI_Enable();
	
	SPI_InterruptSet (SPI_recieveInterrupt);
	
	SPI_InterruptEnable();
	SEI();
	
	LCD_WriteString("Slave");
	
	u8 counter = 0;
	
	u8 data_send = '1';
	
	u8 data_recieve_NotReaded_Index = 0;
	
	while (1)
	{
		SPI_Send(data_send);
		
		//LCD_GoTo(1, 6);
		//LCD_WriteNumber_4Digit(data_send - '0');
		LCD_GoTo(1, 6);
		LCD_WriteChar(data_send);
		LCD_GoTo(1, 0);
		LCD_WriteChar(data_recieve[data_recieve_NotReaded_Index]);
		
		data_recieve_NotReaded_Index++;
		
		if(data_recieve_NotReaded_Index >= 26)
		data_recieve_NotReaded_Index = 0;
		
		data_send++;
		if (data_send > '9')
		data_send = '1';
		
		LCD_GoTo(0, 11);
		LCD_WriteNumber(counter);
		_delay_ms(600);
		counter++;
		if (counter == 10)
		{
			counter = 0;
		}
	}
}

static void SPI_recieveInterrupt ()
{
	data_recieve[data_recieve_Index] = SPI_Recieve();
	data_recieve_Index++;
	
	if(data_recieve_Index >= 26)
	data_recieve_Index = 0;
}