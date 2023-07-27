 


#ifndef SEGMENTS_H_
#define SEGMENTS_H_

#include "SEGMENTS_Lcfg.h"
#include "DIO_interface.h"
#include "StdTypes.h"


//cathode
//LEFT
void SEGMENTS_left (u8 number);

//cathode
//RIGHT
void SEGMENTS_right (u8 number);

//anode
void SEGMENTS2 (u8 number);

//BCD
void SEGMENTS3 (u8 number);

// 4 mSec delay
//needed to check periodically
//2 digit cathode 7 segment 
void SEGMENTS_STOP_Watch (u8 number);

#endif /* SEGMENTS_H_ */