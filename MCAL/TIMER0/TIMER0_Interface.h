/*
 * TIMER0_Interface.h
 *
 * Created: 4/5/2022 8:11:31 PM
 *  Author: Ahmed
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

ES_t TIMER0_enuInit(void);
ES_t TIMER0_enuSetTime_ms(u32 Copy_u32RequiredTime);
ES_t TIMER0_enuStart(void);
ES_t TIMER0_enuStop(void);
ES_t TIMER0_enuCallBack(void*(*pFunAppv)(void*) , void* Copy_pvAppParamter);

ES_t PWM0_enuInit(void);
ES_t PWM0_enuDutycycle(u8 Copy_u8RequiredDutyCycle);
ES_t PWM0_enuStart(void);
ES_t PWM0_enuStop(void);
ES_t PWM0_enuCallBack(void*(*pFunAppv)(void*) , void* Copy_pvAppParamter);




#endif /* TIMER0_INTERFACE_H_ */