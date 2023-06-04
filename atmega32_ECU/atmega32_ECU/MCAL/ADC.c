
#include "ADC.h"

static u8 readFlag = 1;

void ADC_Init (voltage_reference_type Vref, adc_prescaler_type prescaler)
{
	// Vref
	switch (Vref)
	{
		case V_AREF:
		CLR_BIT(ADMUX, REFS1);
		CLR_BIT(ADMUX, REFS0);
		break;
		case V_AVCC:
		CLR_BIT(ADMUX, REFS1);
		SET_BIT(ADMUX, REFS0);
		break;
		case V_INTERNAL:
		SET_BIT(ADMUX, REFS1);
		SET_BIT(ADMUX, REFS0);
		break;
	}
	
	//prescaler
	switch (prescaler)
	{
		case PRESCALER_2:
		CLR_BIT(ADCSRA, ADPS2);
		CLR_BIT(ADCSRA, ADPS1);
		SET_BIT(ADCSRA, ADPS0);
		break;
		case PRESCALER_4:
		CLR_BIT(ADCSRA, ADPS2);
		SET_BIT(ADCSRA, ADPS1);
		CLR_BIT(ADCSRA, ADPS0);
		break;
		case PRESCALER_8:
		CLR_BIT(ADCSRA, ADPS2);
		SET_BIT(ADCSRA, ADPS1);
		SET_BIT(ADCSRA, ADPS0);
		break;
		case PRESCALER_16:
		SET_BIT(ADCSRA, ADPS2);
		CLR_BIT(ADCSRA, ADPS1);
		CLR_BIT(ADCSRA, ADPS0);
		break;
		case PRESCALER_32:
		SET_BIT(ADCSRA, ADPS2);
		CLR_BIT(ADCSRA, ADPS1);
		SET_BIT(ADCSRA, ADPS0);
		break;
		case PRESCALER_64:
		SET_BIT(ADCSRA, ADPS2);
		SET_BIT(ADCSRA, ADPS1);
		CLR_BIT(ADCSRA, ADPS0);
		break;
		case PRESCALER_128:
		SET_BIT(ADCSRA, ADPS2);
		SET_BIT(ADCSRA, ADPS1);
		SET_BIT(ADCSRA, ADPS0);
		break;
	}
	
	// adjust result
	
	//single or running conversion mode

}

void ADC_Enable ()
{
	SET_BIT(ADCSRA, ADEN);
}

void ADC_StartConversion (channel_type channel)
{
	if (readFlag == 1)
	{
		readFlag = 0;
		
		// select channel
		switch (channel)
		{
			case CHANNEL_0:
			CLR_BIT(ADMUX, MUX4);
			CLR_BIT(ADMUX, MUX3);
			CLR_BIT(ADMUX, MUX2);
			CLR_BIT(ADMUX, MUX1);
			CLR_BIT(ADMUX, MUX0);
			break;
			case CHANNEL_1:
			CLR_BIT(ADMUX, MUX4);
			CLR_BIT(ADMUX, MUX3);
			CLR_BIT(ADMUX, MUX2);
			CLR_BIT(ADMUX, MUX1);
			SET_BIT(ADMUX, MUX0);
			break;
			case CHANNEL_2:
			CLR_BIT(ADMUX, MUX4);
			CLR_BIT(ADMUX, MUX3);
			CLR_BIT(ADMUX, MUX2);
			SET_BIT(ADMUX, MUX1);
			CLR_BIT(ADMUX, MUX0);
			break;
			case CHANNEL_3:
			CLR_BIT(ADMUX, MUX4);
			CLR_BIT(ADMUX, MUX3);
			CLR_BIT(ADMUX, MUX2);
			SET_BIT(ADMUX, MUX1);
			SET_BIT(ADMUX, MUX0);
			break;
			case CHANNEL_4:
			CLR_BIT(ADMUX, MUX4);
			CLR_BIT(ADMUX, MUX3);
			SET_BIT(ADMUX, MUX2);
			CLR_BIT(ADMUX, MUX1);
			CLR_BIT(ADMUX, MUX0);
			break;
			case CHANNEL_5:
			CLR_BIT(ADMUX, MUX4);
			CLR_BIT(ADMUX, MUX3);
			SET_BIT(ADMUX, MUX2);
			CLR_BIT(ADMUX, MUX1);
			SET_BIT(ADMUX, MUX0);
			break;
			case CHANNEL_6:
			CLR_BIT(ADMUX, MUX4);
			CLR_BIT(ADMUX, MUX3);
			SET_BIT(ADMUX, MUX2);
			SET_BIT(ADMUX, MUX1);
			CLR_BIT(ADMUX, MUX0);
			break;
			case CHANNEL_7:
			CLR_BIT(ADMUX, MUX4);
			CLR_BIT(ADMUX, MUX3);
			SET_BIT(ADMUX, MUX2);
			SET_BIT(ADMUX, MUX1);
			SET_BIT(ADMUX, MUX0);
			break;
		}
		
		//start conversion
		SET_BIT(ADCSRA, ADSC);
	}
}

