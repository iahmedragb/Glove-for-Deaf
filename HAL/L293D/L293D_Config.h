/*
* L293D_Config.h
*
* Created: 3/23/2022 9:26:30 PM
*  Author: Ahmed
*/


#ifndef L293D_CONFIG_H_
#define L293D_CONFIG_H_

#define L293D_NUM	1
#define DCM_NUM		2

typedef enum
{
	Stop=0,
	Forward=1,
	Backward=2,
	Brake=3
}DC_Motor_Direction_t;

typedef struct
{
	PortPin_t IN1;
	PortPin_t IN2;
}DCM_t;

typedef struct
{
	DCM_t Motors[DCM_NUM];
}L293D_t;


#endif /* L293D_CONFIG_H_ */