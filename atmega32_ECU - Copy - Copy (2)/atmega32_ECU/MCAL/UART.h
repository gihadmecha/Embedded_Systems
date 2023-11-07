

#ifndef UART_H_
#define UART_H_

#include "MemMap.h"
#include "StdTypes.h"
#include "UTILS.h"

void UART_Init ();

void UART_TransmitterEnable ();
void UART_TransmitterDisable ();
void UART_RecieverEnable ();
void UART_RecieverDisable ();

//u8 UART_Send (u8 data);
void UART_Send_polling (u8 data);
void UART_Send(u8 data);
u8 UART_Recieve_polling ();
u8 UART_Recieve_priodicCheck (char* data);
u8 UART_Recieve ();

void UART_RXcomplateInterruptEnable ();
void UART_RXcomplateInterruptDisable ();
void UART_TXcomplateInterruptEnable ();
void UART_TXcomplateInterruptDisable ();
void UART_UDRemptyInterruptEnable ();
void UART_UDRemptyInterruptDisable ();

void UART_RXcomplateInterruptSetFunction (void (*Func)(void));
void UART_TXcomplateInterruptSetFunction (void (*Func)(void));
void UART_UDRemptyInterruptSetFunction (void (*Func)(void));


#endif /* UART_H_ */