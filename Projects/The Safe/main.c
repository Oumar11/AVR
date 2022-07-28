#define  F_CPU 1000000UL

#include <util/delay.h>
#include "keypad.h"
#include "LCD.h"
#include "EEPROM.h"



#define  EEPROM_STATUS_LOCATION 0x20
#define  EEPROM_PASSWORD_LOCATION1 0x21
#define  EEPROM_PASSWORD_LOCATION2 0x22
#define  EEPROM_PASSWORD_LOCATION3 0x23
#define  EEPROM_PASSWORD_LOCATION4 0x24
#define MAX_TRIES 3


char arr[4];


int main(void)
{
	char value = NOTPRESSED;
	char flag= 0 ; 
	char i ;
	char tries = MAX_TRIES;

	 Keypad_Init();
	 LCD_init();
	

	


	
	
	if ( EEPROM_read (EEPROM_STATUS_LOCATION) == NOTPRESSED )
	{
		LCD_send_string("Set Pass :");
		for (i=0;i<=3;i++)
		{
			do
			{
				value=Keypad_Chck();
			}
			while (value == NOTPRESSED);

			LCD_send_character(value);
			_delay_ms(500);

			LCD_move_cursor(1,10+i);
			LCD_send_character('*');
			_delay_ms(500);

			EEPROM_write(EEPROM_PASSWORD_LOCATION1+i,value);
		}
		EEPROM_write(EEPROM_STATUS_LOCATION,0x00);
	}
	while(flag==0)
	{
		arr[0]=arr[1]=arr[2]=arr[3] = NOTPRESSED;
		LCD_clear_screen();
		LCD_send_string("check pass:");

		for (i=0;i<=3;i++)
		{
			do
			{
				arr[i]=Keypad_Chck();
			}
			while (arr[i]==NOTPRESSED);


			LCD_send_character(arr[i]);
			_delay_ms(500);

			LCD_move_cursor(1,12+i);
			LCD_send_character('*');
			_delay_ms(500);

		}

		
		if(EEPROM_read(EEPROM_PASSWORD_LOCATION1)==arr[0] &&  EEPROM_read(EEPROM_PASSWORD_LOCATION2)==arr[1] && EEPROM_read(EEPROM_PASSWORD_LOCATION3)==arr[2] && EEPROM_read(EEPROM_PASSWORD_LOCATION4)==arr[3])
		{
			LCD_clear_screen();
			LCD_send_string("Correct Password");
			LCD_move_cursor(2,1);
			LCD_send_string("Locks are Opened");

			flag=1;
		}
		else
		{
			tries--;

			if (tries > 0)
			{
				LCD_clear_screen();
				LCD_send_string("Wrong Password");
				_delay_ms(1000);

				LCD_clear_screen();
				LCD_send_string("Tries Remaining :");

				LCD_send_character(tries+48);
				_delay_ms(1000);
				
			}
			else
			{
				LCD_clear_screen();
				LCD_send_string("Wrong password");
				LCD_move_cursor(2,1);
				LCD_send_string("Safe Locked");

				flag=1;
			}
		}
	}
}


