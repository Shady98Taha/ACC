/**
 ******************************************************************************
 * @file           : STM32F103xx_HAL_PWM_Cfg.h
 * @author         : Shady Taha
 * @brief          : PWM configuration header file
 ******************************************************************************
*/

#ifndef MCAL_DRIVERS_PWM_STM32F103XX_HAL_PWM_CFG_H_
#define MCAL_DRIVERS_PWM_STM32F103XX_HAL_PWM_CFG_H_

#include"MCAL_Drivers/TIMERS/STM32F103xx_HAL_TIMERS_Cfg.h"



typedef enum{
	Frozen=0,
	active_level_on_match=1,
	inactive_level_on_match=2,
	Toggle=3,
	Force_inactive_level=4,
	Force_active_level=5,
	PWM_mode_1=6,
	PWM_mode_2=7,
}PwmModes_type;

typedef struct{
	Timer_Type Tims;
	channel_Types CC;
	PwmModes_type PWM_Modes;
	Counter_enable_Types Counter_Direction;
}PWM_init;





#endif /* MCAL_DRIVERS_PWM_STM32F103XX_HAL_PWM_CFG_H_ */
