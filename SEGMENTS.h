

#ifndef SEGMENTS_H_
#define SEGMENTS_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"
#include "SEGMENTS_Lcfg.h"

void SEGMENTS1_Init();
void SEGMENTS2_Init();
void SEGMENTS1_2_Init();
void SEGMENTS2_2_Init();
void SEGMENTS3_2_Init ();
void SEGMENTS4_2_Init ();
void SEGMENTS1 (u8 digit);
void SEGMENTS1_2 (u8 digit);
void SEGMENTS2 (u8 digit);
void SEGMENTS2_2 (u8 digit);
void SEGMENTS3_2 (u8 digit);
void SEGMENTS4_2 (u8 digit);



#endif /* SEGMENTS_H_ */