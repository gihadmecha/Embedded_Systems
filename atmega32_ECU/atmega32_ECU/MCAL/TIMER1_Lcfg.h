 


#ifndef TIMER1_LCFG_H_
#define TIMER1_LCFG_H_

#define		CPU_F				        8000000.0				//HZ
#define		TIMER1_PRESCALAR			8.0

#define		TIMER1_ICR					1
#define		TIMER1_OC1A					2

#define		TOP							TIMER1_ICR

//#define		TIMER1_TOP_VALUE			TIMER1_NO_OF_TICKS
#define		TIMER1_TOP_VALUE			(1.0/(50*TIMER1_TICK_TIME))

#endif /* TIMER1_LCFG_H_ */