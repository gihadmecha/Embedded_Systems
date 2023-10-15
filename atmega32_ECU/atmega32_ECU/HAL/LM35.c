
#include "LM35.h"

u32	LM35()
{
	//return	((ADC_Read_Polling(LM35_CHANNEL) * 148)/ 303.0)+2;
	//return	(((u32)ADC_Read_Polling(LM35_CHANNEL) * 1480)/ 303.0)+20;
	
	//return	((ADC_Read_Polling(LM35_CHANNEL) * 150)/ 303.0);
	//return	(((u32)ADC_Read_Polling(LM35_CHANNEL) * 1500)/ 303.0);
	//return	ADC_GetVolt(LM35_CHANNEL)/10 ;

	return	ADC_GetVolt(LM35_CHANNEL);
}