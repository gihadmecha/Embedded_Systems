
#include "transmit_UART_Protocol_on_DIO_Pin.h"

int received = 0;

void UART_pinInit()
{
	DIO_WritePin(PINC0, HIGH);
}

int UART_parityGenerator (u8 data)
{
	int counter = 0;
	for (int index = 0; index < 8; index++)
	{
		if ((data>>index)&1)
			counter++;
	}
	
	//odd parity
	if (counter&1)
		return 0;
	else
		return 1;
}

void UART_transmit (u8 data)
{
	// Baud Rate = 9600 bps
	
	// start bit
	DIO_WritePin(PINC0, LOW);
	_delay_us(104);
	
	// 8-bit data
	DIO_WritePin(PINC0,(data>>0)&1);
	_delay_us(104);
	DIO_WritePin(PINC0,(data>>1)&1);
	_delay_us(104);
	DIO_WritePin(PINC0,(data>>2)&1);
	_delay_us(104);
	DIO_WritePin(PINC0,(data>>3)&1);
	_delay_us(104);
	DIO_WritePin(PINC0,(data>>4)&1);
	_delay_us(104);
	DIO_WritePin(PINC0,(data>>5)&1);
	_delay_us(104);
	DIO_WritePin(PINC0,(data>>6)&1);
	_delay_us(104);
	DIO_WritePin(PINC0,(data>>7)&1);
	_delay_us(104);
	
	// parity bit
	DIO_WritePin(PINC0, UART_parityGenerator(data));
	_delay_us(104);
	
	// stop bit
	DIO_WritePin(PINC0,HIGH);
}

int UART_parityCheck (int data)
{
	int counter = 0;
	
	// odd parity
	for (int index = 0; index <= 8; index++)
	{
		counter += (data>>index) & 1;
	}
	
	if (counter & 1)
		return 1;
	else
		return 0;
}

int UART_frameCheck (int data)
{
	if (data>>9)
		return 1;
	else
		return 0;
}

void UART_receive ()
{
	received = 0;
	_delay_us(105);
	received |= (DIO_ReadPin(PIND2)<<0);
	_delay_us(105);
	received |= (DIO_ReadPin(PIND2)<<1);
	_delay_us(105);
	received |= (DIO_ReadPin(PIND2)<<2);
	_delay_us(105);
	received |= (DIO_ReadPin(PIND2)<<3);
	_delay_us(105);
	received |= (DIO_ReadPin(PIND2)<<4);
	_delay_us(105);
	received |= (DIO_ReadPin(PIND2)<<5);
	_delay_us(105);
	received |= (DIO_ReadPin(PIND2)<<6);
	_delay_us(105);
	received |= (DIO_ReadPin(PIND2)<<7);
	
	_delay_us(105);
	received |= (DIO_ReadPin(PIND2)<<8);
	
	_delay_us(105);
	received |= (DIO_ReadPin(PIND2)<<9);
	
	// parity check & Frame Check
	if (UART_parityCheck(received) == 0 && UART_frameCheck(received) == 0)
		received = 0;
}

void UART_receiveInit ()
{ 
	sei();
	EXI_INT0Init(EXI_FALLING_EDGE);
	EXI_INT0Enable ();
	EXI_INT0SetCallBack (UART_receive);
}
