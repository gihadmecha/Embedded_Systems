
#include "DIO_interface.h"
#include "SEGMENTS.h"
#include "BUTTON.h"

void increaseLeftSegment ();
void increaseRightSegment ();

static u8 leftSegment = 0;
static u8 rightSegment = 0;

int main ()
{
	DIO_Init();
	
	SEGMENTS_left(0);
	SEGMENTS_right(0);
	
	while (1)
	{
		BUTTON1_IfPressed_PeriodicCheck (increaseLeftSegment);
		SEGMENTS_left(leftSegment);
		BUTTON2_IfPressed_PeriodicCheck (increaseRightSegment);
		SEGMENTS_right(rightSegment);
	}
	
}

void increaseLeftSegment ()
{
	leftSegment++;
	
	if (leftSegment == 10)
	{
		leftSegment = 0;
	}
}

void increaseRightSegment ()
{
	rightSegment++;
	
	if (rightSegment == 10)
	{
		rightSegment = 0;
	}
}