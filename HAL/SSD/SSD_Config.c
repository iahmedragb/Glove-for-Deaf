/*
 * SSD_Config.c
 *
 * Created: 3/24/2022 10:39:34 PM
 *  Author: Ahmed
 */ 
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/Error_State.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "SSD_Config.h"

u8 SSD_u8SSDNum = SSD_NUM;
SSD_t SSD_AstrSSDConfig[SSD_NUM]=
{
	{PC6,PA1,PA2,PA3,PA4,PA5,PA6,PA7,PB0,COM_CATHODE}
};


