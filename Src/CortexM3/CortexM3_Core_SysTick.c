/**
 ******************************************************************************
 * @file           : CortexM3_Core_SCB
 * @author         : shady Taha
 * @brief          : System Control Block header file
 ******************************************************************************
*/

#include "CortexM3/CortexM3_Core_SysTick.h"

static void (*Ptr_function)(void)=NULL;
static volatile SysTick_ModeDef Systick_Mode=0;
Core_Error_State Systick_Init(SYSTICK_Init *Sys_Tick_init)
{
	Core_Error_State RetState = Core_OK;
	if(Sys_Tick_init == NULL || (Sys_Tick_init->Delay_Ticks) > SysTick_RELOAD_MSK)
	{
		RetState = Core_ERROR;
	}else
	{
		SYSTICK->CSR &= ~(ENABLE_MSK);
		SYSTICK->CSR &= ~(TICKINT_MSK);
		SYSTICK->CSR &= ~(CLKSOURCE__MSK);
		SYSTICK->CSR |=((Sys_Tick_init->CLOCKSOURCE) << CLKSOURCE);
		SYSTICK->CVR=0;
		SYSTICK->RVR=(Sys_Tick_init->Delay_Ticks);

	}
	return RetState;
}

void Systick_DEInit(void)
{
	SYSTICK->CSR &= ~(ENABLE_MSK);
	SYSTICK->RVR=~(SysTick_RELOAD_MSK);
	SYSTICK->CVR=0;
	SYSTICK->CSR &= ~(TICKINT_MSK);
}

void Systick_WaitBlocking(u32 Delay_Ticks)
{
	SYSTICK->RVR = Delay_Ticks;
	SYSTICK->CSR |= (ENABLE_MSK);
	while((GET_BIT((SYSTICK->CSR),COUNTFLAG))==0)
	{


	}
	SYSTICK->CSR &= ~(ENABLE_MSK);
	SYSTICK->RVR=~(SysTick_RELOAD_MSK);
	SYSTICK->CVR=0;
}
void Systick_SingleInterval(u32 Delay_Ticks,void(* function)())
{
	if(function!=NULL){
		SYSTICK->RVR=Delay_Ticks;
		Ptr_function=function;
		Systick_Mode=SysTick_Single_Interval;
		SYSTICK->CSR |= (TICKINT_MSK);
		SYSTICK->CSR |= (ENABLE_MSK);
	}

}
void Systick_PeriodicInterval(u32 Delay_Ticks, void(*function)())
{
	if(function!=NULL){
		SYSTICK->RVR=Delay_Ticks;
		Ptr_function=function;
		Systick_Mode=SysTick_Periodic_Interval;
		SYSTICK->CSR |= (TICKINT_MSK);
		SYSTICK->CSR |= (ENABLE_MSK);
	}
}

u32 SysTick_GetRemainingTicks(void)
{
	u32 Remaining_Ticks=0;
	Remaining_Ticks=SYSTICK->CVR;
	return Remaining_Ticks;

}
void SysTick_Handler(void)
{
	if(SysTick_Single_Interval==Systick_Mode)
	{
		SYSTICK->CSR &= ~(ENABLE_MSK);
		SYSTICK->RVR=~(SysTick_RELOAD_MSK);
		SYSTICK->CVR=0;
		SYSTICK->CSR &= ~(TICKINT_MSK);
	}else
	{
		/* nothing*/
	}
	if(Ptr_function!=NULL)
	{
		Ptr_function();
	}

}
