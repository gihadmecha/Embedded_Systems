


#ifndef TIMER_SERVICES_H_
#define TIMER_SERVICES_H_

#include "StdTypes.h"
#include "TIMER0.h"
#include "TIMER1.h"

u8 TIMER0_generatePWM_CTC_50dutyCycle (double frequency);

void PWM_measure (u32* frequency, u8* dutyCycle);

#endif 