

#include "LCD.h"

static void LCD_WriteCommand(u8 command)
{
	// to write command
	DIO_WritePin(LCD_RS, LOW);
	

	DIO_WritePORT(LCD_PORT, command);
	
	//trigger
	DIO_WritePin(LCD_EN, HIGH);
	_delay_ms (1);
	DIO_WritePin(LCD_EN, LOW);
	
	_delay_ms(1);
}

static void LCD_WriteData (u8 data)
{
		//write data to CG(store data) or DDRAM(display data)
		
		//to write data
		DIO_WritePin(LCD_RS, HIGH);
		//write data
		DIO_WritePORT(LCD_PORT, data);
		//trigger
		DIO_WritePin(LCD_EN, HIGH);
		_delay_ms (1);
		DIO_WritePin(LCD_EN, LOW);
		_delay_ms(1);
}

extern void LCD_Init()
{
	//wait for LCD initialization
	_delay_ms(50);
	
	////function set
	//// to write command
	//DIO_WritePin(LCD_RS, LOW);
	//
	////command
	////DB4 = DL = Data Length = 1 = Data is sent or received in 8 bit length
	////x = don't care
	////N = set the number of lines = 1 = 2 lines display 
	////F = 0 = 5 * 7 dots (font)
	////DIO_WritePORT(LCD_PORT, 0b0011NFXX);
	//DIO_WritePORT(LCD_PORT, 0b00111000);
	//
	////trigger
	//DIO_WritePin(LCD_EN, HIGH);
	//_delay_ms (1);
	//DIO_WritePin(LCD_EN, LOW);
	//
	//_delay_us(40);
	LCD_WriteCommand(0x38); // 2 line, 5*7
	
	
	////Display on/off control
	//// to write command
	//DIO_WritePin(LCD_RS, LOW);
	////command
	//
	////D = 1 = ON LCD display light
	////  = 0 = OFF LCD display light, the display data remains in the DDRAM
	////C = 1 = display cursor
	////  = 0 = don't display cursor
	////B = 1 = cursor blinking at 0.4 sec intervals
	////    0 = don't blink cursor
	//DIO_WritePORT(LCD_PORT, 0b0000DCB0);
	//DIO_WritePORT(LCD_PORT, 0b00001110);
	//
	////trigger
	//DIO_WritePin(LCD_EN, HIGH);
	//_delay_ms (1);
	//DIO_WritePin(LCD_EN, LOW);
	//
	//_delay_us(40);
	LCD_WriteCommand(0x0C); // cursor, try 0x0F, 0x0E
	
	////Display clear
	//// to write command
	//DIO_WritePin(LCD_RS, LOW);
	//
	////command
	//DIO_WritePORT(LCD_PORT, 1);
	//
	////trigger
	//DIO_WritePin(LCD_EN, HIGH);
	//_delay_ms (1);
	//DIO_WritePin(LCD_EN, LOW);
	//
	//_delay_ms(1.6);
	LCD_WriteCommand(0x01);
	_delay_ms(1);
	
	
	////Entry mode set
	//// to write command
	//DIO_WritePin(LCD_RS, LOW);
	//
	////command
	////I/D = 1 = increase the DDRAM address by 1 when a character code is written into the DDRAM
	////      0 = increase the DDRAM address by 1 when a character code is written into the DDRAM
	////SH = 1 = shift on
	////   = 0 = shift off
	//DIO_WritePORT(LCD_PORT, 0b00000110);
	//
	////trigger
	//DIO_WritePin(LCD_EN, HIGH);
	//_delay_ms (1);
	//DIO_WritePin(LCD_EN, LOW);
	LCD_WriteCommand(0x06); //increase DDRAM address, no shift
}

extern void LCD_GoTo ( u8 line, u8 digit)
{
	if (line == 0)
	{
		//from 2*16 LCD datasheet: 0x00 is the address of the first digit in the first line
		//LCD_WriteCommand(0x80 + 0x00 + digit);
		LCD_WriteCommand(0x80 | 0x00 | digit);
	}
	else if (line == 1)
	{
		//from 2*16 LCD datasheet: 0x40 is the address of the first digit in the second line
		//LCD_WriteCommand(0x80 + 0x45 + digit);
		LCD_WriteCommand(0x80 | 0x40 | digit);
	}
}

/*******************************************************************************************************/


extern void LCD_WriteChar ( u8 character)
{
	LCD_WriteData (character);
}

