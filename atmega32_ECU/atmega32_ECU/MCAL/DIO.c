
#include "DIO_interface.h"
#include "DIO_Private.h"



static void DIO_InitPin( DIO_pin_type pin, DIO_PinStatus_type status)
{
	if ( status == OUTPUT )
	{
		if ( pin >= PINA0 && pin <= PINA7 )
		{
			SET_BIT(DDRA, pin);
			CLR_BIT(PORTA, pin);
		}
		else if ( pin >= PINB0 && pin <= PINB7 )
		{
			pin = pin - PINB0;
			SET_BIT(DDRB, pin);
			CLR_BIT(PORTB, pin);
		}
		else if ( pin >= PINC0 && pin <= PINC7 )
		{
			pin = pin - PINC0;
			SET_BIT(DDRC, pin);
			CLR_BIT(PORTC, pin);
		}
		else if ( pin >= PIND0 && pin <= PIND7 )
		{
			pin = pin - PIND0;
			SET_BIT(DDRD, pin);
			CLR_BIT(PORTD, pin);
		}
	}
	else if ( status == INFREE )
	{
		if ( pin >= PINA0 && pin <= PINA7 )
		{
			CLR_BIT(DDRA, pin);
			CLR_BIT(PORTA, pin);
		}
		else if ( pin >= PINB0 && pin <= PINB7 )
		{
			pin = pin - PINB0;
			CLR_BIT(DDRB, pin);
			CLR_BIT(PORTB, pin);
		}
		else if ( pin >= PINC0 && pin <= PINC7 )
		{
			pin = pin - PINC0;
			CLR_BIT(DDRC, pin);
			CLR_BIT(PORTC, pin);
		}
		else if ( pin >= PIND0 && pin <= PIND7 )
		{
			pin = pin - PIND0;
			CLR_BIT(DDRD, pin);
			CLR_BIT(PORTD, pin);
		}
	}
	else if ( status == INPULL )
	{
		if ( pin >= PINA0 && pin <= PINA7 )
		{
			CLR_BIT(DDRA, pin);
			SET_BIT(PORTA, pin);
		}
		else if ( pin >= PINB0 && pin <= PINB7 )
		{
			pin = pin - PINB0;
			CLR_BIT(DDRB, pin);
			SET_BIT(PORTB, pin);
		}
		else if ( pin >= PINC0 && pin <= PINC7 )
		{
			pin = pin - PINC0;
			CLR_BIT(DDRC, pin);
			SET_BIT(PORTC, pin);
		}
		else if ( pin >= PIND0 && pin <= PIND7 )
		{
			pin = pin - PIND0;
			CLR_BIT(DDRD, pin);
			SET_BIT(PORTD, pin);
		}
	}
}

extern void DIO_Init()
{
	for (DIO_pin_type index = PINA0; index <= PIND7; index++)
	{
		DIO_InitPin(index, PinsStatusArray[index]);
	}
}

extern void DIO_WritePin(DIO_pin_type pin, DIO_pinVoltage_type volt)
{
	if ( volt == LOW )
	{
		if ( pin >= PINA0 && pin <= PINA7 )
		{
			CLR_BIT(PORTA, pin);
		}
		else if ( pin >= PINB0 && pin <= PINB7 )
		{
			pin = pin - PINB0;

			CLR_BIT(PORTB, pin);
		}
		else if ( pin >= PINC0 && pin <= PINC7 )
		{
			pin = pin - PINC0;

			CLR_BIT(PORTC, pin);
		}
		else if ( pin >= PIND0 && pin <= PIND7 )
		{
			pin = pin - PIND0;

			CLR_BIT(PORTD, pin);
		}
	}
	else if ( volt == HIGH )
	{
		if ( pin >= PINA0 && pin <= PINA7 )
		{
			SET_BIT(PORTA, pin);
		}
		else if ( pin >= PINB0 && pin <= PINB7 )
		{
			pin = pin - PINB0;

			SET_BIT(PORTB, pin);
		}
		else if ( pin >= PINC0 && pin <= PINC7 )
		{
			pin = pin - PINC0;

			SET_BIT(PORTC, pin);
		}
		else if ( pin >= PIND0 && pin <= PIND7 )
		{
			pin = pin - PIND0;

			SET_BIT(PORTD, pin);
		}
	}
}

void DIO_TogglePin(DIO_pin_type pin)
{
	if ( pin >= PINA0 && pin <= PINA7 )
	{
		TOG_BIT(PORTA, pin);
	}
	else if ( pin >= PINB0 && pin <= PINB7 )
	{
		pin = pin - PINB0;

		TOG_BIT(PORTB, pin);
	}
	else if ( pin >= PINC0 && pin <= PINC7 )
	{
		pin = pin - PINC0;

		TOG_BIT(PORTC, pin);
	}
	else if ( pin >= PIND0 && pin <= PIND7 )
	{
		pin = pin - PIND0;

		TOG_BIT(PORTD, pin);
	}
}

extern DIO_pinVoltage_type DIO_ReadPin(DIO_pin_type pin)
{
	if ( pin >= PINA0 && pin <= PINA7 )
	{
		return READ_BIT(PINA, pin);
	}
	else if ( pin >= PINB0 && pin <= PINB7 )
	{
		pin = pin - PINB0;

		return READ_BIT(PINB, pin);
	}
	else if ( pin >= PINC0 && pin <= PINC7 )
	{
		pin = pin - PINC0;

		return READ_BIT(PINC, pin);
	}
	else if ( pin >= PIND0 && pin <= PIND7 )
	{
		pin = pin - PIND0;

		return READ_BIT(PIND, pin);
	}
}

extern DIO_pinVoltage_type DIO_ReadPortRegister(DIO_pin_type pin)
{
	if ( pin >= PINA0 && pin <= PINA7 )
	{
		return READ_BIT(PORTA, pin);
	}
	else if ( pin >= PINB0 && pin <= PINB7 )
	{
		pin = pin - PINB0;

		return READ_BIT(PORTB, pin);
	}
	else if ( pin >= PINC0 && pin <= PINC7 )
	{
		pin = pin - PINC0;

		return READ_BIT(PORTC, pin);
	}
	else if ( pin >= PIND0 && pin <= PIND7 )
	{
		pin = pin - PIND0;

		return READ_BIT(PORTD, pin);
	}
}

extern void DIO_WritePORT( Dio_Port_type port,  u8 value)
{
	switch(port)
	{
		case PA:
		PORTA = value;
		break;
		case PB:
		PORTB = value;
		break;
		case PC:
		PORTC = value;
		break;
		case PD:
		PORTD = value;
		break;
	}
}

extern u8 DIO_ReadPORT( Dio_Port_type port)
{
	switch(port)
	{
		case PA:
		return PORTA;
	
		case PB:
		return PORTB;
		
		case PC:
		return PORTC;
		
		case PD:
		return PORTD;
	}
}