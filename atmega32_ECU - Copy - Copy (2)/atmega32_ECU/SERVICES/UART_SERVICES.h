 


#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_

#include "UART.h"

void UART_sendString_synchronous (char* string);
void UART_recieveString_polling_syncronous (char* string);
void UART_recieveString_periodicCheck_syncronous (char* string);
void UART_send32Number (u32 number);
u32 UART_recieve32Number ();
void UART_send_checkSum_synchronous (char* string);
u8 UART_recieve_checkSum_synchronous (char* string);
void UART_sendString_Asynchronous (char* string);
void UART_recieveString_Asyncronous (char* string);
void UART_send_checkSum (char* string);
u8 UART_recieve_checkSum (char* string);




#endif /* UART_SERVICES_H_ */