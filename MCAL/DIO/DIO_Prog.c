/*
* DIO_Prog.c
*
* Created: 4/8/2022 5:44:12 PM
*  Author: Ahmed
*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"

#include "DIO_Config.h"
#include "DIO_Private.h"

ES_t M_DIO_enuSetPinDirection(PortPin_t Copy_enuPxy,Direction_t Copy_enuDirection)
{
	if(Copy_enuDirection <= DIO_Output)
	{
		u8 Local_u8Port=Copy_enuPxy/10;
		u8 Local_u8Pin=Copy_enuPxy%10;
		switch(Copy_enuDirection)
		{
			case DIO_Input:
			switch(Local_u8Port)
			{
				case A:
				CLR_BIT(DDRA,Local_u8Pin);
				break;
				case B:
				CLR_BIT(DDRB,Local_u8Pin);
				break;
				case C:
				CLR_BIT(DDRC,Local_u8Pin);
				break;
				case D:
				CLR_BIT(DDRD,Local_u8Pin);
				break;
				default:return ES_OUT_OF_RANGE;
				break;
			}
			break;
			case DIO_Output:
			switch(Local_u8Port)
			{
				case A:
				SET_BIT(DDRA,Local_u8Pin);
				break;
				case B:
				SET_BIT(DDRB,Local_u8Pin);
				break;
				case C:
				SET_BIT(DDRC,Local_u8Pin);
				break;
				case D:
				SET_BIT(DDRD,Local_u8Pin);
				break;
				default:return ES_OUT_OF_RANGE;
				break;
			}
			break;
			default: return ES_OUT_OF_RANGE;
		}
		return ES_OK;
	}else
	{
		return ES_OUT_OF_RANGE;
	}
}
ES_t M_DIO_enuSetPinValue(PortPin_t Copy_enuPxy,Logic_t Copy_enuState)
{
	if(Copy_enuState <= DIO_High)
	{
		u8 Local_u8Port=Copy_enuPxy/10;
		u8 Local_u8Pin=Copy_enuPxy%10;
		switch(Copy_enuState)
		{
			case DIO_Low:
			switch(Local_u8Port)
			{
				case A:
				CLR_BIT(PORTA,Local_u8Pin);
				break;
				case B:
				CLR_BIT(PORTB,Local_u8Pin);
				break;
				case C:
				CLR_BIT(PORTC,Local_u8Pin);
				break;
				case D:
				CLR_BIT(PORTD,Local_u8Pin);
				break;
				default:return ES_OUT_OF_RANGE;
				break;
			}
			break;
			case DIO_High:
			switch(Local_u8Port)
			{
				case A:
				SET_BIT(PORTA,Local_u8Pin);
				break;
				case B:
				SET_BIT(PORTB,Local_u8Pin);
				break;
				case C:
				SET_BIT(PORTC,Local_u8Pin);
				break;
				case D:
				SET_BIT(PORTD,Local_u8Pin);
				break;
				default:return ES_OUT_OF_RANGE;
				break;
			}
			break;
			default: return ES_OUT_OF_RANGE;
		}
		return ES_OK;
	}else
	{
		return ES_OUT_OF_RANGE;
	}
}
ES_t M_DIO_enuTogglePinValue(PortPin_t Copy_enuPxy)
{
	u8 Local_u8Port=Copy_enuPxy/10;
	u8 Local_u8Pin=Copy_enuPxy%10;
	switch(Local_u8Port)
	{
		case A:
		TGL_BIT(PORTA,Local_u8Pin);
		break;
		case B:
		TGL_BIT(PORTB,Local_u8Pin);
		break;
		case C:
		TGL_BIT(PORTC,Local_u8Pin);
		break;
		case D:
		TGL_BIT(PORTD,Local_u8Pin);
		break;
		default:return ES_OUT_OF_RANGE;
		break;
	}
	return ES_OK;
}
ES_t M_DIO_enuGetPinValue(PortPin_t Copy_enuPxy,u8 *Copy_u8ReadValue)
{
	if(Copy_u8ReadValue != NULL)
	{
		u8 Local_u8Port=Copy_enuPxy/10;
		u8 Local_u8Pin=Copy_enuPxy%10;
		switch(Local_u8Port)
		{
			case A:
			*Copy_u8ReadValue= GET_BIT(PINA,Local_u8Pin);
			break;
			case B:
			*Copy_u8ReadValue= GET_BIT(PINB,Local_u8Pin);
			break;
			case C:
			*Copy_u8ReadValue= GET_BIT(PINC,Local_u8Pin);
			break;
			case D:
			*Copy_u8ReadValue= GET_BIT(PIND,Local_u8Pin);
			break;
			default:return ES_OUT_OF_RANGE;
			break;
		}
		return ES_OK;
	}else
	{
		return ES_NULL_POINTER;
	}
}
ES_t M_DIO_enuSetPinInternalPullUp(PortPin_t Copy_enuPxy,Internal_PullUp_t Copy_enuPullUpState)
{
	if(Copy_enuPullUpState <= Pin_PullUp)
	{
		u8 Local_u8Port=Copy_enuPxy/10;
		u8 Local_u8Pin=Copy_enuPxy%10;
		switch(Pin_PullUp)
		{
			case Pin_Float:
			switch(Local_u8Port)
			{
				case A:
				CLR_BIT(PORTA,Local_u8Pin);
				break;
				case B:
				CLR_BIT(PORTB,Local_u8Pin);
				break;
				case C:
				CLR_BIT(PORTC,Local_u8Pin);
				break;
				case D:
				CLR_BIT(PORTD,Local_u8Pin);
				break;
				default:return ES_OUT_OF_RANGE;
				break;
			}
			break;
			case Pin_PullUp:
			switch(Local_u8Port)
			{
				case A:
				SET_BIT(PORTA,Local_u8Pin);
				break;
				case B:
				SET_BIT(PORTB,Local_u8Pin);
				break;
				case C:
				SET_BIT(PORTC,Local_u8Pin);
				break;
				case D:
				SET_BIT(PORTD,Local_u8Pin);
				break;
				default:return ES_OUT_OF_RANGE;
				break;
			}
			break;
			default: return ES_OUT_OF_RANGE;
		}
		return ES_OK;
	}else
	{
		return ES_OUT_OF_RANGE;
	}
}