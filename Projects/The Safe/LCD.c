#include "LCD.h"

#include <util/delay.h>

void LCD_init(void)
{
	_delay_ms(200);
	
	#if defined four_bits_mode
	//set connection pins:
	GPIO_pin_dir(LCD_PORT,4,1);
	GPIO_pin_dir(LCD_PORT,5,1);
	GPIO_pin_dir(LCD_PORT,6,1);
	GPIO_pin_dir(LCD_PORT,7,1);

	GPIO_pin_dir(EN_PORT,EN,1); //set EN pin to output pin
	GPIO_pin_dir(RW_PORT,RW,1); //set RS pin to output pin
	GPIO_pin_dir(RS_PORT,RS,1); //set RS pin to output pin
	
	GPIO_pin_w(RW_PORT,RW,0);

	
	LCD_send_command(RETURN_HOME);
		_delay_ms(10);
	LCD_send_command(FOUR_BITS);	 //send command to inti LCD:
		_delay_ms(1);
	LCD_send_command(DISPLAY_ON_CURSOR_ON);
		_delay_ms(1);
	LCD_send_command(CLEAR_SCREEN);
		_delay_ms(10);
	LCD_send_command(ENGLISH_ENTRY);
		_delay_ms(1);

	#elif defined eight_bits_mode
	//set connection pins:

	GPIO_port_dir(LCD_PORT,1);
	GPIO_pin_dir(EN_PORT,EN,1);//set EN pin to output pin
	GPIO_pin_dir(RW_PORT,RW,1);//set RS pin to output pin
	GPIO_pin_dir(RS_PORT,RS,1);//set RS pin to output pin
	

	//send command to init LCD:
	LCD_send_command(EIGHT_BITS);


	LCD_send_command(DISPLAY_ON_CURSOR_ON);
		_delay_ms(1);
	LCD_send_command(CLEAR_SCREEN);
		_delay_ms(10);
	LCD_send_command(ENGLISH_ENTRY);
		_delay_ms(1);

		#endif
}


void LCD_Pulse(void)
{
	GPIO_pin_w(EN_PORT,EN,1);
	_delay_ms(2);
	GPIO_pin_w(EN_PORT,EN,0);
	_delay_ms(2);
}
void LCD_send_command(uint8 command)
{
	#if defined four_bits_mode
	
	GPIO_port_write_high_nibble(LCD_PORT,command>>4); //write_high_nipple because LCD is connected to high_nipple pins
	GPIO_pin_w(RS_PORT,RS,0);						  //select command register
	LCD_Pulse();
	GPIO_port_write_high_nibble(LCD_PORT,command); //write_high_nipple because LCD is connected to high_nipple pins
	GPIO_pin_w(RS_PORT,RS,0);	 //select command register
	LCD_Pulse();
	
	#elif defined eight_bits_mode
	
	GPIO_port_w(LCD_PORT,command);
	GPIO_pin_w(RS_PORT,RS,0);
	LCD_Pulse();
	
	#endif
	_delay_ms(1);
}


void LCD_clear_screen(void)
{
	LCD_send_command(CLEAR_SCREEN);
	_delay_ms(10);
}


void LCD_send_character(char character)
{
	#if defined four_bits_mode
	
	
	GPIO_port_write_high_nibble(LCD_PORT,character>>4);
	GPIO_pin_w(RS_PORT,RS,1);
	LCD_Pulse();

	GPIO_port_write_high_nibble(LCD_PORT,character);
	GPIO_pin_w(RS_PORT,RS,1);
	LCD_Pulse();
	
	#elif defined eight_bits_mode
	
	GPIO_pin_w(RS_PORT,RS,1);
	GPIO_port_w(LCD_PORT,character);
	LCD_Pulse();
	
	#endif
		_delay_ms(1);
}

void LCD_send_string(char* character)
{
	while ( (*character) != '\0' )
	{
		LCD_send_character(*character);
		character++;
	}
}
void LCD_move_cursor(uint8 row,uint8 column)
{
	char data = 0 ;
	if(row>2||row<1||column>16||column<1)
	{
		data=0x80;
	}
	else if(row==1)
	{
		data=0x80+column-1 ;
	}
	else if (row==2)
	{
		data=0xc0+column-1;
	}
	LCD_send_command(data);
	_delay_ms(1);
}
