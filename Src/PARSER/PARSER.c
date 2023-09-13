/*
 * PARSER.c
 *
 *  Created on: Aug 2, 2023
 *      Author: shady
 */
#include "Library/STD_TYPES.h"
#include "PARSER/PARSER.h"
#include"MCAL_Drivers/FLASH_DRIVER/STM32F103xx_HAL_FPEC_Interface.h"

u16 Data[100]={0};
u32 Address= 0x08000000;


void ConvertRecieveToRecord(u8* Receive_array,u8* Record_array)
{
	u8 Receive_start=0;
	/*if no record send it will stuck in this for loop*/
	u8 For_loop_break_flag=0;
	for(Receive_start=0;Receive_array[Receive_start]!=':' || Receive_array[Receive_start+1]!=':';Receive_start++ )
	{
		if(Receive_start>=99)
		{
			For_loop_break_flag=1;
			break;
		}
	}
	Receive_start++;

	for(int i=0;Receive_array[Receive_start]!='\r' && For_loop_break_flag==0;i++,Receive_start++)
	{
		Record_array[i]=Receive_array[Receive_start];
	}

}



u8 ASCITOHEX(u8 Copy_data)
{
	u8 RET_Data=0;
	if( (Copy_data>=48) && (Copy_data<=57))
	{
		RET_Data=Copy_data-48;
	}else
	{
		RET_Data=Copy_data-55;
	}
	return RET_Data;
}


void ParseData(u8 *u8RecBuffer)
{
	u8 CC_Digit0=0, CC_Digit1=0,CC=0,ADD_Digit0=0,ADD_Digit1=0,ADD_Digit2=0,ADD_Digit3=0,DATA_DIGIT0,DATA_DIGIT1,DATA_DIGIT2,DATA_DIGIT3;
	u8 DATA_Counter=0;
	/**************Get CC***********************/
	CC_Digit0=ASCITOHEX(u8RecBuffer[1]);
	CC_Digit1=ASCITOHEX(u8RecBuffer[2]);
	CC= ((CC_Digit0<<4)|(CC_Digit1));
	/******************************************/
	/************GET ADDRESS*******************/
	ADD_Digit0=ASCITOHEX(u8RecBuffer[3]);
	ADD_Digit1=ASCITOHEX(u8RecBuffer[4]);
	ADD_Digit2=ASCITOHEX(u8RecBuffer[5]);
	ADD_Digit3=ASCITOHEX(u8RecBuffer[6]);
	Address =Address & (~(LOW_ADD_MSK));
	Address = Address | (ADD_Digit0<<12)|(ADD_Digit1<<8)|(ADD_Digit2<<4)|(ADD_Digit3);
	/*******************************************/
	/************GET DATA***********************/
	for(int i=0; i<CC/2 ;i++)
	{
		DATA_DIGIT0 = ASCITOHEX(u8RecBuffer[(4*i)+9]);
		DATA_DIGIT1 = ASCITOHEX(u8RecBuffer[(4*i)+10]);
		DATA_DIGIT2 = ASCITOHEX(u8RecBuffer[(4*i)+11]);
		DATA_DIGIT3 = ASCITOHEX(u8RecBuffer[(4*i)+12]);

		Data[DATA_Counter]= (DATA_DIGIT0<<4)|(DATA_DIGIT1)|(DATA_DIGIT2<<12)|(DATA_DIGIT3<<8);
		DATA_Counter++;
	}
	/*****************************************/
	FPEC_u8WriteFlash(Address,Data,CC/2);
}

void ParseUpperAddress(u8 *u8RecBuffer)
{
	u8 DataDigit0,DataDigit1,DataDigit2,DataDigit3;
	DataDigit0 = ASCITOHEX(u8RecBuffer[3]);
	DataDigit1 = ASCITOHEX(u8RecBuffer[4]);
	DataDigit2 = ASCITOHEX(u8RecBuffer[5]);
	DataDigit3 = ASCITOHEX(u8RecBuffer[6]);

	Address = Address & 0x0000FFFF;
	Address=Address|(DataDigit3)|(DataDigit2<<4)|(DataDigit1<<8)|(DataDigit0<<12);

}

void Parser_voidParseRecord(u8 *u8RecBuffer)
{
	switch( u8RecBuffer[8])
	{
	case '0':ParseData(u8RecBuffer); 			break;
	case '4':ParseUpperAddress(u8RecBuffer); 	break;
	}
}
