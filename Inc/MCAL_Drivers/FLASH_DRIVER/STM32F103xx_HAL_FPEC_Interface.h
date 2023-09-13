/*
 * STM32F103xx_HAL_FPEC_Interface.h
 *
 *  Created on: Jul 29, 2023
 *      Author: shady
 */

#ifndef HAL_DRIVERS_FLASH_DRIVER_STM32F103XX_HAL_FPEC_INTERFACE_H_
#define HAL_DRIVERS_FLASH_DRIVER_STM32F103XX_HAL_FPEC_INTERFACE_H_


#include "Library/STD_TYPES.h"
#include "Library/BIT_MATH.h"
#include "MCAL_Drivers/FLASH_DRIVER/STM32F103xx_HAL_FPEC_Cfg.h"


void FPEC_voidInit(void);
void FPEC_u8FlashMassErase(void);
void FPEC_u8FlashPageErase(u8 Copy_u8PageNumber);
void FPEC_u8WriteFlash(u32 Copy_U32MemoryAddress,u16 *Address_u16Data,u16 Copy_u16DataLength);
void FPEC_voidEraseAPPArea(void);


#endif /* HAL_DRIVERS_FLASH_DRIVER_STM32F103XX_HAL_FPEC_INTERFACE_H_ */
