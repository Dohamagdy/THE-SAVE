/*
 * KEYPAD.c
 *
 * Created: 10/23/2023 8:01:01 PM
 *  Author: dell
 */ 
#include "dio.h"
void KEYPAD_inti(char port)
{
	for(int i=0;i<4;++i)
	{
		DIO_setpindir(port,i,1);
	}
	for(int i=4;i<8;++i)
	{
		DIO_setpindir(port,i,0);
		DIO_pull_up_state(port,i,1);
	}
	
	
}
char KEYPAD_read(char port)
{
	char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	char row,col,returnvalue=0xff,x;
	for( row=0;row<4;row++)
	{
		DIO_writepin(port,0,1);
		DIO_writepin(port,1,1);
		DIO_writepin(port,2,1);
		DIO_writepin(port,3,1);
		DIO_writepin(port,row,0);
		
		for(col=0;col<4;col++)
		{
			x=DIO_readpin(port,(col+4));
			if(x==0)
			{
				returnvalue=arr[row][col];
				break;
			}
		}
		if(x==0)
		{
			break;
		}
	}
	return returnvalue;
	
}