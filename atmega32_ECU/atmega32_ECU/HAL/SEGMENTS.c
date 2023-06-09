
#include "SEGMENTS.h"
#include "SEGMENTS_Private.h"

static void SEGMENTS_EachPin_Of7Pins (u8 pixels, u8 pina, u8 pinb, u8 pinc, u8 pind, u8 pine, u8 pinf, u8 ping)
{
	
	DIO_WritePin(pina, (pixels>>0)&1);
	DIO_WritePin(pinb, (pixels>>1)&1);
	DIO_WritePin(pinc, (pixels>>2)&1);
	DIO_WritePin(pind, (pixels>>3)&1);
	DIO_WritePin(pine, (pixels>>4)&1);
	DIO_WritePin(pinf, (pixels>>5)&1);
	DIO_WritePin(ping, (pixels>>6)&1);
}

static void SEGMENTS_EachPin_Of4Pins (u8 pixels, u8 pin0, u8 pin1, u8 pin2, u8 pin3)
{
	DIO_WritePin(pin0, (pixels>>0)&1);
	DIO_WritePin(pin1, (pixels>>1)&1);
	DIO_WritePin(pin2, (pixels>>2)&1);
	DIO_WritePin(pin3, (pixels>>3)&1);
}


//cathode
void SEGMENTS1 (u8 number)
{
	if (0 <= number && number <= 15)
	{
		SEGMENTS_EachPin_Of7Pins (SEGMENTS_Pixels[number], SEGMENT1_A, SEGMENT1_B, SEGMENT1_C, SEGMENT1_D, SEGMENT1_E, SEGMENT1_F, SEGMENT1_G);
	}
	else
	{
		SEGMENTS_EachPin_Of7Pins (0, SEGMENT1_A, SEGMENT1_B, SEGMENT1_C, SEGMENT1_D, SEGMENT1_E, SEGMENT1_F, SEGMENT1_G);
	}
}

//anode
void SEGMENTS2 (u8 number)
{
	if (0 <= number && number <= 15)
	{
		SEGMENTS_EachPin_Of7Pins (~SEGMENTS_Pixels[number], SEGMENT2_A, SEGMENT2_B, SEGMENT2_C, SEGMENT2_D, SEGMENT2_E, SEGMENT2_F, SEGMENT2_G);
	}
	else
	{
		SEGMENTS_EachPin_Of7Pins (0xFF, SEGMENT2_A, SEGMENT2_B, SEGMENT2_C, SEGMENT2_D, SEGMENT2_E, SEGMENT2_F, SEGMENT2_G);
	}
}

//BCD
void SEGMENTS3 (u8 number)
{
	if (0 <= number && number <= 15)
	{
		SEGMENTS_EachPin_Of4Pins (number, SEGMENT3_0, SEGMENT3_1, SEGMENT3_2, SEGMENT3_3);
	}
	else
	{
		SEGMENTS_EachPin_Of4Pins (0, SEGMENT3_0, SEGMENT3_1, SEGMENT3_2, SEGMENT3_3);
	}
}

//2 digit cathode 7 segment
void SEGMENTS4 (u8 number)
{
	if (0 <= number && number <= 99)
	{
		DIO_WritePin(SEGMENT4_2, HIGH);
		DIO_WritePin(SEGMENT4_1, LOW);
		SEGMENTS_EachPin_Of7Pins (SEGMENTS_Pixels[number/10], SEGMENT4_A, SEGMENT4_B, SEGMENT4_C, SEGMENT4_D, SEGMENT4_E, SEGMENT4_F, SEGMENT4_G);
		_delay_ms(1);
		DIO_WritePin(SEGMENT4_1, HIGH);
		DIO_WritePin(SEGMENT4_2, LOW);
		SEGMENTS_EachPin_Of7Pins (SEGMENTS_Pixels[number%10], SEGMENT4_A, SEGMENT4_B, SEGMENT4_C, SEGMENT4_D, SEGMENT4_E, SEGMENT4_F, SEGMENT4_G);
		_delay_ms(1);
	}
	else
	{
		DIO_WritePin(SEGMENT4_2, HIGH);
		DIO_WritePin(SEGMENT4_1, LOW);
		SEGMENTS_EachPin_Of7Pins (0, SEGMENT4_A, SEGMENT4_B, SEGMENT4_C, SEGMENT4_D, SEGMENT4_E, SEGMENT4_F, SEGMENT4_G);
		_delay_ms(1);
		DIO_WritePin(SEGMENT4_1, HIGH);
		DIO_WritePin(SEGMENT4_2, LOW);
		SEGMENTS_EachPin_Of7Pins (0, SEGMENT4_A, SEGMENT4_B, SEGMENT4_C, SEGMENT4_D, SEGMENT4_E, SEGMENT4_F, SEGMENT4_G);
		_delay_ms(1);
	}
}