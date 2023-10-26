
#include "POTONTIOMETER.h" 


u8 POTONTIOMETER1 ()
{
	return ((u32)ADC_Read_Polling(POT1_CHANNEL) * 100.0)/1023.0;
	//return ((u32)ADC_GetVolt(POT_CHANNEL) * 100.0)/5000.0;
}

u8 POTONTIOMETER2 ()
{
	return ((u32)ADC_Read_Polling(POT2_CHANNEL) * 100.0)/1023.0;
	//return ((u32)ADC_GetVolt(POT_CHANNEL) * 100.0)/5000.0;
}

u8 POTONTIOMETER3 ()
{
	return ((u32)ADC_Read_Polling(POT3_CHANNEL) * 100.0)/1023.0;
	//return ((u32)ADC_GetVolt(POT_CHANNEL) * 100.0)/5000.0;
}