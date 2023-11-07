
#include "ADC.h"

static u8 readFlag = 1;

void ADC_Init (ADC_Vref_type Vref, ADC_prescaler_type prescaler)
{
	// Vref
	switch (Vref)
	{
		case ADC_AREF:
		CLR_BIT(ADMUX, REFS1);
		CLR_BIT(ADMUX, REFS0);
		break;
		case ADC_VCC:
		CLR_BIT(ADMUX, REFS1);
		SET_BIT(ADMUX, REFS0);
		break;
		case ADC_V256:
		SET_BIT(ADMUX, REFS1);
		SET_BIT(ADMUX, REFS0);
		break;
	}
	
	//prescaler
	// ADCSRA = (ADCSRA & 0b11111000) | prescaler;
	switch (prescaler)
	{
		case ADC_PRESCALER_2:
		CLR_BIT(ADCSRA, ADPS2);
		CLR_BIT(ADCSRA, ADPS1);
		SET_BIT(ADCSRA, ADPS0);
		break;
		case ADC_PRESCALER_4:
		CLR_BIT(ADCSRA, ADPS2);
		SET_BIT(ADCSRA, ADPS1);
		CLR_BIT(ADCSRA, ADPS0);
		break;
		case ADC_PRESCALER_8:
		CLR_BIT(ADCSRA, ADPS2);
		SET_BIT(ADCSRA, ADPS1);
		SET_BIT(ADCSRA, ADPS0);
		break;
		case ADC_PRESCALER_16:
		SET_BIT(ADCSRA, ADPS2);
		CLR_BIT(ADCSRA, ADPS1);
		CLR_BIT(ADCSRA, ADPS0);
		break;
		case ADC_PRESCALER_32:
		SET_BIT(ADCSRA, ADPS2);
		CLR_BIT(ADCSRA, ADPS1);
		SET_BIT(ADCSRA, ADPS0);
		break;
		case ADC_PRESCALER_64:
		SET_BIT(ADCSRA, ADPS2);
		SET_BIT(ADCSRA, ADPS1);
		CLR_BIT(ADCSRA, ADPS0);
		break;
		case ADC_PRESCALER_128:
		SET_BIT(ADCSRA, ADPS2);
		SET_BIT(ADCSRA, ADPS1);
		SET_BIT(ADCSRA, ADPS0);
		break;
	}
	
	// adjust result from left to right
	CLR_BIT(ADMUX, ADLAR);
	
	//single or running conversion mode

}

void ADC_Enable ()
{
	SET_BIT(ADCSRA, ADEN);
}

void ADC_InterruptEnable ()
{
	SET_BIT(ADCSRA, ADIE);
}

void ADC_InterruptDisable ()
{
	CLR_BIT(ADCSRA, ADIE);
}

void ADC_StartConversion (ADC_channel_type channel)
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

u16 ADC_Read_Polling (ADC_channel_type channel)
{
	
	// select channel
	//ADMUX = (ADMUX&0b11100000)|channel;
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
	while (READ_BIT(ADCSRA, ADSC));  //busy wait
	//return (((u16)ADCH)<<8)|ADCL;
	return ADC;
}

u8 ADC_Read_periodicCheck (u16* data)
{
	if (READ_BIT(ADCSRA, ADSC))
	{
		//*data = (((u16)ADCH)<<8)|ADCL;
		*data = ADC;
		readFlag = 1;
		return 1;
	}
	else
	{
		return 0;
	}
}

u16 ADC_Read ()
{
	readFlag = 1;
	return	ADC;
}

void ADC_Disable ()
{
	CLR_BIT(ADCSRA, ADEN);
}


u16 ADC_GetVolt (ADC_channel_type channel)
{
	return	((u32)ADC_Read_Polling(channel) * V_REF)/1024;
}

static void (*funcptr)(void) = NULL;

ISR(ADC_vect)
{
	if (funcptr != NULLPTR)
	{
		funcptr();
	}
}

void ADC_Interrupt (void (*func)(void))
{
	funcptr = func;
}