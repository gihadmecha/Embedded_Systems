

#ifndef ADC_H_
#define ADC_H_

#include "MemMap.h"
#include "UTILS.h"
#include "StdTypes.h"
#include "ADC_Lcfg.h"

typedef enum {
	ADC_AREF,
	ADC_VCC,
	ADC_V256 = 3   //2.56v with external capacitor at AREF pin
	}ADC_Vref_type;
	
typedef enum{
	ADC_PRESCALER_2 = 1,
	ADC_PRESCALER_4,
	ADC_PRESCALER_8,
	ADC_PRESCALER_16,
	ADC_PRESCALER_32,
	ADC_PRESCALER_64,
	ADC_PRESCALER_128
	}ADC_prescaler_type;
	
typedef enum{
	CHANNEL_0,
	CHANNEL_1,
	CHANNEL_2,
	CHANNEL_3,
	CHANNEL_4,
	CHANNEL_5,
	CHANNEL_6,
	CHANNEL_7
	}ADC_channel_type;

void ADC_Init (ADC_Vref_type Vref, ADC_prescaler_type prescaler);
void ADC_Enable ();
void ADC_InterruptEnable ();
void ADC_InterruptDisable ();
void ADC_StartConversion (ADC_channel_type channel);
u16 ADC_Read_Polling (ADC_channel_type channel);
u8 ADC_Read_periodicCheck (u16* data);
u16 ADC_Read ();
void ADC_Disable ();

void ADC_Interrupt (void (*funcptr)(void));

u16 ADC_GetVolt (ADC_channel_type channel);


#endif /* ADC_H_ */