/*
* SSD_Config.h
*
* Created: 3/24/2022 10:40:04 PM
*  Author: Ahmed
*/


#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_

#define SSD_NUM	2
/*COM_CATHODE			COM_ANODE*/
#define COM_CATHODE			3
#define COM_ANODE			6
#define COMMEN_TYPE			COM_CATHODE

typedef struct
{
	PortPin_t	COM;
	PortPin_t	A;
	PortPin_t B;
	PortPin_t C;
	PortPin_t D;
	PortPin_t E;
	PortPin_t F;
	PortPin_t G;
	PortPin_t DP;
	u8 COM_Type;
}SSD_t;



#endif /* SSD_CONFIG_H_ */