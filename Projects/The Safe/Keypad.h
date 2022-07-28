/*
 * Keypad.h
 *
 * Created: 6/12/2022 8:57:18 PM
 *  Author: Omar
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "GPIO.h"

#define NOTPRESSED 0xff
#define KEYPAD_PORT 'D'


void Keypad_Init(void);
char Keypad_Chck(void);





#endif /* KEYPAD_H_ */