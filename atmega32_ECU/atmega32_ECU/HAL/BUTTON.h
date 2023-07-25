


#ifndef BUTTON_H_
#define BUTTON_H_

#include "BUTTON_Lcfg.h"
#include "DIO_interface.h"
#include "StdTypes.h"

//needed to check periodically
void BUTTON1_IfPressed_PeriodicCheck (void(*FUNC_PTR)(void));

//needed to check periodically
void BUTTON2_IfPressed_PeriodicCheck (void(*FUNC_PTR)(void));

//needed to check periodically
void BUTTON_mode_IfPressed_PeriodicCheck (void(*FUNC_PTR)(void));



#endif /* BUTTON_H_ */