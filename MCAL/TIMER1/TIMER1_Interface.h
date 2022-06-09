/*
 * TIMER1_Interface.h
 *
 * Created: 4/7/2022 10:15:01 PM
 *  Author: Ahmed
 */ 


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_



ES_t TIMER1_enuInit(void);
ES_t TIMER1_enuSetTime_ms(u32 Copy_u32RequiredTime);
ES_t TIMER1_enuStart(void);
ES_t TIMER1_enuStop(void);
ES_t TIMER1_enuCallBack(void*(*pFunAppv)(void*) , void* Copy_pvAppParamter);

ES_t PWM1_enuInit(void);
ES_t PWM1_enuDutycycle(u8 Copy_u8RequiredDutyCycle);
ES_t PWM1_enuStart(void);
ES_t PWM1_enuStop(void);
ES_t PWM1_enuCallBack(void*(*pFunAppv)(void*) , void* Copy_pvAppParamter);


#endif /* TIMER1_INTERFACE_H_ */