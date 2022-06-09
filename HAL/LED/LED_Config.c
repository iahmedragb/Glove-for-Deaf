/*
 * LED_Config.c
 *
 * Created: 4/8/2022 10:14:12 PM
 *  Author: Ahmed
 */ 
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "LED_Config.h"

u8 LED_u8LEDNum= LED_NUM;

PortPin_t LED_AstrLEDConfig[LED_NUM]=
{
	PC2,
	PC7,
	PD3
};