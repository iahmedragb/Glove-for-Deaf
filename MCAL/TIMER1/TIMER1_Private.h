/*
 * TIMER1_Private.h
 *
 * Created: 4/7/2022 10:15:08 PM
 *  Author: Ahmed
 */ 


#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define FREQUENCY		16000000UL
#define SREG    (*((volatile u16*)(0x5F)))
#define DDRD	(*(volatile u8*)(0x31))

/* Timer 1 */
#define ICR1    (*((volatile u16*)(0x46)))
#define OCR1B   (*((volatile u16*)(0x48)))
#define OCR1A   (*((volatile u16*)(0x4A)))
#define TCNT1   (*((volatile u16*)(0x4C)))
/*Control Register*/
#define TCCR1B  (*((volatile u8*)(0x4E)))
/* TCCR1B */
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

#define TCCR1A  (*((volatile u8*)(0x4F)))
/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0
/*************************/
/*TIMER0 Interrupt Flag*/
#define TIFR		(*((volatile u8*)(0x58)))
/* TIFR */
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2


/*TIMER0 PIE*/
#define TIMSK		(*((volatile u8*)(0x59)))
/* TIMSK */
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2



#define SFIOR		(*((volatile u8*)(0x50)))



#define NORMAL					0
#define PHASE_CORRECT		1
#define CTC						2
#define	FAST_PWM				3

#define TOGGLE					1
#define CLEAR					2
#define SET						3

#define INVERTED				2
#define NON_INVERTED			3


#define A				2
#define B			3
typedef enum
{
	STOP=0,
	NO_PRESCALE=1,
	PRESCALE_8=2,
	PRESCALE_64=3,
	PRESCALE_256=4,
	PRESCALE_1024=5,
	EXTERNAL_FALLING=6,
	EXTERNAL_RISING=7
}CLK_t;

#endif /* TIMER1_PRIVATE_H_ */