

#ifndef RC_CAR_H_
#define RC_CAR_H_

#include "MOTOR.h"

#define		FORWARD_BUTTON		BUTTON1
#define		LEFT_BUTTON			BUTTON2
#define		RIGHT_BUTTON		BUTTON3
#define		BACKWARD_BUTTON		BUTTON4

#define		STOP_BUTTON				BUTTON5
#define		TURN_LEFT_BUTTON		BUTTON6
#define		TURN_RIGHT_BUTTON		BUTTON7


void RC_forward ();
void RC_left ();
void RC_right ();
void RC_backward ();

void RC_stop ();
void RC_turnLeft ();
void RC_turnRight ();	


#endif /* RC_CAR_H_ */