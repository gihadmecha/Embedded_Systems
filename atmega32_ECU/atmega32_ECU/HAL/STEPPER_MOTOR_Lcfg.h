

#ifndef STEPPER_MOTOR_LCFG_H_
#define STEPPER_MOTOR_LCFG_H_

#define     STEPPER3_STEP_ANGLE				10

//Bi poler stepper Motor
#define		coilA1_STEPPER1		PINC3
#define		coilA2_STEPPER1		PINC4
#define		coilB1_STEPPER1		PINC5
#define		coilB2_STEPPER1		PINC6

//Unipolar stepper Motor
//Full Step
#define		coilA1_STEPPER2		PIND0
#define		coilA2_STEPPER2		PIND1
#define		coilB1_STEPPER2		PIND2
#define		coilB2_STEPPER2 	PIND3

//Unipolar stepper Motor
//Half Step
#define		coilA1_STEPPER3		PINC0
#define		coilA2_STEPPER3		PINC1
#define		coilB1_STEPPER3		PINC2
#define		coilB2_STEPPER3 	PINC3



#endif /* STEPPER_MOTOR_LCFG_H_ */