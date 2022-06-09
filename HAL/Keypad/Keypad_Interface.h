/*
 * Keypad_Interface.h
 *
 * Created: 3/23/2022 7:47:46 PM
 *  Author: Ahmed
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

ES_t KEYPAD_enuInit(void);
ES_t Keypad_GetPressedKey(u8 * Copy_pu8KeyValue);



#endif /* KEYPAD_INTERFACE_H_ */