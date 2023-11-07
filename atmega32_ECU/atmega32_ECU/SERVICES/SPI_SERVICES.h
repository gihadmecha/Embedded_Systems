

#ifndef SPI_SERVICES_H_
#define SPI_SERVICES_H_

#include "DIO_interface.h"
#include "SPI.h"

#define		SLAVE1		PINC0
#define		SLAVE2		PINC1
#define		SLAVE3		PINC2

void SPI_sendRecieveArray (u8 arraySend[], u8 arrayRecieve[], u32 arraySize, u8 slaveNumber);


#endif /* SPI_SERVICES_H_ */