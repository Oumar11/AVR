/*
 * EEPROM.c
 *
 * Created: 7/27/2022 8:46:14 PM
 *  Author: Omar
 */ 
 #include <avr/io.h>
 #include "std_macros.h"
 #include "typedef.h"
 void EEPROM_write(uint16  address, uint8 data )
 {
	 /*set up address register*/
	 EEARL = (char)address;
	 EEARH = (char)(address>>8);
	 /*set up data register*/
	 EEDR = data ;
	 /*write logical one to EEMWE*/
	 SET_BIT(EECR,EEMWE);
	 /*start EEPROM write by setting EEWE*/
	 SET_BIT(EECR,EEWE);
	 /* wait for completion of write operation*/
	 while(READ_BIT(EECR,EEWE)==1);
	 
 }
 unsigned char EEPROM_read(uint16 address)
 {
	 /*set up address register*/
	 EEARL=(char)address;
	 EEARH=(char)(address>>8);
	 /*start EEPROM read by setting EERE*/
	 SET_BIT(EECR,EERE);
	 /*return data from data register*/
	 return EEDR ;
 }
