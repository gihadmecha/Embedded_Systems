


#ifndef ALARM_MASTER_PRIVATE_H_
#define ALARM_MASTER_PRIVATE_H_

#define		ALARM	0
#define		NORMAL	1

#define		FIRE	45
#define		HEAT	43

static void Alarm_master_Button ();
static void ALARM_master_INT0Interrupt ();
static void Alarm_master_getTemp ();
static void Alarm_master_tempInit ();
static void Alarm_master_led ();

#endif /* ALARM_MASTER_PRIVATE_H_ */