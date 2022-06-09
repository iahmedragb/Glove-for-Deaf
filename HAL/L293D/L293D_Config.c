/*
* L293D_Config.c
*
* Created: 3/23/2022 9:26:23 PM
*  Author: Ahmed
*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"


#include "../../MCAL/DIO/DIO_Interface.h"

#include "L293D_Config.h"
#include "L293D_Private.h"

u8 L293D_u8L293DNum = L293D_NUM;
u8 DCM_u8DCMNum = DCM_NUM;
L293D_t L293D_AstrL293DConfig[L293D_NUM]=
{
	//{{{PORT_C,Pin_0,PORT_B,Pin_3,PORT_C,Pin_2},{PORT_C,Pin_3,PORT_B,Pin_3,PORT_C,Pin_5}}}
	{{{PC3,PC4},{PC5,PC6}}}
};
