

#ifndef TIMER0_LCFG_H_
#define TIMER0_LCFG_H_


#define		CPU_F				8000000.0				//HZ
#define		TIMER0_PRESCALAR			8.0
#define		TIMER0_TIMER_F				(CPU_F/TIMER0_PRESCALAR)		//HZ
#define		TIMER0_TICK_TIME			(1.0/TIMER0_TIMER_F)			//sec
#define		TIMER0_OVERFLOW_TICKS		256



#endif /* TIMER0_LCFG_H_ */