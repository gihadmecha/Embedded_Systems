 


#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_

#include "UART.h"

void UART_sendString (char* string);
void UART_sendString_Asynchronous (char* string);
void UART_recieveString_syncronous (char* string);
void UART_recieveString_Asyncronous (char* string);
void UART_send_checkSum (char* string);
u8 UART_recieve_checkSum (char* string);




#endif /* UART_SERVICES_H_ */