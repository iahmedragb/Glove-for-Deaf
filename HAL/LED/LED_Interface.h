/*
 * LED_Interface.h
 *
 * Created: 4/8/2022 10:14:47 PM
 *  Author: Ahmed
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
#include "LED_Config.h"
extern PortPin_t LED_AstrLEDConfig[LED_NUM];

ES_t LED_enuInit(PortPin_t *Copy_pAstrLEDConfig);
ES_t LED_enuOffAll(PortPin_t *Copy_pAstrLEDConfig);
ES_t LED_enuOnAll(PortPin_t *Copy_pAstrLEDConfig);
ES_t LED_enuOn(PortPin_t *Copy_pstrLEDInfo);
ES_t LED_enuOff(PortPin_t *Copy_pstrLEDInfo);
ES_t LED_enuToggle(PortPin_t *Copy_pstrLEDInfo);




#endif /* LED_INTERFACE_H_ */