

#include "SERVO.h"

void SERVO_setAngle (double angle)
{
	u16 top = 1.0/(50*0.000001);
	
	TIMER1_ICR1_WRITE (top);
	
	u16 compareMatch = 1000 + (1000 * ((90 + angle) / 180));
	
	TIMER1_OCR1B_WRITE (compareMatch);
}