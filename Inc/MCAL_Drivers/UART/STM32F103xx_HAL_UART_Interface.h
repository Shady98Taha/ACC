/*
 * STM32F103xx_HAL_UART_Interface.h
 *
 *  Created on: Jul 29, 2023
 *      Author: shady
 */

#ifndef HAL_DRIVERS_UART_STM32F103XX_HAL_UART_INTERFACE_H_
#define HAL_DRIVERS_UART_STM32F103XX_HAL_UART_INTERFACE_H_

#include"Library/STD_TYPES.h"
#include"STM32F103xx_HAL_UART_Cfg.h"




void MUSART1_VoidInit(void);
void MUSART1_VoidTransmit(u8 num);
void MUSART1_VoidTransmitArray(u8 *arr);
u8 MUSART1_VoidReceive(void);
UART_DATA_RECIEVE MUSART1_EnumReceiveBuffer(u8 *arr);
#endif /* HAL_DRIVERS_UART_STM32F103XX_HAL_UART_INTERFACE_H_ */
