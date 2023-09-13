/**
 ******************************************************************************
 * @file           : STM32F103xx_HAL_PWM.c
 * @author         : Shady Taha
 * @brief          : PWM source file
 ******************************************************************************
 */

#include"Library/STD_TYPES.h"
#include"Library/BIT_MATH.h"
#include"MCAL_Drivers/PWM/STM32F103xx_HAL_PWM_Private.h"
#include"MCAL_Drivers/PWM/STM32F103xx_HAL_PWM_Cfg.h"


/******************************************************************************/
/* Syntax           : void PWM_VoidInit
 * Description      : initialize PWM
 * Sync\Async       : Synchronous
 * Parameters       : PWM_init *TimersPwmInit, u16 PWM_Frequency,u16 ARR_Value
 * Return value:    : void
 *******************************************************************************/
void PWM_VoidInit(PWM_init *TimersPwmInit, u16 PWM_Frequency,u16 ARR_Value)
{
	switch(TimersPwmInit->Tims)
	{
	case TIM2:
	{
		switch(TimersPwmInit->CC)
		{
		case CC1:
		{
			/*clear CC1S bit so that CC1 channel is configured as output*/
			TIMER_2->TIMx_CCMR1 &= ~(CC1S_MSK);
			/*select PWM mode*/
			TIMER_2->TIMx_CCMR1 |=((TimersPwmInit->PWM_Modes)<<OC1M);
			/*enable pre-load*/
			TIMER_2->TIMx_CCMR1 |=((PWM_PRELOAD_ON)<<OC1PE);
			/*SET Timer Direction*/
			TIMER_2->TIMx_CR1 |= ((TimersPwmInit->Counter_Direction)<<DIRECTION);
			/*set auto reload pre-load*/
			SET_BIT(TIMER_2->TIMx_CR1,ARPE);
			/*Enable output pin for the selected channel*/
			SET_BIT(TIMER_2->TIMx_CCER,CC1E);
			/*Set ARR Value*/
			TIMER_2->TIMx_ARR = ARR_Value;
			/*set pre-scaler value*/
			TIMER_2->TIMx_PSC=PWM_Frequency;
			/*Duty = 2*/
			TIMER_2->TIMx_CCR1=2;
			/*set Update generation bit*/
			SET_BIT(TIMER_2->TIMx_EGR,UG);
			/*enable counter*/
			SET_BIT(TIMER_2->TIMx_CR1,CEN);
			break;
		}
		case CC2:
		{
			/*clear CC2S bit so that CC1 channel is configured as output*/
			TIMER_2->TIMx_CCMR1 &= ~(CC2S_MSK);
			/*select PWM mode*/
			TIMER_2->TIMx_CCMR1 |=((TimersPwmInit->PWM_Modes)<<OC2M);
			/*enable pre-load*/
			TIMER_2->TIMx_CCMR1 |=((PWM_PRELOAD_ON)<<OC2PE);
			/*SET Timer Direction*/
			TIMER_2->TIMx_CR1 |= ((TimersPwmInit->Counter_Direction)<<DIRECTION);
			/*set auto reload pre-load*/
			SET_BIT(TIMER_2->TIMx_CR1,ARPE);
			/*Enable output pin for the selected channel*/
			SET_BIT(TIMER_2->TIMx_CCER,CC2E);
			/*Set ARR Value*/
			TIMER_2->TIMx_ARR = ARR_Value;
			/*set pre-scaler value*/
			TIMER_2->TIMx_PSC=PWM_Frequency;
			/*Duty = 2*/
			TIMER_2->TIMx_CCR2=2;
			/*set Update generation bit*/
			SET_BIT(TIMER_2->TIMx_EGR,UG);
			/*enable counter*/
			SET_BIT(TIMER_2->TIMx_CR1,CEN);
			break;
		}
		case CC3:
		{
			/*clear CC3S bit so that CC1 channel is configured as output*/
			TIMER_2->TIMx_CCMR2 &= ~(CC3S_MSK);
			/*select PWM mode*/
			TIMER_2->TIMx_CCMR2 |=((TimersPwmInit->PWM_Modes)<<OC3M);
			/*enable pre-load*/
			TIMER_2->TIMx_CCMR2 |=((PWM_PRELOAD_ON)<<OC3PE);
			/*SET Timer Direction*/
			TIMER_2->TIMx_CR1 |= ((TimersPwmInit->Counter_Direction)<<DIRECTION);
			/*set auto reload pre-load*/
			SET_BIT(TIMER_2->TIMx_CR1,ARPE);
			/*Enable output pin for the selected channel*/
			SET_BIT(TIMER_2->TIMx_CCER,CC3E);
			/*Set ARR Value*/
			TIMER_2->TIMx_ARR = ARR_Value;
			/*set pre-scaler value*/
			TIMER_2->TIMx_PSC=PWM_Frequency;
			/*Duty = 2*/
			TIMER_2->TIMx_CCR1=2;
			/*set Update generation bit*/
			SET_BIT(TIMER_2->TIMx_EGR,UG);
			/*enable counter*/
			SET_BIT(TIMER_2->TIMx_CR1,CEN);
			break;
		}
		case CC4:
		{
			/*clear CC4S bit so that CC1 channel is configured as output*/
			TIMER_2->TIMx_CCMR2 &= ~(CC4S_MSK);
			/*select PWM mode*/
			TIMER_2->TIMx_CCMR2 |=((TimersPwmInit->PWM_Modes)<<OC4M);
			/*enable pre-load*/
			TIMER_2->TIMx_CCMR2 |=((PWM_PRELOAD_ON)<<OC4PE);
			/*SET Timer Direction*/
			TIMER_2->TIMx_CR1 |= ((TimersPwmInit->Counter_Direction)<<DIRECTION);
			/*set auto reload pre-load*/
			SET_BIT(TIMER_2->TIMx_CR1,ARPE);
			/*Enable output pin for the selected channel*/
			SET_BIT(TIMER_2->TIMx_CCER,CC4E);
			/*Set ARR Value*/
			TIMER_2->TIMx_ARR = ARR_Value;
			/*set pre-scaler value*/
			TIMER_2->TIMx_PSC=PWM_Frequency;
			/*Duty = 2*/
			TIMER_2->TIMx_CCR1=2;
			/*set Update generation bit*/
			SET_BIT(TIMER_2->TIMx_EGR,UG);
			/*enable counter*/
			SET_BIT(TIMER_2->TIMx_CR1,CEN);
			break;
		}
		}
		break;
	}
	case TIM3:
	{
		switch(TimersPwmInit->CC)
		{
		case CC1:
		{
			/*clear CC1S bit so that CC1 channel is configured as output*/
			TIMER_3->TIMx_CCMR1 &= ~(CC1S_MSK);
			/*select PWM mode*/
			TIMER_3->TIMx_CCMR1 |=((TimersPwmInit->PWM_Modes)<<OC1M);
			/*enable pre-load*/
			TIMER_3->TIMx_CCMR1 |=((PWM_PRELOAD_ON)<<OC1PE);
			/*SET Timer Direction*/
			TIMER_3->TIMx_CR1 |= ((TimersPwmInit->Counter_Direction)<<DIRECTION);
			/*set auto reload pre-load*/
			SET_BIT(TIMER_3->TIMx_CR1,ARPE);
			/*Enable output pin for the selected channel*/
			SET_BIT(TIMER_3->TIMx_CCER,CC1E);
			/*Set ARR Value*/
			TIMER_3->TIMx_ARR = ARR_Value;
			/*set pre-scaler value*/
			TIMER_3->TIMx_PSC=MCU_Frequency/((PWM_Frequency*ARR_Value)-1);
			/*Duty = 2*/
			TIMER_3->TIMx_CCR1=0;
			/*set Update generation bit*/
			SET_BIT(TIMER_3->TIMx_EGR,UG);
			/*enable counter*/
			SET_BIT(TIMER_3->TIMx_CR1,CEN);
			break;
		}
		case CC2:
		{
			/*clear CC2S bit so that CC1 channel is configured as output*/
			TIMER_3->TIMx_CCMR1 &= ~(CC2S_MSK);
			/*select PWM mode*/
			TIMER_3->TIMx_CCMR1 |=((TimersPwmInit->PWM_Modes)<<OC2M);
			/*enable pre-load*/
			TIMER_3->TIMx_CCMR1 |=((PWM_PRELOAD_ON)<<OC2PE);
			/*SET Timer Direction*/
			TIMER_3->TIMx_CR1 |= ((TimersPwmInit->Counter_Direction)<<DIRECTION);
			/*set auto reload pre-load*/
			SET_BIT(TIMER_3->TIMx_CR1,ARPE);
			/*Enable output pin for the selected channel*/
			SET_BIT(TIMER_3->TIMx_CCER,CC2E);
			/*Set ARR Value*/
			TIMER_3->TIMx_ARR = ARR_Value;
			/*set pre-scaler value*/
			TIMER_3->TIMx_PSC=PWM_Frequency;
			/*Duty = 2*/
			TIMER_3->TIMx_CCR1=2;
			/*set Update generation bit*/
			SET_BIT(TIMER_3->TIMx_EGR,UG);
			/*enable counter*/
			SET_BIT(TIMER_3->TIMx_CR1,CEN);
			break;
		}
		case CC3:
		{
			/*clear CC3S bit so that CC1 channel is configured as output*/
			TIMER_3->TIMx_CCMR2 &= ~(CC3S_MSK);
			/*select PWM mode*/
			TIMER_3->TIMx_CCMR2 |=((TimersPwmInit->PWM_Modes)<<OC3M);
			/*enable pre-load*/
			TIMER_3->TIMx_CCMR2 |=((PWM_PRELOAD_ON)<<OC3PE);
			/*SET Timer Direction*/
			TIMER_3->TIMx_CR1 |= ((TimersPwmInit->Counter_Direction)<<DIRECTION);
			/*set auto reload pre-load*/
			SET_BIT(TIMER_3->TIMx_CR1,ARPE);
			/*Enable output pin for the selected channel*/
			SET_BIT(TIMER_3->TIMx_CCER,CC3E);
			/*Set ARR Value*/
			TIMER_3->TIMx_ARR = ARR_Value;
			/*set pre-scaler value*/
			TIMER_3->TIMx_PSC=PWM_Frequency;
			/*Duty = 2*/
			TIMER_3->TIMx_CCR1=2;
			/*set Update generation bit*/
			SET_BIT(TIMER_3->TIMx_EGR,UG);
			/*enable counter*/
			SET_BIT(TIMER_3->TIMx_CR1,CEN);
			break;
		}
		case CC4:
		{
			/*clear CC4S bit so that CC1 channel is configured as output*/
			TIMER_3->TIMx_CCMR2 &= ~(CC4S_MSK);
			/*select PWM mode*/
			TIMER_3->TIMx_CCMR2 |=((TimersPwmInit->PWM_Modes)<<OC4M);
			/*enable pre-load*/
			TIMER_3->TIMx_CCMR2 |=((PWM_PRELOAD_ON)<<OC4PE);
			/*SET Timer Direction*/
			TIMER_3->TIMx_CR1 |= ((TimersPwmInit->Counter_Direction)<<DIRECTION);
			/*set auto reload pre-load*/
			SET_BIT(TIMER_3->TIMx_CR1,ARPE);
			/*Enable output pin for the selected channel*/
			SET_BIT(TIMER_3->TIMx_CCER,CC4E);
			/*Set ARR Value*/
			TIMER_3->TIMx_ARR = ARR_Value;
			/*set pre-scaler value*/
			TIMER_3->TIMx_PSC=PWM_Frequency;
			/*Duty = 2*/
			TIMER_3->TIMx_CCR1=2;
			/*set Update generation bit*/
			SET_BIT(TIMER_3->TIMx_EGR,UG);
			/*enable counter*/
			SET_BIT(TIMER_3->TIMx_CR1,CEN);
			break;
		}
		}
		break;
	}
	case TIM4:
	{
		switch(TimersPwmInit->CC)
		{
		case CC1:
		{
			/*clear CC1S bit so that CC1 channel is configured as output*/
			TIMER_4->TIMx_CCMR1 &= ~(CC1S_MSK);
			/*select PWM mode*/
			TIMER_4->TIMx_CCMR1 |=((TimersPwmInit->PWM_Modes)<<OC1M);
			/*enable pre-load*/
			TIMER_4->TIMx_CCMR1 |=((PWM_PRELOAD_ON)<<OC1PE);
			/*SET Timer Direction*/
			TIMER_4->TIMx_CR1 |= ((TimersPwmInit->Counter_Direction)<<DIRECTION);
			/*set auto reload pre-load*/
			SET_BIT(TIMER_4->TIMx_CR1,ARPE);
			/*Enable output pin for the selected channel*/
			SET_BIT(TIMER_4->TIMx_CCER,CC1E);
			/*Set ARR Value*/
			TIMER_4->TIMx_ARR = ARR_Value;
			/*set pre-scaler value*/
			TIMER_4->TIMx_PSC=PWM_Frequency;
			/*Duty = 2*/
			TIMER_4->TIMx_CCR1=2;
			/*set Update generation bit*/
			SET_BIT(TIMER_4->TIMx_EGR,UG);
			/*enable counter*/
			SET_BIT(TIMER_4->TIMx_CR1,CEN);
			break;
		}
		case CC2:
		{
			/*clear CC2S bit so that CC1 channel is configured as output*/
			TIMER_4->TIMx_CCMR1 &= ~(CC2S_MSK);
			/*select PWM mode*/
			TIMER_4->TIMx_CCMR1 |=((TimersPwmInit->PWM_Modes)<<OC2M);
			/*enable pre-load*/
			TIMER_4->TIMx_CCMR1 |=((PWM_PRELOAD_ON)<<OC2PE);
			/*SET Timer Direction*/
			TIMER_4->TIMx_CR1 |= ((TimersPwmInit->Counter_Direction)<<DIRECTION);
			/*set auto reload pre-load*/
			SET_BIT(TIMER_4->TIMx_CR1,ARPE);
			/*Enable output pin for the selected channel*/
			SET_BIT(TIMER_4->TIMx_CCER,CC2E);
			/*Set ARR Value*/
			TIMER_4->TIMx_ARR = ARR_Value;
			/*set pre-scaler value*/
			TIMER_4->TIMx_PSC=PWM_Frequency;
			/*Duty = 2*/
			TIMER_4->TIMx_CCR1=2;
			/*set Update generation bit*/
			SET_BIT(TIMER_4->TIMx_EGR,UG);
			/*enable counter*/
			SET_BIT(TIMER_4->TIMx_CR1,CEN);
			break;
		}
		case CC3:
		{
			/*clear CC3S bit so that CC1 channel is configured as output*/
			TIMER_4->TIMx_CCMR2 &= ~(CC3S_MSK);
			/*select PWM mode*/
			TIMER_4->TIMx_CCMR2 |=((TimersPwmInit->PWM_Modes)<<OC3M);
			/*enable pre-load*/
			TIMER_4->TIMx_CCMR2 |=((PWM_PRELOAD_ON)<<OC3PE);
			/*SET Timer Direction*/
			TIMER_4->TIMx_CR1 |= ((TimersPwmInit->Counter_Direction)<<DIRECTION);
			/*set auto reload pre-load*/
			SET_BIT(TIMER_4->TIMx_CR1,ARPE);
			/*Enable output pin for the selected channel*/
			SET_BIT(TIMER_4->TIMx_CCER,CC3E);
			/*Set ARR Value*/
			TIMER_4->TIMx_ARR = ARR_Value;
			/*set pre-scaler value*/
			TIMER_4->TIMx_PSC=PWM_Frequency;
			/*Duty = 2*/
			TIMER_4->TIMx_CCR1=2;
			/*set Update generation bit*/
			SET_BIT(TIMER_4->TIMx_EGR,UG);
			/*enable counter*/
			SET_BIT(TIMER_4->TIMx_CR1,CEN);
			break;
		}
		case CC4:
		{
			/*clear CC4S bit so that CC1 channel is configured as output*/
			TIMER_4->TIMx_CCMR2 &= ~(CC4S_MSK);
			/*select PWM mode*/
			TIMER_4->TIMx_CCMR2 |=((TimersPwmInit->PWM_Modes)<<OC4M);
			/*enable pre-load*/
			TIMER_4->TIMx_CCMR2 |=((PWM_PRELOAD_ON)<<OC4PE);
			/*SET Timer Direction*/
			TIMER_4->TIMx_CR1 |= ((TimersPwmInit->Counter_Direction)<<DIRECTION);
			/*set auto reload pre-load*/
			SET_BIT(TIMER_4->TIMx_CR1,ARPE);
			/*Enable output pin for the selected channel*/
			SET_BIT(TIMER_4->TIMx_CCER,CC4E);
			/*Set ARR Value*/
			TIMER_4->TIMx_ARR = ARR_Value;
			/*set pre-scaler value*/
			TIMER_4->TIMx_PSC=PWM_Frequency;
			/*Duty = 2*/
			TIMER_4->TIMx_CCR1=2;
			/*set Update generation bit*/
			SET_BIT(TIMER_4->TIMx_EGR,UG);
			/*enable counter*/
			SET_BIT(TIMER_4->TIMx_CR1,CEN);
			break;
		}
		}
		break;
	}
	case TIM5:
	{
		switch(TimersPwmInit->CC)
		{
		case CC1:
		{
			/*clear CC1S bit so that CC1 channel is configured as output*/
			TIMER_5->TIMx_CCMR1 &= ~(CC1S_MSK);
			/*select PWM mode*/
			TIMER_5->TIMx_CCMR1 |=((TimersPwmInit->PWM_Modes)<<OC1M);
			/*enable pre-load*/
			TIMER_5->TIMx_CCMR1 |=((PWM_PRELOAD_ON)<<OC1PE);
			/*SET Timer Direction*/
			TIMER_5->TIMx_CR1 |= ((TimersPwmInit->Counter_Direction)<<DIRECTION);
			/*set auto reload pre-load*/
			SET_BIT(TIMER_5->TIMx_CR1,ARPE);
			/*Enable output pin for the selected channel*/
			SET_BIT(TIMER_5->TIMx_CCER,CC1E);
			/*Set ARR Value*/
			TIMER_5->TIMx_ARR = ARR_Value;
			/*set pre-scaler value*/
			TIMER_5->TIMx_PSC=PWM_Frequency;;
			/*Duty = 2*/
			TIMER_5->TIMx_CCR1=2;
			/*set Update generation bit*/
			SET_BIT(TIMER_5->TIMx_EGR,UG);
			/*enable counter*/
			SET_BIT(TIMER_5->TIMx_CR1,CEN);
			break;
		}
		case CC2:
		{
			/*clear CC2S bit so that CC1 channel is configured as output*/
			TIMER_5->TIMx_CCMR1 &= ~(CC2S_MSK);
			/*select PWM mode*/
			TIMER_5->TIMx_CCMR1 |=((TimersPwmInit->PWM_Modes)<<OC2M);
			/*enable pre-load*/
			TIMER_5->TIMx_CCMR1 |=((PWM_PRELOAD_ON)<<OC2PE);
			/*SET Timer Direction*/
			TIMER_5->TIMx_CR1 |= ((TimersPwmInit->Counter_Direction)<<DIRECTION);
			/*set auto reload pre-load*/
			SET_BIT(TIMER_5->TIMx_CR1,ARPE);
			/*Enable output pin for the selected channel*/
			SET_BIT(TIMER_5->TIMx_CCER,CC2E);
			/*Set ARR Value*/
			TIMER_5->TIMx_ARR = ARR_Value;
			/*set pre-scaler value*/
			TIMER_5->TIMx_PSC=PWM_Frequency;
			/*Duty = 2*/
			TIMER_5->TIMx_CCR1=2;
			/*set Update generation bit*/
			SET_BIT(TIMER_5->TIMx_EGR,UG);
			/*enable counter*/
			SET_BIT(TIMER_5->TIMx_CR1,CEN);
			break;
		}
		case CC3:
		{
			/*clear CC3S bit so that CC1 channel is configured as output*/
			TIMER_5->TIMx_CCMR2 &= ~(CC3S_MSK);
			/*select PWM mode*/
			TIMER_5->TIMx_CCMR2 |=((TimersPwmInit->PWM_Modes)<<OC3M);
			/*enable pre-load*/
			TIMER_5->TIMx_CCMR2 |=((PWM_PRELOAD_ON)<<OC3PE);
			/*SET Timer Direction*/
			TIMER_5->TIMx_CR1 |= ((TimersPwmInit->Counter_Direction)<<DIRECTION);
			/*set auto reload pre-load*/
			SET_BIT(TIMER_5->TIMx_CR1,ARPE);
			/*Enable output pin for the selected channel*/
			SET_BIT(TIMER_5->TIMx_CCER,CC3E);
			/*Set ARR Value*/
			TIMER_5->TIMx_ARR = ARR_Value;
			/*set pre-scaler value*/
			TIMER_5->TIMx_PSC=PWM_Frequency;
			/*Duty = 2*/
			TIMER_5->TIMx_CCR1=2;
			/*set Update generation bit*/
			SET_BIT(TIMER_5->TIMx_EGR,UG);
			/*enable counter*/
			SET_BIT(TIMER_5->TIMx_CR1,CEN);
			break;
		}
		case CC4:
		{
			/*clear CC4S bit so that CC1 channel is configured as output*/
			TIMER_5->TIMx_CCMR2 &= ~(CC4S_MSK);
			/*select PWM mode*/
			TIMER_5->TIMx_CCMR2 |=((TimersPwmInit->PWM_Modes)<<OC4M);
			/*enable pre-load*/
			TIMER_5->TIMx_CCMR2 |=((PWM_PRELOAD_ON)<<OC4PE);
			/*SET Timer Direction*/
			TIMER_5->TIMx_CR1 |= ((TimersPwmInit->Counter_Direction)<<DIRECTION);
			/*set auto reload pre-load*/
			SET_BIT(TIMER_5->TIMx_CR1,ARPE);
			/*Enable output pin for the selected channel*/
			SET_BIT(TIMER_5->TIMx_CCER,CC4E);
			/*Set ARR Value*/
			TIMER_5->TIMx_ARR = ARR_Value;
			/*set pre-scaler value*/
			TIMER_5->TIMx_PSC=PWM_Frequency;
			/*Duty = 2*/
			TIMER_5->TIMx_CCR1=2;
			/*set Update generation bit*/
			SET_BIT(TIMER_5->TIMx_EGR,UG);
			/*enable counter*/
			SET_BIT(TIMER_5->TIMx_CR1,CEN);
			break;
		}
		}
		break;
	}
	}
}

