/*
* Buzzer_Prog.c
*
* Created: 3/23/2022 4:07:53 PM
*  Author: Ahmed
*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/Cpu_Configuration.h"
#include <util/delay.h>

#include "../../MCAL/DIO/DIO_Interface.h"

#include "Buzzer_Config.h"
#include "Buzzer_Private.h"

extern u8 Buzzer_u8BuzzerNum;
ES_t Buzzer_enuInit(PortPin_t *Copy_pAstrBuzzerConfig)
{
	if(Copy_pAstrBuzzerConfig !=NULL)
	{
		u8 Local_u8Iter=0;
		for(;Local_u8Iter<Buzzer_u8BuzzerNum; Local_u8Iter++)
		{
			M_DIO_enuSetPinDirection(Copy_pAstrBuzzerConfig[Local_u8Iter],DIO_Output);
			M_DIO_enuSetPinValue(Copy_pAstrBuzzerConfig[Local_u8Iter],DIO_Low);
		}
		return ES_OK;
	}else
	{
		return ES_NULL_POINTER;
	}
}
ES_t Buzzer_enuON(PortPin_t *Copy_pstrBuzzerInfo)
{
	if(Copy_pstrBuzzerInfo != NULL)
	{
		M_DIO_enuSetPinValue(*Copy_pstrBuzzerInfo,DIO_High);
		return ES_OK;
	}
	else
	{
		return ES_NULL_POINTER;
	}
}
ES_t Buzzer_enuOFF(PortPin_t *Copy_pstrBuzzerInfo)
{
	if(Copy_pstrBuzzerInfo != NULL)
	{
		M_DIO_enuSetPinValue(*Copy_pstrBuzzerInfo,DIO_Low);
		return ES_OK;
	}
	else
	{
		return ES_NULL_POINTER;
	}
}
ES_t Buzzer_enuToggle(PortPin_t *Copy_pstrBuzzerInfo)
{
	if(Copy_pstrBuzzerInfo != NULL)
	{
		M_DIO_enuTogglePinValue(*Copy_pstrBuzzerInfo);
		return ES_OK;
	}
	else
	{
		return ES_NULL_POINTER;
	}
}
ES_t Buzzer_enuOnce(PortPin_t* Copy_pstrBuzzerInfo)
{
	if(Copy_pstrBuzzerInfo != NULL)
	{
		M_DIO_enuSetPinValue(*Copy_pstrBuzzerInfo,DIO_High);
		_delay_ms(100);
		M_DIO_enuSetPinValue(*Copy_pstrBuzzerInfo,DIO_Low);
		return ES_OK;
	}
	else
	{
		return ES_NULL_POINTER;
	}
}
ES_t Buzzer_enuTwice(PortPin_t *Copy_pstrBuzzerInfo)
{
	if(Copy_pstrBuzzerInfo != NULL)
	{
		M_DIO_enuSetPinValue(*Copy_pstrBuzzerInfo,DIO_High);
		_delay_ms(100);
		M_DIO_enuSetPinValue(*Copy_pstrBuzzerInfo,DIO_Low);
		_delay_ms(200);
		M_DIO_enuSetPinValue(*Copy_pstrBuzzerInfo,DIO_High);
		_delay_ms(100);
		M_DIO_enuSetPinValue(*Copy_pstrBuzzerInfo,DIO_Low);
		return ES_OK;
	}
	else
	{
		return ES_NULL_POINTER;
	}
}
ES_t Buzzer_enuTriple(PortPin_t *Copy_pstrBuzzerInfo)
{
	if(Copy_pstrBuzzerInfo != NULL)
	{
		M_DIO_enuSetPinValue(*Copy_pstrBuzzerInfo,DIO_High);
		_delay_ms(100);
		M_DIO_enuSetPinValue(*Copy_pstrBuzzerInfo,DIO_Low);
		_delay_ms(200);
		M_DIO_enuSetPinValue(*Copy_pstrBuzzerInfo,DIO_High);
		_delay_ms(100);
		M_DIO_enuSetPinValue(*Copy_pstrBuzzerInfo,DIO_Low);
		_delay_ms(200);
		M_DIO_enuSetPinValue(*Copy_pstrBuzzerInfo,DIO_High);
		_delay_ms(100);
		M_DIO_enuSetPinValue(*Copy_pstrBuzzerInfo,DIO_Low);
		return ES_OK;
	}
	else
	{
		return ES_NULL_POINTER;
	}
}
ES_t Buzzer_enuLong(PortPin_t *Copy_pstrBuzzerInfo)
{
	M_DIO_enuSetPinValue(*Copy_pstrBuzzerInfo,DIO_High);
	_delay_ms(1000);
	M_DIO_enuSetPinValue(*Copy_pstrBuzzerInfo,DIO_Low);
	return ES_OK;
}