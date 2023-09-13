/**
 ******************************************************************************
 * @file           : WIFI_Initerface.h
 * @author         : Shady Taha
 * @brief          : WIFI interface header file
 ******************************************************************************
*/

#ifndef WIFI_WIFI_INITERFACE_H_
#define WIFI_WIFI_INITERFACE_H_


void ESP_VoidInit(void);
void ESP_VoidWifiConnect(void);
void ESP_VoidServerConnect(void);
void ESP_VoidServerRequest(u8 *Data_arr,u8 *WORDS_NUMBER,u8 *WEBSITE_URL);
void ESP_VoidArrayFlush(u8 *Data_arr);

#endif /* WIFI_WIFI_INITERFACE_H_ */
