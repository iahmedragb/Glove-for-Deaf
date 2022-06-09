/*
 * EEPROM_Prog.c
 *
 * Created: 4/4/2022 4:13:19 AM
 *  Author: Ahmed
 */ 
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Cpu_Configuration.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/Interrupt.h"

#include "EEPROM_Config.h"
#include "EEPROM_Private.h"

ES_t EEPROM_write(u16 u16Address, u8 u8Data)
{
	/* Wait for completion of previous write */
	while(GET_BIT(EECR,EEWE));
	
	while(GET_BIT(SPMCR,SPMEN));/*Optional based on bootloader present*/
	
	/* Set up address and data registers */
	EEAR = u16Address;
	EEDR = u8Data;
	/* Write logical one to EEMWE */
	SET_BIT(EECR,EEMWE);
	/* Start eeprom write by setting EEWE */
	SET_BIT(EECR,EEWE);
	return ES_OK;
}
ES_t EEPROM_read(u16 u16Address, u8 *Copy_pu8ReadValue)
{
	if(Copy_pu8ReadValue != NULL)
	{
		/* Wait for completion of previous write */
		while(GET_BIT(EECR,EEWE));
		/* Set up address register */
		EEAR = u16Address;
		/* Start eeprom read by writing EERE */
		SET_BIT(EECR,EERE);
		/* Return data from data register */
		*Copy_pu8ReadValue= EEDR;
		return ES_OK;
	}else
	{
		return ES_NULL_POINTER;
	}
	return ES_NOK;
}