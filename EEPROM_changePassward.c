
#include "DIO_interface.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "EEPROM.h"

static u16 addressAddress = 1;
static u16 counterAddress = 2;
static u16 eepromWriteCounter = 0;

static u16 dataAddress;

void EEPROM_passwardRetrieval (u8 passward[], u16 passwardSize, u16 address);
void EEPROM_KeyPad_passwardSave (u8 passward[], u16 passwardSize, u16 address);

int main ()
{
	DIO_Init();
	LCD_Init ();
	
	u8 passward[10] = {NULL};
	u16 passwardSize = 10;
	u16 passwardAddress = 3;
	
	u8* dataAddressPointer = &dataAddress;
	
	*(dataAddressPointer + 0) = EEPROM_read(addressAddress);
	*(dataAddressPointer + 1) = EEPROM_read(addressAddress - 1);
	
	if ( (dataAddress > 1023 - passwardSize - 1) || (dataAddress < 2) )
	{
		dataAddress = 2;
		EEPROM_write(addressAddress, *(dataAddressPointer + 0));
		EEPROM_write(addressAddress - 1, *(dataAddressPointer + 1) );
	}
	
	counterAddress = dataAddress;
	eepromWriteCounter = EEPROM_read(counterAddress);
	
	if (eepromWriteCounter >= 3)
	{
		EEPROM_write (counterAddress, 0);
		eepromWriteCounter = 0;
	}
	
	passwardAddress = dataAddress + 1;
	EEPROM_passwardRetrieval ( passward, passwardSize, passwardAddress);
	
	while (1)
	{
		EEPROM_KeyPad_passwardSave ( passward, passwardSize, passwardAddress);
		
		LCD_GoTo(0, 0);
		LCD_WriteNumber (dataAddress);
		LCD_GoTo(1, 0);
		LCD_WriteNumber_4Digit(addressAddress);
		
		LCD_GoTo(0, 6);
		LCD_WriteNumber_4Digit(eepromWriteCounter);
		LCD_GoTo(1, 6);
		LCD_WriteNumber_4Digit(counterAddress);
		
		LCD_GoTo(0, 11);
		LCD_WriteString(passward);
		LCD_WriteString("    ");
		
		LCD_GoTo(1, 11);
		LCD_WriteNumber_4Digit(passwardAddress);
		
		if (eepromWriteCounter == 3)
		{
			dataAddress = dataAddress + passwardSize + 1;
			
			if ( (dataAddress > 1023 - passwardSize - 1) || (dataAddress < 2) )
			{
				dataAddress = 2;
			}
			
			EEPROM_write(addressAddress, *(dataAddressPointer + 0));
			EEPROM_write(addressAddress - 1, *(dataAddressPointer + 1) );
			
			counterAddress = dataAddress;
			EEPROM_write(counterAddress, 0);
			eepromWriteCounter = 0;
			
			u8 index;
			u8 eeprom_passwardReadChar = EEPROM_read(passwardAddress + 0);
			for (index = 0; eeprom_passwardReadChar;  )
			{
				EEPROM_write(dataAddress + 1 + index, eeprom_passwardReadChar);
				index++;
				eeprom_passwardReadChar = EEPROM_read(passwardAddress + index);
			}
			EEPROM_write(dataAddress + 1 + index, NULL);
			passwardAddress = dataAddress + 1;
		}
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
		passward[index] = NULL;
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
		index = 0;
	}
	
	if (index < (passwardSize - 1) && key != NULL && changePasswardFlag == 1 && key != '=')
	{
		if (key != 'C')
		{
			passward[index] = key;
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
		
		EEPROM_write (counterAddress, ++eepromWriteCounter);
		
		changePasswardFlag = 0;
	}
}