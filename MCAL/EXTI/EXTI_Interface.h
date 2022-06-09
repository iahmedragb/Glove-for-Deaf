/*
 * EXTI_Interface.h
 *
 * Created: 4/5/2022 12:04:08 AM
 *  Author: Ahmed
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum
{
	LOW_LVL = 0,
	ANY_CHANGE=1,
	FALLING_EDGE=2,
	RISING_EDGE =3
}SenseLvL_t;

typedef enum
{
	INT_0 = 0,
	INT_1=1,
	INT_2=2
}INT_t;


typedef enum
{
	ENABLE = 0,
	DISABLE=1
}MODE_t;

typedef struct
{
	SenseLvL_t SenseLvl;
	INT_t	INT_Num;
	MODE_t	INT_Mode;
}EXTI_t;
ES_t EXTI_enuInit(EXTI_t *Copy_pAstrEXTIConfig);
ES_t EXTI_enuSenseLvl(EXTI_t *Copy_pstrEXTIInfo, SenseLvL_t Copy_enuSenseLvl);
ES_t EXTI_enuEnable(EXTI_t *Copy_pstrEXTIInfo);
ES_t EXTI_enuDisable(EXTI_t *Copy_pstrEXTIInfo);
ES_t EXTI_enuCallBack(EXTI_t *Copy_pstrEXTIInfo, void*(*pFunAppv)(void*) , void* Copy_pvAppParamter);




#endif /* EXTI_INTERFACE_H_ */