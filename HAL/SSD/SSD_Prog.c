/*
* SSD_Prog.c


*
* Created: 3/24/2022 10:39:44 PM
*  Author: Ahmed
*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Cpu_Configuration.h"
#include <util/delay.h>

#include "../../MCAL/DIO/DIO_Interface.h"

#include "SSD_Config.h"
#include "SSD_Private.h"
extern u8 SSD_u8SSDNum ;

/*matrix represent 7Seg from 0 to F values as common cathode	*(DP)gfedcba)*/
static u8 catSeg []= {
	0x3f,0x06,0x5B,0x4F,0x66,
	0x6D,0x7D,0x07,0x7F,0x6F,0x77,
	0x7C,0x39,0x5E,0x79,0x71
};
ES_t SSD_enuInit(SSD_t *Copy_pAstrSSDConfig)
{
	u8 Local_ErrorState = ES_NOK;
	if(Copy_pAstrSSDConfig !=NULL)
	{
		u8 Local_u8Iter;
		for(Local_u8Iter=0;Local_u8Iter<SSD_u8SSDNum;Local_u8Iter++)
		{
			M_DIO_enuSetPinDirection(Copy_pAstrSSDConfig[Local_u8Iter].COM,DIO_Output);
			M_DIO_enuSetPinDirection(Copy_pAstrSSDConfig[Local_u8Iter].A,DIO_Output);
			M_DIO_enuSetPinDirection(Copy_pAstrSSDConfig[Local_u8Iter].B,DIO_Output);
			M_DIO_enuSetPinDirection(Copy_pAstrSSDConfig[Local_u8Iter].C,DIO_Output);
			M_DIO_enuSetPinDirection(Copy_pAstrSSDConfig[Local_u8Iter].D,DIO_Output);
			M_DIO_enuSetPinDirection(Copy_pAstrSSDConfig[Local_u8Iter].E,DIO_Output);
			M_DIO_enuSetPinDirection(Copy_pAstrSSDConfig[Local_u8Iter].F,DIO_Output);
			M_DIO_enuSetPinDirection(Copy_pAstrSSDConfig[Local_u8Iter].G,DIO_Output);
			M_DIO_enuSetPinDirection(Copy_pAstrSSDConfig[Local_u8Iter].DP,DIO_Output);
			
			M_DIO_enuSetPinValue(Copy_pAstrSSDConfig[Local_u8Iter].COM,DIO_High);

			switch(Copy_pAstrSSDConfig[Local_u8Iter].COM_Type)
			{
				case COM_CATHODE:

				M_DIO_enuSetPinValue(Copy_pAstrSSDConfig[Local_u8Iter].A,DIO_High);
				M_DIO_enuSetPinValue(Copy_pAstrSSDConfig[Local_u8Iter].B,DIO_High);
				M_DIO_enuSetPinValue(Copy_pAstrSSDConfig[Local_u8Iter].C,DIO_High);
				M_DIO_enuSetPinValue(Copy_pAstrSSDConfig[Local_u8Iter].D,DIO_High);
				M_DIO_enuSetPinValue(Copy_pAstrSSDConfig[Local_u8Iter].E,DIO_High);
				M_DIO_enuSetPinValue(Copy_pAstrSSDConfig[Local_u8Iter].F,DIO_High);
				M_DIO_enuSetPinValue(Copy_pAstrSSDConfig[Local_u8Iter].G,DIO_High);
				//DIO_enuSetPinValue(Copy_pAstrSSDConfig[Local_u8Iter].DP_Port,Copy_pAstrSSDConfig[Local_u8Iter].DP_Pin,DIO_High);
				break;
				case COM_ANODE:

				M_DIO_enuSetPinValue(Copy_pAstrSSDConfig[Local_u8Iter].A,DIO_Low);
				M_DIO_enuSetPinValue(Copy_pAstrSSDConfig[Local_u8Iter].B,DIO_Low);
				M_DIO_enuSetPinValue(Copy_pAstrSSDConfig[Local_u8Iter].C,DIO_Low);
				M_DIO_enuSetPinValue(Copy_pAstrSSDConfig[Local_u8Iter].D,DIO_Low);
				M_DIO_enuSetPinValue(Copy_pAstrSSDConfig[Local_u8Iter].E,DIO_Low);
				M_DIO_enuSetPinValue(Copy_pAstrSSDConfig[Local_u8Iter].F,DIO_Low);
				M_DIO_enuSetPinValue(Copy_pAstrSSDConfig[Local_u8Iter].G,DIO_Low);
				//DIO_enuSetPinValue(Copy_pAstrSSDConfig[Local_u8Iter].DP_Port,Copy_pAstrSSDConfig[Local_u8Iter].DP_Pin,DIO_Low);
				break;
			}

			
			
			
			
		}
		Local_ErrorState = ES_OK;
	}else
	{
		Local_ErrorState =ES_NULL_POINTER;
	}
	
	
	return Local_ErrorState;
}
ES_t SSD_enuDisplaySingleNumber(SSD_t *Copy_pAstrSSDinfo,u8 Copy_u8Number)
{
	u8 Local_u8ErrorState=ES_NOK;
	if(Copy_u8Number <= 15)
	{
		switch(Copy_pAstrSSDinfo->COM_Type)
		{
			case COM_CATHODE:
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->A,DIO_High);
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->B,DIO_High);
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->C,DIO_High);
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->D,DIO_High);
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->E,DIO_High);
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->F,DIO_High);
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->G,DIO_High);
			
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->A,((catSeg[Copy_u8Number])&(1<<0)));
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->B,((catSeg[Copy_u8Number])&(1<<1)));
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->C,((catSeg[Copy_u8Number])&(1<<2)));
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->D,((catSeg[Copy_u8Number])&(1<<3)));
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->E,((catSeg[Copy_u8Number])&(1<<4)));
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->F,((catSeg[Copy_u8Number])&(1<<5)));
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->G,((catSeg[Copy_u8Number])&(1<<6)));
			
			break;
			case COM_ANODE:
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->A,DIO_Low);
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->B,DIO_Low);
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->C,DIO_Low);
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->D,DIO_Low);
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->E,DIO_Low);
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->F,DIO_Low);
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->G,DIO_Low);
			 
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->A,((catSeg[Copy_u8Number])& ~(1<<0)));
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->B,((catSeg[Copy_u8Number])& ~(1<<1)));
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->C,((catSeg[Copy_u8Number])& ~(1<<2)));
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->D,((catSeg[Copy_u8Number])& ~(1<<3)));
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->E,((catSeg[Copy_u8Number])& ~(1<<4)));
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->F,((catSeg[Copy_u8Number])& ~(1<<5)));
			M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->G,((catSeg[Copy_u8Number])& ~(1<<6)));
			break;
		}
		Local_u8ErrorState  = ES_OK;
	}else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}
	return Local_u8ErrorState;
}

