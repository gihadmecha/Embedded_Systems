
#include "ALARM_master_Private.h"
#include "Alarm_master.h"

#define		Button		BUTTON1_IfPressed_PeriodicCheck
#define		LED_on		LED1_On
#define		LED_off		LED1_Off

static u8 temp = 0;

static u8 tempInitFlag = 1;
static u8 lastState = NORMAL;

void ALARM_master_Init ()
{
	DIO_Init();
	INT0_Init(INT0_FALLING_EDGE);
	SPI_InitMaster (SPI_PRESCALAR_4);
	
	LCD_Init();
	
	SPI_Enable ();
	
	INT0_Interrupt (ALARM_master_INT0Interrupt);
	INT0_Enable ();
	SEI ();
	
	LCD_GoTo(0, 0);
	LCD_WriteString("Temp.");
}

void ALARM_master_Run ()
{
	Alarm_master_tempInit ();
	
	LCD_GoTo(1, 0);
	LCD_WriteNumber_4Digit((u16)temp);
	
	Button (Alarm_master_Button);
	
	Alarm_master_led ();
}

static void Alarm_master_Button ()
{
	Alarm_master_getTemp ();
	
	if (temp <= HEAT)
	{
		lastState = NORMAL;
	}
}

static void ALARM_master_INT0Interrupt ()
{
	Alarm_master_getTemp ();
	
	lastState = ALARM;
}

static void Alarm_master_getTemp ()
{
	temp = SPI_SendRecieve(NULL);
	_delay_us(15);
	temp = SPI_SendRecieve(NULL);
}

static void Alarm_master_tempInit ()
{
	if (1 <= tempInitFlag && tempInitFlag < 20)
	{
		tempInitFlag++;
	}
	if (tempInitFlag == 20)
	{
		Alarm_master_getTemp ();
		
		tempInitFlag = 0;
	}
}

static void Alarm_master_led ()
{
	if (lastState == NORMAL)
	{
		LED_off ();
		BUZZER_Off();
	}
	else if (lastState == ALARM)
	{
		LED_on ();
		BUZZER_On();
	}
}