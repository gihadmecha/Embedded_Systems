 

#ifndef TRANSMIT_UART_PROTOCOL_ON_DIO_PIN_H_
#define TRANSMIT_UART_PROTOCOL_ON_DIO_PIN_H_


#include "StdTypes.h"
#include "DIO_interface.h"
#include "EXI.h"

void UART_pinInit();
int UART_parityGenerator (u8 data);
void UART_transmit (u8 data);
void UART_receive ();
void UART_receiveInit ();



#endif /* TRANSMIT_UART_PROTOCOL_ON_DIO_PIN_H_ */