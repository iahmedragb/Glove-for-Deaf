/*
 * WDT_Prog.c
 *
 * Created: 3/30/2022 1:28:57 PM
 *  Author: Ahmed
 */ 
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/Error_State.h"

#include "WDT_Config.h"
#include "WDT_Private.h"

void WDT_Init(void)
{
	/*Enable Watch Dog Timer*/
	SET_BIT(WDTCR,WDE);
	/*At 5v and longest timer 2.1s*/
	SET_BIT(WDTCR,WDP2);SET_BIT(WDTCR,WDP1);SET_BIT(WDTCR,WDP0);
}
void WDT_Refresh(void)
{
	asm("WDR");
}
void WDT_off(void)
{
	/* Write logical one to WDTOE and WDE */
	WDTCR = (1<<WDTOE) | (1<<WDE);
	/* Turn off WDT */
	WDTCR = 0x00;
}