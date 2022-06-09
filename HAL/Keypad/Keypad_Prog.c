/*
* Keypad_Prog.c
*
* Created: 3/23/2022 7:47:26 PM
*  Author: Ahmed
*/
#include "../../LIB/Std_Types.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Bit_Math.h"

#include "../../LIB/Cpu_Configuration.h"
#include <util/delay.h>
#include "../../LIB/Cpu_Configuration.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "Keypad_Config.h"
#include "Keypad_Private.h"

ES_t KEYPAD_enuInit(void)
{
	M_DIO_enuSetPinDirection(C1,DIO_Output);
	M_DIO_enuSetPinDirection(C2,DIO_Output);
	M_DIO_enuSetPinDirection(C3,DIO_Output);
	M_DIO_enuSetPinDirection(C4,DIO_Output);
	M_DIO_enuSetPinValue(C1,DIO_High);
	M_DIO_enuSetPinValue(C2,DIO_High);
	M_DIO_enuSetPinValue(C3,DIO_High);
	M_DIO_enuSetPinValue(C4,DIO_High);
	
	M_DIO_enuSetPinDirection(R1,DIO_Input);
	M_DIO_enuSetPinDirection(R2,DIO_Input);
	M_DIO_enuSetPinDirection(R3,DIO_Input);
	M_DIO_enuSetPinDirection(R4,DIO_Input);
	/*Pull Up*/
	M_DIO_enuSetPinInternalPullUp(R1,PullUp);
	M_DIO_enuSetPinInternalPullUp(R2,PullUp);
	M_DIO_enuSetPinInternalPullUp(R3,PullUp);
	M_DIO_enuSetPinInternalPullUp(R4,PullUp);
	
	return ES_OK;
	
}

ES_t Keypad_GetPressedKey(u8 * Copy_pu8KeyValue)
{	
	u8 Local_u8RowIter = 0;
	u8 Local_u8ColIter = 0;

	u8 Local_Au8Row[]={R1,R2,R3,R4};

	u8 Local_Au8Col[]={C1,C2,C3,C4};
	

	u8 Local_u8RowValue=96 , Local_u8Flag=0;

	for (;Local_u8ColIter < Col ; Local_u8ColIter++ )
	{
		M_DIO_enuSetPinValue(Local_Au8Col[Local_u8ColIter], DIO_Low   );

		for (Local_u8RowIter=0; Local_u8RowIter<Row; Local_u8RowIter++)
		{
			M_DIO_enuGetPinValue(Local_Au8Row[Local_u8RowIter],&Local_u8RowValue);
			if (! Local_u8RowValue)
			{
				_delay_ms(10);
				M_DIO_enuGetPinValue(Local_Au8Row[Local_u8RowIter],&Local_u8RowValue);

				if (! Local_u8RowValue)
				{
					while (! Local_u8RowValue)
					M_DIO_enuGetPinValue(Local_Au8Row[Local_u8RowIter],&Local_u8RowValue);

					u8 Local_Au8KeyValues[Row][Col] =KEYS_VALUES;
					*Copy_pu8KeyValue = Local_Au8KeyValues[Local_u8RowIter][Local_u8ColIter];
					Local_u8Flag =1;
				}
			}
		}
		M_DIO_enuSetPinValue(Local_Au8Col[Local_u8ColIter], DIO_High   );
	}
	if (! Local_u8Flag)
	{
		*Copy_pu8KeyValue = NOT_PRESSED;
	}
	return ES_OK;
}