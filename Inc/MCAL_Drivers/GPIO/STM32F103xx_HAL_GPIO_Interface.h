/*
 * STM32F103xx_HAL_GPIO_Interface.h
 *
 *  Created on: Jul 19, 2023
 *      Author: shady
 */

#ifndef HAL_DRIVERS_GPIO_STM32F103XX_HAL_GPIO_INTERFACE_H_
#define HAL_DRIVERS_GPIO_STM32F103XX_HAL_GPIO_INTERFACE_H_

#include "MCAL_Drivers/GPIO/STM32F103xx_HAL_GPIO_Cfg.h"

void GPIO_VoidSetPinDirection(PIN_State *State);
void GPIO_VoidSetPinValue(GPIO_PINS pin,GPIO_Value Value);
u32 GPIO_GetPinValue(GPIO_PINS pin);
void GPIO_TogglePinValue(GPIO_PINS pin);
#endif /* HAL_DRIVERS_GPIO_STM32F103XX_HAL_GPIO_INTERFACE_H_ */
