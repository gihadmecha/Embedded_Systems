
#include "TIMER0_SERVICES.h"

u8 TIMER0_generatePWM_CTC_50dutyCycle (double frequency)
{
	double OCR0Value = (1.0/(2.0*frequency*TIMER0_TICK_TIME))-1.0;
	
	if (0 <= OCR0Value && OCR0Value <=255)
	{
		TIMER0_OCR0_WRITE (OCR0Value);
		return 1;
	}
	
	return 0;
}
