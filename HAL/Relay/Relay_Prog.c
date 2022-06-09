/*
* Relay_Prog.c
*
* Created: 3/24/2022 10:09:07 PM
*  Author: Ahmed
*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"

#include "../../MCAL/DIO/DIO_Config.h"
#include "../../MCAL/DIO/DIO_Interface.h"

#include "Relay_Config.h"
#include "Relay_Private.h"

extern u8 Relay_u8RelayNum;
ES_t Relay_enuInit(PortPin_t *Copy_pAstrConfig)
{
	if(Copy_pAstrConfig !=NULL)
	{
		u8 Local_u8Iter;
		for(Local_u8Iter=0; Local_u8Iter<Relay_u8RelayNum; Local_u8Iter++)
		{
			M_DIO_enuSetPinDirection(Copy_pAstrConfig[Local_u8Iter],DIO_Output);
			M_DIO_enuSetPinValue(Copy_pAstrConfig[Local_u8Iter],DIO_Low);
		}
		return ES_OK;
	}else
	{
		return ES_NULL_POINTER;
	}
}
ES_t Relay_enuTrip(PortPin_t *Copy_pstrRelayInfo)
{
	if(Copy_pstrRelayInfo !=NULL)
	{
		M_DIO_enuSetPinValue(*Copy_pstrRelayInfo,DIO_High);
		return ES_OK;
	}else
	{
		return ES_NULL_POINTER;	
	}
	
}
ES_t Relay_enuSwitch(PortPin_t *Copy_pstrRelayInfo)
{
	if(Copy_pstrRelayInfo !=NULL)
	{
		M_DIO_enuSetPinValue(*Copy_pstrRelayInfo,DIO_Low);
		return ES_OK;
	}else
	{
		return ES_NULL_POINTER;
	}
}


