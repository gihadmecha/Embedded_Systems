

#ifndef ADC_H_
#define ADC_H_

#include "MemMap.h"
#include "UTILS.h"
#include "StdTypes.h"

typedef enum {
	V_AREF,
	V_AVCC,
	V_INTERNAL = 3   //2.56v with external capacitor at AREF pin
	}voltage_reference_type;
	
typedef enum{
	PRESCALER_2 = 1,
	PRESCALER_4,
	PRESCALER_8,
	PRESCALER_16,
	PRESCALER_32,
	PRESCALER_64,
	PRESCALER_128
	}adc_prescaler_type;
	
typedef enum{
	CHANNEL_0,
	CHANNEL_1,
	CHANNEL_2,
	CHANNEL_3,
	CHANNEL_4,
	CHANNEL_5,
	CHANNEL_6,
	CHANNEL_7
	}channel_type;

void ADC_Init (voltage_reference_type Vref, adc_prescaler_type prescaler);
void ADC_Enable ();
void ADC_StartConversion (channel_type channel);
u16 ADC_Read_Polling (channel_type channel);
u8 ADC_Read (u16* data);
void ADC_Disable ();


#endif /* ADC_H_ */