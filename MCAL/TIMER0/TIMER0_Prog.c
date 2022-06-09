/*
* TIMER0_Prog.c
*
* Created: 4/5/2022 8:11:50 PM
*  Author: Ahmed
*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Cpu_Configuration.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/Interrupt.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "TIMER0_Config.h"
#include "TIMER0_Private.h"
/*TIMER OVERFLOW Mode*/
static u32 Num_OVF;
static	u8 Preload;
/*CTC*/
static u32 Num_OCM;

/*ISR*/
static void* (*pFunApp)(void*)={NULL};
static void* vpAppParameter={NULL};
ES_t TIMER0_enuInit(void)
{
	SET_BIT(DDRB,3);
	
	/*FOC0*/				/*Waveform Generator Mode*/											/*Compare Output Mode*/			/*Clk must be stopped*/
	CLR_BIT(TCCR0,FOC0);	TCCR0 |= ((((TIMER0_MODE&1)<<WGM00) | ((TIMER0_MODE &2)<<WGM01)));	TCCR0 |= (NPWM_OC0_MODE<<4);	TCCR0|= STOP;
	
	/*Enable PIE*/
	SET_BIT(TIMSK,(TIMER0_MODE/2));
	/*Enable GIE*/
	asm("SEI");
	return ES_OK;
}
ES_t TIMER0_enuSetTime_ms(u32 Copy_u32RequiredTime)
{
	u8 Local_u8TickTime = PRESCALE*1000UL*1000UL/FREQUENCY;	//in micro seconds
	u32 Local_u32Total_Ticks= Copy_u32RequiredTime*1000UL/Local_u8TickTime;
	#if TIMER0_MODE == NORMAL
	Num_OVF = Local_u32Total_Ticks/256;
	Preload = 256 - (Local_u32Total_Ticks%256);
	if(Preload)
	{
		Num_OVF++;
		TCNT0 = Preload;
	}else
	{
		TCNT0=0;
	}
	#elif	TIMER0_MODE	== CTC
	u8 Local_u8OCR0=255;
	while(Local_u32Total_Ticks%Local_u8OCR0)
	{
		Local_u8OCR0--;
	}
	Num_OCM = Local_u32Total_Ticks/Local_u8OCR0;
	OCR0 = Local_u8OCR0-1;
	
	#else
	#error  "Timer0 Mode"
	#endif
	return ES_OK;
}
ES_t TIMER0_enuStart(void)
{
	TCCR0|= STOP;
	TCCR0|=CLK;
	return ES_OK;
	
}
ES_t TIMER0_enuStop(void)
{
	TCCR0|= STOP;
	return ES_OK;
}
ES_t TIMER0_enuCallBack(void*(*pFunAppv)(void*) , void* Copy_pvAppParamter)
{
	if(pFunAppv !=NULL)
	{
		pFunApp = pFunAppv;
		if(Copy_pvAppParamter!=NULL)
		{
			vpAppParameter = Copy_pvAppParamter;
		}
		return ES_OK;
	}else
	{
		return ES_NULL_POINTER;
	}
	return ES_NOK;
}

ES_t PWM0_enuInit(void)
{
	SET_BIT(DDRB,3);
	/*FOC0*/				/*Waveform Generator Mode*/											/*Compare Output Mode*/			/*Clk must be stopped*/
	CLR_BIT(TCCR0,FOC0);	TCCR0 |= ((((PWM0_MODE&1)<<WGM00) | ((PWM0_MODE &2)<<WGM01)));		TCCR0 |= (PWM_OC0_MODE<<4);					TCCR0 &=~(7<<0);

	
	/*Enable PIE*/
	SET_BIT(TIMSK,TOIE0);
	SET_BIT(TIMSK,OCIE0);
	/*Enable GIE*/
	asm("SEI");
	return ES_OK;
}
ES_t PWM0_enuDutycycle(u8 Copy_u32RequiredDutyCycle)
{
	if(Copy_u32RequiredDutyCycle <=100)
	{
		#if PWM0_MODE	== FAST_PWM
		#if PWM_OC0_MODE	== INVERTED
		OCR0 = 255-((((u32)Copy_u32RequiredDutyCycle*255)/100));
		#elif	PWM_OC0_MODE == NON_INVERTED
		OCR0 = ((((u32)Copy_u32RequiredDutyCycle*255)/100));
		#else
		#error	"PWM OC0 Mode"
		#endif
		#elif	PWM0_MODE	== PHASE_CORRECT
		#if PWM_OC0_MODE	== INVERTED
		OCR0 = 255-((((u32)Copy_u32RequiredDutyCycle*255)/100));
		#elif	PWM_OC0_MODE == NON_INVERTED
		OCR0 = ((((u32)Copy_u32RequiredDutyCycle*255)/100));
		#else
		#error	"PWM OC0 Mode"
		#endif
		#else
		#error	"PWM Mode"
		#endif
		return ES_OK;
	}
	else
	{
		return ES_OUT_OF_RANGE;
	}
	return ES_OK;
}
ES_t PWM0_enuStart(void)
{
		TCCR0 &=~(7<<0);
	TCCR0|=CLK;
	return ES_OK;
}
ES_t PWM0_enuStop(void)
{
		TCCR0 &=~(7<<0);

	return ES_OK;
}
ES_t PWM0_enuCallBack(void*(*pFunAppv)(void*) , void* Copy_pvAppParamter)
{
	if(pFunAppv !=NULL)
	{
		pFunApp = pFunAppv;
		if(Copy_pvAppParamter!=NULL)
		{
			vpAppParameter = Copy_pvAppParamter;
		}
		return ES_OK;
	}else
	{
		return ES_NULL_POINTER;
	}
	return ES_NOK;
}

ISR(TIMER0_OVF_vect_11)
{
	static u32 counter;
	counter++;
	if(counter == Num_OVF)
	{
		pFunApp(vpAppParameter);
		counter=0;
		TCNT0 = Preload;
	}
}
ISR(TIMER0_COMP_vect_10)
{
	static u32 counter;
	counter++;
	if(counter == Num_OCM)
	{
		pFunApp(vpAppParameter);
		counter=0;
	}
	
}