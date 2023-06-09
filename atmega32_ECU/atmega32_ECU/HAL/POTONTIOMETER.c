
#include "POTONTIOMETER.h" 


u8 POTONTIOMETER ()
{
	return ((u32)ADC_Read_Polling(POT_CHANNEL) * 100.0)/1023.0;
	//return ((u32)ADC_GetVolt(POT_CHANNEL) * 100.0)/5000.0;
}