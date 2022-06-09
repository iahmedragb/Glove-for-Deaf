/*
 * DIO_Private.h
 *
 * Created: 4/8/2022 5:44:01 PM
 *  Author: Ahmed
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_
/*PORT	D*/
#define PIND	(*(volatile u8*)(0x30))
#define DDRD	(*(volatile u8*)(0x31))
#define PORTD	(*(volatile u8*)(0x32))
/*PORT	C*/
#define PINC	(*(volatile u8*)(0x33))
#define DDRC	(*(volatile u8*)(0x34))
#define PORTC	(*(volatile u8*)(0x35))
/*PORT	B*/
#define PINB	(*(volatile u8*)(0x36))
#define DDRB	(*(volatile u8*)(0x37))
#define PORTB	(*(volatile u8*)(0x38))
/*PORT	A*/
#define PINA	(*(volatile u8*)(0x39))
#define DDRA	(*(volatile u8*)(0x3A))
#define PORTA	(*(volatile u8*)(0x3B))

typedef enum
{
	PA0=0,
	PA1=1,
	PA2=2,
	PA3=3,
	PA4=4,
	PA5=5,
	PA6=6,
	PA7=7,
	PB0=10,
	PB1=11,
	PB2=12,
	PB3=13,
	PB4=14,
	PB5=15,
	PB6=16,
	PB7=17,
	PC0=20,
	PC1=21,
	PC2=22,
	PC3=23,
	PC4=24,
	PC5=25,
	PC6=26,
	PC7=27,
	PD0=30,
	PD1=31,
	PD2=32,
	PD3=33,
	PD4=34,
	PD5=35,
	PD6=36,
	PD7=37
}PortPin_t;
typedef enum
{
	DIO_Input=0,
	DIO_Output=1
}Direction_t;
typedef enum
{
	DIO_Low	=0,
	DIO_High=1
}Logic_t;
typedef enum
{
	Pin_Float	=0,
	Pin_PullUp=1
}Internal_PullUp_t;
/**/
#define A				0
#define B				1
#define C				2
#define D				3
#endif /* DIO_PRIVATE_H_ */