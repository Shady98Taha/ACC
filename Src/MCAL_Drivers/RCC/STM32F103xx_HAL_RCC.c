/*
 * STM32F103xx_HAL_RCC.c
 *
 *  Created on: Jul 16, 2023
 *      Author: shady
 */

#include"MCAL_Drivers/RCC/STM32F103xx_HAL_RCC.h"


HAL_Error_State HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_init)
{
	HAL_Error_State RetState=HAL_OK;
	if(NULL == RCC_init)
	{
		RetState=HAL_ERROR;


	}else
	{
		if(RCC_OSCILLATORTYPE_HSE==RCC_init->RCC_OSCILLATORTYPES)
		{
			RCC->CR &= ~(HSEON_MSK);
			RCC->CR |= ((RCC_init->HSE_STATE) << HSEON );
			RCC->CFGR &= ~(SW_MSK);
			RCC->CFGR |= ((RCC_init->Clock_switch)<<SW);

		}else if(RCC_OSCILLATORTYPE_HSI==RCC_init->RCC_OSCILLATORTYPES)
		{
			RCC->CR &= ~(HSION_MSK);
			RCC->CR |= ((RCC_init->HSI_STATE) << HSION );
			RCC->CFGR &= ~(SW_MSK);
			RCC->CFGR |= ((RCC_init->Clock_switch) << SW);
		}else if(RCC_OSCILLATORTYPE_LSE==RCC_init->RCC_OSCILLATORTYPES)
		{
			RCC->BDCR &= ~(LSEON_MSK);
			RCC->BDCR |= ((RCC_init->LSE_STATE)<<LSEON);

		}else if(RCC_OSCILLATORTYPE_LSI==RCC_init->RCC_OSCILLATORTYPES)
		{
			RCC->CSR &= ~(LSION_MSK);
			RCC->CSR |= ((RCC_init->LSI_STATE)<<LSION);
		}
	}
	return RetState;
}



void HAL_RCC_PLLConfig(PLL_CLKDEf *PLL_Value)
{
	RCC->CR &= ~(PLLON_MSK);
	RCC->CFGR &= ~(PLLON_MUL_MSK);
	switch(PLL_Value->CLKSource)
	{
	case HSI_oscillator_clock:
	{
		RCC->CFGR &= ~(PLLSRC_MSK);
		break;
	}
	case HSE_oscillator_clock:
	{
		RCC->CFGR &= ~(PLLSRC_MSK);
		RCC->CFGR |= PLLSRC_MSK;
		RCC->CFGR &= ~(PLLXTPRE_MSK);
		break;
	}
	case HSE_clock_divided_by_2:
	{
		RCC->CFGR &= ~(PLLSRC_MSK);
		RCC->CFGR |= PLLSRC_MSK;
		RCC->CFGR &= ~(PLLXTPRE_MSK);
		RCC->CFGR |=(PLLXTPRE_MSK);
		break;
	}
	}
	RCC->CFGR |=((PLL_Value->MUL_Value) << PLLON_MUL);
	RCC->CR |= (PLLON_MSK);
	RCC->CFGR &= ~(0x03);
	RCC->CFGR |= 0x02;


}






HAL_Error_State HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_CLK_Init)
{
	HAL_Error_State RetState=HAL_OK;
	if(NULL == RCC_CLK_Init)
	{
		RetState=HAL_ERROR;
	}else
	{
		RCC->CFGR &= ~(HPRE_MSK);
		RCC->CFGR |= ((RCC_CLK_Init->AHBCLKDivider) << HPRE);

		RCC->CFGR &= ~(PPRE1_MSK);
		RCC->CFGR |= ((RCC_CLK_Init->APB1CLKDivider)<< PPRE1);

		RCC->CFGR &= ~(PPRE2_MSK);
		RCC->CFGR |= ((RCC_CLK_Init->APB2CLKDivider)<<PPRE2);
	}
	return RetState;
}

HAL_Error_State HAL_RCC_ClockEnable(Enable_Clock_values *Clock_values)
{
	HAL_Error_State RetState=HAL_OK;
	if(31 < (Clock_values->Value))
	{
		RetState=HAL_ERROR;
	}else
	{
		switch((Clock_values->Bus_Type))
		{
		case RCC_AHBENR:  SET_BIT((RCC->AHBENR),(Clock_values->Value)); break;
		case RCC_APB2ENR: SET_BIT((RCC->APB2ENR),(Clock_values->Value)); break;
		case RCC_APB1ENR: SET_BIT((RCC->APB1ENR),(Clock_values->Value)); break;
		}
	}
	return RetState;
}


HAL_Error_State HAL_RCC_ClockDisable(Enable_Clock_values *Clock_values)
{
	HAL_Error_State RetState=HAL_OK;
	if(31 < (Clock_values->Value))
	{
		RetState=HAL_ERROR;
	}else
	{
		switch((Clock_values->Bus_Type))
		{
		case RCC_AHBENR:  CLR_BIT((RCC->AHBENR),(Clock_values->Value)); break;
		case RCC_APB2ENR: CLR_BIT((RCC->APB2ENR),(Clock_values->Value)); break;
		case RCC_APB1ENR: CLR_BIT((RCC->APB1ENR),(Clock_values->Value)); break;
		}
	}
	return RetState;
}
