/*
 * STM32F103xx_HAL_UART.c
 *
 *  Created on: Jul 29, 2023
 *      Author: shady
 */
#include"Library/STD_TYPES.h"
#include"Library/BIT_MATH.h"
#include"MCAL_Drivers/Common/STM32F103xx_HAL_Def.h"
#include"MCAL_Drivers/UART/STM32F103xx_HAL_UART_Private.h"
#include "MCAL_Drivers/UART/STM32F103xx_HAL_UART_Cfg.h"


void MUSART1_VoidInit(void)
{
	/*For Baud Rate 9600*/
	UART->UART_BRR=BaudRate;
	/*Enable RX*/
	SET_BIT(UART->UART_CR1,RX_Enable);
	/*Enable TX*/
	SET_BIT(UART->UART_CR1,TX_Enable);
	/*Enable UART*/
	SET_BIT(UART->UART_CR1,UART_Enable);
	/*Clear status register*/
	UART->UART_SR=0;
}
void MUSART1_VoidTransmit(u8 num)
{
	while(!GET_BIT((UART->UART_SR),TC))
	{

	}
	UART->UART_DR=num;
}


void MUSART1_VoidTransmitArray(u8 *arr)
{
	u8 i=0;

	while(arr[i] != '\0')
	{
		MUSART1_VoidTransmit(arr[i]);
		i++;
	}
}
u8 MUSART1_VoidReceive(void)
{
	while(!GET_BIT((UART->UART_SR),RXNE))
	{

	}
	return ((UART->UART_DR)&0xFF);
}

