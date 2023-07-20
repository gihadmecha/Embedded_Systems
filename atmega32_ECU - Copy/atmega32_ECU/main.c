
//Reciever

#include "UART.h"
#include "DIO_interface.h"
#include "LCD.h"
#include "UART_SERVICES.h"

static void recieveInterruptFunction ();

static u8 recievedByteArray[20];
static u8 recievedByteArrayPointer = 0;
static u8 doneByte = 0;

int main ()
{
	UART_Init();
	UART_TransmitterEnable();
	UART_RecieverEnable();
	DIO_Init();
	LCD_Init();
	
	//UART_RXcomplateInterruptSetFunction (recieveInterruptFunction);
	
	SEI();
	//UART_RXcomplateInterruptEnable ();
	
	//UART_Send_polling('A');
	////_delay_ms(1);
	//UART_Send_polling('B');
	////_delay_ms(1);
	//UART_Send_polling('C');
	//_delay_ms(1);
	
	//UART_sendString ("Ahmed");
	////
	//UART_sendString_Asynchronous ("Mohamed");
	//
	//UART_sendString_Asynchronous ("Abd allah");
	////
	//UART_sendString_Asynchronous ("Omer");
	
	//UART_send_checkSum ("Ali");
	
	u8 recievedByte = 0;
	u8 counter = 0;
	u8 data = 0;
	u8 xlocation = 0;
	
	char name[255];
	char name2[255];
	
	LCD_GoTo(0, 0);
	LCD_WriteString("RX");
	
	while (1)
	{
		//LCD_GoTo(0, 0);
		//recievedByte = UART_Recieve_polling ();
		//LCD_WriteChar(recievedByte);
		
		//LCD_GoTo(0, xlocation);
		//if (UART_Recieve_priodicCheck (&data))
		//{
			//LCD_WriteChar(data);
			//xlocation++;
			//if (xlocation == 17)
			//{
				//xlocation = 0;
			//}
		//}
		
		//LCD_GoTo(0, xlocation);
		//if (doneByte < recievedByteArrayPointer)
		//{
			//LCD_WriteChar(recievedByteArray[doneByte]);
			//doneByte++;
			//xlocation++;
			//if (xlocation == 17)
			//{
				//xlocation = 0;
			//}
		//}
		
		
		//UART_recieveString_Asyncronous(name);
		//LCD_GoTo(0, 0);
		//LCD_WriteString(name);
		
		//UART_recieveString_syncronous(name);
		//LCD_GoTo(0, 0);
		//LCD_WriteString(name);
		
		if (UART_recieve_checkSum_synchronous (name))
		{
			LCD_GoTo(1, 6);
			LCD_WriteString(name);
		}
	
		
		//UART_send_checkSum("Ali");
		
		//if (UART_recieve_checkSum(name))
		//{
			//LCD_GoTo(0, 0);
			//LCD_WriteString(name);
		//}
		
		//if (UART_recieve_checkSum(name2))
		//{
			//LCD_GoTo(0, 6);
			//LCD_WriteString(name2);
		//}
		
		LCD_GoTo(1, 0);
		LCD_WriteNumber(counter);
		//_delay_ms(600);
		counter++;
		if (counter == 10)
		{
			counter = 0;
		}
	}
}

//static void recieveInterruptFunction ()
//{
	//recievedByteArray [recievedByteArrayPointer] = UART_Recieve ();
	//recievedByteArrayPointer++;
//}