

#include "SEGMENTS.h"

static const u8 SEGMENTS_pixel[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
	
void SEGMENTS1_Init()
{
	SET_BIT (SEGMENT1_A_PORT_DDR, SEGMENT1_A_PIN);
	SET_BIT (SEGMENT1_B_PORT_DDR, SEGMENT1_B_PIN);
	SET_BIT (SEGMENT1_C_PORT_DDR, SEGMENT1_C_PIN);
	SET_BIT (SEGMENT1_D_PORT_DDR, SEGMENT1_D_PIN);
	SET_BIT (SEGMENT1_E_PORT_DDR, SEGMENT1_E_PIN);
	SET_BIT (SEGMENT1_F_PORT_DDR, SEGMENT1_F_PIN);
	SET_BIT (SEGMENT1_G_PORT_DDR, SEGMENT1_G_PIN);
}

void SEGMENTS2_Init()
{
	SET_BIT (SEGMENT2_A_PORT_DDR, SEGMENT2_A_PIN);
	SET_BIT (SEGMENT2_B_PORT_DDR, SEGMENT2_B_PIN);
	SET_BIT (SEGMENT2_C_PORT_DDR, SEGMENT2_C_PIN);
	SET_BIT (SEGMENT2_D_PORT_DDR, SEGMENT2_D_PIN);
	SET_BIT (SEGMENT2_E_PORT_DDR, SEGMENT2_E_PIN);
	SET_BIT (SEGMENT2_F_PORT_DDR, SEGMENT2_F_PIN);
	SET_BIT (SEGMENT2_G_PORT_DDR, SEGMENT2_G_PIN);
}

void SEGMENTS1_2_Init ()
{
	SEGMENTS1_2_PORT_DDR = 0x7F;
}

void SEGMENTS2_2_Init ()
{
	SEGMENTS2_2_PORT_DDR = 0x7F;
}

void SEGMENTS1 (u8 digit)
{
	if ((0 <= digit && digit <= 15) || ('a' <= digit && digit <= 'f') || ('A' <= digit && digit <= 'F'))
	{
		u8 pixels = SEGMENTS_pixel[digit];
		
		if ((pixels>>0) & 1)
		{
			SET_BIT (SEGMENT1_A_PORT_PORT, SEGMENT1_A_PIN);
		}
		else
		{
			CLR_BIT (SEGMENT1_A_PORT_PORT, SEGMENT1_A_PIN);
		}
		
		if ((pixels>>1) & 1)
		{
			SET_BIT (SEGMENT1_B_PORT_PORT, SEGMENT1_B_PIN);
		}
		else
		{
			CLR_BIT (SEGMENT1_B_PORT_PORT, SEGMENT1_B_PIN);
		}
		
		if ((pixels>>2) & 1)
		{
			SET_BIT (SEGMENT1_C_PORT_PORT, SEGMENT1_C_PIN);
		}
		else
		{
			CLR_BIT (SEGMENT1_C_PORT_PORT, SEGMENT1_C_PIN);
		}
		
		if ((pixels>>3) & 1)
		{
			SET_BIT (SEGMENT1_D_PORT_PORT, SEGMENT1_D_PIN);
		}
		else
		{
			CLR_BIT (SEGMENT1_D_PORT_PORT, SEGMENT1_D_PIN);
		}
		
		if ((pixels>>4) & 1)
		{
			SET_BIT (SEGMENT1_E_PORT_PORT, SEGMENT1_E_PIN);
		}
		else
		{
			CLR_BIT (SEGMENT1_E_PORT_PORT, SEGMENT1_E_PIN);
		}
		
		if ((pixels>>5) & 1)
		{
			SET_BIT (SEGMENT1_F_PORT_PORT, SEGMENT1_F_PIN);
		}
		else
		{
			CLR_BIT (SEGMENT1_F_PORT_PORT, SEGMENT1_F_PIN);
		}
		
		if ((pixels>>6) & 1)
		{
			SET_BIT (SEGMENT1_G_PORT_PORT, SEGMENT1_G_PIN);
		}
		else
		{
			CLR_BIT (SEGMENT1_G_PORT_PORT, SEGMENT1_G_PIN);
		}
	}
	else
	{
		CLR_BIT (SEGMENT1_A_PORT_PORT, SEGMENT1_A_PIN);
		CLR_BIT (SEGMENT1_B_PORT_PORT, SEGMENT1_B_PIN);
		CLR_BIT (SEGMENT1_C_PORT_PORT, SEGMENT1_C_PIN);
		CLR_BIT (SEGMENT1_D_PORT_PORT, SEGMENT1_D_PIN);
		CLR_BIT (SEGMENT1_E_PORT_PORT, SEGMENT1_E_PIN);
		CLR_BIT (SEGMENT1_F_PORT_PORT, SEGMENT1_F_PIN);
		CLR_BIT (SEGMENT1_G_PORT_PORT, SEGMENT1_G_PIN);
	}
}

void SEGMENTS1_2 (u8 digit)
{
	if ((0 <= digit && digit <= 15) || ('a' <= digit && digit <= 'f') || ('A' <= digit && digit <= 'F'))
	{
		SEGMENTS1_2_PORT_PORT = SEGMENTS_pixel[digit];	
	}
	else
	{
		SEGMENTS1_2_PORT_PORT = 0;
	}
}

void SEGMENTS2 (u8 digit)
{
	if ((0 <= digit && digit <= 15) || ('a' <= digit && digit <= 'f') || ('A' <= digit && digit <= 'F'))
	{
		u8 pixels = ~SEGMENTS_pixel[digit];
		
		if ((pixels>>0) & 1)
		{
			SET_BIT (SEGMENT2_A_PORT_PORT, SEGMENT2_A_PIN);
		}
		else
		{
			CLR_BIT (SEGMENT2_A_PORT_PORT, SEGMENT2_A_PIN);
		}
		
		if ((pixels>>1) & 1)
		{
			SET_BIT (SEGMENT2_B_PORT_PORT, SEGMENT2_B_PIN);
		}
		else
		{
			CLR_BIT (SEGMENT2_B_PORT_PORT, SEGMENT2_B_PIN);
		}
		
		if ((pixels>>2) & 1)
		{
			SET_BIT (SEGMENT2_C_PORT_PORT, SEGMENT2_C_PIN);
		}
		else
		{
			CLR_BIT (SEGMENT2_C_PORT_PORT, SEGMENT2_C_PIN);
		}
		
		if ((pixels>>3) & 1)
		{
			SET_BIT (SEGMENT2_D_PORT_PORT, SEGMENT2_D_PIN);
		}
		else
		{
			CLR_BIT (SEGMENT2_D_PORT_PORT, SEGMENT2_D_PIN);
		}
		
		if ((pixels>>4) & 1)
		{
			SET_BIT (SEGMENT2_E_PORT_PORT, SEGMENT2_E_PIN);
		}
		else
		{
			CLR_BIT (SEGMENT2_E_PORT_PORT, SEGMENT2_E_PIN);
		}
		
		if ((pixels>>5) & 1)
		{
			SET_BIT (SEGMENT2_F_PORT_PORT, SEGMENT2_F_PIN);
		}
		else
		{
			CLR_BIT (SEGMENT2_F_PORT_PORT, SEGMENT2_F_PIN);
		}
		
		if ((pixels>>6) & 1)
		{
			SET_BIT (SEGMENT2_G_PORT_PORT, SEGMENT2_G_PIN);
		}
		else
		{
			CLR_BIT (SEGMENT2_G_PORT_PORT, SEGMENT2_G_PIN);
		}
	}
	else
	{
		CLR_BIT (SEGMENT2_A_PORT_PORT, SEGMENT2_A_PIN);
		CLR_BIT (SEGMENT2_B_PORT_PORT, SEGMENT2_B_PIN);
		CLR_BIT (SEGMENT2_C_PORT_PORT, SEGMENT2_C_PIN);
		CLR_BIT (SEGMENT2_D_PORT_PORT, SEGMENT2_D_PIN);
		CLR_BIT (SEGMENT2_E_PORT_PORT, SEGMENT2_E_PIN);
		CLR_BIT (SEGMENT2_F_PORT_PORT, SEGMENT2_F_PIN);
		CLR_BIT (SEGMENT2_G_PORT_PORT, SEGMENT2_G_PIN);
	}
}

void SEGMENTS2_2 (u8 digit)
{
	if ((0 <= digit && digit <= 15) || ('a' <= digit && digit <= 'f') || ('A' <= digit && digit <= 'F'))
	{
		SEGMENTS2_2_PORT_PORT = ~SEGMENTS_pixel[digit];
	}
	else
	{
		SEGMENTS2_2_PORT_PORT = 0xFF;
	}
}

void SEGMENTS3_2_Init ()
{
	SEGMENTS3_2_PORT_DDR = SEGMENTS3_2_PORT_DDR | (0x00 | 0x0F);
}

void SEGMENTS3_2 (u8 digit)
{
	if (0 <= digit && digit <= 15)
	{
		SEGMENTS3_2_PORT_PORT = (SEGMENTS3_2_PORT_PORT | 0x0F) & (digit | 0xF0);
	}
}

void SEGMENTS4_2_Init ()
{
	SEGMENTS4_2_PORT_DDR = 0xFF;
	SET_BIT(SEGMENT4_1_DDR, SEGMENT4_1_PIN);
	SET_BIT(SEGMENT4_2_DDR, SEGMENT4_2_PIN);
}

void SEGMENTS4_2 (u8 number)
{
	if (0 <= number && number <= 99)
	{
		//pixels = SEGMENTS_pixel[number/10];
		SET_BIT(SEGMENT4_2_PORT, SEGMENT4_2_PIN);
		CLR_BIT(SEGMENT4_1_PORT, SEGMENT4_1_PIN);
		SEGMENTS4_2_PORT_PORT = SEGMENTS_pixel[number/10];
		_delay_ms(1);
		//u8 pixels = SEGMENTS_pixel[number%10];
		SET_BIT(SEGMENT4_1_PORT, SEGMENT4_1_PIN);
		CLR_BIT(SEGMENT4_2_PORT, SEGMENT4_2_PIN);
		SEGMENTS4_2_PORT_PORT = SEGMENTS_pixel[number%10]; 
		_delay_ms(1);	
	}
	else
	{
		SET_BIT(SEGMENT4_2_PORT, SEGMENT4_2_PIN);
		CLR_BIT(SEGMENT4_1_PORT, SEGMENT4_1_PIN);
		SEGMENTS4_2_PORT_PORT = 0;
		_delay_ms(1);
		SET_BIT(SEGMENT4_1_PORT, SEGMENT4_1_PIN);
		CLR_BIT(SEGMENT4_2_PORT, SEGMENT4_2_PIN);
		SEGMENTS4_2_PORT_PORT = 0;
		_delay_ms(1);
	}
}