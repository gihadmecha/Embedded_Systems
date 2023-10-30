


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "ultrasonic_Lcfg.h"

void ultrasonic_Init ();
double ultrasonic ();
double ultrasonic1 ();
double ultrasonic2 ();
double ultrasonic3 ();
double ultrasonic4 ();

static void ICUFunction ();
static void overflowFunction ();

#endif /* ULTRASONIC_H_ */