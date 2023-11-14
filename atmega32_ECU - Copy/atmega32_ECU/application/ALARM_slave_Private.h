

#ifndef ALARM_SLAVE_PRIVATE_H_
#define ALARM_SLAVE_PRIVATE_H_

#include "StdTypes.h"

#define		ALARM	0
#define		NORMAL	1

#define		FIRE	45
#define		HEAT	43

static void ALARM_slave_SPIInterrupt ();
static u8 AlARM_slave_LM35OutApproximation ();
static void ALARM_slave_alarm ();
static void ALARM_slave_trigger();



#endif /* ALARM_SLAVE_PRIVATE_H_ */