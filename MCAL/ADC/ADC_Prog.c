/*
 * ADC_Prog.c
 *
 * Created: 5/2/2022 4:51:42 AM
 *  Author: Ahmed
 */ 
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Cpu_Configuration.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/Interrupt.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "ADC_Config.h"
#include "ADC_Private.h"
#include "ADC_Interface.h"
static volatile u16 *ADC_thumb;
static volatile u16 *ADC_indexfinger;
static volatile u16 *ADC_middle;
static volatile u16 *ADC_ring;
static volatile u16 *ADC_pinky;
static volatile void (*ADC_AppFun)(void);

void ADC_Init(void)
{
	//DDRA = 0;
	//PORTA= 0;
	//ADMUX =0x40;
	/*ADC Enable*/
	SET_BIT(ADCSRA,ADEN);
	SET_BIT(ADCSRA,REFS0);
	/*channel*/
	ADMUX = ADC_Channel0;
	/*Prescaler */
	ADCSRA |= (7U<<0);
	/*ADC Interrupt*/
	SET_BIT(ADCSRA,ADIE);
	

}
void ADC_Start(void)
{
	/*Clear flag*/
	//SET_BIT(ADCSRA,ADIF);
	/*Start Conversion*/
	SET_BIT(ADCSRA,ADSC);	
}
u16 ADC_Read(void)
{
	u16 adcread=0;
	while(!(GET_BIT(ADCSRA,ADIF)));
	adcread= ADC;
	return adcread;
}
void ADC_Callback(u16 *pApAppFunParameter0,u16 *pApAppFunParameter1,u16 *pApAppFunParameter2,u16 *pApAppFunParameter3,u16 *pApAppFunParameter4,void (*pAppFun)(void))
{
	ADC_thumb = pApAppFunParameter0;
	ADC_indexfinger  = pApAppFunParameter1;
	ADC_middle  = pApAppFunParameter2;
	ADC_ring  = pApAppFunParameter3;
	ADC_pinky  = pApAppFunParameter4;
	ADC_AppFun = pAppFun;
	
}
ISR(ADC_vect_16)
{
	static u8 channel=ADC_Channel0;
	switch(channel)
	{
		case ADC_Channel0: 
		*ADC_thumb=ADC;
		ADMUX = ADC_Channel1;
		channel=ADC_Channel1;
		/*Start Conversion*/
		SET_BIT(ADCSRA,ADSC);
		break;
		case ADC_Channel1:
		*ADC_indexfinger=ADC;
		ADMUX = ADC_Channel2;
		channel=ADC_Channel2;
		/*Start Conversion*/
		SET_BIT(ADCSRA,ADSC);
		break;
		case ADC_Channel2:
		*ADC_middle=ADC;
		ADMUX = ADC_Channel3;
		channel=ADC_Channel3;
		/*Start Conversion*/
		SET_BIT(ADCSRA,ADSC);
		break;
		case ADC_Channel3:
		*ADC_ring=ADC;
		ADMUX = ADC_Channel4;
		channel=ADC_Channel4;
		/*Start Conversion*/
		SET_BIT(ADCSRA,ADSC);
		break;
		case ADC_Channel4:
		*ADC_pinky=ADC;
		ADMUX = ADC_Channel0;
		channel=ADC_Channel0;
		ADC_AppFun();
		break;
	}
		
}