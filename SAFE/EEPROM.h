/*
 * EEPROM.h
 *
 * Created: 10/10/2023 11:23:13 PM
 *  Author: dell
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_write(unsigned short address,unsigned char data);
unsigned char EEPROM_read(unsigned short address);

#endif /* EEPROM_H_ */