extern void LCD_WriteString ( u8* str)
{
	for (unsigned int index = 0; str[index]; index++)
	{
		LCD_WriteData (str[index]);
	}
}

static u8 LCD_stringLength (u8* str)
{
	unsigned int index;
	for (index = 0; str[index]; index++);
	return index;
}

static void LCD_swapChar (u8* character1, u8* character2)
{
	u8 temperoryChar = *character1;
	*character1 = *character2;
	*character2 = temperoryChar;
}

static void LCD_stringReverse (u8* str)
{
	unsigned int stringLength = LCD_stringLength(str);
	for (unsigned int index = 0; index < (stringLength)/2; index++)
	{
		LCD_swapChar(str + index, str + stringLength - index-1);
	}
}
static void LCD_numberToSring (double number, u8* numberString)
{
	u8 index = 0;
	signed char dotFlag = 0;
	u8 digit;
	
	if (numberString == NULLPTR)
		return;
	
	
	if (number == 0)
	{
		numberString[index] = '0';
		index++;
	}
	
	//if number is negative, let it positive
	if (number < 0)
	{
		numberString[index] = '-';
		index++;
		dotFlag++;
		number = -number;
	}
	
	while (number >= 1)
	{
		number = number / 10;
		dotFlag++;
	}
	
	//store the number digits as characters in numberString array
	while (number != (int)number)
	{
		numberString[dotFlag] = '.';
		
		number = number * 10;
		
		digit = '0' + (int)number % 10;
		
		if (index != dotFlag)
		{
			numberString[index] = digit;
			index++;
		}
		else
		{
			index++;
			numberString[index] = digit;
			index++;
		}
	}
	
	//the end of numberString
	numberString[index] = NULL;
}

static void LCD_intToSring ( int number, u8* numberString)
{
	u8 index = 0;
	u8 digit;
	
	if (numberString == NULLPTR)
	return;
	
	
	if (number == 0)
	{
		numberString[index] = '0';
		index++;
	}
	
	//if number is negative, let it positive
	if (number < 0)
	{
		numberString[index] = '-';
		index++;
		number = -number;
	}
	
	//store the number digits as characters in numberString array
	while (number != 0)
	{
		digit = '0' + number % 10;
	
		numberString[index] = digit;
		index++;
		
		number = number / 10; 
	}
	
	//the end of numberString
	numberString[index] = NULL;
}

extern void LCD_WriteNumber ( double number)
{
	u8 numberString[20];
	//LCD_numberToSring ( number, numberString);
	LCD_intToSring ( number, numberString);
	LCD_stringReverse(numberString);
	LCD_WriteString ( numberString);
}

extern void LCD_WriteNumber_4Digit ( int number)
{
	LCD_WriteChar('0' + (number / 1000)%10);
	LCD_WriteChar('0' + (number / 100)%10);
	LCD_WriteChar('0' + (number / 10)%10);
	LCD_WriteChar('0' + (number %10));
}

extern void LCD_WriteBinary (u8 number)
{
	u8 oneFlag = 0;
	
	for (s8 index = 7; index >= 0; index--)
	{
		//LCD_WriteNumber( (number >> index) & 1 );
		
		if (((number >> index) & 1))
		{
			LCD_WriteChar('1');
			oneFlag = 1;
		}
		else if (oneFlag == 1)
		{
			LCD_WriteChar('0');
		}
	}
}

extern void LCD_WriteHex1 (u8 number)
{
	double leftDigit;
	double rightDigit;
	
	leftDigit = number>>4;
	rightDigit = number & 0b00001111;
	
	LCD_WriteString("0X");
	
	if (leftDigit <= 9)
	LCD_WriteChar( leftDigit + '0');
	else
	LCD_WriteChar( (leftDigit - 10) + 'A');
	
	if (rightDigit <= 9)
	LCD_WriteChar( rightDigit + '0');
	else
	LCD_WriteChar( (rightDigit - 10) + 'A');
}

extern void LCD_WriteHex2 (u8 number)
{
	u8 digit = number;
	u8 digitString[3];
	
	LCD_WriteString("0X");
	
	for (signed int index = 1; index >= 0; index--)
	{
		digit = number - (int)(number/16)*16;
		
		if (digit <= 9)
		digitString[index] = '0' + digit;
		else
		digitString[index] = 'A' + (digit-10);
		
		number = (int)(number/16);
	}
	digitString[2] = NULL;
	
	LCD_WriteString(digitString);
}

