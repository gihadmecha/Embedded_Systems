
#include "UART_SERVICES.h"
#include "DIO_interface.h"

void UART_sendString (char* string)
{
	u8 index = 0;
	for (		; string[index]; index++)
	{
		UART_Send_polling(string[index]);
	}
	UART_Send_polling(0);
}
////////////////////////////////////////////////////////////////////////////////

static void sendInterruptFunction ();

static char* stringsArray[20] = {NULLPTR};
static u8 stringsArrayPointer = 0;
static u8 doneString = 0;
static u8 charIndex = 0;

void UART_sendString_Asynchronous (char* string)
{
	UART_TXcomplateInterruptSetFunction (sendInterruptFunction);
	UART_TXcomplateInterruptEnable ();
	stringsArray[stringsArrayPointer] = string;
	UART_Send(stringsArray[doneString][charIndex]);
	if (stringsArrayPointer < 20)
	{
		stringsArrayPointer++;
	}
}

static void sendInterruptFunction ()
{
	if (doneString < stringsArrayPointer)
	{
		if (stringsArray[doneString][charIndex] != NULL)
		{
			charIndex++;
			UART_Send(stringsArray[doneString][charIndex]);
		}
		else
		{
			doneString++;
			charIndex = 0;
			if (doneString < stringsArrayPointer)
			{
				UART_Send(stringsArray[doneString][charIndex]);
				charIndex++;
			}
		}
	}
	else
	{
		stringsArrayPointer = 0;
		doneString = 0;
	}
} 

////////////////////////////////////////////////////////////////////////////////
void UART_recieveString_syncronous (char* string)
{
	static u8 index = 0;
	if (UART_Recieve_priodicCheck(string + index))
	{
		index++;
		if (string[index-1] == 13)
		{
			string[index-1] = 0;
			index = 0;
		}
	}
	
}


///////////////////////////////////////////////////////////////////////////////////

//static void recieveInterruptFunction ();
//
//static u8 recievedByteArray[258] = {0};
//static u8 recievedByteArrayPointer = 0;
//static u8 doneByte = 0;
//
//void UART_recieveString_Asyncronous (char* string)
//{
	//UART_RXcomplateInterruptSetFunction (recieveInterruptFunction);
	//UART_RXcomplateInterruptEnable ();
	//
	//while (doneByte < recievedByteArrayPointer)
	//{
		//if (recievedByteArray[doneByte] != 0)
		//{
			//string[doneByte] = recievedByteArray[doneByte];
			//doneByte++;
		//}
		//else 
		//{
			//string[doneByte] = 0;
			//recievedByteArrayPointer = 0;
			//doneByte = 0;
		//}
	//}
//}
//
//static void recieveInterruptFunction ()
//{
	//if (recievedByteArrayPointer < 258)
	//{
		//recievedByteArray [recievedByteArrayPointer] = UART_Recieve ();
		//recievedByteArrayPointer++;
	//}
//}
///////////////////////////////////////////////////////////////////////////////////////

static void recieveInterruptFunction ();

char* recieveStringsArray[20] = {NULLPTR};
static u8 recieveStringsArrayPointer = 0;
static u8 recieveDoneString = 0;
static u8 recieveCharIndex = 0;

void UART_recieveString_Asyncronous (char* string)
{
	UART_RXcomplateInterruptSetFunction (recieveInterruptFunction);
	UART_RXcomplateInterruptEnable ();
	recieveStringsArray[recieveStringsArrayPointer] = string;
	
	if (recieveStringsArrayPointer < 20)
	{
		recieveStringsArrayPointer++;
	}
	
}

static void recieveInterruptFunction ()
{
	
	if (recieveDoneString < recieveStringsArrayPointer)
	{
		
		recieveStringsArray[recieveDoneString][recieveCharIndex] = UART_Recieve();
		//LCD_GoTo(0, 6);
		//LCD_WriteChar(recieveStringsArray[recieveDoneString][recieveCharIndex]);
		if (recieveStringsArray[recieveDoneString][recieveCharIndex] != NULL)
		{
			recieveCharIndex++;
		}
		else
		{
			DIO_TogglePin(PINA0);
			recieveDoneString++;
			recieveCharIndex = 0;
		}
		
	}
	else
	{
		recieveStringsArrayPointer = 0;
		recieveDoneString = 0;
	}
}

///////////////////////////////////////////////////////////////////////////////////////


static u8 string_length (char* string)
{
	u8 stringLength = 0;
	for (stringLength = 0; string[stringLength]; stringLength++);
	return stringLength;
}

static u16 string_sum (char* string)
{
	u16 sum = 0;
	
	for (u8 index = 0; string[index]; index++)
	{
		sum += string[index];
	}
	
	return sum;
}

static char sendCheckSumString[258];
void UART_send_checkSum (char* string)
{
	u8 index = 0;
	
	u8 stringLength = string_length(string);
	sendCheckSumString[0] = stringLength;
	
	index = 1;
	for (		; index <= stringLength; index++)
	{
		sendCheckSumString[index] = string[index - 1];
	}
	
	u16 stringSum = string_sum(string);
	char* stringSumPointer = &stringSum;
	sendCheckSumString[index] = stringSumPointer[1];
	index++;
	sendCheckSumString[index] = stringSumPointer[0];
	index++;
	sendCheckSumString[index] = 0;
	
	UART_sendString_Asynchronous(sendCheckSumString);
}
//////////////////////////////////////////////////////////////////////////////////


static char recieveCheckSumString[258] = {0};
u8 UART_recieve_checkSum (char* string)
{
	UART_recieveString_Asyncronous(recieveCheckSumString);
	
	u8 index = 1;
	for (		; index <= recieveCheckSumString[0]; index++)
	{
		string[index - 1] = recieveCheckSumString[index];
	}
	
	if (recieveCheckSumString[0] != NULL)
	{
		string[recieveCheckSumString[0]] = 0;
	}
	
	u16 stringSum = (u16)recieveCheckSumString[index] << 8;
	index++;
	stringSum += recieveCheckSumString[index];
	
	if (string_sum(string) == stringSum)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}