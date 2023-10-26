/*
 * import_std.h
 *
 * Created: 9/8/2023 10:26:01 PM
 *  Author: dell
 */ 


#ifndef IMPORT_STD_H_
#define IMPORT_STD_H_

	#define SET_BIT(reg,bit)		reg|=(1<<bit)
	#define CLR_BIT(reg,bit)		reg&=(~(1<<bit))
	#define TOG_BIT(reg,bit)		reg^=(1<<bit)
	#define READ_BIT(reg,bit)		((reg&(1<<bit))>>bit)
	#define ROR_REG(reg,num)		reg=((reg>>num)|(reg<<(8-num)))
	#define ROL_REG(reg,num)		reg=((reg<<num)|(reg>>(8-num)))






#endif /* IMPORT_STD_H_ */