u16 ADC_Read_Polling (channel_type channel)
{
	
	// select channel
	switch (channel)
	{
		case CHANNEL_0:
		CLR_BIT(ADMUX, MUX4);
		CLR_BIT(ADMUX, MUX3);
		CLR_BIT(ADMUX, MUX2);
		CLR_BIT(ADMUX, MUX1);
		CLR_BIT(ADMUX, MUX0);
		break;
		case CHANNEL_1:
		CLR_BIT(ADMUX, MUX4);
		CLR_BIT(ADMUX, MUX3);
		CLR_BIT(ADMUX, MUX2);
		CLR_BIT(ADMUX, MUX1);
		SET_BIT(ADMUX, MUX0);
		break;
		case CHANNEL_2:
		CLR_BIT(ADMUX, MUX4);
		CLR_BIT(ADMUX, MUX3);
		CLR_BIT(ADMUX, MUX2);
		SET_BIT(ADMUX, MUX1);
		CLR_BIT(ADMUX, MUX0);
		break;
		case CHANNEL_3:
		CLR_BIT(ADMUX, MUX4);
		CLR_BIT(ADMUX, MUX3);
		CLR_BIT(ADMUX, MUX2);
		SET_BIT(ADMUX, MUX1);
		SET_BIT(ADMUX, MUX0);
		break;
		case CHANNEL_4:
		CLR_BIT(ADMUX, MUX4);
		CLR_BIT(ADMUX, MUX3);
		SET_BIT(ADMUX, MUX2);
		CLR_BIT(ADMUX, MUX1);
		CLR_BIT(ADMUX, MUX0);
		break;
		case CHANNEL_5:
		CLR_BIT(ADMUX, MUX4);
		CLR_BIT(ADMUX, MUX3);
		SET_BIT(ADMUX, MUX2);
		CLR_BIT(ADMUX, MUX1);
		SET_BIT(ADMUX, MUX0);
		break;
		case CHANNEL_6:
		CLR_BIT(ADMUX, MUX4);
		CLR_BIT(ADMUX, MUX3);
		SET_BIT(ADMUX, MUX2);
		SET_BIT(ADMUX, MUX1);
		CLR_BIT(ADMUX, MUX0);
		break;
		case CHANNEL_7:
		CLR_BIT(ADMUX, MUX4);
		CLR_BIT(ADMUX, MUX3);
		SET_BIT(ADMUX, MUX2);
		SET_BIT(ADMUX, MUX1);
		SET_BIT(ADMUX, MUX0);
		break;
	}
	
	//start conversion
	SET_BIT(ADCSRA, ADSC);
	
	//read
	//_delay_us (300);
	while (READ_BIT(ADCSRA, ADSC));
	return ADC;
}

u8 ADC_Read (u16* data)
{
	if (READ_BIT(ADCSRA, ADSC))
	{
		*data = ADC;
		readFlag = 1;
		return 1;
	}
	else
	{
		return 0;
	}
}

void ADC_Disable ()
{
	CLR_BIT(ADCSRA, ADEN);
}
