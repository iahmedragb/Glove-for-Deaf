/*
* LCD_Prog.c
*
* Created: 3/19/2022 3:58:32 AM
*  Author: Ahmed
*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/Cpu_Configuration.h"

#include <util/delay.h>


#include "../../MCAL/DIO/DIO_Interface.h"

#include "LCD_Config.h"
#include "LCD_Private.h"


ES_t LCD_enuInit(void)
{
	_delay_ms(35);
	M_DIO_enuSetPinDirection(LCD_CTRL_RS,DIO_Output);
	M_DIO_enuSetPinDirection(LCD_CTRL_RW,DIO_Output);
	M_DIO_enuSetPinDirection(LCD_CTRL_EN,DIO_Output);
	M_DIO_enuSetPinDirection(LCD_DATA_D7,DIO_Output);
	M_DIO_enuSetPinDirection(LCD_DATA_D6,DIO_Output);
	M_DIO_enuSetPinDirection(LCD_DATA_D5,DIO_Output);
	M_DIO_enuSetPinDirection(LCD_DATA_D4,DIO_Output);
	#if LCD_MODE == EIGHT_BIT_MODE
	/*
	DIO_enuSetPinDirection(LCD_DATA_D3,DIO_Output);
	DIO_enuSetPinDirection(LCD_DATA_D2,DIO_Output);
	DIO_enuSetPinDirection(LCD_DATA_D1,DIO_Output);
	DIO_enuSetPinDirection(LCD_DATA_D0,DIO_Output);
	*/
	/*Function Set*/
	_delay_ms(35);
	LCD_enuLatch((0x30 || (N_DISPLAY_LINES<<3)||(F_DISPLAY_FONT<<2)));
	_delay_ms(1);
	#elif LCD_MODE == FOUR_BIT_MODE
	M_DIO_enuSetPinValue(LCD_CTRL_RS,DIO_Low);
	/*Function Set*/
	M_DIO_enuSetPinValue(LCD_DATA_D7, 0);
	M_DIO_enuSetPinValue(LCD_DATA_D6, 0);
	M_DIO_enuSetPinValue(LCD_DATA_D5, 1);
	M_DIO_enuSetPinValue(LCD_DATA_D4, 0);
	M_DIO_enuSetPinValue(LCD_CTRL_EN, DIO_High);
	_delay_ms(5);
	M_DIO_enuSetPinValue(LCD_CTRL_EN, DIO_Low);
	_delay_ms(5);
	LCD_enuLatch((0x20 | (N_DISPLAY_LINES<<3)|(F_DISPLAY_FONT<<2)));
	_delay_ms(1);
	#else
	#error "Undefined LCD Mode"
	#endif
	/*Display Control*/
	LCD_enuLatch((0x08)|(D_DISPLAY_MODE<<2)|(C_CURSOR_MODE<<1)|(B_BLINK_MODE<<0));
	_delay_ms(1);
	/*Display Clear*/
	LCD_enuLatch(COM_CLEAR_DISPLAY);
	_delay_ms(2);
	/*Entry Set*/
	LCD_enuLatch((0x04)|(ID_INCREMENT_MODE<<1)|(SH_SHIFT_MODE<<0));
	return ES_OK;
}
ES_t LCD_enuWriteCommand(u8 Copy_u8Command)
{
	M_DIO_enuSetPinValue(LCD_CTRL_RS,DIO_Low);
	M_DIO_enuSetPinValue(LCD_CTRL_RW,DIO_Low);
	M_DIO_enuSetPinValue(LCD_CTRL_EN,DIO_Low);
	LCD_enuLatch(Copy_u8Command);
	return ES_OK;
}
ES_t LCD_enuWriteData(u8 Copy_u8Data)
{
	M_DIO_enuSetPinValue(LCD_CTRL_RS,DIO_High);
	M_DIO_enuSetPinValue(LCD_CTRL_RW,DIO_Low);
	M_DIO_enuSetPinValue(LCD_CTRL_EN,DIO_Low);
	LCD_enuLatch(Copy_u8Data);
	return ES_OK;
}
ES_t LCD_enuWriteString(u8 *Copy_pu8String)
{
	u8 Local_u8ErrorState = ES_NOK;
	if(Copy_pu8String != NULL)
	{
		u8 Local_u8iter = 0;
		while(Copy_pu8String[Local_u8iter] != '\0')
		{
			LCD_enuWriteData(Copy_pu8String[Local_u8iter++]);
		}
		Local_u8ErrorState = ES_OK;
	}else
	{
		Local_u8ErrorState = ES_NULL_POINTER;
	}
	return Local_u8ErrorState;
}
ES_t LCD_enuWriteIntegerNum(s32 Copy_s32IntegerNum)
{
	u8 Local_u8ErrorState = ES_NOK;
	if(Copy_s32IntegerNum == 0)
	{
		LCD_enuWriteData('0');
		Local_u8ErrorState = ES_OK;
	}else
	{
		if(Copy_s32IntegerNum<0)
		{
			LCD_enuWriteData('-');
			Copy_s32IntegerNum *= (-1);
		}
		u32 Local_u32Num = 0,Local_u32DecimalUnit=10;
		u8 Local_u8Digits=0;
		while(Copy_s32IntegerNum)
		{
			Local_u8Digits++;
			Local_u32Num *= Local_u32DecimalUnit;

			Local_u32Num += (Copy_s32IntegerNum%10) ;
			Copy_s32IntegerNum /= 10;

		}
		while(Local_u8Digits)
		{
			LCD_enuWriteData((Local_u32Num%10)+'0');
			Local_u32Num /=10;
			Local_u8Digits--;
		}
		Local_u8ErrorState = ES_OK;
	}
	return Local_u8ErrorState;
}
ES_t LCD_enuWriteFloatNum(f32 Copy_f32FloatNum)
{
	u8 Local_u8ErrorState = ES_NOK;
	if(Copy_f32FloatNum == 0)
	{
		LCD_enuWriteData('0');
		Local_u8ErrorState = ES_OK;
	}else
	{
		s32 Local_s32DecimalVal = Copy_f32FloatNum;
		LCD_enuWriteIntegerNum(Local_s32DecimalVal);
		LCD_enuWriteData('.');
		Copy_f32FloatNum -= Local_s32DecimalVal;
		Copy_f32FloatNum *= 1000000;
		Local_s32DecimalVal = Copy_f32FloatNum;
		while((Local_s32DecimalVal%10 == 0))
		{
			Local_s32DecimalVal /=10;
		}
		LCD_enuWriteIntegerNum(Local_s32DecimalVal);
		
		Local_u8ErrorState = ES_OK;
	}
	return Local_u8ErrorState;
}
ES_t LCD_enuGoToPosition(u8 Copy_u8Row, u8 Copy_u8Column)
{
	u8 Local_u8ErrorState = ES_NOK;
	if(Copy_u8Row<=2 && Copy_u8Column<=16)
	{
		switch(Copy_u8Row)
		{
			case  1 :
			LCD_enuWriteCommand((0x80)+Copy_u8Column-1);
			Local_u8ErrorState = ES_OK;
			break;
			case 2 :
			LCD_enuWriteCommand((0xC0)+Copy_u8Column-1);
			Local_u8ErrorState = ES_OK;
			break;
			default:
			Local_u8ErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}
	return Local_u8ErrorState;
}
ES_t LCD_enuCharacterGenerator(u8 Pattern, const u8 *Copy_u8CustomCharacter)
{
	u8 Local_u8ErrorState = ES_NOK;
	if(Copy_u8CustomCharacter != NULL)
	{
		LCD_enuWriteCommand((0x40)+(8*Pattern));
		u8 Local_u8Iter = 0;
		for(;Local_u8Iter<8 ; Local_u8Iter++)
		{
			LCD_enuWriteData(Copy_u8CustomCharacter[Local_u8Iter]);
		}
	}else
	{
		Local_u8ErrorState = ES_NULL_POINTER;
	}
	return Local_u8ErrorState;
}

static ES_t LCD_enuLatch(u8 Copy_u8Latch)
{
	u8 Local_u8ErrorState = ES_NOK;
	M_DIO_enuSetPinValue(LCD_CTRL_RW, DIO_Low);
	M_DIO_enuSetPinValue(LCD_CTRL_EN, DIO_Low);
	#if LCD_MODE == EIGHT_BIT_MODE
	/*DIO_enuSetPinValue(LCD_DATA_D7_PORT, LCD_DATA_D7_PIN, (Copy_u8Latch>>Pin_7) & 1));
	DIO_enuSetPinValue(LCD_DATA_D6_PORT, LCD_DATA_D6_PIN, (Copy_u8Latch>>Pin_6) & 1));
	DIO_enuSetPinValue(LCD_DATA_D5_PORT, LCD_DATA_D5_PIN, (Copy_u8Latch>>Pin_5) & 1));
	DIO_enuSetPinValue(LCD_DATA_D4_PORT, LCD_DATA_D4_PIN, (Copy_u8Latch>>Pin_4) & 1));
	DIO_enuSetPinValue(LCD_DATA_D3_PORT, LCD_DATA_D3_PIN, (Copy_u8Latch>>Pin_3) & 1);
	DIO_enuSetPinValue(LCD_DATA_D2_PORT, LCD_DATA_D2_PIN, (Copy_u8Latch>>Pin_2) & 1);
	DIO_enuSetPinValue(LCD_DATA_D1_PORT, LCD_DATA_D1_PIN, (Copy_u8Latch>>Pin_1) & 1);
	DIO_enuSetPinValue(LCD_DATA_D0_PORT, LCD_DATA_D0_PIN, (Copy_u8Latch>>Pin_0) & 1);*/
	#elif LCD_MODE == FOUR_BIT_MODE
	M_DIO_enuSetPinValue(LCD_DATA_D7, ((Copy_u8Latch>>7) & 1));
	M_DIO_enuSetPinValue(LCD_DATA_D6, ((Copy_u8Latch>>6) & 1));
	M_DIO_enuSetPinValue(LCD_DATA_D5, ((Copy_u8Latch>>5) & 1));
	M_DIO_enuSetPinValue(LCD_DATA_D4, ((Copy_u8Latch>>4) & 1));
	M_DIO_enuSetPinValue(LCD_CTRL_EN, DIO_High);
	_delay_ms(10);
	M_DIO_enuSetPinValue(LCD_CTRL_EN, DIO_Low);
	_delay_ms(10);
	
	M_DIO_enuSetPinValue(LCD_DATA_D7, ((Copy_u8Latch>>3) & 1));
	M_DIO_enuSetPinValue(LCD_DATA_D6, ((Copy_u8Latch>>2) & 1));
	M_DIO_enuSetPinValue(LCD_DATA_D5, ((Copy_u8Latch>>1) & 1));
	M_DIO_enuSetPinValue(LCD_DATA_D4, ((Copy_u8Latch>>0) & 1));
	
	#else
	#error "Undefined LCD Mode"
	#endif
	M_DIO_enuSetPinValue(LCD_CTRL_EN, DIO_High);
	_delay_ms(5);
	M_DIO_enuSetPinValue(LCD_CTRL_EN, DIO_Low);
	_delay_ms(5);
	
	Local_u8ErrorState = ES_OK;
	return Local_u8ErrorState;
}




ES_t LCD_enuStopWatch(u8 Seconds,u8  Minutes,u8  Hours)
{
	/*Hours Display*/
	LCD_enuGoToPosition(1,5);
	if(Hours<=9)
	{
		LCD_enuWriteData('0');
	}
	LCD_enuWriteIntegerNum(Hours);
	LCD_enuWriteData(':');
	/*Minutes Display*/
	if(Minutes<=9)
	{
		LCD_enuWriteData('0');
	}
	LCD_enuWriteIntegerNum(Minutes);
	LCD_enuWriteData(':');
	/*Seconds Display*/
	if(Seconds<=9)
	{
		LCD_enuWriteData('0');
	}
	LCD_enuWriteIntegerNum(Seconds);
	LCD_enuWriteCommand(0xC0);
	

	return ES_OK;
}