ES_t SSD_enuEnableDisplay(SSD_t *Copy_pAstrSSDinfo)
{
	M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->COM,DIO_High);

	return ES_OK;
}
ES_t SSD_enuDisableDisplay(SSD_t *Copy_pAstrSSDinfo)
{
	
	M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->COM,DIO_Low);
	return ES_OK;
}
ES_t SSD_enuEnableDot(SSD_t *Copy_pAstrSSDinfo)
{
	M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->DP,DIO_High);
	return ES_OK;
}
ES_t SSD_enuDisableDot(SSD_t *Copy_pAstrSSDinfo)
{
	M_DIO_enuSetPinValue(Copy_pAstrSSDinfo->DP,DIO_Low);
	return ES_OK;
}
ES_t SSD_enuDisplayNumbers(SSD_t *Copy_pAstrSSDinfo,u8 Copy_u8Number)
{
	u8 Local_u8ErrorState=ES_NOK;
	if(Copy_pAstrSSDinfo != NULL)
	{
		if(Copy_u8Number>15)
		{
			SSD_enuEnableDisplay(Copy_pAstrSSDinfo+0);
			SSD_enuDisableDisplay(Copy_pAstrSSDinfo+1);
			SSD_enuDisplaySingleNumber(Copy_pAstrSSDinfo+0,(Copy_u8Number%16));
			_delay_ms(10);
			SSD_enuEnableDisplay(Copy_pAstrSSDinfo+1);
			SSD_enuDisableDisplay(Copy_pAstrSSDinfo+0);
			SSD_enuDisplaySingleNumber(Copy_pAstrSSDinfo+1,(Copy_u8Number/16));
			_delay_ms(10);
		}
		
		Local_u8ErrorState  = ES_OK;
	}
	else
	{
		Local_u8ErrorState = ES_NULL_POINTER;
	}
	return Local_u8ErrorState;
}
/*
#include <util/delay.h>
int main(void)
{
	SSD_enuInit(SSD_AstrSSDConfig);
	
	while (1)
	{
		u8 i=0,j=0;
		for(;;i++)
		{
			j=0;
			while(j<50)
			{
				SSD_enuDisplayNumbers(SSD_AstrSSDConfig,i);
				j++;
			}
		}
		
	}
}

*/