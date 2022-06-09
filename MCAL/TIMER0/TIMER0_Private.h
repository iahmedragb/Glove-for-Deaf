/*
* TIMER0_Private.h
*
* Created: 4/5/2022 8:11:42 PM
*  Author: Ahmed
*/


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_
#define FREQUENCY		16000000UL
#define DDRB	(*(volatile u8*)(0x37))

/* Timer 0 */
#define TCNT0		(*((volatile u8*)(0x52)))
#define OCR0		(*((volatile u8*)(0x5C)))
/*Control Register*/
#define TCCR0		(*((volatile u8*)(0x53)))
#define CS00	0
#define CS01	1
#define CS02	2
#define WGM01	3
#define COM00	4
#define COM01	5
#define WGM00	6
#define FOC0	7
/*************************/
/*TIMER0 Interrupt Flag*/
#define TIFR		(*((volatile u8*)(0x58)))
#define TOV0	0
#define OCF0	1
/*TIMER0 PIE*/
#define TIMSK		(*((volatile u8*)(0x59)))
#define TOIE0	0
#define OCIE0	1

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

#endif /* TIMER0_PRIVATE_H_ */