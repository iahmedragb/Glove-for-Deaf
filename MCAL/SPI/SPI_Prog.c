/*
* SPI_Prog.c
*
* Created: 3/30/2022 6:46:28 PM
*  Author: Ahmed
*/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/Interrupt.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "SPI_Config.h"
#include "SPI_Private.h"

void SPI_voidMasterInit(void)
{
	SET_BIT(DDRB,4);
	SET_BIT(DDRB,5);
	CLR_BIT(DDRB,6);
	SET_BIT(DDRB,7);
	
	SPCR= (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}
void SPI_voidSlaveInit(void)
{
	CLR_BIT(DDRB,4);
	CLR_BIT(DDRB,5);
	SET_BIT(DDRB,6);
	CLR_BIT(DDRB,7);
	SPCR= (1<<SPE);
}
u8 SPI_voidMaterTransmitReceive(u8 copy_u8DataMaster)
{
	/*start transmission*/
	SPDR = copy_u8DataMaster;
	/*W8 till complete*/
	while((GET_BIT(SPSR,SPIF)) == 0);
	return SPDR;
}

void SPI_SlaveSelect(PortPin_t slave)
{
	M_DIO_enuSetPinValue(slave,DIO_Low);

}