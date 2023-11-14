
#include "ALARM_slave_Private.h"
#include "ALARM_slave.h"

static volatile u8 temp = 0;
static u8 lastState = NORMAL;

extern void ALARM_slave_Init ()
{
	DIO_Init();
	//line idle
	DIO_WritePin(PINC0, HIGH);
	ADC_Init(ADC_VCC, ADC_PRESCALER_8);
	SPI_InitSlave();
	
	LCD_Init();
	
	ADC_Enable();
	SPI_Enable ();
	
	SPI_InterruptSet (ALARM_slave_SPIInterrupt);
	SPI_InterruptEnable ();
	SEI ();
	
	LCD_GoTo(0, 0);
	LCD_WriteString("Temp.");
}

extern void ALARM_slave_Run ()
{
	temp = AlARM_slave_LM35OutApproximation ();
	
	LCD_GoTo(1, 0);
	LCD_WriteNumber_4Digit((u16)temp);
	
	ALARM_slave_alarm ();
}

static u8 AlARM_slave_LM35OutApproximation ()
{
	return ( LM35() + 5	) / 10.0;
}

static void ALARM_slave_SPIInterrupt ()
{
	SPI_Send(temp);
}

static void ALARM_slave_alarm ()
{
	if (temp >= FIRE)
	{
		ALARM_slave_trigger();
		
		lastState = ALARM;
	}
	else if ((temp == HEAT) && lastState == ALARM)
	{
		ALARM_slave_trigger();
		
		lastState = NORMAL;
	}
	else if (temp < HEAT)
	{
		DIO_WritePin (PINC0, HIGH);
		
		lastState = NORMAL;
	}
	else
	{
		switch (lastState)
		{
			case ALARM:
			ALARM_slave_trigger();
			break;
		}
	}
}

static void ALARM_slave_trigger()
{
	DIO_WritePin (PINC0, LOW);
	DIO_WritePin (PINC0, HIGH);	
}