/*
 * EEPROM.c
 *
 * Created: 10/10/2023 11:23:29 PM
 *  Author: dell
 */ 
#include <avr/io.h>
#include "import_std.h"
void EEPROM_write(unsigned short adress,unsigned char data)
{
	//EEARL=(char)adress;
	EEAR=adress;
	EEDR=data;
	 SET_BIT(EECR,EEMWE);
	 SET_BIT(EECR,EEWE);
	 while(READ_BIT(EECR,EEWE)==1);
	
}
unsigned char EEPROM_read(unsigned short address)
{
	EEAR=address;
	SET_BIT(EECR,EERE);
	return EEDR;
} 