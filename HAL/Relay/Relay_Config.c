/*
 * Relay_Config.c
 *
 * Created: 3/24/2022 10:09:01 PM
 *  Author: Ahmed
 */ 
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "Relay_Config.h"

u8 Relay_u8RelayNum= RELAY_NUM;

PortPin_t Relay_AstrRelayConfig[RELAY_NUM]=
{
	PC4,
	PC3
};