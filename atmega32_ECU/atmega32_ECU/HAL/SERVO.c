

#include "SERVO.h"

void SERVO_setAngle (double angle)
{
	// 50 HZ
	u16 top = 1.0/(50*TIMER1_TICK_TIME);
	u16 compareMatch = 999 + (1000 * ((90 + angle) / 180));
	
	switch (TOP)
	{
		case TIMER1_ICR:
		TIMER1_ICR1_WRITE (top);
		break;
	}
	
	switch (SERVO_PIN)
	{
		case OC1B_pin:
		TIMER1_OCR1B_WRITE (compareMatch);
		break;
	}
}