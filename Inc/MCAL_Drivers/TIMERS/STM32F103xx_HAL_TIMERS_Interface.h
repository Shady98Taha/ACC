/*
 * STM32F103xx_HAL_TIMERS_Interface.h
 *
 *  Created on: Aug 23, 2023
 *      Author: shady
 */

#ifndef HAL_DRIVERS_TIMERS_STM32F103XX_HAL_TIMERS_INTERFACE_H_
#define HAL_DRIVERS_TIMERS_STM32F103XX_HAL_TIMERS_INTERFACE_H_

#include "STM32F103xx_HAL_TIMERS_Cfg.h"

void Timers_VoidInit(Timer_init *Timers_init);
void Timer_start(Timer_Type Timers_num);
void Timer_stop(Timer_Type Timers_num);
void Timer2_VoidEmptyCounterRegister(void);
void TIMER2_VoidICUInit(ICU_Types *ICU_Values);
void Timer2_VoidIcuTriggerEdge(Edge_Types Edge_polarity,channel_Types CC);
u16 TIMER2_U16IcuGetCaptureValue(channel_Types CC);
u8 Timer2_U8IcuGetCaptureFlag(channel_Types CC);
void TIMER2_VoidIcuInterruptEnable(void);
void TIMER2_VoidIcuInterruptDisable(void);
void TIMER2_VoidCallBack(void(*ptr_1)(void));
void Timer2_VoidTimeEventGenerationSet(void);
void Timer2_VoidClearFlag(void);

#endif /* HAL_DRIVERS_TIMERS_STM32F103XX_HAL_TIMERS_INTERFACE_H_ */
