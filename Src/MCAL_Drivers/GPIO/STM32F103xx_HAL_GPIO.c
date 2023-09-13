/*
 * STM32F103xx_HAL_GPIO.c
 *
 *  Created on: Jul 19, 2023
 *      Author: shady
 */

#include "Library/STD_TYPES.h"
#include "Library/BIT_MATH.h"
#include "MCAL_Drivers/GPIO/STM32F103xx_HAL_GPIO_Cfg.h"
#include "MCAL_Drivers/GPIO/STM32F103xx_HAL_GPIO_Private.h"

void GPIO_VoidSetPinDirection(PIN_State *State)
{
	switch((State->Pins)/16)
	{
	case PORTA:
	{
		if((((State->Pins) %16) <= 7))
		{
			GPIOA->CRL &= ~((MODE_MSK) << (((State->Pins) % 16)*4));
			GPIOA->CRL |= ((State->Mode) << (((State->Pins) % 16)*4));
		}else if((((State->Pins) %16) > 7) && (((State->Pins) %16) <= 15))
		{
			State->Pins-=8;
			GPIOA->CRH &= ~((MODE_MSK) << (((State->Pins) % 16)*4));
			GPIOA->CRH |= ((State->Mode) << (((State->Pins) % 16)*4));
		}
		break;
	}
	case PORTB:
	{
		if((((State->Pins) %16) <= 7))
		{
			GPIOB->CRL &= ~((MODE_MSK) << (((State->Pins) % 16)*4));
			GPIOB->CRL |= ((State->Mode) << (((State->Pins) % 16)*4));
		}else if((((State->Pins) %16) > 7) && (((State->Pins) %16) <= 15))
		{
			GPIOB->CRH &= ~((MODE_MSK) << (((State->Pins) % 16)*4));
			GPIOB->CRH |= ((State->Mode) << (((State->Pins) % 16)*4));
		}
		break;
	}
	case PORTC:
	{
		if((((State->Pins) %16) <= 7))
		{
			GPIOC->CRL &= ~((MODE_MSK) << (((State->Pins) % 16)*4));
			GPIOC->CRL |= ((State->Mode) << (((State->Pins) % 16)*4));
		}else if((((State->Pins) %16) > 7) && (((State->Pins) %16) <= 15))
		{
			GPIOC->CRH &= ~((MODE_MSK) << (((State->Pins) % 16)*4));
			GPIOC->CRH |= ((State->Mode) << (((State->Pins) % 16)*4));
		}
		break;
	}
	}
}



void GPIO_VoidSetPinValue(GPIO_PINS pin,GPIO_Value Value)
{
	switch((pin/16))
	{
	case PORTA:
	{
		if(Value == GPIO_HIGH)
		{
			SET_BIT((GPIOA->ODR),(pin%16));
		}else if(Value == GPIO_LOW)
		{
			CLR_BIT((GPIOA->ODR),(pin%16));
		}
		break;
	}
	case PORTB:
	{
		if(Value == GPIO_HIGH)
		{
			SET_BIT((GPIOB->ODR),(pin%16));
		}else if(Value == GPIO_LOW)
		{
			CLR_BIT((GPIOB->ODR),(pin%16));
		}
		break;
	}
	case PORTC:
	{
		if(Value == GPIO_HIGH)
		{
			SET_BIT((GPIOC->ODR),(pin%16));
		}else if(Value == GPIO_LOW)
		{
			CLR_BIT((GPIOC->ODR),(pin%16));
		}
		break;
	}
	}
}



u32 GPIO_GetPinValue(GPIO_PINS pin)
{
	u32 Local_Value=0;
	switch((pin/16))
	{
	case PORTA: Local_Value=GET_BIT((GPIOA->IDR),(pin%16)); break;
	case PORTB: Local_Value=GET_BIT((GPIOB->IDR),(pin%16)); break;
	case PORTC: Local_Value=GET_BIT((GPIOC->IDR),(pin%16)); break;
	}
	return Local_Value;
}


void GPIO_TogglePinValue(GPIO_PINS pin)
{

	switch((pin/16))
	{
	case PORTA: TOG_BIT((GPIOA->ODR),(pin%16)); break;
	case PORTB: TOG_BIT((GPIOB->ODR),(pin%16)); break;
	case PORTC: TOG_BIT((GPIOC->ODR),(pin%16)); break;
	}

}
