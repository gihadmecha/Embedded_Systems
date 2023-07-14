 


#ifndef UTILS_H_
#define UTILS_H_

#define		F_CPU		8000000
#include <util/delay.h> 

#define		SET_BIT(reg, bit)				( reg = reg | (1 << bit) )
#define		CLR_BIT(reg, bit)				(reg = reg & (~(1<<bit)))
#define		READ_BIT(reg, bit)				((reg>>bit) & 1)
#define		WRITE_BIT(reg, bit, value)		(reg = (reg & (~(1<<bit))) | (1<<bit))	
#define		TOG_BIT(reg, bit)				(reg = reg^(1<<bit))



#endif /* UTILS_H_ */