


#ifndef SERVO_H_
#define SERVO_H_

#include "StdTypes.h"
#include "TIMER1.h"
#include "SERVO_Lcfg.h"

//FAST PWM

/********************************************************************/
// note: it sets Timer1 TCNT TOP with [1.0/(50*TIMER1_TICK_TIME)]
/********************************************************************/

//F_CPU: 8000000 HZ
//timer1 prescaler: 8
//clear on compareMatch
void SERVO_setAngle (double angle);




#endif /* SERVO_H_ */