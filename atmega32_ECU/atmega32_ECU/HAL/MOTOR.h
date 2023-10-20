

#ifndef MOTOR_H_
#define MOTOR_H_

#include "MOTOR_Lcfg.h"
#include "DIO_interface.h"
#include "TIMER0.h"
#include "TIMER1.h"

#if (EN_M1 == OC1A_PIN) || (EN_M1 == OC1B_PIN)

void MOTOR1_Init ();
void MOTOR1_Forward (u8 dutyCycle);
void MOTOR1_backward (u8 dutyCycle);
void MOTOR1_Stop ();

#elif (EN_M1 == OC0_PIN) || (EN_M1 == OC2_PIN)

void MOTOR1_Forward (u8 dutyCycle);
void MOTOR1_backward (u8 dutyCycle);

#else

void MOTOR1_Forward ();
void MOTOR1_backward ();
void MOTOR1_Stop ();

#endif

void MOTOR2_Forward ();
void MOTOR2_backward ();
void MOTOR2_Stop ();

void MOTOR3_Forward ();
void MOTOR3_backward ();
void MOTOR3_Stop ();

void MOTOR4_Forward ();
void MOTOR4_backward ();
void MOTOR4_Stop ();


#endif /* MOTOR_H_ */