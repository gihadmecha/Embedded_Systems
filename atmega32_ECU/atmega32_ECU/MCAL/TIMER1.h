 


#ifndef TIMER1_H_
#define TIMER1_H_


#include "MemMap.h"
#include "StdTypes.h"
#include "UTILS.h"
#include "TIMER1_Lcfg.h"

#define		TIMER1_F				    (CPU_F/TIMER1_PRESCALAR)		//HZ
#define		TIMER1_TICK_TIME			(1.0/TIMER1_F)			        //sec
#define		TIMER1_NO_OF_TICKS			65536

#define		TIMER1_TCNT1_READ()				TCNT1
#define		TIMER1_TCNT1_WRITE(data)	    TCNT1 = data
#define		TIMER1_OCR1A_READ()				OCR1A
#define		TIMER1_OCR1A_WRITE(data)	    OCR1A = data
#define		TIMER1_OCR1B_READ()				OCR1B
#define		TIMER1_OCR1B_WRITE(data)	    OCR1B = data
#define		TIMER1_ICR1_READ()				ICR1
#define		TIMER1_ICR1_WRITE(data)			ICR1 = data


typedef enum {
	TIMER1_PRESCALER_NO_CLOCK,
	TIMER1_PRESCALER_1,
	TIMER1_PRESCALER_8,
	TIMER1_PRESCALER_64,
	TIMER1_PRESCALER_256,
	TIMER1_PRESCALER_1024
}timer1_prescaler_type;

typedef enum {
	TIMER1_NORMAL,
	TIMER1_PHASE_CORRECT_PWM_8BIT,
	TIMER1_PHASE_CORRECT_PWM_9BIT,
	TIMER1_PHASE_CORRECT_PWM_10BIT,
	TIMER1_CTC_OCR1A_TOP,
	TIMER1_FAST_PWM_8BIT,
	TIMER1_FAST_PWM_9BIT,
	TIMER1_FAST_PWM_10BIT,
	TIMER1_PHASE_FREQUENCY_CORRECT_PWM_ICR1_TOP,
	TIMER1_PHASE_FREQUENCY_CORRECT_PWM_OCR1A_TOP,
	TIMER1_PHASE_CORRECT_PWM_ICR1_TOP,
	TIMER1_PHASE_CORRECT_PWM_OCR1A_TOP,
	TIMER1_CTC_ICR1_TOP,
	TIMER1_FAST_PWM_ICR1_TOP = 14,
	TIMER1_FAST_PWM_OCR1A_TOP,
}timer1_mode_type;

typedef enum {
	TIMER1_OC1A_DISCONNECTED,
	TIMER1_OC1A_TOGGLE_ON_COMPARE_MATCH,
	TIMER1_OC1A_CLEAR_ON_COMPARE_MATCH,
	TIMER1_OC1A_SET_ON_COMPARE_MATCH
}timer1_OC1A_mode_type;

typedef enum {
	TIMER1_OC1B_DISCONNECTED,
	TIMER1_OC1B_TOGGLE_ON_COMPARE_MATCH,
	TIMER1_OC1B_CLEAR_ON_COMPARE_MATCH,
	TIMER1_OC1B_SET_ON_COMPARE_MATCH
}timer1_OC1B_mode_type;

typedef enum {
	TIMER1_ICU_FALLING_EDGE,
	TIMER1_ICU_RAISING_EDGE
	}timer1_ICP_EDGE_type;

void TIMER1_Init (timer1_prescaler_type prescaler, timer1_mode_type timerMode, timer1_OC1A_mode_type OC1AMode, timer1_OC1B_mode_type OC1BMode);
void TIMER1_ICPedgeMode (timer1_ICP_EDGE_type edgeType);
void TIMER1_OCM1A_interruptEnable ();
void TIMER1_OCM1A_interruptDisable ();
void TIMER1_OCM1B_interruptEnable ();
void TIMER1_OCM1B_interruptDisable ();
void TIMER1_overflow_interruptEnable ();
void TIMER1_overflow_interruptDisable ();
void TIMER1_timeStamp_interruptEnable ();
void TIMER1_timeStamp_interruptDisable ();
void TIMER1_compareMatch1AInterruptSet (void (*func)(void));
void TIMER1_compareMatch1BInterruptSet (void (*func)(void));
void TIMER1_overflowInterruptSet (void (*func)(void));
void TIMER1_timeStampInterruptSet (void (*func)(void));



#endif /* TIMER1_H_ */