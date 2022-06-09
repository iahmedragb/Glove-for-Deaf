/*
* EXTI_Config.c
*
* Created: 4/5/2022 12:05:23 AM
*  Author: Ahmed
*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Cpu_Configuration.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/Interrupt.h"

#include "EXTI_Config.h"

u8 EXTI_u8EXTINum = EXTI_NUM;
EXTI_t EXTI_AstrEXTIConfig[EXTI_NUM]=
{
	{RISING_EDGE,INT_0,ENABLE},
	{FALLING_EDGE,INT_1,ENABLE},
	{FALLING_EDGE,INT_2,ENABLE}
};