
#include "LCD.h"


#if MODE == MODE_8_BIT

void LCD_WriteCommand(u8 command)
{
	//to write command
	DIO_WritePin(RS, LOW);
	
	DIO_WritePin(DB0, (command>>0)&1);
	DIO_WritePin(DB1, (command>>1)&1);
	DIO_WritePin(DB2, (command>>2)&1);
	DIO_WritePin(DB3, (command>>3)&1);
	DIO_WritePin(DB4, (command>>4)&1);
	DIO_WritePin(DB5, (command>>5)&1);
	DIO_WritePin(DB6, (command>>6)&1);
	DIO_WritePin(DB7, (command>>7)&1);
	
	//trigger
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	
	//wait to LCD MCU Execute
	_delay_ms(1);
}

void LCD_WriteData(u8 data)
{
	//write data to CG(store data) or DDRAM(display data)
	
	//to write data
	DIO_WritePin(RS, HIGH);
	
	DIO_WritePin(DB0, (data>>0)&1);
	DIO_WritePin(DB1, (data>>1)&1);
	DIO_WritePin(DB2, (data>>2)&1);
	DIO_WritePin(DB3, (data>>3)&1);
	DIO_WritePin(DB4, (data>>4)&1);
	DIO_WritePin(DB5, (data>>5)&1);
	DIO_WritePin(DB6, (data>>6)&1);
	DIO_WritePin(DB7, (data>>7)&1);
	
	//trigger
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	
	//wait to LCD MCU Execute
	_delay_ms(1);
}

void LCD_Init()
{
	_delay_ms(50);
	
	// F: 5*7 Font
	// N: 2 Lines
	LCD_WriteCommand(0b00110000);
	
	// B: not blinking cursor
	// C: display cursor
	// D: display DDRAM Data on the Screen
	LCD_WriteCommand(0b00001110);
	
	LCD_WriteCommand(0b00000001);
	_delay_ms(1);
	
	// SH: no shift
	// I/D: increase DDRAM address by 1 when a character code is written into
	LCD_WriteCommand(0b00000110);
}


#elif MODE == MODE_4_BIT

void LCD_WriteCommand(u8 command)
{
	//to write command
	DIO_WritePin(RS, LOW);
	
	DIO_WritePin(DB4, (command>>4)&1);
	DIO_WritePin(DB5, (command>>5)&1);
	DIO_WritePin(DB6, (command>>6)&1);
	DIO_WritePin(DB7, (command>>7)&1);
	
	//trigger
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	
	DIO_WritePin(DB4, (command>>0)&1);
	DIO_WritePin(DB5, (command>>1)&1);
	DIO_WritePin(DB6, (command>>2)&1);
	DIO_WritePin(DB7, (command>>3)&1);
	
	//trigger
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	
	//wait to LCD MCU Execute
	_delay_ms(1);
}

void LCD_WriteData(u8 data)
{
	//write data to CG(store data) or DDRAM(display data)
	
	//to write data
	DIO_WritePin(RS, HIGH);
	
	DIO_WritePin(DB4, (data>>4)&1);
	DIO_WritePin(DB5, (data>>5)&1);
	DIO_WritePin(DB6, (data>>6)&1);
	DIO_WritePin(DB7, (data>>7)&1);
	
	//trigger
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	
	DIO_WritePin(DB4, (data>>0)&1);
	DIO_WritePin(DB5, (data>>1)&1);
	DIO_WritePin(DB6, (data>>2)&1);
	DIO_WritePin(DB7, (data>>3)&1);
	
	//trigger
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	
	//wait to LCD MCU Execute
	_delay_ms(1);
}

