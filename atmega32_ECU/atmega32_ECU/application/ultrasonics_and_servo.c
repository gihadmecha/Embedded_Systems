
#include "ultrasonics_and_servo.h"

#define		SERVO_POTENTIOMETER		POTONTIOMETER1()

void ultrasonics_and_servo_Init ()
{
	DIO_Init();
	ADC_Init(ADC_VCC, ADC_PRESCALER_8);
	TIMER1_OCR1A_WRITE (TIMER1_TOP_VALUE);
	TIMER1_Init(TIMER1_PRESCALER_8, TIMER1_FAST_PWM_OCR1A_TOP, TIMER1_OC1A_DISCONNECTED, TIMER1_OC1B_CLEAR_ON_COMPARE_MATCH);
	LCD_Init();
	ultrasonic_Init();
	
	ADC_Enable();
	
	LCD_GoTo(0, 0);
	LCD_WriteString("U1=");
	LCD_GoTo(0, 9);
	LCD_WriteString("U2=");
	LCD_GoTo(1, 0);
	LCD_WriteString("U3=");
	LCD_GoTo(1, 9);
	LCD_WriteString("U4=");
}

void ultrasonics_and_servo_Run ()
{
	
	LCD_GoTo(0, 3);
	LCD_WriteNumber_4Digit((u16)ultrasonic1 ());
	LCD_GoTo(0, 12);
	LCD_WriteNumber_4Digit((u16)ultrasonic2 ());
	LCD_GoTo(1, 3);
	LCD_WriteNumber_4Digit((u16)ultrasonic3 ());
	LCD_GoTo(1, 12);
	LCD_WriteNumber_4Digit((u16)ultrasonic4 ());
	
	SERVO_setAngle(ultrasonics_and_servo_servoAngle ());
}

static double ultrasonics_and_servo_servoAngle ()
{
	return ((SERVO_POTENTIOMETER * 180.0)/100.0) - 90.0;
}