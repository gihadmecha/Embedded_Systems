

#include "MQ_2.h"

extern u16 MQ_2 ()
{
	return (ADC_Read_Polling(MQ_2_1) * 100.0) / 1024.0;
}
