

#ifndef WDT_H_
#define WDT_H_

#include "MemMap.h"
#include "StdTypes.h"
#include "UTILS.h"

typedef enum {
	timeout_16ms,
	timeout_32ms,
	timeout_65ms,
	timeout_130ms,
	timeout_260ms,
	timeout_520ms,
	timeout_1000ms,
	timeout_2100ms
	}TimeOut_type;

void WDT_Set (TimeOut_type time);
void WDT_Stop ();

#endif /* WDT_H_ */