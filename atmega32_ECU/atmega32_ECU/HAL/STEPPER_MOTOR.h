


#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

#include "STEPPER_MOTOR_Lcfg.h"
#include "DIO_interface.h"

#define		DELAY		500

//Bipoler Stepper Motor
//full Step
void STEPPER1_Forward ();
void STEPPER1_Backward ();
void STEPPER1_Stop ();

//unipoler Stepper Motor
//full Step
void STEPPER2_Forward ();
void STEPPER2_Backward ();
void STEPPER2_Stop ();

//unipoler Stepper Motor
//Half Step
void STEPPER3_Forward ();
void STEPPER3_Backward ();
void STEPPER3_Stop ();

#endif /* STEPPER_MOTOR_H_ */