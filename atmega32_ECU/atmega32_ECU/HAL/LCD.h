

#ifndef LCD_H_
#define LCD_H_

#include "DIO_interface.h"
#include "LCD_Lcfg.h"

extern void LCD_Init ();
extern void LCD_Clear ();
extern void LCD_WriteChar ( u8 character);
extern void LCD_WriteString ( u8* str);
extern void LCD_WriteNumber ( double number);
extern void LCD_WriteNumber_4Digit ( int number);
extern void LCD_WriteBinary (u8 number);
extern void LCD_WriteHex1 (u8 number);
extern void LCD_WriteHex2 (u8 number);
extern void LCD_GoTo ( u8 line, u8 digit);

#endif /* LCD_H_ */