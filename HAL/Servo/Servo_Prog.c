/*
 * Servo_Prog.c
 *
 * Created: 3/26/2022 6:06:05 PM
 *  Author: Ahmed
 */ 
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/Std_Types.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMER1/TIMER1_Interface.h"

#include "Servo_Config.h"
#include "Servo_Private.h"
void Servo_Init(void)
{
	
	PWM1_enuInit();
	
}
void Servo_Rotate(u8 angle)
{
	
	PWM1_enuDutycycle(angle);
	PWM1_enuStart();
}