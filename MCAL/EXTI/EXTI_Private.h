/*
 * EXTI_Private.h
 *
 * Created: 4/5/2022 12:04:18 AM
 *  Author: Ahmed
 */ 


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_
#define MCUCR	(*((volatile u8*)(0x55)))
#define MCUCSR	(*((volatile u8*)(0x54)))
#define GICR	(*((volatile u8*)(0x5B)))
#define GIFR	(*((volatile u8*)(0x5A)))

/* GICR */
#define INT1    7
#define INT0    6
#define INT2    5
#define IVSEL   1
#define IVCE    0

/* GIFR */
#define INTF1   7
#define INTF0   6
#define INTF2   5

#endif /* EXTI_PRIVATE_H_ */