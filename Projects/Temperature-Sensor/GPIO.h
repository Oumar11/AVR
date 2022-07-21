#ifndef __ATMEGA_GPIO_HEADER__
#define __ATMEGA_GPIO_HEADER__




#include <avr/io.h>
#include "std_macros.h"
#include "typedef.h"



/*---------------------- PROTOTYPES : -------------------------*/



void GPIO_pin_dir(char PORT, uint8 BIT, uint8 DIR);

void GPIO_pin_w(char PORT, uint8 BIT, uint8 DATA);

uint8 GPIO_pin_r(char PORT, uint8 BIT);

void GPIO_pin_tog(char PORT, uint8 BIT);

void GPIO_port_dir(char PORT, uint8 DIR);

void GPIO_port_w(char PORT, uint8 DATA);

uint8 GPIO_port_r(char PORT);

void GPIO_pin_pullup(char port_name, uint8 pin_number);

void GPIO_port_write_high_nibble(char port_name, uint8 high_nibble);

void GPIO_port_write_low_nibble(char port_name, uint8 low_nibble);


#endif //__ATMEGA_GPIO_HEADER__