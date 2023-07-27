

#include "BUZZER.h"

extern void BUZZER_On()
{
	DIO_WritePin(BUZZER, HIGH);
}

extern void BUZZER_Off()
{
	DIO_WritePin(BUZZER, LOW);
}

extern void BUZZER_Toggle ()
{
	DIO_TogglePin(BUZZER);
}

extern buzzer_status_type BUZZER_Read ()
{
	return DIO_ReadPortRegister(BUZZER);
}