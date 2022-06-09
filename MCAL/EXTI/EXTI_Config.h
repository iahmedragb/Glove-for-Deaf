/*
* EXTI_Config.h
*
* Created: 4/5/2022 12:04:00 AM
*  Author: Ahmed
*/


#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_
#define EXTI_NUM	3

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



#endif /* EXTI_CONFIG_H_ */