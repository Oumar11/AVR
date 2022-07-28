#ifndef LCD_H_
#define LCD_H_


#include "../std_macros.h"
#include "../typedef.h"
#include "../GPIO/GPIO.h"
#include "LCD_config.h"

/************* MACROS **********************/

//LCD commands:
#define CLEAR_SCREEN 0x01  
#define RETURN_HOME 0x02 
#define ENGLISH_ENTRY 0x06 
#define DISPLAY_ON_CURSOR_ON 0x0E

//-----------------------------------------
//set display mode and connection:
#if defined four_bits_mode

#define LCD_PORT 'A'	// Define the port connected to LCD
#define EN 0	// Enable pin number
#define RS 1	// Register select pin number
#define RW 2

#define RS_PORT 'A'
#define EN_PORT 'A'
#define RW_PORT 'A'
#define FOUR_BITS 0x28

#elif defined eight_bits_mode

#define LCD_PORT 'A'	// Define the port connected to LCD
#define EN 0	// Enable pin number
#define RS 1	// Register select pin number
#define RW 2
#define RS_PORT 'B'
#define EN_PORT 'B'
#define RW_PORT 'B'
#define EIGHT_BITS 0x38

#endif

void LCD_init(void);
void LCD_Pulse(void);
void LCD_send_command(uint8 command);
void LCD_send_character(char character);
void LCD_send_string(char* character);
void LCD_clear_screen(void);
void LCD_move_cursor(uint8 row, uint8 column);


#endif /* LCD_H_ */