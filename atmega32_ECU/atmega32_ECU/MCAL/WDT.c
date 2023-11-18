
#include "WDT.h"

void WDT_Set (TimeOut_type time)
{
	// WDE SET, WDTOE Clear
	u8 wdt_value = 0x08; // 0b00001000
	wdt_value |= time;
	
	WDTCR |= (1<<WDTOE) | (1<<WDE);
	WDTCR = wdt_value;
}

void WDT_Stop ()
{
	WDTCR |= (1<<WDTOE) | (1<<WDE);
	WDTCR = 0;
}