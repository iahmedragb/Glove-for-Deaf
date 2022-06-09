/*
* Switch_Config.c
*
* Created: 3/19/2022 2:15:27 AM
*  Author: Ahmed
*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "Switch_Config.h"

u8 Switch_u8SwitchNum= SWITCH_NUM;

Switch_t Switch_AstrSwitchConfig[SWITCH_NUM]=
{
	{PB0,Float},
	{PD6,Float},
	{PD2,Float}
};