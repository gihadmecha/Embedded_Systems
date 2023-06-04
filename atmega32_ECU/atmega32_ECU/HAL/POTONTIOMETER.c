
#include "POTONTIOMETER.h" 


u8 POTONTIOMETER_Read ()
{
	return (ADC_Read_Polling(POT_CHANNEL) * 100.0)/1023.0;
}