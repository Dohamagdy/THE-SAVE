/*
 * LCD.h
 *
 * Created: 10/17/2023 10:47:47 PM
 *  Author: dell
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "LCDmode.h"
#include "dio.h"
#define EIGHT_BITS 0x38
#define FOUR_BITS 0x28
#define CLR_SCREEN 0x01
#define RETURN_HOME 0x02
#define CURSOR_ON_DISPLAY_ON 0x0e
#define ENTRY_MODE 0x06
void LCD_inti(unsigned char port,unsigned char controlport,unsigned controlpin);
void LCD_send_cmd(char port,unsigned char cmd);
void send_falling_edge(void);
void LCD_movecursor(char port,char row,char coloumn);
void LCD_send_string(char port, char *data);
void LCD_send_char(char port,char data);
void LCD_clearscreen(char port);




#endif /* LCD_H_ */