
#include "UART_SERVICES.h"

void UART_sendString_synchronous (char* string)
{
	u8 index = 0;
	for (		; string[index]; index++)
	{
		UART_Send_polling(string[index]);
	}
	UART_Send_polling(0);
}

////////////////////////////////////////////////////////////////////////////////

void UART_recieveString_polling_syncronous (char* string)
{
	u8 index = 0;
	string[index] = UART_Recieve_polling();
	for (index = 0; string[index] != 13;		)
	{
		index++;
		string[index] = UART_Recieve_polling();
	}
	string[index] = 0;
}


////////////////////////////////////////////////////////////////////////////////
void UART_recieveString_periodicCheck_syncronous (char* string)
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

////////////////////////////////////////////////////////////////////////////////////

void UART_send32Number (u32 number)
{
	u32* pnumber = &number;
	UART_Send_polling(pnumber[0]);
	UART_Send_polling(pnumber[1]);
	UART_Send_polling(pnumber[2]);
	UART_Send_polling(pnumber[3]);
}
///////////////////////////////////////////////////////////////////////////////////

u32 UART_recieve32Number ()
{
	u8 byte0 = UART_Recieve_polling();
	u8 byte1 = UART_Recieve_polling();
	u8 byte2 = UART_Recieve_polling();
	u8 byte3 = UART_Recieve_polling();
	
	u32 number = ((u32)byte3<<24) | ((u32)byte2<<16) | ((u32)byte1<<8) | byte0;
	
	return number;
}

////////////////////////////////////////////////////////////////////////////////

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

void UART_send_checkSum_synchronous (char* string)
{
	u8 stringLength = string_length(string);
	UART_Send_polling(stringLength);
	
	for (u8	index = 0; index < stringLength; index++)
	{
		UART_Send_polling(string[index]);
	}
	
	u16 stringSum = string_sum(string);
	char* stringSumPointer = &stringSum;
	UART_Send_polling(stringSumPointer[0]);
	UART_Send_polling(stringSumPointer[1]);
}

/////////////////////////////////////////////////////////////////////////////////////

u8 UART_recieve_checkSum_synchronous (char* string)
{
	u8 length = UART_Recieve_polling();
	
	u8 index = 0;
	for (index = 0; index < length; index++)
	{
		string[index] = UART_Recieve_polling();
	}
	string[index] = NULL;
	
	u8 stringSum0 = UART_Recieve_polling(); 
	u8 stringSum1 = UART_Recieve_polling();
	
	u16 stringSum = (((u16)stringSum1)<<8) | stringSum0;
	
	if ( stringSum == string_sum(string))
	{
		return 1;
	}
	else
	{
		return 0;
	}
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

	if (stringsArrayPointer == 0)
	{
		UART_Send(stringsArray[doneString][charIndex]);
		
		charIndex++;
		
	}
	
	if (stringsArrayPointer < 20)
	{
		stringsArrayPointer++;
	}
}

static void sendInterruptFunction ()
{
	if (doneString < stringsArrayPointer)
	{
		UART_Send(stringsArray[doneString][charIndex]);
		
		if (stringsArray[doneString][charIndex] != NULL)
		{
			charIndex++;
		}
		else
		{
			doneString++;
			charIndex = 0;
		}
	}
	else
	{
		stringsArrayPointer = 0;
		doneString = 0;
	}
} 

//////////////////////////////////////////////////////////////////////////////////////

static void recieveInterruptFunction ();

static u8 recievedByteArray[258] = {0};
static u8 recievedByteArrayPointer = 0;
static u8 doneByte = 0;

//void UART_recieveString_Asyncronous (char* string)
//{
	//UART_RXcomplateInterruptSetFunction (recieveInterruptFunction);
	//UART_RXcomplateInterruptEnable ();
	//
	//while (doneByte < recievedByteArrayPointer)
	//{
		//if (recievedByteArray[doneByte] != 13)
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
		
		if (recieveStringsArray[recieveDoneString][recieveCharIndex] != 13)
		{
			recieveCharIndex++;
			recieveStringsArray[recieveDoneString][recieveCharIndex] = NULL;
		}
		else
		{
			recieveStringsArray[recieveDoneString][recieveCharIndex] = 13;
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