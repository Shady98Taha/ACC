/**
 ******************************************************************************
 * @file           : CortexM3_Core_SCB
 * @author         : shady Taha
 * @brief          : DC Motor source file
 ******************************************************************************
*/

#include"Library/STD_TYPES.h"
#include"Library/BIT_MATH.h"
#include"MCAL_Drivers/GPIO/STM32F103xx_HAL_GPIO_Interface.h"
#include"MCAL_Drivers/TIMERS/STM32F103xx_HAL_TIMERS_Interface.h"
#include"MCAL_Drivers/PWM/STM32F103xx_HAL_PWM_Interface.h"
#include"HAL_Drivers/DC_MOTOR/DcMotor_Private.h"
#include"HAL_Drivers/DC_MOTOR/DcMotor_cfg.h"



void DC_MotorVoidInit(PWM_init TimersPwmInit, u16 PWM_Frequency,u16 ARR_Value)
{
	PWM_VoidInit(&TimersPwmInit,PWM_Frequency,ARR_Value);
}
void DC_MOTOR_ON(u16 Copy_U16Duty, Timer_Type Tims,channel_Types CC, PWM_Direction Motor_Direction)
{
	switch(Motor_Direction)
	{
	case MOTOR_Reverse: GPIO_VoidSetPinValue(PINA7,GPIO_HIGH); GPIO_VoidSetPinValue(PINA8,GPIO_LOW); break;
	case MOTOR_Forward: GPIO_VoidSetPinValue(PINA8,GPIO_HIGH); GPIO_VoidSetPinValue(PINA7,GPIO_LOW); break;
	}
	PWM_VoidSetDutyCycle(Copy_U16Duty, Tims, CC);
}
