
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
//LEFT
void SEGMENTS_left (u8 number)
{
	if (0 <= number && number <= 15)
	{
		SEGMENTS_EachPin_Of7Pins (SEGMENTS_Pixels[number], SEGMENT_LEFT_A, SEGMENT_LEFT_B, SEGMENT_LEFT_C, SEGMENT_LEFT_D, SEGMENT_LEFT_E, SEGMENT_LEFT_F, SEGMENT_LEFT_G);
	}
	else
	{
		SEGMENTS_EachPin_Of7Pins (0, SEGMENT_LEFT_A, SEGMENT_LEFT_B, SEGMENT_LEFT_C,SEGMENT_LEFT_D, SEGMENT_LEFT_E, SEGMENT_LEFT_F, SEGMENT_LEFT_G);
	}
}

//cathode
//RIGHT
void SEGMENTS_right (u8 number)
{
	if (0 <= number && number <= 15)
	{
		SEGMENTS_EachPin_Of7Pins (SEGMENTS_Pixels[number], SEGMENT_RIGHT_A, SEGMENT_RIGHT_B, SEGMENT_RIGHT_C, SEGMENT_RIGHT_D, SEGMENT_RIGHT_E, SEGMENT_RIGHT_F, SEGMENT_RIGHT_G);
	}
	else
	{
		SEGMENTS_EachPin_Of7Pins (0, SEGMENT_RIGHT_A, SEGMENT_RIGHT_B, SEGMENT_RIGHT_C, SEGMENT_RIGHT_D, SEGMENT_RIGHT_E, SEGMENT_RIGHT_F, SEGMENT_RIGHT_G);
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
void SEGMENTS_STOP_Watch (u8 number)
{
	if (0 <= number && number <= 99)
	{
		DIO_WritePin(SEGMENTS_STOP_WATCH_2, HIGH);
		DIO_WritePin(SEGMENTS_STOP_WATCH_1, LOW);
		SEGMENTS_EachPin_Of7Pins (SEGMENTS_Pixels[number/10], SEGMENTS_STOP_WATCH_A, SEGMENTS_STOP_WATCH_B, SEGMENTS_STOP_WATCH_C, SEGMENTS_STOP_WATCH_D, SEGMENTS_STOP_WATCH_E, SEGMENTS_STOP_WATCH_F, SEGMENTS_STOP_WATCH_G);
		_delay_ms(8);
		DIO_WritePin(SEGMENTS_STOP_WATCH_1, HIGH);
		DIO_WritePin(SEGMENTS_STOP_WATCH_2, LOW);
		SEGMENTS_EachPin_Of7Pins (SEGMENTS_Pixels[number%10], SEGMENTS_STOP_WATCH_A, SEGMENTS_STOP_WATCH_B, SEGMENTS_STOP_WATCH_C, SEGMENTS_STOP_WATCH_D, SEGMENTS_STOP_WATCH_E, SEGMENTS_STOP_WATCH_F, SEGMENTS_STOP_WATCH_G);
		_delay_ms(8);
	}
	else
	{
		DIO_WritePin(SEGMENTS_STOP_WATCH_2, HIGH);
		DIO_WritePin(SEGMENTS_STOP_WATCH_1, LOW);
		SEGMENTS_EachPin_Of7Pins (0, SEGMENTS_STOP_WATCH_A, SEGMENTS_STOP_WATCH_B, SEGMENTS_STOP_WATCH_C, SEGMENTS_STOP_WATCH_D, SEGMENTS_STOP_WATCH_E, SEGMENTS_STOP_WATCH_F, SEGMENTS_STOP_WATCH_G);
		_delay_ms(8);
		DIO_WritePin(SEGMENTS_STOP_WATCH_1, HIGH);
		DIO_WritePin(SEGMENTS_STOP_WATCH_2, LOW);
		SEGMENTS_EachPin_Of7Pins (0, SEGMENTS_STOP_WATCH_A, SEGMENTS_STOP_WATCH_B, SEGMENTS_STOP_WATCH_C, SEGMENTS_STOP_WATCH_D, SEGMENTS_STOP_WATCH_E, SEGMENTS_STOP_WATCH_F, SEGMENTS_STOP_WATCH_G);
		_delay_ms(8);
	}
}