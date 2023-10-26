/*
 * dio.h
 *
 * Created: 9/8/2023 7:07:09 PM
 *  Author: dell
 */ 


#ifndef DIO_H_
#define DIO_H_
void DIO_setpindir(char port,char bit,char dir);
void DIO_writepin(char port ,char bit,char value);
char DIO_readpin(char port,char pin );
void DIO_toggelpin(char port,char pin);
void DIO_set_port_direction( char portname,unsigned char direction);
unsigned char DIO_read_port( char portname);
void DIO_write_port( char portname,unsigned char value);
void DIO_toggle_port( char portname);
void DIO_pull_up_state(char port,char pin,char state);




#endif /* DIO_H_ */