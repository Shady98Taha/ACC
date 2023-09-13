/*
 * Ultrasonic_Program.c
 *
 *  Created on: Aug 25, 2023
 *      Author: shady
 */
#include "Library/STD_TYPES.h"
#include "Library/BIT_MATH.h"
#include"CortexM3/CortexM3_Core_SysTick.h"
#include"MCAL_Drivers/GPIO/STM32F103xx_HAL_GPIO_Interface.h"
#include"MCAL_Drivers/TIMERS/STM32F103xx_HAL_TIMERS_Interface.h"
#include"HAL_Drivers/Ultrasonic/Ultrasonic_Private.h"




extern Timer_init Timer2_init;
extern ICU_Types ICU_Values;

/******************************************************************************/
/* Syntax           :
 * Description      :
 * Sync\Async       :
 * Parameters       :
 * Return value:    :
 *******************************************************************************/
void Ultrasonic_VoidInit(void)
{

	Timers_VoidInit(&Timer2_init);
	TIMER2_VoidICUInit(&ICU_Values);

}


/******************************************************************************/
/* Syntax           :
 * Description      :
 * Sync\Async       :
 * Parameters       :
 * Return value:    :
 *******************************************************************************/
void Ultrasonic_VoidTrigger(void)
{
	GPIO_VoidSetPinValue(PINA0, GPIO_LOW);
	Systick_WaitBlocking(40);
	GPIO_VoidSetPinValue(PINA0,GPIO_HIGH);
	Systick_WaitBlocking(120);
	GPIO_VoidSetPinValue(PINA0,GPIO_LOW);
}




/******************************************************************************/
/* Syntax           :
 * Description      :
 * Sync\Async       :
 * Parameters       :
 * Return value:    :
 *******************************************************************************/
void Ultrasonic_readTimer(u16 *Distance1,u16 *Distance2)
{
	/*empty timer 2 counter*/
	Timer2_VoidEmptyCounterRegister();
	while(Timer2_U8IcuGetCaptureFlag(CC2)==0)
	{

	}
	/*get value in counter in a variable*/
	*Distance1=TIMER2_U16IcuGetCaptureValue(CC2);
	/*set the UG bit*/
	Timer2_VoidTimeEventGenerationSet();
	/*start the timer*/
	Timer_start(TIM2);
    /*make edge detection falling*/
	Timer2_VoidIcuTriggerEdge(FALLING_EDGE, CC2);
	while(Timer2_U8IcuGetCaptureFlag(CC2)==0)
	{

	}

	*Distance2=TIMER2_U16IcuGetCaptureValue(CC2);

	Timer2_VoidIcuTriggerEdge(RISING_EDGE, CC2);

	Timer2_VoidClearFlag();

	Timer_stop(TIM2);

	Timer2_VoidEmptyCounterRegister();
}


/******************************************************************************/
/* Syntax           :
 * Description      :
 * Sync\Async       :
 * Parameters       :
 * Return value:    :
 *******************************************************************************/
static u16 Ultrasonic_GetDistance(u16 *Distance1,u16 *Distance2)
{
	u16 Total_time=*Distance2-*Distance1;
	u16 total_distance=0;
	total_distance= (0.0085* Total_time);
	return total_distance;
}

/******************************************************************************/
/* Syntax           :
 * Description      :
 * Sync\Async       :
 * Parameters       :
 * Return value:    :
 *******************************************************************************/
u16 Ultrasonic_readDistance(void)
{
	u16 Distance1=0,Distance2=0,total_distance;
	/*trigger the Ultra-sonic sensor*/
	Ultrasonic_VoidTrigger();

	Ultrasonic_readTimer(&Distance1,&Distance2);
	total_distance=Ultrasonic_GetDistance(&Distance1,&Distance2);
	return total_distance;
}
