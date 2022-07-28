
#ifndef EEPROM_H_
#define EEPROM_H_

#include <avr/io.h>
#include "../std_macros.h"
#include "../typedef.h"

void EEPROM_write(uint16  address,   uint8  data);

unsigned char EEPROM_read( uint16  address );




#endif /* EEPROM_H_ */