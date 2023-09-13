/*
 * STM32F103xx_HAL_TIMERS.c
 *
 *  Created on: Aug 23, 2023
 *      Author: shady
 */

#include "Library/STD_TYPES.h"
#include "Library/BIT_MATH.h"
#include "MCAL_Drivers/TIMERS/STM32F103xx_HAL_TIMERS_Private.h"
#include "MCAL_Drivers/TIMERS/STM32F103xx_HAL_TIMERS_Cfg.h"

void(*Timer_ptr)(void)=NULL;

channel_Types GLOBAL_Channel_Selected;


/******************************************************************************/
/* Syntax           : void Timers2_VoidInit
 * Description      : select timer counter, pre-scaler ,and pre-load value
 * Sync\Async       : Synchronous
 * Parameters       : Timer_init *Timers_init
 * Return value:    : void
 *******************************************************************************/
void Timers_VoidInit(Timer_init *Timers_init)
{
	switch(Timers_init->Timer_num)
	{
	case TIM2:
	{
		/*select counter state*/
		TIMER_2->TIMx_CR1 |= ((Timers_init->counter_dir)<<DIR);

		/*select pre-scaler value*/
		TIMER_2->TIMx_PSC=(Timers_init->Prescaler_value);

		/*insert pre-load value*/
		TIMER_2->TIMx_ARR=(Timers_init->preload_value);
		break;
	}
	case TIM3:
	{
		/*select counter state*/
		TIMER_3->TIMx_CR1 |= ((Timers_init->counter_dir)<<DIR);

		/*select pre-scaler value*/
		TIMER_3->TIMx_PSC=(Timers_init->Prescaler_value);

		/*insert pre-load value*/
		TIMER_3->TIMx_ARR=(Timers_init->preload_value);
		break;
	}
	case TIM4:
	{
		/*select counter state*/
		TIMER_4->TIMx_CR1 |= ((Timers_init->counter_dir)<<DIR);

		/*select pre-scaler value*/
		TIMER_4->TIMx_PSC=(Timers_init->Prescaler_value);

		/*insert pre-load value*/
		TIMER_4->TIMx_ARR=(Timers_init->preload_value);
		break;
	}
	case TIM5:
	{
		/*select counter state*/
		TIMER_5->TIMx_CR1 |= ((Timers_init->counter_dir)<<DIR);

		/*select pre-scaler value*/
		TIMER_5->TIMx_PSC=(Timers_init->Prescaler_value);

		/*insert pre-load value*/
		TIMER_5->TIMx_ARR=(Timers_init->preload_value);
		break;
	}
	}

}

/******************************************************************************/
/* Syntax           : void Timer_start
 * Description      : start timer 2
 * Sync\Async       :
 * Parameters       : Timer_Type Timers_num
 * Return value:    :
 *******************************************************************************/
void Timer_start(Timer_Type Timers_num)
{
	switch(Timers_num)
	{
	case TIM2:
	{
		SET_BIT(TIMER_2->TIMx_CR1,CEN);
		break;
	}
	case TIM3:
	{
		SET_BIT(TIMER_3->TIMx_CR1,CEN);
		break;
	}
	case TIM4:
	{
		SET_BIT(TIMER_4->TIMx_CR1,CEN);
		break;
	}
	case TIM5:
	{
		SET_BIT(TIMER_5->TIMx_CR1,CEN);
		break;
	}
	}

}




/******************************************************************************/
/* Syntax           :
 * Description      : clear counter register
 * Sync\Async       :
 * Parameters       :
 * Return value:    :
 *******************************************************************************/
void Timer2_VoidEmptyCounterRegister(void)
{
	TIMER_2->TIMx_CNT=0;
}

/******************************************************************************/
/* Syntax           :
 * Description      : stop timer2
 * Sync\Async       :
 * Parameters       :
 * Return value:    :
 *******************************************************************************/
void Timer_stop(Timer_Type Timers_num)
{
	switch(Timers_num)
	{
	case TIM2:
	{
		CLR_BIT(TIMER_2->TIMx_CR1,CEN);
		break;
	}
	case TIM3:
	{
		CLR_BIT(TIMER_3->TIMx_CR1,CEN);
		break;
	}
	case TIM4:
	{
		CLR_BIT(TIMER_4->TIMx_CR1,CEN);
		break;
	}
	case TIM5:
	{
		CLR_BIT(TIMER_5->TIMx_CR1,CEN);
		break;
	}
	}

}



/*******************************************************************************/
/****************************Input capture unit*********************************/
/*******************************************************************************/

/******************************************************************************/
/* Syntax           :
 * Description      : select channel and edge and enabling the captue channel
 * Sync\Async       :
 * Parameters       :
 * Return value:    :
 *******************************************************************************/
void TIMER2_VoidICUInit(ICU_Types *ICU_Values)
{


	if((ICU_Values->channel_selected)==CC1)
	{

		/*select the channel and storage place*/
		TIMER_2->TIMx_CCMR1 |=((ICU_Values->CC_Types)<<CC1S);

		/*select edge you want to detect rising or falling*/
		TIMER_2->TIMx_CCER |=((ICU_Values->Edge_polarity)<<CC1P);

		/*Capture enabled*/
		SET_BIT(TIMER_2->TIMx_CCER,CC1E);

	}else if((ICU_Values->channel_selected)==CC2)
	{
		TIMER_2->TIMx_CCMR1 |= ((ICU_Values->CC_Types)<<CC2S);

		SET_BIT(TIMER_2->TIMx_CCER,CC2E);

		TIMER_2->TIMx_CCER |= ((ICU_Values->Edge_polarity)<<CC2P);
	}else if(ICU_Values->channel_selected==CC3)
	{
		TIMER_2->TIMx_CCMR2 |=((ICU_Values->CC_Types)<<CC3S);
		TIMER_2->TIMx_CCER |=((ICU_Values->Edge_polarity)<<CC3P);
		SET_BIT(TIMER_2->TIMx_CCER,CC3E);

	}else if(ICU_Values->channel_selected==CC3)
	{
		TIMER_2->TIMx_CCMR2 |= ((ICU_Values->CC_Types)<<CC4S);
		TIMER_2->TIMx_CCER |= ((ICU_Values->Edge_polarity)<<CC4P);
		SET_BIT(TIMER_2->TIMx_CCER,CC4E);
	}


	/*assign channel selected to global variable for interrupt function*/
	GLOBAL_Channel_Selected=(ICU_Values->channel_selected);

}


