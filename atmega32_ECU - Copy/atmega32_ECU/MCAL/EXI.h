


#ifndef EXI_H_
#define EXI_H_

#include "MemMap.h"
#include "UTILS.h"
#include "StdTypes.h"

typedef enum {
	INT0_LOW,
	INT0_ANY_LOGICAL_CHANGE,
	INT0_FALLING_EDGE,
	INT0_RISING_EDGE
}INT0_Event_type;

typedef enum {
	INT1_LOW,
	INT1_ANY_LOGICAL_CHANGE,
	INT1_FALLING_EDGE,
	INT1_RISING_EDGE
}INT1_Event_type;

typedef enum {
	INT2_FALLING_EDGE,
	INT2_RISING_EDGE
}INT2_Event_type;

void INT0_Init (INT0_Event_type event);
void INT0_Enable ();
void INT0_Disable ();
void INT0_Interrupt (void (*func)(void));

void INT1_Init (INT1_Event_type event);
void INT1_Enable ();
void INT1_Disable ();
void INT1_Interrupt (void (*func)(void));

void INT2_Init (INT2_Event_type event);
void INT2_Enable ();
void INT2_Disable ();
void INT2_Interrupt (void (*func)(void));

#endif /* EXI_H_ */