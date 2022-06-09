/*
 * SPI_Interface.h
 *
 * Created: 3/30/2022 6:45:59 PM
 *  Author: Ahmed
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidMasterInit(void);
void SPI_voidSlaveInit(void);
u8 SPI_voidSlaveRecive(void);
u8 SPI_voidMaterTransmitReceive(u8 copy_u8DataMaster);
void SPI_SlaveSelect(PortPin_t slave);





#endif /* SPI_INTERFACE_H_ */