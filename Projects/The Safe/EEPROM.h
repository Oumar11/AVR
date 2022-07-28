/*
 * EEPROM.h
 *
 * Created: 7/27/2022 8:46:00 PM
 *  Author: Omar
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_


void EEPROM_write(uint16  address,   uint8  data);

unsigned char EEPROM_read( uint16  address );




#endif /* EEPROM_H_ */