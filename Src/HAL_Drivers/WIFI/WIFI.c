/*
 * WIFI.c
 *
 *  Created on: Aug 9, 2023
 *      Author: shady
 */


#include "Library/STD_TYPES.h"
#include "Library/BIT_MATH.h"
#include"MCAL_Drivers/UART/STM32F103xx_HAL_UART_Interface.h"
#include "HAL_Drivers/WIFI/WIFI_Private.h"
#include"HAL_Drivers/WIFI//WIFI_cfg.h"
#include"CortexM3/CORTEXM3_Interface.h"

/*trial to see if link isnt valid is an disconnect to server problem*/
u8 Disconnect_Flag=0;
/*flag to indicate an error received*/
u8 SEND_FAILED_Flag=0;
/********************************************************************/

/***********A flag to indicate if Iam in WIFI connect stage or not********/
u8 WIFI_Connect_FLAG=0;

/**********A FLAG TO INDICATE I AM IN HTTP REQUEST STATE******************/
u8 HTTP_Request_FLAG=0;

/*************************************************************************/
/********** A flag to indicate you are ready to write GET function********/
u8 SERVER_FLAG_WRITE=0;
/*************************************************************************/


void ESP_VoidArrayFlush(u8 *Data_arr)
{
	for(u8 i=0;i<100;i++)
	{
		Data_arr[i]=0;
	}
}


WIFI_Response ESP_VoidResponse(void)
{
	u8 Local_Response[100]={0},i=0,Ret=0;
	WIFI_Response Result=Response_NOT_Received;
	while(Ret!=255)
	{
		Ret=MUSART1_VoidReceive();
		Local_Response[i]=Ret;
		i++;
	}
	for(int j=0;j<(i-1);j++)
	{
		if(Local_Response[j]=='E' && Local_Response[j+1]=='R' && Local_Response[j+2]=='R' && Local_Response[j+3]=='O' &&Local_Response[j+4]=='R')
		{
			break;
		}else if(Local_Response[j]=='O' && Local_Response[j+1]=='K')
		{
			/******To check if after sending AT+CIPSEND did he responded with ( > ) or not ******/
			if(Local_Response[6]=='>')
			{
				SERVER_FLAG_WRITE=1;
			}
			Result=Response_Received;
			break;
		}else if(Local_Response[j]=='A' && Local_Response[j+1]=='L' && Local_Response[j+2]=='R' && Local_Response[j+3]=='E' && Local_Response[j+4]=='A' && Local_Response[j+5]=='D' && Local_Response[j+6]=='Y')
		{
			/************ when i send IP some times it respond with already connected****************/
			Result=Response_Received;

			break;
		}else if(Local_Response[j]=='l' && Local_Response[j+1]=='i' && Local_Response[j+2]=='n' && Local_Response[j+3]=='k' && Local_Response[j+4]==' ' && Local_Response[j+5]=='i' && Local_Response[j+6]=='s')
		{
			Disconnect_Flag=1;
		}
	}

	return Result;
}



void ESP_VoidInit(void)
{
	WIFI_Response Result=Response_NOT_Received;
	while(Result==Response_NOT_Received)
	{
		MUSART1_VoidTransmitArray((u8*)"ATE0\r\n");
		Result= ESP_VoidResponse();
	}
	Result=Response_NOT_Received;
	while(Result==Response_NOT_Received)
	{
		MUSART1_VoidTransmitArray((u8*)"AT+CWMODE=1\r\n");
		Result= ESP_VoidResponse();
	}
}


void ESP_VoidWifiConnect(void)
{
	WIFI_Connect_FLAG=1;
	WIFI_Response Result=Response_NOT_Received;
	while(Result==Response_NOT_Received)
	{
		MUSART1_VoidTransmitArray((u8*)"AT+CWJAP_CUR=\"");
		MUSART1_VoidTransmitArray((u8*)Wifi_Name);
		MUSART1_VoidTransmitArray((u8*)"\",\"");
		MUSART1_VoidTransmitArray((u8*)Wifi_Pass);
		MUSART1_VoidTransmitArray((u8*)"\"\r\n");
		Result= ESP_VoidResponse();
	}
	WIFI_Connect_FLAG=0;

}


void ESP_VoidServerConnect(void)
{
	WIFI_Response Result=Response_NOT_Received;
	while(Result==Response_NOT_Received)
	{
		MUSART1_VoidTransmitArray((u8*)"AT+CIPSTART=\"");
		MUSART1_VoidTransmitArray((u8*)Server_Mode);
		MUSART1_VoidTransmitArray((u8*)"\",\"");
		MUSART1_VoidTransmitArray((u8*)Server_IP);
		MUSART1_VoidTransmitArray((u8*)"\",");
		MUSART1_VoidTransmitArray((u8*)Server_Port);
		MUSART1_VoidTransmitArray((u8*)"\r\n");
		Result= ESP_VoidResponse();
		Systick_WaitBlocking(1000000);

	}
}

WIFI_Response ESP_VoidDataReceive(u8 *Data_arr)
{
	u8 Local_index=0;
	WIFI_Response Result=Response_NOT_Received;
	Data_arr[Local_index]=MUSART1_VoidReceive();
	for(;Data_arr[Local_index] !=255;)
	{
		Local_index++;
		Data_arr[Local_index]=MUSART1_VoidReceive();
	}
	for(u8 i=0;i<100;i++)
	{
		if(Data_arr[i]=='S' && Data_arr[i+1]=='E' && Data_arr[i+2]=='N' && Data_arr[i+3]=='D' && Data_arr[i+4]==' ' && Data_arr[i+5]=='F' && Data_arr[i+6]=='A' && Data_arr[i+7]=='I' && Data_arr[i]=='L')
		{
			SEND_FAILED_Flag=1;
			ESP_VoidArrayFlush(Data_arr);
		}

	}
	/*check whether is there data received or not*/
	if(Local_index>0 && Data_arr[Local_index-1] !=255 && SEND_FAILED_Flag==0)
	{
		Result=Response_Received;
	}
	return Result;
}



void ESP_VoidServerRequest(u8 *Data_arr,u8 *WORDS_NUMBER,u8 *WEBSITE_URL)
{

	WIFI_Response Result=Response_NOT_Received;
	while(Result==Response_NOT_Received && SERVER_FLAG_WRITE==0)
	{
		MUSART1_VoidTransmitArray((u8*)"AT+CIPSEND=");
		MUSART1_VoidTransmitArray((u8*)WORDS_NUMBER);
		MUSART1_VoidTransmitArray((u8*)"\r\n");
		Result=ESP_VoidResponse();
		Systick_WaitBlocking(1000000);
		/*see if giving link is not valid error it should reconnect to server*/
		if(Disconnect_Flag==1)
		{
			Disconnect_Flag=0;
			ESP_VoidServerConnect();
		}
	}
	SERVER_FLAG_WRITE=0;
	/*Temporary putting Response of GET in bigger time out counter********/

	MUSART1_VoidTransmitArray((u8*)"GET ");
	MUSART1_VoidTransmitArray((u8*)WEBSITE_URL);
	MUSART1_VoidTransmitArray((u8*)"\r\n");
	Result=ESP_VoidDataReceive(Data_arr);
	/*Temporary putting Response of GET in bigger time out counter********/
	HTTP_Request_FLAG=0;
	Systick_WaitBlocking(1000000);
}
