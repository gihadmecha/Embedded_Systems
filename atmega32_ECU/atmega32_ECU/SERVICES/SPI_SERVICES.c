

#include "SPI_SERVICES.h"

void SPI_sendRecieveArray (u8 arraySend[], u8 arrayRecieve[], u32 arraySize, u8 slaveNumber)
{
	switch (slaveNumber)
	{
		case 1:
		DIO_WritePin(SLAVE1, LOW);
		DIO_WritePin(SLAVE2, HIGH);
		DIO_WritePin(SLAVE3, HIGH);
		break;
		case 2:
		DIO_WritePin(SLAVE1, HIGH);
		DIO_WritePin(SLAVE2, LOW);
		DIO_WritePin(SLAVE3, HIGH);
		break;
		case 3:
		DIO_WritePin(SLAVE1, HIGH);
		DIO_WritePin(SLAVE2, HIGH);
		DIO_WritePin(SLAVE3, LOW);
		break;
	}
	
	SPI_SendRecieve (0);
	_delay_us(15);
	for (u32 index = 0; index <= arraySize; index++)
	{
		arrayRecieve[index] = SPI_SendRecieve (arraySend[index]);
		_delay_us(15);
	}
	
	DIO_WritePin(SLAVE1, HIGH);
	DIO_WritePin(SLAVE2, HIGH);
	DIO_WritePin(SLAVE3, HIGH);
}
