/*
* TIMER1_Prog.c
*
* Created: 4/7/2022 10:15:17 PM
*  Author: Ahmed
*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Cpu_Configuration.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/Interrupt.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "TIMER1_Config.h"
#include "TIMER1_Private.h"

/*TIMER OVERFLOW Mode*/
static u32 Num_OVF;
static	u16 Preload;
/*CTC*/
static u32 Num_OCM;

/*ISR*/
static void* (*pFunApp)(void*)={NULL};
static void* vpAppParameter={NULL};
ES_t TIMER1_enuInit(void)
{
	
	#if COMPARE_OUTPUT_CHANNEL == A
	/*Compare Output Mode*/
	TCCR1A |= (NPWM_OC1_MODE<<6);
	SET_BIT(DDRD,5);
	#elif COMPARE_OUTPUT_CHANNEL	== B
	TCCR1A |= (NPWM_OC1_MODE<<4);
	SET_BIT(DDRD,4);
	#else
	#error "hamada"
	#endif
	/*FOC1*/										/*Waveform Generator Mode*/
	CLR_BIT(TCCR1A,FOC1A);CLR_BIT(TCCR1A,FOC1B);	TCCR1A |= ((((TIMER1_MODE&1)<<WGM10) | ((TIMER1_MODE &2)<<WGM11)));TCCR1B |=((((TIMER1_MODE&3)<<WGM12) | ((TIMER1_MODE &4)<<WGM13)));
	/*Clk must be stopped*/
	TCCR1B|= STOP;
	#if TIMER1_MODE	== NORMAL
	/*Enable PIE*/
	SET_BIT(TIMSK,2);
	#elif TIMER1_MODE == CTC
	#if COMPARE_OUTPUT_CHANNEL == A
	SET_BIT(TIMSK,4);
	#elif COMPARE_OUTPUT_CHANNEL	== B
	SET_BIT(TIMSK,3);
	#else
	#error "hamada"
	#endif
	#else
	#error "error init timer1"
	#endif
	/*Enable GIE*/
	asm("SEI");
	return ES_OK;
}
ES_t TIMER1_enuSetTime_ms(u32 Copy_u32RequiredTime)
{
	u8 Local_u8TickTime = PRESCALE*1000UL*1000UL/FREQUENCY;	//in micro seconds
	u32 Local_u32Total_Ticks= Copy_u32RequiredTime*1000UL/Local_u8TickTime;
	#if TIMER1_MODE == NORMAL
	Num_OVF = Local_u32Total_Ticks/65535;
	Preload = 65535 - (Local_u32Total_Ticks%65535);
	if(Preload)
	{
		Num_OVF++;
		TCNT1 = Preload;
	}else
	{
		TCNT1=0;
	}
	#elif	TIMER1_MODE	== CTC
	u16 Local_u16OCR1=65535;
	while(Local_u32Total_Ticks%Local_u16OCR1)
	{
		Local_u16OCR1--;
	}
	Num_OCM = Local_u32Total_Ticks/Local_u16OCR1;
	OCR1A = Local_u16OCR1-1;
	OCR1B = Local_u16OCR1-1;
	#else
	#error  "Timer1 Mode"
	#endif
	return ES_OK;
}
ES_t TIMER1_enuStart(void)
{
	TCCR1B &=~(7<<0);

	TCCR1B|=CLK;
	return ES_OK;
	
}
ES_t TIMER1_enuStop(void)
{
	TCCR1B &=~(7<<0);
	return ES_OK;
}
ES_t TIMER1_enuCallBack(void*(*pFunAppv)(void*) , void* Copy_pvAppParamter)
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

ES_t PWM1_enuInit(void)
{
	
	#if COMPARE_OUTPUT_CHANNEL == A
	/*Compare Output Mode*/
	TCCR1A |= (NPWM_OC1_MODE<<6);
	SET_BIT(DDRD,5);

	#elif COMPARE_OUTPUT_CHANNEL	== B
	TCCR1A |= (NPWM_OC1_MODE<<4);
	SET_BIT(DDRD,4);

	#else
	#error "hamada"
	#endif
	/*FOC1*/										/*Waveform Generator Mode*/
	CLR_BIT(TCCR1A,FOC1A);CLR_BIT(TCCR1A,FOC1B);	TCCR1A |= ((((PWM1_MODE&1)<<WGM10) | ((PWM1_MODE &2)<<WGM11)));TCCR1B |=((((PWM1_MODE&3)<<WGM12) | ((PWM1_MODE &4)<<WGM13)));
	/*Clk must be stopped*/
	TCCR1B &= ~7;
	/*Enable PIE*/
	TIMSK |=0x3C;
	
	/*Enable GIE*/
	asm("SEI");
	return ES_OK;
}

ES_t PWM1_enuDutycycle(u8 Copy_u8RequiredDutyCycle)
{
	
	
	if(Copy_u8RequiredDutyCycle <=100)
	{
		#if PWM1_MODE	== FAST_PWM
		#if PWM_OC1_MODE	== INVERTED
		OCR1A =(65535- ((((u32)Copy_u8RequiredDutyCycle*65535)/100)));
		#elif	PWM_OC1_MODE == NON_INVERTED
		OCR1A = ((((u32)Copy_u8RequiredDutyCycle*65535)/100) - 1);
		#else
		#error	"PWM OC1 Mode"
		#endif
		#elif	PWM0_MODE	== PHASE_CORRECT
		#if PWM_OC0_MODE	== INVERTED
		OCR1A = 65535-((((u32)Copy_u8RequiredDutyCycle*65535)/100));
		#elif	PWM_OC0_MODE == NON_INVERTED
		OCR1A = ((((u32)Copy_u8RequiredDutyCycle*65535)/100));
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
ES_t PWM1_enuStart(void)
{
	TCCR1B|=CLK;
	return ES_OK;
}
ES_t PWM1_enuStop(void)
{
	TCCR1B &=~ (7<<0);
	return ES_OK;
}
ES_t PWM1_enuCallBack(void*(*pFunAppv)(void*) , void* Copy_pvAppParamter)
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
ISR(TIMER1_CAPT_vect_6)
{
	
}
ISR(TIMER1_COMPA_vect_7)
{
	static u32 counter;
	counter++;
	if(counter == Num_OCM)
	{
		pFunApp(vpAppParameter);
		counter=0;
	}
}
ISR(TIMER1_COMPB_vect_8)
{
	static u32 counter;
	counter++;
	if(counter == Num_OCM)
	{
		pFunApp(vpAppParameter);
		counter=0;
	}
}
ISR(TIMER1_OVF_vect_9)
{
	static u32 counter;
	counter++;
	if(counter == Num_OVF)
	{
		pFunApp(vpAppParameter);
		counter=0;
		TCNT1 = Preload;
	}
}


