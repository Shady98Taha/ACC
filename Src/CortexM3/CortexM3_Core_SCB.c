/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 *****************************************************************************
 **/
#include "CortexM3/CortexM3_Core_SCB.h"


void SCB_SetPriorityGrouping(SCB_PRIORITYGROUP_Types PriorityGroup)
{
	u32 Register_Value=0;
	u32 PriorityGroupTemp=PriorityGroup & (u32)0x7;
	Register_Value = (SCB->AIRCR);
	Register_Value &=~(SCB_AIRCR_VECTKETSTAT_MSK|SCB_AIRCR_PRIGROUP_MSK);
	Register_Value|=((u32)VECTKEY<<SCB_AIRCR_VECTKEYSTAT_POS)|(PriorityGroupTemp<<SCB_AIRCR_PRIGROUP_POS);
	SCB->AIRCR=Register_Value;
}


u32 SCB_GetPriorityGrouping(void)
{
	return((SCB->AIRCR & SCB_AIRCR_PRIGROUP_MSK)>>SCB_AIRCR_PRIGROUP_POS);
}


