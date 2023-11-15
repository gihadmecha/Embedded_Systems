
#include "DIO_interface.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "EEPROM.h"

void EEPROM_passwardRetrieval (u8 passward[], u16 passwardSize, u16 address);
void EEPROM_KeyPad_passwardSave (u8 passward[], u16 passwardSize, u16 address);

int main ()
{
	DIO_Init();
	LCD_Init ();
	
	u8 passward[20] = {NULL};
	u16 passwardSize = 20;
	u16 address = 0;
	
	EEPROM_passwardRetrieval ( passward, passwardSize, address);
	
	while (1)
	{
		EEPROM_KeyPad_passwardSave ( passward, passwardSize, address);
		LCD_GoTo(0, 0);
		LCD_WriteString(passward);
		LCD_WriteString("                ");
	}
}

void EEPROM_passwardRetrieval (u8 passward[], u16 passwardSize, u16 address)
{
	if (passwardSize > 0)
	{
		passward[0] = EEPROM_read(address);
		
		u16 index;
		for (index = 1; index < (passwardSize - 1) && passward[index - 1] != NULL; index++)
		{
			passward[index] = EEPROM_read(address + index);
		}
	}
}

void EEPROM_KeyPad_passwardSave (u8 passward[], u16 passwardSize, u16 address)
{
	static u8 key = NULL;
	static u8 changePasswardFlag = 0;
	static u16 index = 0;
	
	key = KEYPAD_GetKey ();
	
	if (key == 'C')
	{
		changePasswardFlag = 1;
	}
	
	if (index < (passwardSize - 1) && key != NULL && changePasswardFlag == 1 && key != '=')
	{
		if (key != 'C')
		{
			passward[address + index] = key;
			index++;
			passward[index] = NULL;
		}
	}
	
   if (changePasswardFlag == 1 && index > 0 && key == '=')
	{
		u16 index;
		for (index = 0; passward[index]; index++)
		{
			EEPROM_write (address + index, passward[index]);
		}
		EEPROM_write (address + index, NULL);
		
		changePasswardFlag = 0;
	}
}
