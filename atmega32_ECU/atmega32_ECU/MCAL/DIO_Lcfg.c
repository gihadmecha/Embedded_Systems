
#include "DIO_interface.h"

const DIO_PinStatus_type PinsStatusArray[] = {
	OUTPUT, //PINA0
	OUTPUT, //PINA1
	OUTPUT, //PINA2
	OUTPUT, //PINA3
	OUTPUT, //PINA4
	OUTPUT, //PINA5
	OUTPUT, //PINA6
	OUTPUT, //PINA7
	OUTPUT, //PINB0
	OUTPUT, //PINB1
	OUTPUT, //PINB2//INT2
	OUTPUT, //PINB3//oc0
	INPULL, //PINB4//ss
	INPULL, //PINB5//mosi
	INPULL, //PINB6//miso
	INPULL, //PINB7//clk
	OUTPUT, //PINC0
	OUTPUT, //PINC1
	OUTPUT, //PINC2
	OUTPUT, //PINC3
	OUTPUT, //PINC4
	OUTPUT, //PINC5
	OUTPUT, //PINC6
	OUTPUT, //PINC7
	OUTPUT, //PIND0
	OUTPUT, //PIND1
	INPULL, //PIND2//INT0
	INPULL, //PIND3//INT1
	INPULL, //PIND4//OC1B
	INPULL, //PIND5//OC1A
	OUTPUT, //PIND6//ICP1
	OUTPUT  //PIND7
};