/******************************************************************************/
/* Syntax           : void Timer2_VoidIcuTriggerEdge(Edge_Types Edge_polarity,channel_Types CC)
 * Description      : select or change edge that triggers ICU
 * Sync\Async       : Synchronous
 * Parameters       : Edge_Types Edge_polarity,channel_Types CC
 * Return value:    : void
 *******************************************************************************/
void Timer2_VoidIcuTriggerEdge(Edge_Types Edge_polarity,channel_Types CC)
{
	if(CC==CC1)
	{
		TIMER_2->TIMx_CCER &= ~(CC1P_MSK);
		TIMER_2->TIMx_CCER |=(Edge_polarity <<CC1P );
	}else if(CC==CC2)
	{
		TIMER_2->TIMx_CCER &= ~(CC2P_MSK);
		TIMER_2->TIMx_CCER |=(Edge_polarity<< CC2P);
	}else if(CC==CC3)
	{
		TIMER_2->TIMx_CCER &= ~(CC3P_MSK);
		TIMER_2->TIMx_CCER |=(Edge_polarity<< CC3P);
	}else if(CC==CC4)
	{
		TIMER_2->TIMx_CCER &= ~(CC4P_MSK);
		TIMER_2->TIMx_CCER |=(Edge_polarity<< CC4P);
	}

}

/******************************************************************************/
/* Syntax           : u16 TIMER2_U16IcuGetCaptureValue(channel_Types CC)
 * Description      : Get captured value by ICU from CCR register
 * Sync\Async       : Synchronous
 * Parameters       : channel_Types CC
 * Return value:    : u16
 *******************************************************************************/
u16 TIMER2_U16IcuGetCaptureValue(channel_Types CC)
{
	u16 Capture_Value=0;
	switch(CC)
	{
	case CC1: Capture_Value=TIMER_2->TIMx_CCR1;break;
	case CC2: Capture_Value=TIMER_2->TIMx_CCR2;break;
	case CC3: Capture_Value=TIMER_2->TIMx_CCR3;break;
	case CC4: Capture_Value=TIMER_2->TIMx_CCR4;break;
	}
	return Capture_Value;
}

/******************************************************************************/
/* Syntax           :
 * Description      : get ICU capture flag state
 * Sync\Async       :
 * Parameters       :
 * Return value:    :
 *******************************************************************************/
u8 Timer2_U8IcuGetCaptureFlag(channel_Types CC)
{
	u16 Capture_Flag=0;
	switch(CC)
	{
	case CC1: Capture_Flag=GET_BIT((TIMER_2->TIMx_SR),CC1);break;
	case CC2: Capture_Flag=GET_BIT((TIMER_2->TIMx_SR),CC2);break;
	case CC3: Capture_Flag=GET_BIT((TIMER_2->TIMx_SR),CC3);break;
	case CC4: Capture_Flag=GET_BIT((TIMER_2->TIMx_SR),CC4);break;
	}
	return Capture_Flag;

}

/******************************************************************************/
/* Syntax           :
 * Description      : Enable Timer2 Interrupt
 * Sync\Async       :
 * Parameters       :
 * Return value:    :
 *******************************************************************************/
void TIMER2_VoidIcuInterruptEnable(void)
{

	TIMER_2->TIMx_DIER |= (1<<GLOBAL_Channel_Selected);
}

/******************************************************************************/
/* Syntax           :
 * Description      : cleat timer 2 flags
 * Sync\Async       :
 * Parameters       :
 * Return value:    :
 *******************************************************************************/
void Timer2_VoidClearFlag(void)
{
	CLR_BIT((TIMER_2->TIMx_SR),0);
}

/******************************************************************************/
/* Syntax           :
 * Description      : Disable Timer2 ICU interrupt
 * Sync\Async       :
 * Parameters       :
 * Return value:    :
 *******************************************************************************/
void TIMER2_VoidIcuInterruptDisable(void)
{
	TIMER_2->TIMx_DIER &= (~(1<<GLOBAL_Channel_Selected));
}


/******************************************************************************/
/* Syntax           :
 * Description      : pass function to be called in ISR
 * Sync\Async       :
 * Parameters       :
 * Return value:    :
 *******************************************************************************/
void TIMER2_VoidCallBack(void(*ptr_1)(void))
{
	if(ptr_1 != NULL)
	{
		Timer_ptr=ptr_1;
	}
}


/******************************************************************************/
/* Syntax           :
 * Description      : pass function to be called in ISR
 * Sync\Async       :
 * Parameters       :
 * Return value:    :
 *******************************************************************************/
void Timer2_VoidTimeEventGenerationSet(void)
{
	SET_BIT(TIMER_2->TIMx_EGR,0);
}


void TIM2_IRQHandler(void)
{
	if(Timer_ptr != NULL)
	{
		Timer_ptr();
	}
}
