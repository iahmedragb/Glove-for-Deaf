/*
* WDT_Private.h
*
* Created: 3/30/2022 1:28:47 PM
*  Author: Ahmed
*/


#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_

#define WDTCR		(*(volatile u8*)(0x41))



typedef enum
{
	WDP0=0,
	WDP1=1,
	WDP2=2,
	WDE=3,
	WDTOE=4
}WDT_t;

typedef enum
{
	Mode0=0,
	Mode1=1,
	Mode2=2,
	Mode3=3,
	Mode4=4,
	Mode5=5,
	Mode6=6,
	Mode7=7
}WDT_Mode_t;

#endif /* WDT_PRIVATE_H_ */