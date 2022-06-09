/*
 * SSD_Interface.h
 *
 * Created: 3/24/2022 10:40:33 PM
 *  Author: Ahmed
 */ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_
#include "SSD_Config.h"
extern SSD_t SSD_AstrSSDConfig[SSD_NUM];
ES_t SSD_enuInit(SSD_t *Copy_pAstrSSDConfig);
ES_t SSD_enuDisplaySingleNumber(SSD_t *Copy_pAstrSSDinfo,u8 Copy_u8Number);
ES_t SSD_enuDisplayNumbers(SSD_t *Copy_pAstrSSDinfo,u8 Copy_u8Number);
ES_t SSD_enuEnableDisplay(SSD_t *Copy_pAstrSSDinfo);
ES_t SSD_enuDisableDisplay(SSD_t *Copy_pAstrSSDinfo);
ES_t SSD_enuEnableDot(SSD_t *Copy_pAstrSSDinfo);
ES_t SSD_enuDisableDot(SSD_t *Copy_pAstrSSDinfo);





#endif /* SSD_INTERFACE_H_ */