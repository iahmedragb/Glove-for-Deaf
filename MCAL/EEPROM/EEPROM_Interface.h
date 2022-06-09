/*
 * EEPROM_Interface.h
 *
 * Created: 4/4/2022 4:13:02 AM
 *  Author: Ahmed
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


ES_t EEPROM_write(u16 uiAddress, u8 ucData);
ES_t EEPROM_read(u16 u16Address, u8 *Copy_pu8ReadValue);

#endif /* EEPROM_INTERFACE_H_ */