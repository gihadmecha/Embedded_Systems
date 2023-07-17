
#include "UART.h"

int main ()
{
	UART_Init();
	UART_TransmitterEnable();
	
	UART_Send_polling('A');
	//_delay_ms(1);
	UART_Send_polling('B');
	//_delay_ms(1);
	UART_Send_polling('C');
	//_delay_ms(1);
	while (1)
	{
		
	}
}