void PWM_VoidSetDutyCycle(u16 Copy_U16Duty, Timer_Type Tims,channel_Types CC)
{
	switch(Tims)
	{
	case TIM2:
	{
		switch(CC)
		{
		case CC1: TIMER_2->TIMx_CCR1=Copy_U16Duty; break;
		case CC2: TIMER_2->TIMx_CCR2=Copy_U16Duty; break;
		case CC3: TIMER_2->TIMx_CCR3=Copy_U16Duty; break;
		case CC4: TIMER_2->TIMx_CCR4=Copy_U16Duty; break;
		}

		break;
	}
	case TIM3:
	{
		switch(CC)
		{
		case CC1: TIMER_3->TIMx_CCR1=Copy_U16Duty; break;
		case CC2: TIMER_3->TIMx_CCR2=Copy_U16Duty; break;
		case CC3: TIMER_3->TIMx_CCR3=Copy_U16Duty; break;
		case CC4: TIMER_3->TIMx_CCR4=Copy_U16Duty; break;
		}

		break;
	}
	case TIM4:
	{
		switch(CC)
		{
		case CC1: TIMER_4->TIMx_CCR1=Copy_U16Duty; break;
		case CC2: TIMER_4->TIMx_CCR2=Copy_U16Duty; break;
		case CC3: TIMER_4->TIMx_CCR3=Copy_U16Duty; break;
		case CC4: TIMER_4->TIMx_CCR4=Copy_U16Duty; break;
		}

		break;
	}
	case TIM5:
	{
		switch(CC)
		{
		case CC1: TIMER_5->TIMx_CCR1=Copy_U16Duty; break;
		case CC2: TIMER_5->TIMx_CCR2=Copy_U16Duty; break;
		case CC3: TIMER_5->TIMx_CCR3=Copy_U16Duty; break;
		case CC4: TIMER_5->TIMx_CCR4=Copy_U16Duty; break;
		}
		break;
	}
	}
}
