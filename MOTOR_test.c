
#include "DIO_interface.h"
#include "MOTOR.h"

int main()
{
	DIO_Init();
	
	while (1)
	{
		DIO_TogglePin(PINC0);
		DIO_TogglePin(PINC3);
		DIO_TogglePin(PIND4);
		DIO_TogglePin(PIND6);
		MOTOR1_Forward();
		_delay_ms(3000);
		MOTOR1_backward();
		DIO_TogglePin(PINC0);
		DIO_TogglePin(PINC3);
		DIO_TogglePin(PIND4);
		DIO_TogglePin(PIND6);
		_delay_ms(3000);
		MOTOR_Stop();
		DIO_TogglePin(PINC0);
		DIO_TogglePin(PINC3);
		DIO_TogglePin(PIND4);
		DIO_TogglePin(PIND6);
		_delay_ms(3000);
	}
}