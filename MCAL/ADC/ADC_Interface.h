/*
 * ADC_Interface.h
 *
 * Created: 5/2/2022 4:52:11 AM
 *  Author: Ahmed
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_Init(void);
void ADC_Start(void);
u16 ADC_Read(void);
void ADC_Callback(u16 *pApAppFunParameter0,u16 *pApAppFunParameter1,u16 *pApAppFunParameter2,u16 *pApAppFunParameter3,u16 *pApAppFunParameter4,void(*pAppFun)(void));



#endif /* ADC_INTERFACE_H_ */