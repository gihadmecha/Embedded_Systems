
#include "SPI.h"

void SPI_InitMaster (spi_prescalar_type prescaler)
{
	//Master SPI mode
	SET_BIT (SPCR, MSTR);
	
	//prescaler
	switch (prescaler)
	{
		case SPI_PRESCALAR_4:
		CLR_BIT (SPSR, SP12X);
		CLR_BIT (SPCR, SPR1);
		CLR_BIT (SPCR, SPR0);
		break;
		case SPI_PRESCALAR_16:
		CLR_BIT (SPSR, SP12X);
		CLR_BIT (SPCR, SPR1);
		SET_BIT (SPCR, SPR0);
		break;
		case SPI_PRESCALAR_64:
		CLR_BIT (SPSR, SP12X);
		SET_BIT (SPCR, SPR1);
		CLR_BIT (SPCR, SPR0);
		break;
		case SPI_PRESCALAR_128:
		CLR_BIT (SPSR, SP12X);
		SET_BIT (SPCR, SPR1);
		SET_BIT (SPCR, SPR0);
		break;
		case SPI_PRESCALAR_2:
		SET_BIT (SPSR, SP12X);
		CLR_BIT (SPCR, SPR1);
		CLR_BIT (SPCR, SPR0);
		break;
		case SPI_PRESCALAR_8:
		SET_BIT (SPSR, SP12X);
		CLR_BIT (SPCR, SPR1);
		SET_BIT (SPCR, SPR0);
		break;
		case SPI_PRESCALAR_32:
		SET_BIT (SPSR, SP12X);
		SET_BIT (SPCR, SPR1);
		CLR_BIT (SPCR, SPR0);
		break;
	}
	
	//dataOrder
	if (DATA_ORDER == 1)
	{
		SET_BIT (SPCR, DORD);
	}
	else if (DATA_ORDER == 0)
	{
		CLR_BIT (SPCR, DORD);
	}
}

void SPI_InitSlave ()
{
	//Slave SPI mode
	CLR_BIT (SPCR, MSTR);
	
	//dataOrder
	if (DATA_ORDER == 1)
	{
		SET_BIT (SPCR, DORD);
	}
	else if (DATA_ORDER == 0)
	{
		CLR_BIT (SPCR, DORD);
	}
}


void SPI_Enable ()
{
	SET_BIT (SPCR, SPE);
}

void SPI_Disable ()
{
	CLR_BIT (SPCR, SPE);
}


u8 SPI_SendRecieve (u8 data)
{
	SPDR = data;
	while (READ_BIT(SPSR, SPIF) == 0);
	return SPDR;
}

u8 SPI_SendRecieve_runTimeOut (u8 data, u8* pdata_recieved, u8 time)
{
	SPDR = data;
	
	u8 counter = 0;
	while (READ_BIT(SPSR, SPIF) == 0 && counter < time)
	{
		_delay_ms(1);
		counter++;
	}
	
	if (counter == time)
	{
		return 0;
	}
	
	*pdata_recieved = SPDR;
	return 1;
}

void SPI_Send (u8 data)
{
	SPDR = data;
}

u8 SPI_Recieve_periodicCheck (u8* data)
{
	if (READ_BIT(SPSR, SPIF) == 1)
	{
		*data = SPDR;
		return 1;
	}
	
	return 0;
}

u8 SPI_Recieve()
{
	return SPDR;
}

void SPI_InterruptEnable ()
{
	SET_BIT (SPCR, SPIE);
}

void SPI_InterruptDisable ()
{
	CLR_BIT (SPCR, SPIE);
}


static void (*SPI_INTERRUP_PTR)(void) = NULLPTR;

void SPI_InterruptSet (void (*Func)(void))
{
	SPI_INTERRUP_PTR = Func;
}

ISR (SPI_Vect)
{
	if (SPI_INTERRUP_PTR != NULLPTR)
	{
		SPI_INTERRUP_PTR();
	}
}