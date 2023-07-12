
#include "LCD.h"

static void LCD_WriteCommed8(u8 command)
{
	DIO_WritePin(RS, LOW);
	
	DIO_WritePin(DB0, (command>>0)&1);
	DIO_WritePin(DB1, (command>>1)&1);
	DIO_WritePin(DB2, (command>>2)&1);
	DIO_WritePin(DB3, (command>>3)&1);
	DIO_WritePin(DB4, (command>>4)&1);
	DIO_WritePin(DB5, (command>>5)&1);
	DIO_WritePin(DB6, (command>>6)&1);
	DIO_WritePin(DB7, (command>>7)&1);
	
	DIO_WritePin(E, HIGH);
	_delay_ms(50);
	DIO_WritePin(E, LOW);
}

static void LCD_WriteCommed4(u8 command)
{
	DIO_WritePin(RS, LOW);
	
	DIO_WritePin(DB0, (command>>0)&1);
	DIO_WritePin(DB1, (command>>1)&1);
	DIO_WritePin(DB2, (command>>2)&1);
	DIO_WritePin(DB3, (command>>3)&1);
	DIO_WritePin(DB4, (command>>4)&1);
	DIO_WritePin(DB5, (command>>5)&1);
	DIO_WritePin(DB6, (command>>6)&1);
	DIO_WritePin(DB7, (command>>7)&1);
	
	DIO_WritePin(E, HIGH);
	_delay_ms(50);
	DIO_WritePin(E, LOW);
}

void LCD_WriteCommed(u8 command)
{
	switch (MODE)
	{
		case MODE_8_BIT:
		LCD_WriteCommed8(command);
		break;
		case MODE_4_BIT:
		LCD_WriteCommed4(command);
		break;
	}
}

void LCD_WritData()
{
	DIO_WritePin(RS, HIGH);
	
	DIO_WritePin(E, HIGH);
	_delay_ms(50);
	DIO_WritePin(E, LOW);
	_delay_ms(50);
}

static void LCD_Init8()
{
	_delay_ms(50);
	
	//DIO_WritePin(DB0, HIGH);
	//DIO_WritePin(DB1, HIGH);
	//DIO_WritePin(DB2, HIGH); // 5*10 Font
	//DIO_WritePin(DB3, HIGH); // 2 Lines
	//DIO_WritePin(DB4, HIGH);
	//DIO_WritePin(DB5, HIGH);
	//DIO_WritePin(DB6, LOW);
	//DIO_WritePin(DB7, LOW);
	LCD_WriteCommed(0xb00111111);
	
	//DIO_WritePin(DB0, LOW); // not blinking cursor
	//DIO_WritePin(DB1, HIGH);// display cursor
	//DIO_WritePin(DB2, HIGH);// display DDRAM Data on the Screen
	//DIO_WritePin(DB3, HIGH); 
	//DIO_WritePin(DB4, LOW);
	//DIO_WritePin(DB5, LOW);
	//DIO_WritePin(DB6, LOW);
	//DIO_WritePin(DB7, LOW);
	LCD_WriteCommed(0b00001110);
	
	//DIO_WritePin(DB0, HIGH);
	//DIO_WritePin(DB1, LOW);
	//DIO_WritePin(DB2, LOW); 
	//DIO_WritePin(DB3, LOW);
	//DIO_WritePin(DB4, LOW);
	//DIO_WritePin(DB5, LOW);
	//DIO_WritePin(DB6, LOW);
	//DIO_WritePin(DB7, LOW);
	LCD_WriteCommed(0b00000001);
	
	//DIO_WritePin(DB0, HIGH);// shift the entire display
	//DIO_WritePin(DB1, HIGH);// increase DDRAM address by 1 when a character code is written into 
	//DIO_WritePin(DB2, HIGH);
	//DIO_WritePin(DB3, LOW);
	//DIO_WritePin(DB4, LOW);
	//DIO_WritePin(DB5, LOW);
	//DIO_WritePin(DB6, LOW);
	//DIO_WritePin(DB7, LOW);
	LCD_WriteCommed(0b00000111);
}

