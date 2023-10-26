/*
 * SAFE.c
 *
 * Created: 10/24/2023 3:20:11 PM
 * Author : dell
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "KEYPAD.h"
#include "EEPROM.h"

#define EEPROM_STATUS_LOCATION 0x00
#define EEPROM_PASSWORD_LOCATION1 0x01
#define EEPROM_PASSWORD_LOCATION2 0x02
#define EEPROM_PASSWORD_LOCATION3 0x03
#define EEPROM_PASSWORD_LOCATION4 0x04

#define TRIES 3

char arr[4];

int main(void)
{
	LCD_inti('A','B',0);
	KEYPAD_inti('D');
	if (EEPROM_read(EEPROM_STATUS_LOCATION)==0xff)
	{
		LCD_send_string('A',"SET PASS :");
		for (int i=0;i<4;++i)
		{
			char value ;
			do 
			{
				value=KEYPAD_read('D');
			} while (value==0xff);
			LCD_send_char('A',value);
			_delay_ms(400);
			
			LCD_movecursor('A',1,11+i);
			LCD_send_char('A','*');			
			EEPROM_write(EEPROM_PASSWORD_LOCATION1+i,value);
		}
		EEPROM_write(EEPROM_STATUS_LOCATION,0x00);
	}
	char flag=0,tries=TRIES;
	while (flag==0)
	{
		LCD_clearscreen('A');
		arr[0]=arr[1]=arr[2]=arr[3]=0xff;
		LCD_send_string('A',"CHECK PASS:");
		_delay_ms(400);
		for (int i=0;i<4;++i)
		{
			do 
			{
				arr[i]=KEYPAD_read('D');
			} while (arr[i]==0xff);
			LCD_send_char('A',arr[i]);
			_delay_ms(400);
			LCD_movecursor('A',1,12+i);
			LCD_send_char('A','*');
			_delay_ms(400);
		}
		
		if(EEPROM_read(EEPROM_PASSWORD_LOCATION1)==arr[0]&&EEPROM_read(EEPROM_PASSWORD_LOCATION2)==arr[1]&&EEPROM_read(EEPROM_PASSWORD_LOCATION3)==arr[2]&&EEPROM_read(EEPROM_PASSWORD_LOCATION4)==arr[3])
		{
			LCD_clearscreen('A');
			LCD_send_string('A',"RIGHT PASSWORD");
			LCD_movecursor('A',2,1);
			LCD_send_string('A',"SAFE OPEND");
			_delay_ms(400);
			flag=1;
		}
		else 
		{
			tries--;
			if (tries>0)
			{
				LCD_clearscreen('A');
				LCD_send_string('A',"WRONG PASSWORD");
				LCD_movecursor('A',2,1);
				LCD_send_string('A',"TRIES LEFT :");
				_delay_ms(400);
				LCD_send_char('A',tries+'0');
				_delay_ms(400);
				
			}
			else
			{
				LCD_clearscreen('A');
				LCD_send_string('A',"WRONG PASSWORD");
				LCD_movecursor('A',2,1);
				LCD_send_string('A',"SAFED CLOSED");
				_delay_ms(400);
				flag=1;
			}
			
			
		}		
	}
	}

