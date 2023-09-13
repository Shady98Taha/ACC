/*
 * STM32F103xx_HAL_UART_Cfg.h
 *
 *  Created on: Jul 29, 2023
 *      Author: shady
 */

#ifndef HAL_DRIVERS_UART_STM32F103XX_HAL_UART_CFG_H_
#define HAL_DRIVERS_UART_STM32F103XX_HAL_UART_CFG_H_

#define BaudRate9600 	0x341
#define BaudRate115200	0x45
#define BaudRate BaudRate9600

typedef enum{
	NO_DATA_REC	=0,
	DATA_REC	=1
}UART_DATA_RECIEVE;
#endif /* HAL_DRIVERS_UART_STM32F103XX_HAL_UART_CFG_H_ */