static void LCD_Init4()
{
	_delay_ms(50);
	
	LCD_WriteCommed();
	
	DIO_WritePin(DB4, LOW);
	DIO_WritePin(DB5, HIGH);
	DIO_WritePin(DB6, LOW);
	DIO_WritePin(DB7, LOW);
	
	LCD_WriteCommed();
	
	DIO_WritePin(DB4, LOW);
	DIO_WritePin(DB5, HIGH);
	DIO_WritePin(DB6, LOW);
	DIO_WritePin(DB7, LOW);
	
	LCD_WriteCommed();
	
	DIO_WritePin(DB6, HIGH);
	DIO_WritePin(DB7, HIGH);
	
	_delay_ms(50);
	
	LCD_WriteCommed();
	
	DIO_WritePin(DB4, LOW);
	DIO_WritePin(DB5, LOW);
	DIO_WritePin(DB6, LOW);
	DIO_WritePin(DB7, LOW);
	
	LCD_WriteCommed();
	
	DIO_WritePin(DB4, LOW);
	DIO_WritePin(DB5, HIGH);
	DIO_WritePin(DB6, HIGH);
	DIO_WritePin(DB7, HIGH);
	
	_delay_ms(50);
	
	LCD_WriteCommed();
	
	DIO_WritePin(DB4, LOW);
	DIO_WritePin(DB5, LOW);
	DIO_WritePin(DB6, LOW);
	DIO_WritePin(DB7, LOW);
	
	LCD_WriteCommed();
	
	DIO_WritePin(DB4, HIGH);
	DIO_WritePin(DB5, LOW);
	DIO_WritePin(DB6, LOW);
	DIO_WritePin(DB7, LOW);
	
	_delay_ms(50);
	
	LCD_WriteCommed();
	
	DIO_WritePin(DB4, LOW);
	DIO_WritePin(DB5, LOW);
	DIO_WritePin(DB6, LOW);
	DIO_WritePin(DB7, LOW);
	
	LCD_WriteCommed();
	
	DIO_WritePin(DB4, HIGH);
	DIO_WritePin(DB5, HIGH);
	DIO_WritePin(DB6, HIGH);
	DIO_WritePin(DB7, LOW);
}

void LCD_Init()
{
	switch (MODE)
	{
		case MODE_8_BIT:
		LCD_Init8();
		break;
		case MODE_4_BIT:
		LCD_Init4();
		break;
	}
}

static void LCD_Clear8()
{
	//DIO_WritePin(DB0, HIGH);
	//DIO_WritePin(DB1, LOW);
	//DIO_WritePin(DB2, LOW);
	//DIO_WritePin(DB3, LOW);
	//DIO_WritePin(DB4, LOW);
	//DIO_WritePin(DB5, LOW);
	//DIO_WritePin(DB6, LOW);
	//DIO_WritePin(DB7, LOW);
	LCD_WriteCommed(0b0000001);
	_delay_ms(50);
}

static void LCD_Clear4()
{
	DIO_WritePin(DB4, LOW);
	DIO_WritePin(DB5, LOW);
	DIO_WritePin(DB6, LOW);
	DIO_WritePin(DB7, LOW);
	LCD_WriteCommed();
	DIO_WritePin(DB4, HIGH);
	DIO_WritePin(DB5, LOW);
	DIO_WritePin(DB6, LOW);
	DIO_WritePin(DB7, LOW);
	LCD_WriteCommed();
	_delay_ms(50);
}

void LCD_Clear()
{
	switch (MODE)
	{
		case MODE_8_BIT:
		LCD_Clear8();
		break;
		case MODE_4_BIT:
		LCD_Clear4();
		break;
	}
}

static void LCD_WriteChar8(u8 character)
{
	DIO_WritePin(DB0, (character>>0)&1);
	DIO_WritePin(DB1, (character>>1)&1);
	DIO_WritePin(DB2, (character>>2)&1);
	DIO_WritePin(DB3, (character>>3)&1);
	DIO_WritePin(DB4, (character>>4)&1);
	DIO_WritePin(DB5, (character>>5)&1);
	DIO_WritePin(DB6, (character>>6)&1);
	DIO_WritePin(DB7, (character>>7)&1);
	LCD_WritData();
}

static void LCD_WriteChar4(u8 character)
{
	
	DIO_WritePin(DB4, (character>>4)&1);
	DIO_WritePin(DB5, (character>>5)&1);
	DIO_WritePin(DB6, (character>>6)&1);
	DIO_WritePin(DB7, (character>>7)&1);
	LCD_WritData();
	DIO_WritePin(DB4, (character>>0)&1);
	DIO_WritePin(DB5, (character>>1)&1);
	DIO_WritePin(DB6, (character>>2)&1);
	DIO_WritePin(DB7, (character>>3)&1);
	LCD_WritData();
}

void LCD_WriteChar(u8 character)
{
	switch (MODE)
	{
		case MODE_8_BIT:
		LCD_WriteChar8(character);
		break;
		case MODE_4_BIT:
		LCD_WriteChar4(character);
		break;
	}
}