void LCD_Init()
{
	_delay_ms(50);
	
	LCD_WriteCommand(0b00100010);
	
	
	//to write command
	DIO_WritePin(RS, LOW);
	
	// F: 5*7 Font
	// N: 2 Lines
	DIO_WritePin(DB6, 0);
	DIO_WritePin(DB7, 1);
	
	//trigger
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	
	//wait to LCD MCU Execute
	_delay_ms(1);
	
	// B: not blinking cursor
	// C: display cursor
	// D: display DDRAM Data on the Screen
	LCD_WriteCommand(0b00001100);
	
	LCD_WriteCommand(0b00000001);
	_delay_ms(1);
	
	// SH: no shift
	// I/D: increase DDRAM address by 1 when a character code is written into
	LCD_WriteCommand(0b00000110);
}

#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LCD_Clear()
{
	LCD_WriteCommand(0b00000001);
	_delay_ms(1);
}

void LCD_GoTo(u8 line, u8 digit)
{
	if (line == 0)
	LCD_WriteCommand(0b10000000 | (0x00 + digit));
	else if (line == 1)
	LCD_WriteCommand(0b10000000 | (0x40 + digit));
}

void LCD_setCGRAM_Address(u8 pattarnCGRAM_location)
{
	LCD_WriteCommand(0b01000000 | (0x00 + pattarnCGRAM_location*8));
}

void LCD_createCharacter (const u8* pattarn, u8 pattarnCGRAM_location)
{
	LCD_setCGRAM_Address(pattarnCGRAM_location);
	
	for (u8 count = 0; count <= 7; count++)
	{
		LCD_WriteData(pattarn[count]);
	}
	
	LCD_GoTo(0, 0);
}

void LCD_WriteChar(char character)
{
	LCD_WriteData(character);
}

void LCD_WriteString (char* string)
{
	for (u8 count = 0; string[count]; count++)
	{
		LCD_WriteChar(string[count]);
	}
}

void LCD_WriteNumber (s32 number)
{
	double numberCopy = number;
	s8 digitCounter = 0;
	
	if(number == 0)
	{
		LCD_WriteChar('0');
	}
	else
	{
		if (number < 0)
		{
			LCD_WriteChar('-');
			numberCopy = -number;
		}
		
		while (numberCopy >= 1)
		{
			numberCopy /= 10;
			digitCounter++;
		}
		
		while (digitCounter)
		{
			numberCopy *= 10;
			LCD_WriteChar('0' + (u32)numberCopy % 10);
			digitCounter--;
		}
	}
}

void LCD_WriteNumber_4Digit (u16 number)
{
	LCD_WriteChar('0' + (number/1000)%10);
	LCD_WriteChar('0' + (number/100)%10);
	LCD_WriteChar('0' + (number/10)%10);
	LCD_WriteChar('0' + (number)%10);
}

void LCD_WriteBinary (u8 number)
{
	u8 firstOneFlag = 0;
	for (s8 index = 7; index >= 0; index--)
	{
		if ((number>>index)&1)
		firstOneFlag = 1;
		
		if (firstOneFlag)
		LCD_WriteChar('0' + ((number>>index)&1));
	}
}

void LCD_WriteHex(u8 number)
{
	u8 left4Digit = (number>>4) & 0b00001111;
	u8 right4Digit = number & 0b00001111;
	
	LCD_WriteChar('0');
	LCD_WriteChar('x');
	
	if (left4Digit < 10)
	LCD_WriteChar('0' + left4Digit);
	else
	LCD_WriteChar('A' + (left4Digit-10));
	
	if (right4Digit < 10)
	LCD_WriteChar('0' + right4Digit);
	else
	LCD_WriteChar('A' + (right4Digit-10));
}

void LCD_GoToClear(u8 line, u8 digit, u8 noOfDigits)
{
	LCD_GoTo(line, digit);
	for (u8 count = 1; count <= noOfDigits; count++)
	{
		LCD_WriteChar(' ');
	}
	LCD_GoTo(line, digit);
}

void LCD_GoToWritString (u8 line, u8 digit, char* string)
{
	LCD_GoTo(line, digit);
	LCD_WriteString(string);
}
