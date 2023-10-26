/*
 * LCD.c
 *
 * Created: 10/17/2023 10:47:13 PM
 *  Author: dell
 */ 
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void LCD_inti(unsigned char port,unsigned char controlport,unsigned controlpin)
{
	_delay_ms(200);
	#ifdef  EIGHT_BIT_MODE
	DIO_set_port_direction(port,0xff);
	DIO_setpindir(controlport,controlpin,1);
	DIO_setpindir(controlport,controlpin+1,1);
	DIO_setpindir(controlport,controlpin+2,1);
	LCD_send_cmd(port,EIGHT_BITS);
	LCD_send_cmd(port,CLR_SCREEN);
	_delay_ms(10);
	LCD_send_cmd(port,CURSOR_ON_DISPLAY_ON);
	LCD_send_cmd(port,ENTRY_MODE);
	#else
	DIO_set_nibble(port,4,1);
	DIO_setpindir(controlport,controlpin,1);
	DIO_setpindir(controlport,controlpin+1,1);
	DIO_setpindir(controlport,controlpin+2,1);
	LCD_send_cmd(RETURN_HOME);
	_delay_ms(10);
	LCD_send_cmd(port,FOUR_BITS);
	LCD_send_cmd(port,CURSOR_ON_DISPLAY_ON);
	LCD_send_cmd(port,CLR_SCREEN);
	_delay_ms(10);
	LCD_send_cmd(port,ENTRY_MODE);
	#endif
}
void LCD_send_cmd(char port,unsigned char cmd)
{
	#ifdef  EIGHT_BIT_MODE
	DIO_write_port(port,cmd);
	DIO_writepin('B',1,0);
	send_falling_edge();
	#else
	DIO_write_nibble(port,4,cmd>>4);
	DIO_writepin('B',1,0);
	send_falling_edge();
	DIO_write_nibble(port,4,cmd);
	DIO_writepin('B',1,0);
	send_falling_edge();
	#endif
	_delay_ms(1);
	
}
void send_falling_edge(void)
{
	DIO_writepin('B',0,1);
	_delay_ms(2);
	DIO_writepin('B',0,0);
	_delay_ms(2);
	
}
void LCD_send_char(char port,char data)
{
	#ifdef EIGHT_BIT_MODE
	DIO_write_port(port,data);
	DIO_writepin('B',1,1);
	send_falling_edge();
	#else 
	DIO_write_nibble(port,0,data>>4);
	DIO_writepin('B',1,1);
	send_falling_edge();
	DIO_write_nibble(port,0,data);
	DIO_writepin('B',1,1);
	send_falling_edge();
	#endif
	_delay_ms(1);
}
void LCD_send_string(char port, char *data)
{
	while((*data)!='\0')
	{
		LCD_send_char(port,*data);
		data++;
	}
}

void LCD_clearscreen(char port)
{
	LCD_send_cmd(port,CLR_SCREEN);
	_delay_ms(10);
}
void LCD_movecursor(char port,char row,char coloumn)
{
	char data ;
	if(row>2||row<1||coloumn>16||coloumn<1)
	{
		data=0x80;
	}
	else if(row==1)
	{
		data=0x80+coloumn-1 ;
	}
	else if (row==2)
	{
		data=0xc0+coloumn-1;
	}
	LCD_send_cmd(port,data);

}








