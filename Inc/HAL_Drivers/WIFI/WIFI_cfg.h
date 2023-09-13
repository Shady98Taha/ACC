/**
 ******************************************************************************
 * @file           : WIFI_cfg.h
 * @author         : Shady Taha
 * @brief          : WIFI congfiguration header file
 ******************************************************************************
*/

#ifndef WIFI_WIFI_CFG_H_
#define WIFI_WIFI_CFG_H_



#define Wifi_Name 	 "Esp8266"
#define Wifi_Pass 	 "12345678"
#define Server_Mode  "TCP"
#define Server_IP 	 "23.179.32.36"
#define Server_Port  "80"


typedef enum{
	Response_NOT_Received	=0,
	Response_Received		=1,
}WIFI_Response;


#endif /* WIFI_WIFI_CFG_H_ */
