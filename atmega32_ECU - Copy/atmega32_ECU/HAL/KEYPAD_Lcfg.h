 


#ifndef KEYPAD_LCFG_H_
#define KEYPAD_LCFG_H_

#define		A		PINC0
#define		B		PINC1
#define		C		PINC2
#define		D		PINC3
#define		_1		PINC4
#define		_2		PINC5
#define		_3		PINC6
#define		_4		PINC7

#define		NO_KEY		NULL

static const char KEYPAD[4][4] = {{'7', '8', '9', '/'},
								  {'4', '5', '6', '*'},
								  {'1', '2', '3', '-'},
								  {'C', '0', '=', '+'}};



#endif /* KEYPAD_LCFG_H_ */