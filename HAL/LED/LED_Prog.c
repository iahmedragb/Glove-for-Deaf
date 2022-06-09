/*
* LED_Prog.c
*
* Created: 4/8/2022 10:14:20 PM
*  Author: Ahmed
*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"
#include "../../MCAL/DIO/DIO_Interface.h"

#include "LED_Config.h"
#include "LED_Private.h"
extern u8 LED_u8LEDNum;
ES_t LED_enuInit(PortPin_t *Copy_pAstrLEDConfig)
{
	if(Copy_pAstrLEDConfig != NULL)
	{
		u8 Local_u8Iter = 0;
		for(;Local_u8Iter < LED_u8LEDNum ; Local_u8Iter++)
		{
			M_DIO_enuSetPinDirection(Copy_pAstrLEDConfig[Local_u8Iter],DIO_Output);
			M_DIO_enuSetPinValue(Copy_pAstrLEDConfig[Local_u8Iter],DIO_Low);
		}
		return ES_OK;
	}else
	{
		return ES_NULL_POINTER;
	}
}
ES_t LED_enuOffAll(PortPin_t *Copy_pAstrLEDConfig)
{
	if(Copy_pAstrLEDConfig != NULL)
	{
		u8 Local_u8Iter = 0;
		for(;Local_u8Iter < LED_u8LEDNum ; Local_u8Iter++)
		{
			M_DIO_enuSetPinValue(Copy_pAstrLEDConfig[Local_u8Iter],DIO_Low);
		}
		return ES_OK;
	}else
	{
		return ES_NULL_POINTER;
	}
}
ES_t LED_enuOnAll(PortPin_t *Copy_pAstrLEDConfig)
{
	if(Copy_pAstrLEDConfig != NULL)
	{
		u8 Local_u8Iter = 0;
		for(;Local_u8Iter < LED_u8LEDNum ; Local_u8Iter++)
		{
			M_DIO_enuSetPinValue(Copy_pAstrLEDConfig[Local_u8Iter],DIO_High);
		}
		return ES_OK;
	}else
	{
		return ES_NULL_POINTER;
	}
}
ES_t LED_enuOn(PortPin_t *Copy_pstrLEDInfo)
{
	if(Copy_pstrLEDInfo != NULL)
	{
		M_DIO_enuSetPinValue(*Copy_pstrLEDInfo,DIO_High);
		return ES_OK;
	}else
	{
		return ES_NULL_POINTER;
	}
}
ES_t LED_enuOff(PortPin_t *Copy_pstrLEDInfo)
{
	if(Copy_pstrLEDInfo != NULL)
	{
		M_DIO_enuSetPinValue(*Copy_pstrLEDInfo,DIO_Low);
		return ES_OK;
	}else
	{
		return ES_NULL_POINTER;
	}
}
ES_t LED_enuToggle(PortPin_t *Copy_pstrLEDInfo)
{
	if(Copy_pstrLEDInfo != NULL)
	{
		M_DIO_enuTogglePinValue(*Copy_pstrLEDInfo);
		return ES_OK;
	}else
	{
		return ES_NULL_POINTER;
	}
}
