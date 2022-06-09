/*
* L293D_Prog.c
*
* Created: 3/23/2022 9:27:14 PM
*  Author: Ahmed
*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMER0/TIMER0_Interface.h"
#include "L293D_Config.h"
#include "L293D_Private.h"

extern u8 L293D_u8L293DNum;
extern u8 DCM_u8DCMNum;

ES_t L293D_enuInit(L293D_t * Copy_pAstrL293DConfig)
{
	u8 Local_u8ErrorState = ES_NOK;
	if(Copy_pAstrL293DConfig != NULL)
	{
		u8 Local_u8L293DIter=0,Local_u8DCMIter=0;
		for(;Local_u8L293DIter<L293D_u8L293DNum; Local_u8L293DIter++)
		{
			for(;Local_u8DCMIter<DCM_u8DCMNum; Local_u8DCMIter++)
			{
				/*DIO_enuSetPinDirection(Copy_pAstrL293DConfig[Local_u8L293DIter].Motors[Local_u8DCMIter].EN_Port,
				Copy_pAstrL293DConfig[Local_u8L293DIter].Motors[Local_u8DCMIter].EN_Pin,DIO_Output);*/
				M_DIO_enuSetPinDirection(Copy_pAstrL293DConfig[Local_u8L293DIter].Motors[Local_u8DCMIter].IN1,DIO_Output);
				M_DIO_enuSetPinDirection(Copy_pAstrL293DConfig[Local_u8L293DIter].Motors[Local_u8DCMIter].IN2,DIO_Output);
				
				/*DIO_enuSetPinValue(Copy_pAstrL293DConfig[Local_u8L293DIter].Motors[Local_u8DCMIter].EN_Port,
				Copy_pAstrL293DConfig[Local_u8L293DIter].Motors[Local_u8DCMIter].EN_Pin,DIO_High);*/
				M_DIO_enuSetPinValue(Copy_pAstrL293DConfig[Local_u8L293DIter].Motors[Local_u8DCMIter].IN1,DIO_Low);
				M_DIO_enuSetPinValue(Copy_pAstrL293DConfig[Local_u8L293DIter].Motors[Local_u8DCMIter].IN2,DIO_Low);
			}
		}
		Local_u8ErrorState = ES_OK;
	}else
	{
		Local_u8ErrorState = ES_NULL_POINTER;
	}
	return Local_u8ErrorState;
}
ES_t L293D_enuDirection(DCM_t *Copy_pstrDCMInfo, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState = ES_NOK;
	if(Copy_pstrDCMInfo !=NULL)
	{
		switch(Copy_u8Direction)
		{
			case Stop :
			M_DIO_enuSetPinValue(Copy_pstrDCMInfo->IN1, DIO_Low);
			M_DIO_enuSetPinValue(Copy_pstrDCMInfo->IN2, DIO_Low);
			break;
			
			case Forward:
			M_DIO_enuSetPinValue(Copy_pstrDCMInfo->IN1, DIO_High);
			M_DIO_enuSetPinValue(Copy_pstrDCMInfo->IN2, DIO_Low);
			break;
			
			case Backward:
			M_DIO_enuSetPinValue(Copy_pstrDCMInfo->IN1, DIO_Low);
			M_DIO_enuSetPinValue(Copy_pstrDCMInfo->IN2, DIO_High);
			break;
			
			case Brake :
			M_DIO_enuSetPinValue(Copy_pstrDCMInfo->IN1, DIO_High);
			M_DIO_enuSetPinValue(Copy_pstrDCMInfo->IN2, DIO_High);
			break;
			
			default:
			return ES_OUT_OF_RANGE;
		}
		Local_u8ErrorState = ES_OK;
	}else
	{
		Local_u8ErrorState = NULL;
	}
	
	return Local_u8ErrorState;
}
ES_t L293D_enuReverseDirection(DCM_t *Copy_pstrDCMInfo)
{
	M_DIO_enuTogglePinValue(Copy_pstrDCMInfo->IN1);
	M_DIO_enuTogglePinValue(Copy_pstrDCMInfo->IN2);
	return ES_OK;
}
ES_t L293D_enuSpeed(u8 Copy_u8Speed)
{
	u8 Local_u8ErrorState = ES_NOK;
	if(Copy_u8Speed <=100)
	{
		PWM0_enuInit();
		PWM0_enuDutycycle(Copy_u8Speed);
		Local_u8ErrorState = ES_OK;
	}else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}
	return Local_u8ErrorState;
}
ES_t L293D_enuStart(void)
{
	PWM0_enuStart();
	return ES_OK;
}
ES_t L293D_enuStop(void)
{
	PWM0_enuStop();
	return ES_OK;
}
ES_t L293D_enuCallBack(void(*Copy_pAppFun)(void));
