/*
 * STM32F103xx_HAL_TIMERS_Cfg.c
 *
 *  Created on: Aug 23, 2023
 *      Author: shady
 */

#include"STM32F103xx_HAL_TIMERS_Cfg.h"



Timer_init Timer2_init={Up_Counter_enable,15,0xFFFF,TIM2};
ICU_Types ICU_Values={CC_INPUT_TI2,CC2,RISING_EDGE};
