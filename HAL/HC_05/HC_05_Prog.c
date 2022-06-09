/*
 * HC_05_Prog.c
 *
 * Created: 3/28/2022 1:35:27 PM
 *  Author: Ahmed
 */ 
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/Error_State.h"

#include "../../MCAL/UART/UART_Interface.h"

#include "HC_05_Config.h"
#include "HC_05_Private.h"

void HC_05_Init(void)
{
	 UART_Init();
}
u8 HC_05_Receive(void)
{
	static u8 data;
	data = UART_Receive();
	return data;
}