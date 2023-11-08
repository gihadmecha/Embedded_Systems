

//Slave

#include "DIO_interface.h"
#include "SPI.h"
#include "LCD.h"

static void SPI_recieveInterrupt ();

static u8 data_recieve[26] = {0};
static u8 data_recieve_Index = 0;

static u8 data_send[26] = "Master1";
static u8 data_send_Index = 0;

int main ()
{
	DIO_Init();
	SPI_InitSlave();
	LCD_Init();
	
	
	SPI_Enable();
	
	SPI_InterruptSet (SPI_recieveInterrupt);
	
	SPI_InterruptEnable();
	SEI();
	
	LCD_WriteString("Slave");
	
	u8 counter = 0;
	
	SPI_Send(0);
	
	while (1)
	{
		LCD_GoTo(1, 0);
		LCD_WriteString(data_recieve);
		
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
	if (data_send_Index > 0)
	{
		data_recieve[data_recieve_Index] = SPI_Recieve();
		data_recieve_Index++;
		if(data_recieve_Index >= 26)
		data_recieve_Index = 0;
	}
	
	SPI_Send(data_send[data_send_Index]);
	data_send_Index++;
	if(data_send_Index >= 26)
	data_send_Index = 0;
}