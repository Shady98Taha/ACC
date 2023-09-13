/*
 * STM32F103xx_HAL_TIMERS_Cfg.h
 *
 *  Created on: Aug 23, 2023
 *      Author: shady
 */

#ifndef HAL_DRIVERS_TIMERS_STM32F103XX_HAL_TIMERS_CFG_H_
#define HAL_DRIVERS_TIMERS_STM32F103XX_HAL_TIMERS_CFG_H_

#include"Library/STD_TYPES.h"
#include"Library/BIT_MATH.h"

/*************************TIMER CONFIG PARA DATA TYPE START*****************************/
typedef enum{
	No_prescaler=0,
	Prescaler_div_2=1,
	Prescaler_div_4=2,
	Reserved3=3
}Clock_Types;

typedef enum{
	Auto_reload_preload_disabled=0,
	 Auto_reload_preload_enabled=1
} Auto_reload_preload_Types;

typedef enum{
	 Edge_aligned=0,
	 Center_aligned_mode_1 =1,
	 Center_aligned_mode_2 =2,
	 Center_aligned_mode_3 =3
}Center_aligned_mode_Types;


typedef enum{
	upcounter=0,
	downcounter=1,
}Direction_Types;


typedef enum{
	One_pulse_mode_disabled=0,
	One_pulse_mode_enabled=1
}One_pulse_Types;


typedef enum{

	Update_request_source_enabled=0,
	Update_request_source_disabled=1
}Update_request_source_Types;

typedef enum{
	 Up_Counter_enable=0,
	 Down_Counter_enable=1
} Counter_enable_Types;

typedef enum{
	TIM2=2,
	TIM3=3,
	TIM4=4,
	TIM5=5
}Timer_Type;

/******************************************************/
typedef struct{
	Counter_enable_Types counter_dir;
	u16 Prescaler_value;
	u16 preload_value;
	Timer_Type Timer_num;
}Timer_init;
/*****************************************************/

/*************************TIMER CONFIG PARA DATA TYPE END*****************************/

/*************************ICU CONFIG PARA DATA TYPE START*****************************/
typedef enum{
	CC_INPUT_TI2	=1,
	CC_INPUT_TI1	=2,
	CC_Input_TRC	=3
}CC_channel_types;

typedef enum{
	CC1=1,
	CC2=2,
	CC3=3,
	CC4=4
}channel_Types;

typedef enum{
	RISING_EDGE=0,
	FALLING_EDGE=1
}Edge_Types;

typedef struct{
	CC_channel_types CC_Types;
	channel_Types channel_selected;
	Edge_Types Edge_polarity;
}ICU_Types;
/*************************ICU CONFIG PARA DATA TYPE END*****************************/
#endif /* HAL_DRIVERS_TIMERS_STM32F103XX_HAL_TIMERS_CFG_H_ */
