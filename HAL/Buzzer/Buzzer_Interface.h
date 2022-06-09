/*
 * Buzzer_Interface.h
 *
 * Created: 3/23/2022 4:07:34 PM
 *  Author: Ahmed
 */ 


#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_
 #include "Buzzer_Config.h"
 extern PortPin_t Buzzer_BuzzerAstrConfig[BUZZER_NUM];
 ES_t Buzzer_enuInit(PortPin_t *Copy_pAstrBuzzerConfig);
 ES_t Buzzer_enuON(PortPin_t *Copy_pstrBuzzerInfo);
 ES_t Buzzer_enuOFF(PortPin_t *Copy_pstrBuzzerInfo);
 ES_t Buzzer_enuToggle(PortPin_t *Copy_pstrBuzzerInfo);
 ES_t Buzzer_enuOnce(PortPin_t *Copy_pstrBuzzerInfo);
 ES_t Buzzer_enuTwice(PortPin_t *Copy_pstrBuzzerInfo);
 ES_t Buzzer_enuTriple(PortPin_t *Copy_pstrBuzzerInfo);
 ES_t Buzzer_enuLong(PortPin_t *Copy_pstrBuzzerInfo);
 




#endif /* BUZZER_INTERFACE_H_ */