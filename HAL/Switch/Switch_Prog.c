/*
* Switch_Prog.c
*
* Created: 3/19/2022 2:15:39 AM
*  Author: Ahmed
*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/Cpu_Configuration.h"

#include <util/delay.h>
#include "../../MCAL/DIO/DIO_Interface.h"

#include "Switch_Config.h"
#include "Switch_Private.h"

extern u8 Switch_u8SwitchNum;
ES_t Switch_enuInit(Switch_t *Copy_pAstrSwitchConfig)
{
	if(Copy_pAstrSwitchConfig != NULL)
	{
		ES_t Local_u8Iter = 0;
		for(;Local_u8Iter < Switch_u8SwitchNum ; Local_u8Iter++)
		{
			M_DIO_enuSetPinDirection(Copy_pAstrSwitchConfig[Local_u8Iter].PortPin, DIO_Input);
			M_DIO_enuSetPinInternalPullUp(Copy_pAstrSwitchConfig[Local_u8Iter].PortPin, Copy_pAstrSwitchConfig[Local_u8Iter].Switch_State);
		}
		return ES_OK;
	}else
	{
		return ES_NULL_POINTER;
	}
}
ES_t Switch_enuGetState(Switch_t *Copy_pstrSwitchInfo , u8 *Copy_StateGetStateValue)
{
	if((Copy_StateGetStateValue!=NULL)&&(Copy_pstrSwitchInfo!=NULL))
	{
		switch(Copy_pstrSwitchInfo->Switch_State)
		{
			case Float:
			M_DIO_enuGetPinValue(Copy_pstrSwitchInfo->PortPin, Copy_StateGetStateValue);
			if((*Copy_StateGetStateValue))
			{
				_delay_ms(10);
				M_DIO_enuGetPinValue(Copy_pstrSwitchInfo->PortPin, Copy_StateGetStateValue);
				if((*Copy_StateGetStateValue))
				{
					while((*Copy_StateGetStateValue))
					{
						M_DIO_enuGetPinValue(Copy_pstrSwitchInfo->PortPin, Copy_StateGetStateValue);
					}
					*Copy_StateGetStateValue = DIO_High;
				}
			}
			break;
			case PullUp:
			M_DIO_enuGetPinValue(Copy_pstrSwitchInfo->PortPin, Copy_StateGetStateValue);
			if(!(*Copy_StateGetStateValue))
			{
				_delay_ms(10);
				M_DIO_enuGetPinValue(Copy_pstrSwitchInfo->PortPin, Copy_StateGetStateValue);
				if(!(*Copy_StateGetStateValue))
				{
					while(!(*Copy_StateGetStateValue))
					{
						M_DIO_enuGetPinValue(Copy_pstrSwitchInfo->PortPin, Copy_StateGetStateValue);
					}
					*Copy_StateGetStateValue = DIO_Low;
				}
			}
			break;
			default: return ES_OUT_OF_RANGE;
		}
		return ES_OK;
	}else
	{
		return  ES_NULL_POINTER;
	}
}