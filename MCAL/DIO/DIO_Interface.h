/*
* DIO_Interface.h
*
* Created: 4/8/2022 5:43:52 PM
*  Author: Ahmed
*/


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

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
	Float	=0,
	PullUp=1
}Internal_PullUp_t;
ES_t	M_DIO_enuSetPinDirection(PortPin_t Copy_enuPxy,Direction_t Copy_enuDirection);
ES_t	M_DIO_enuSetPinValue(PortPin_t Copy_enuPxy,Logic_t Copy_enuState);
ES_t	M_DIO_enuTogglePinValue(PortPin_t Copy_enuPxy);
ES_t	M_DIO_enuGetPinValue(PortPin_t Pxy,u8 *Copy_u8ReadValue);
ES_t	M_DIO_enuSetPinInternalPullUp(PortPin_t Copy_enuPxy,Internal_PullUp_t Copy_enuPullUpState);
#endif /* DIO_INTERFACE_H_ */