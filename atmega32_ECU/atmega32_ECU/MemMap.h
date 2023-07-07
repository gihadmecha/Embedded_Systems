

#ifndef MEMMAP_H_
#define MEMMAP_H_


/*************************DIO*******************************/
#define		DDRA	( *(volatile unsigned char*)0x3A )
#define		PORTA	( *(volatile unsigned char*)0x3B )
#define		PINA	( *(volatile unsigned char*)0x39 )

#define		DDRB	( *(volatile unsigned char*)0x37 )
#define		PORTB	( *(volatile unsigned char*)0x38 )
#define		PINB	( *(volatile unsigned char*)0x36 )

#define		DDRC	( *(volatile unsigned char*)0x34 )
#define		PORTC	( *(volatile unsigned char*)0x35 )
#define		PINC	( *(volatile unsigned char*)0x33 )

#define		DDRD	( *(volatile unsigned char*)0x31 )
#define		PORTD	( *(volatile unsigned char*)0x32 )
#define		PIND	( *(volatile unsigned char*)0x30 )


/************************ADC********************************/
#define		ADMUX	( *(volatile unsigned char*)0x27 )
#define		REFS1	7
#define		REFS0	6
#define		ADLAR	5
#define		MUX4	4
#define		MUX3	3
#define		MUX2	2
#define		MUX1	1
#define		MUX0	0
#define		ADCSRA	( *(volatile unsigned char*)0x26 )
#define		ADEN	7
#define		ADSC	6
#define		ADIE	3
#define		ADPS2	2
#define		ADPS1	1
#define		ADPS0	0
#define		ADCH	( *(volatile unsigned char*) 0x25)
#define		ADCL	( *(volatile unsigned char*) 0x24)
#define		ADC	    ( *(volatile unsigned short*) 0x24)

/***********************************************EXI******************************************/
#define		GICR	(*(unsigned volatile char*)0x5B)
#define     INT0	6
#define     INT1	7
#define     INT2	5

#define		MCUCR	(*(unsigned volatile char*)0x55)
#define		ISC00	0
#define		ISC01	1

#define		MCUCSR	(*(unsigned volatile char*)0x54)
#define		ISC2	6

/******************************INTERRUPPT_ATTRRIBUTES****************************************/
#define		SEI()		    __asm__ __volatile__("SEI"::)
#define		CLI()		    __asm__ __volatile__("CLI"::)

#define		ADC_vect	    __vector_16
#define		INT0_vect	    __vector_1
#define		INT1_vect	    __vector_2
#define		INT2_vect	    __vector_3
#define		ISR(vector)		void vector(void)__attribute__((signal));\
						    void vector(void)

/*********************************STATUS REGISTER*******************************************/
#define		SREG	(*(unsigned volatile char*)0x5F)
#define		I		7

#endif /* MEMMAP_H_ */