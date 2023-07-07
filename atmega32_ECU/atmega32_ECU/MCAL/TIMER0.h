


#ifndef TIMER0_H_
#define TIMER0_H_

#include "MemMap.h"
#include "StdTypes.h"
#include "UTILS.h"

#define		TCNT0_READ()	    TCNT0
#define		TCNT0_WRITE(data)	TCNT0 = data
#define		OCR0_READ()		    OCR0
#define		OCR0_WRITE(data)	OCR0 = data


typedef enum {
	TIMER0_PRESCALER_NO_CLOCK,
	TIMER0_PRESCALER_1,
	TIMER0_PRESCALER_8,
	TIMER0_PRESCALER_64,
	TIMER0_PRESCALER_256,
	TIMER0_PRESCALER_1024
}timer0_prescaler_type;

typedef enum {
	TIMER0_NORMAL,
	TIMER0_PHASE_CORRECT_PWM,
	TIMER0_CTC,
	TIMER0_FAST_PWM
}timer0_mode_type;

typedef enum {
	TIMER0_OC0_DISCONNECTED,
	TIMER0_OC0_TOGGLE_ON_COMPARE_MATCH,
	TIMER0_OC0_CLEAR_ON_COMPARE_MATCH,
	TIMER0_OC0_SET_ON_COMPARE_MATCH
	}timer0_OC0_mode_type;
	
void TIMER0_Init (timer0_prescaler_type prescaler, timer0_mode_type timerMode, timer0_OC0_mode_type OC0Mode);
void TIMER0_OCM_interruptEnable ();
void TIMER0_OCM_interruptDisable ();
void TIMER0_overflow_interruptEnable ();
void TIMER0_overflow_interruptDisable ();

#endif 