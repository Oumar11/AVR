#include <avr/io.h>
#include "ADC.h"
#include "LCD.h"
char read_val;
unsigned short temperatue;
int main(void)
{
	GPIO_pin_dir('D',0,1);
	GPIO_pin_dir('D',1,1);
	LCD_init();
	ADC_init();
	LCD_send_string("Temperature=");
	while(1)
	{ 
		
		temperatue=(ADC_convert_read()*0.25);
		
		if(temperatue<10)
		{
			LCD_move_cursor(1,13);
			LCD_send_character(30);
			LCD_send_character((temperatue%10)+48);
			LCD_send_character(0xDF);
			LCD_send_character('c');
		}
		else if( temperatue<100)
		{
			LCD_move_cursor(1,13); 
			LCD_send_character((temperatue/10)+48);
			LCD_send_character((temperatue%10)+48);
			LCD_send_character(0XDF);
			LCD_send_character('c');
			
			if(temperatue<20)
			{
				GPIO_pin_w('D',1,1);
			}
			else if (temperatue>30)
			{
				GPIO_pin_w('D',0,1);
			}
			else
			{
				GPIO_pin_w('D',0,0);
				GPIO_pin_w('D',1,0);
			}
		}
		else
		{
			
		}
		
	}
}
