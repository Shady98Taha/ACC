/**
 ******************************************************************************
 * @file           : STM32F103xx_HAL_PWM_Interface.h
 * @author         : Shady Taha
 * @brief          : PWM interface header file
 ******************************************************************************
*/

#ifndef MCAL_DRIVERS_PWM_STM32F103XX_HAL_PWM_INTERFACE_H_
#define MCAL_DRIVERS_PWM_STM32F103XX_HAL_PWM_INTERFACE_H_

#include"MCAL_Drivers/PWM/STM32F103xx_HAL_PWM_Cfg.h"



void PWM_VoidInit(PWM_init *TimersPwmInit, u16 PWM_Frequency,u16 ARR_Value);
void PWM_VoidSetDutyCycle(u16 Copy_U16Duty, Timer_Type Tims,channel_Types CC);


#endif /* MCAL_DRIVERS_PWM_STM32F103XX_HAL_PWM_INTERFACE_H_ */
