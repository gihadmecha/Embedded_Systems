

#ifndef SPI_H_
#define SPI_H_

#include "MemMap.h"
#include "StdTypes.h"
#include "UTILS.h"

#include "SPI_Lcfg.h"

typedef enum {
	SPI_PRESCALAR_4,
	SPI_PRESCALAR_16,
	SPI_PRESCALAR_64,
	SPI_PRESCALAR_128,
	SPI_PRESCALAR_2,
	SPI_PRESCALAR_8,
	SPI_PRESCALAR_32,
	}spi_prescalar_type;
	
	
typedef enum {
	SPI_MSB,
	SPI_LSB
	}spi_dataOrder_type;

void SPI_InitMaster (spi_prescalar_type prescaler);
void SPI_InitSlave ();

void SPI_Enable ();
void SPI_Disable ();

u8 SPI_SendRecieve (u8 data);
void SPI_Send (u8 data);
u8 SPI_Recieve_periodicCheck (u8* data);
u8 SPI_Recieve ();

void SPI_InterruptEnable ();
void SPI_InterruptDisable ();

void SPI_InterruptSet (void (*Func)(void));

#endif /* SPI_H_ */