


#ifndef LCD_H_
#define LCD_H_

#include "LCD_Lcfg.h"
#include "DIO_interface.h"


void LCD_Init();
void LCD_GoTo(u8 line, u8 digit);
void LCD_setCGRAM_Address(u8 pattarnCGRAM_location);
void LCD_createCharacter (const u8* pattarn, u8 pattarnCGRAM_location);
void LCD_Clear();
void LCD_WriteChar(char character);
void LCD_WriteString (char* string);
void LCD_WriteNumber (s32 number);
void LCD_WriteNumber_4Digit (u16 number);
void LCD_WriteBinary (u8 number);
void LCD_WriteHex(u8 number);
void LCD_GoToClear(u8 line, u8 digit, u8 noOfDigits);
void LCD_GoToWritString (u8 line, u8 digit, char* string);



#endif /* LCD_H_ */