/*
* EXTI_Prog.c
*
* Created: 4/5/2022 12:04:50 AM
*  Author: Ahmed
*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Cpu_Configuration.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/Interrupt.h"

#include "EXTI_Config.h"
#include "EXTI_Private.h"

extern u8 EXTI_u8EXTINum;
static void* (*ApFunApp[EXTI_NUM])(void*)={NULL,NULL,NULL};
static void* AvpAppParameter[EXTI_NUM]={NULL,NULL,NULL};

ES_t EXTI_enuInit(EXTI_t *Copy_pAstrEXTIConfig)
{
	if(Copy_pAstrEXTIConfig != NULL)
	{
		u8 Local_u8Iter;
		for(Local_u8Iter=0; Local_u8Iter < EXTI_u8EXTINum;Local_u8Iter++)
		{
			if((Copy_pAstrEXTIConfig[Local_u8Iter].INT_Num == INT_0) ||(Copy_pAstrEXTIConfig[Local_u8Iter].INT_Num == INT_1))
			{
				CLR_BIT(MCUCR, (Copy_pAstrEXTIConfig[Local_u8Iter].INT_Num )*2);
				CLR_BIT(MCUCR, (((Copy_pAstrEXTIConfig[Local_u8Iter].INT_Num )*2)+1));
				switch(Copy_pAstrEXTIConfig[Local_u8Iter].SenseLvl)
				{
					
					case LOW_LVL:
					break;
					case ANY_CHANGE:
					SET_BIT(MCUCR, (Copy_pAstrEXTIConfig[Local_u8Iter].INT_Num )*2);
					CLR_BIT(MCUCR, (((Copy_pAstrEXTIConfig[Local_u8Iter].INT_Num )*2)+1));
					break;
					case FALLING_EDGE:
					CLR_BIT(MCUCR, (Copy_pAstrEXTIConfig[Local_u8Iter].INT_Num )*2);
					SET_BIT(MCUCR, (((Copy_pAstrEXTIConfig[Local_u8Iter].INT_Num )*2)+1));
					break;
					case RISING_EDGE:
					SET_BIT(MCUCR, (Copy_pAstrEXTIConfig[Local_u8Iter].INT_Num )*2);
					SET_BIT(MCUCR, (((Copy_pAstrEXTIConfig[Local_u8Iter].INT_Num )*2)+1));
					break;
					default:return ES_NOK;
					break;
				}
				switch(Copy_pAstrEXTIConfig[Local_u8Iter].INT_Mode)
				{
					
					case ENABLE :
					SET_BIT(GICR, (6+(Copy_pAstrEXTIConfig[Local_u8Iter].INT_Num)));
					break;
					case DISABLE:
					CLR_BIT(GICR, (6+(Copy_pAstrEXTIConfig[Local_u8Iter].INT_Num)));
					break;
					default: return ES_NOK;
				}
				
			}else if (Copy_pAstrEXTIConfig[Local_u8Iter].INT_Num == INT_2)
			{
				CLR_BIT(MCUCSR,6);
				switch(Copy_pAstrEXTIConfig[Local_u8Iter].SenseLvl)
				{
					case FALLING_EDGE :
					break;
					case RISING_EDGE:
					SET_BIT(MCUCSR,6);
					break;
					default: return ES_NOK;
					break;
				}
				switch(Copy_pAstrEXTIConfig[Local_u8Iter].INT_Mode)
				{
					case DISABLE: CLR_BIT(GICR,5);
					break;
					case ENABLE: SET_BIT(GICR,5);
					break;
					default: return ES_NOK;
				}
			}
			else
			{
				return ES_OUT_OF_RANGE;
			}
			return ES_OK;
		}
	}else
	{
		return ES_NULL_POINTER;
	}
	return ES_NOK;
}
ES_t EXTI_enuSenseLvl(EXTI_t *Copy_pstrEXTIInfo, SenseLvL_t Copy_enuSenseLvl)
{
	if(Copy_pstrEXTIInfo != NULL)
	{
		if((Copy_pstrEXTIInfo->INT_Num == INT_0) ||(Copy_pstrEXTIInfo->INT_Num == INT_1))
		{
			CLR_BIT(MCUCR, (Copy_pstrEXTIInfo->INT_Num)*2);
			CLR_BIT(MCUCR, (((Copy_pstrEXTIInfo->INT_Num)*2)+1));
			switch(Copy_pstrEXTIInfo->SenseLvl)
			{
				
				case LOW_LVL:
				break;
				case ANY_CHANGE:
				SET_BIT(MCUCR, (Copy_pstrEXTIInfo->INT_Num)*2);
				CLR_BIT(MCUCR, (((Copy_pstrEXTIInfo->INT_Num)*2)+1));
				break;
				case FALLING_EDGE:
				CLR_BIT(MCUCR, (Copy_pstrEXTIInfo->INT_Num)*2);
				SET_BIT(MCUCR, (((Copy_pstrEXTIInfo->INT_Num)*2)+1));
				break;
				case RISING_EDGE:
				SET_BIT(MCUCR, (Copy_pstrEXTIInfo->INT_Num)*2);
				SET_BIT(MCUCR, (((Copy_pstrEXTIInfo->INT_Num)*2)+1));
				break;
				default:return ES_NOK;
				break;
			}
		}else if (Copy_pstrEXTIInfo->INT_Num == INT_2)
		{
			CLR_BIT(MCUCSR,6);
			switch(Copy_pstrEXTIInfo->SenseLvl)
			{
				case FALLING_EDGE :
				break;
				case RISING_EDGE:
				SET_BIT(MCUCSR,6);
				break;
				default: return ES_NOK;
				break;
			}
		}
		else
		{
			return ES_OUT_OF_RANGE;
		}
		return ES_OK;
	}else
	{
		return ES_NULL_POINTER;
	}
	return ES_NOK;
}
ES_t EXTI_enuEnable(EXTI_t *Copy_pstrEXTIInfo)
{
	if(Copy_pstrEXTIInfo != NULL)
	{
		if((Copy_pstrEXTIInfo->INT_Num == INT_0) ||(Copy_pstrEXTIInfo->INT_Num == INT_1))
		{
			SET_BIT(GICR, (6+(Copy_pstrEXTIInfo->INT_Num)));
			
			
		}else if (Copy_pstrEXTIInfo->INT_Num == INT_2)
		{
			SET_BIT(GICR,5);
			
		}
		else
		{
			return ES_OUT_OF_RANGE;
		}
		return ES_OK;
	}else
	{
		return ES_NULL_POINTER;
	}
	return ES_NOK;
}
ES_t EXTI_enuDisable(EXTI_t *Copy_pstrEXTIInfo)
{
	if(Copy_pstrEXTIInfo != NULL)
	{
		if((Copy_pstrEXTIInfo->INT_Num == INT_0) ||(Copy_pstrEXTIInfo->INT_Num == INT_1))
		{
			
			CLR_BIT(GICR, (6+(Copy_pstrEXTIInfo->INT_Num)));
			
			
		}else if (Copy_pstrEXTIInfo->INT_Num == INT_2)
		{
			CLR_BIT(GICR,5);
			
		}
		else
		{
			return ES_OUT_OF_RANGE;
		}
		return ES_OK;
	}else
	{
		return ES_NULL_POINTER;
	}
	return ES_NOK;
}
ES_t EXTI_enuCallBack(EXTI_t *Copy_pstrEXTIInfo, void*(*pFunAppv)(void*) , void* Copy_pvAppParamter)
{
	if((Copy_pstrEXTIInfo !=NULL)&&(pFunAppv != NULL))
	{
		ApFunApp[(Copy_pstrEXTIInfo->INT_Num)]= pFunAppv;
		AvpAppParameter[(Copy_pstrEXTIInfo->INT_Num)] = Copy_pvAppParamter;
		return ES_OK;
	}else
	{
		return ES_NULL_POINTER;
	}
	return ES_NOK;
}

ISR(INT0_vect_1)
{
	if(AvpAppParameter[0] != NULL)
	{
		ApFunApp[0](AvpAppParameter[0]);
	}
}
ISR(INT1_vect_2)
{
	if(AvpAppParameter[1] != NULL)
	{
		ApFunApp[1](AvpAppParameter[1]);
	}
}
ISR(INT2_vect_3)
{
	if(AvpAppParameter[2] != NULL)
	{
		ApFunApp[2](AvpAppParameter[2]);
	}
}
