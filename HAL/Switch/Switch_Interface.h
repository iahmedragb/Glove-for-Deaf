/*
 * Switch_Interface.h
 *
 * Created: 3/19/2022 2:16:23 AM
 *  Author: Ahmed
 */ 


#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_
#include "Switch_Config.h"
Switch_t Switch_AstrSwitchConfig[SWITCH_NUM];

ES_t Switch_enuInit(Switch_t *Copy_pAstrSwitchConfig);
ES_t Switch_enuGetState(Switch_t *Copy_pstrSwitchInfo , u8 *Copy_StateGetStateValue);

#define NOT_PRESSED	0xFF




#endif /* SWITCH_INTERFACE_H_ */