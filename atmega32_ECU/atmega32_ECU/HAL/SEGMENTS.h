 


#ifndef SEGMENTS_H_
#define SEGMENTS_H_

#include "SEGMENTS_Lcfg.h"
#include "DIO_interface.h"
#include "StdTypes.h"


//cathode
void SEGMENTS1 (u8 number);

//anode
void SEGMENTS2 (u8 number);

//BCD
void SEGMENTS3 (u8 number);

//needed to check periodically
//2 digit cathode 7 segment 
void SEGMENTS4 (u8 number);

#endif /* SEGMENTS_H_ */