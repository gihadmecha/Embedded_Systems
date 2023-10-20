 


#ifndef KEYPAD_LCFG_H_
#define KEYPAD_LCFG_H_

#define		A		PINB4
#define		B		PINB5
#define		C		PINB6
#define		D		PINB7
#define		_1		PIND2
#define		_2		PIND3
#define		_3		PIND4
#define		_4		PIND0

#define		NO_KEY		NULL

static const char KEYPAD[4][4] = {{'7', '8', '9', '/'},
								  {'4', '5', '6', '*'},
								  {'1', '2', '3', '-'},
								  {'C', '0', '=', '+'}};



#endif /* KEYPAD_LCFG_H_ */