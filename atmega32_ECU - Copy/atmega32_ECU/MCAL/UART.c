
#include "UART.h"


void UART_Init ()
{
	//asyncronous mode
	SET_BIT (UCSRC, URSEL);
	CLR_BIT (UCSRC, UMSEL);
	
	//normal speed
	CLR_BIT (UCSRA, U2X);
	
	//no parity
	SET_BIT (UCSRC, URSEL);
	CLR_BIT (UCSRC, UPM1);
	CLR_BIT (UCSRC, UPM0);
	
	//1 stop bit
	SET_BIT (UCSRC, URSEL);
	CLR_BIT (UCSRC, USBS);
	
	//8 bit frame size
	SET_BIT (UCSRC, URSEL);
	CLR_BIT (UCSRC, UCSZ2);
	SET_BIT (UCSRC, UCSZ1);
	SET_BIT (UCSRC, UCSZ0);
	
	//no clock polarity
	SET_BIT (UCSRC, URSEL);
	CLR_BIT (UCSRC, UCPOL);
	
	//baud rate 9600 bps for 8MHZ crystal
	UBRRL = 51;
	CLR_BIT (UCSRC, URSEL);
	UBRRH = 0;
}

void UART_TransmitterEnable ()
{
	SET_BIT(UCSRB, TXEN);
}

void UART_TransmitterDisable ()
{
	CLR_BIT(UCSRB, TXEN);
}

void UART_RecieverEnable ()
{
	SET_BIT(UCSRB, RXEN);
}

void UART_RecieverDisable ()
{
	CLR_BIT(UCSRB, RXEN);
}

//u8 UART_Send (u8 data)
//{
	//if (READ_BIT (UCSRA, UDRE) == 1)
	//{
		//UDR = data;
		//return 1;
	//}
	//else
	//{
		//return 0;
	//}
//}

void UART_Send_polling (u8 data)
{
	//while (READ_BIT(UCSRA, TXC) == 1);    ??
	while (READ_BIT(UCSRA, UDRE) == 0);   
	UDR = data;
}

void UART_Send(u8 data)
{
	UDR = data;
}

u8 UART_Recieve_polling ()
{
	while (READ_BIT(UCSRA, RXC) == 0);
	return UDR;
}

u8 UART_Recieve_priodicCheck (char* data)
{
	if (READ_BIT(UCSRA, RXC) == 1)
	{
		*data = UDR;
		return 1;
	}
	
	return 0;
}

u8 UART_Recieve ()
{
	return UDR;
}

void UART_RXcomplateInterruptEnable ()
{
	SET_BIT(UCSRB, RXCIE);
}

void UART_RXcomplateInterruptDisable ()
{
	CLR_BIT(UCSRB, RXCIE);
}

void UART_TXcomplateInterruptEnable ()
{
	SET_BIT(UCSRB, TXCIE);
}

void UART_TXcomplateInterruptDisable ()
{
	CLR_BIT(UCSRB, RXCIE);
}

void UART_UDRemptyInterruptEnable ()
{
	SET_BIT(UCSRB, UDRIE);
}

void UART_UDRemptyInterruptDisable ()
{
	CLR_BIT(UCSRB, UDRIE);
}


static void (*RXcomplateInterruptPTR)(void) = NULLPTR;
static void (*TXcomplateInterruptPTR)(void) = NULLPTR;
static void (*UDRemptyInterruptPTR)(void) = NULLPTR;

void UART_RXcomplateInterruptSetFunction (void (*Func)(void))
{
	RXcomplateInterruptPTR = Func;
}

void UART_TXcomplateInterruptSetFunction (void (*Func)(void))
{
	TXcomplateInterruptPTR = Func;
}

void UART_UDRemptyInterruptSetFunction (void (*Func)(void))
{
	UDRemptyInterruptPTR = Func;
}

ISR (UART_RXC_vect)
{
	if (RXcomplateInterruptPTR != NULLPTR)
	{
		RXcomplateInterruptPTR();
	}
}

ISR (UART_TXC_vect)
{
	if (TXcomplateInterruptPTR != NULLPTR)
	{
		TXcomplateInterruptPTR();
	}
}

ISR (UART_UDRempty_vect)
{
	if (UDRemptyInterruptPTR != NULLPTR)
	{
		UDRemptyInterruptPTR();
	}
}