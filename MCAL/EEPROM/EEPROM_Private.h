/*
 * EEPROM_Private.h
 *
 * Created: 4/4/2022 4:13:11 AM
 *  Author: Ahmed
 */ 


#ifndef EEPROM_PRIVATE_H_
#define EEPROM_PRIVATE_H_

//#define EEARH			(*((volatile u8*)(0x3F)))		/*Address register higher 2-bits*/
#define EEAR			(*((volatile u8*)(0x3E)))		/*Address register lower 8-bits*/
#define EEDR			(*((volatile u8*)(0x3D)))		/*Data register*/
#define EECR			(*((volatile u8*)(0x3C)))		/*Control Register*/

#define EERIE	3		/*EEPROM READY IE*/
#define EEMWE	2		/*EEPROM MASTER WRITE Enable*/
#define EEWE	1		/*EEPROM Write Enable*/
#define EERE	0		/*EEPROM Read Enable*/

#define SPMCR			(*((volatile u8*)(0x57)))
#define SPMEN	0

#endif /* EEPROM_PRIVATE_H_ */