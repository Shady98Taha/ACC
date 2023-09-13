/**
 ******************************************************************************
 * @file           : STM32F103xx_HAL_PWM_Cfg.h
 * @author         : Shady Taha
 * @brief          : PWM configuration source file
 ******************************************************************************
*/

#include"MCAL_Drivers/TIMERS/STM32F103xx_HAL_TIMERS_Cfg.h"
#include"MCAL_Drivers/PWM/STM32F103xx_HAL_PWM_Cfg.h"

/********Timer_Type************
TIM2
TIM3
TIM4
TIM5
*******************************/
/********channel_Types*********
CC1
CC2
CC3
CC4
******************************/
/********PwmModes_type*********
Frozen
active_level_on_match
inactive_level_on_match
Toggle
Force_inactive_level
Force_active_level
PWM_mode_1
PWM_mode_2
******************************/


PWM_init TimersPwmInit={TIM3,CC1,PWM_mode_1,Up_Counter_enable};
PWM_init TimersPwmInit2={TIM4,CC1,PWM_mode_1,Up_Counter_enable};
