

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define F_CPU 8000000
#include <util/delay.h>

#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"

typedef	enum{
	PA,
	PB,
	PC,
	PD
	}Dio_Port_type;
	
typedef enum{
	OUTPUT,
	INFREE,
	INPULL
	}DIO_PinStatus_type;
	
typedef enum{
	LOW,
	HIGH
	}DIO_pinVoltage_type;
	
typedef enum{
	PINA0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7
	}DIO_pin_type;


extern void DIO_Init ();
extern void DIO_WritePin(DIO_pin_type pin, DIO_pinVoltage_type volt);
extern void DIO_TogglePin(DIO_pin_type pin);
extern DIO_pinVoltage_type DIO_ReadPin(DIO_pin_type pin);
extern DIO_pinVoltage_type DIO_ReadPortRegister(DIO_pin_type pin);
extern void DIO_WritePORT( Dio_Port_type port,  u8 value);
extern u8	DIO_ReadPORT( Dio_Port_type port);




#endif /* DIO_INTERFACE_H_ */