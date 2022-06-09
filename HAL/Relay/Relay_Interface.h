/*
 * Relay_Interface.h
 *
 * Created: 3/24/2022 10:09:28 PM
 *  Author: Ahmed
 */ 


#ifndef RELAY_INTERFACE_H_
#define RELAY_INTERFACE_H_

#include "Relay_Config.h"
extern PortPin_t Relay_AstrRelayConfig[RELAY_NUM];

ES_t Relay_enuInit(PortPin_t *Copy_pAstrConfig);
ES_t Relay_enuTrip(PortPin_t *Copy_pstrRelayInfo);
ES_t Relay_enuSwitch(PortPin_t *Copy_pstrRelayInfo);



#endif /* RELAY_INTERFACE_H_ */