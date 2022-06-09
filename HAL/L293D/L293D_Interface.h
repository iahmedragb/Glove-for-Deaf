/*
 * L293D_Interface.h
 *
 * Created: 3/23/2022 9:26:45 PM
 *  Author: Ahmed
 */ 


#ifndef L293D_INTERFACE_H_
#define L293D_INTERFACE_H_
#include "L293D_Config.h"
extern L293D_t L293D_AstrL293DConfig[L293D_NUM];
ES_t L293D_enuInit(L293D_t * Copy_pAstrL293DConfig);
ES_t L293D_enuStart(void);
ES_t L293D_enuStop(void);
ES_t L293D_enuDirection(DCM_t *Copy_pstrDCMInfo, u8 Copy_u8Direction);
ES_t L293D_enuReverseDirection(DCM_t *Copy_pstrDCMInfo);
ES_t L293D_enuSpeed(u8 Copy_u8Speed);
ES_t L293D_enuCallBack(void(*Copy_pAppFun)(void));






#endif /* L293D_INTERFACE_H_ */