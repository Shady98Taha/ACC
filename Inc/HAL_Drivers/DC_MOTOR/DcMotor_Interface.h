/*
 * DcMotor_Interface.h
 *
 *  Created on: Aug 29, 2023
 *      Author: shady
 */

#ifndef HAL_DRIVERS_DC_MOTOR_DCMOTOR_INTERFACE_H_
#define HAL_DRIVERS_DC_MOTOR_DCMOTOR_INTERFACE_H_
#include"MCAL_Drivers/PWM/STM32F103xx_HAL_PWM_Interface.h"
#include"HAL_Drivers/DC_MOTOR/DcMotor_cfg.h"

void DC_MotorVoidInit(PWM_init TimersPwmInit, u16 PWM_Frequency,u16 ARR_Value);
void DC_MOTOR_ON(u16 Copy_U16Duty, Timer_Type Tims,channel_Types CC, PWM_Direction Motor_Direction);

#endif /* HAL_DRIVERS_DC_MOTOR_DCMOTOR_INTERFACE_H_ */
