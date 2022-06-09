/*
* Switch_Config.h
*
* Created: 3/19/2022 2:16:13 AM
*  Author: Ahmed
*/


#ifndef SWITCH_CONFIG_H_
#define SWITCH_CONFIG_H_

#define SWITCH_NUM	3
typedef struct
{
	PortPin_t PortPin;
	Internal_PullUp_t Switch_State;
}Switch_t;



#endif /* SWITCH_CONFIG_H_ */