/*
 * Keypad.c
 *
 * Created: 6/12/2022 8:57:18 PM
 *  Author: Omar
 */ 
 #include "Keypad.h"
 #include "std_macros.h"
 void Keypad_Init()
 {
	 
	 GPIO_pin_dir(KEYPAD_PORT,0,1);
	 GPIO_pin_dir(KEYPAD_PORT,1,1);
	 GPIO_pin_dir(KEYPAD_PORT,2,1);
	 
	 GPIO_pin_pullup(KEYPAD_PORT,3);
	 GPIO_pin_pullup(KEYPAD_PORT,4);
	 GPIO_pin_pullup(KEYPAD_PORT,5);
	 GPIO_pin_pullup(KEYPAD_PORT,6);
	 
 }
 char Keypad_Chck()
 {
	 
	char button[4][3] = {		 {'1','2','3'},
								 {'4','5','6'},
								 {'7','8','9'},
								 {'*','0','#'} 
													 };
	 
	 uint8 row = 0, column = 0, pressed = 1;
	 char val = NOTPRESSED;
	 
	 for (column=0; column<3; ++column)
	 {
		 GPIO_pin_w(KEYPAD_PORT,0,1);
		 GPIO_pin_w(KEYPAD_PORT,1,1);
		 GPIO_pin_w(KEYPAD_PORT,2,1);
		 GPIO_pin_w(KEYPAD_PORT,column,0);
		 for (row=0; row<4; ++row)
		 {
			 pressed = GPIO_pin_r(KEYPAD_PORT,(row+3));
			 if (0 == pressed)
			 {
				 val = button[row][column];
				 break;
			 }
		 }
		 
		 if (0 == pressed)
		 {
			 break;
		 }
	 }
	 return val;
}