

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


/***********************************************TIMER0******************************************/
#define		TCCR0	(*(unsigned volatile char*)0x53)
#define		WGM00	6
#define		COM01	5
#define		COM00	4
#define		WGM01	3
#define		CS02	2
#define		CS01	1
#define		CS00	0

#define		TIMSK	(*(unsigned volatile char*)0x59)
#define		OCIE0	1
#define		TOIE0	0

#define		TCNT0	(*(unsigned volatile char*)0x52)
#define		OCR0	(*(unsigned volatile char*)0x5C)


/***********************************************TIMER1******************************************/
#define		TCNT1H	(*(unsigned volatile char*)0x4D)
#define		TCNT1L	(*(unsigned volatile char*)0x4C)
#define		TCNT1	(*(unsigned volatile short*)0x4C)

#define		OCR1AH	(*(unsigned volatile char*)0x4B)
#define		OCR1AL	(*(unsigned volatile char*)0x4A)
#define		OCR1A	(*(unsigned volatile short*)0x4A)

#define		OCR1BH	(*(unsigned volatile char*)0x49)
#define		OCR1BL	(*(unsigned volatile char*)0x48)
#define		OCR1B	(*(unsigned volatile short*)0x48)

#define		ICR1H	(*(unsigned volatile char*)0x47)
#define		ICR1L	(*(unsigned volatile char*)0x46)
#define		ICR1	(*(unsigned volatile short*)0x46)

#define		TIMSK	(*(unsigned volatile char*)0x59)
#define		TICIE1	5
#define		OCIE1A	4
#define		OCIE1B	3
#define		TOIE1	2

#define		TCCR1B	(*(unsigned volatile char*)0x4E)
#define		ICES1	6
#define		WGM13	4
#define		WGM12	3
#define		CS12	2
#define		CS11	1
#define		CS10	0

#define		TCCR1A	(*(unsigned volatile char*)0x4F)
#define		COM1A1	7
#define		COM1A0	6
#define		COM1B1	5
#define		COM1B0	4
#define		WGM11	1
#define		WGM10	0

/***********************************************UART******************************************/
#define		UDR		(*(unsigned volatile char*)0x2C)

#define		UCSRA	(*(unsigned volatile char*)0x2B)
#define		RXC		7
#define		TXC		6
#define		UDRE	5
#define		U2X		1

#define		UCSRB	(*(unsigned volatile char*)0x2A)
#define		RXCIE	7
#define		TXCIE	6
#define		UDRIE	5
#define		RXEN	4
#define		TXEN	3
#define		UCSZ2	2

#define		UCSRC	(*(unsigned volatile char*)0x40)
#define		URSEL	7
#define		UMSEL	6
#define		UPM1	5
#define		UPM0	4
#define		USBS	3
#define		UCSZ1	2
#define		UCSZ0	1
#define		UCPOL	0

#define		UBRRH	(*(unsigned volatile char*)0x40)

#define		UBRRL	(*(unsigned volatile char*)0x29)

/***********************************************SPI******************************************/
#define		SPCR	(*(unsigned volatile char*)0x2D)
#define		SPIE	7
#define		SPE		6
#define		DORD	5
#define		MSTR	4
#define		SPR1	1
#define		SPR0	0

#define		SPSR	(*(unsigned volatile char*)0x2E)
#define		SPIF	7
#define		WCOL	6
#define		SP12X	0	

#define		SPDR	(*(unsigned volatile char*)0x2F)

/***********************************************EEPROM******************************************/
#define		EECR    (*(unsigned volatile char*)0x3C)
#define		EERE    0
#define		EEWE    1
#define		EEMWE   2
#define		EEARH   (*(unsigned volatile char*)0x3F)
#define		EEARL   (*(unsigned volatile char*)0x3E)
#define		EEAR    (*(unsigned volatile short*)0x3E)
#define		EEDR	(*(unsigned volatile short*)0x3D)

/***********************************************EEPROM******************************************/
#define		WDTCR	(*(unsigned volatile char*)0x41)
#define		WDP0	0
#define		WDP1	1
#define		WDP2	2
#define		WDE		3
#define		WDTOE	4

/******************************INTERRUPPT_ATTRRIBUTES****************************************/
#define		SEI()		    __asm__ __volatile__("SEI"::)
#define		CLI()		    __asm__ __volatile__("CLI"::)

#define		ADC_vect					__vector_16
#define		INT0_vect					__vector_1
#define		INT1_vect					__vector_2
#define		INT2_vect					__vector_3
#define		TIMER0_overflow_vect		__vector_11
#define		TIMER0_compareMatch_vect	__vector_10
#define		TIMER1_compareMatch1A_vect  __vector_7
#define		TIMER1_compareMatch1B_vect  __vector_8
#define		TIMER1_timeStamp_vect		__vector_6
#define		TIMER1_overflow_vect		__vector_9
#define		UART_RXC_vect				__vector_13
#define		UART_UDRempty_vect			__vector_14
#define		UART_TXC_vect				__vector_15
#define		SPI_Vect					__vector_12
#define		ISR(vector)		void vector(void)__attribute__((signal));\
						    void vector(void)

/*********************************STATUS REGISTER*******************************************/
#define		SREG	(*(unsigned volatile char*)0x5F)
#define		I		7

#endif /* MEMMAP_H_ */