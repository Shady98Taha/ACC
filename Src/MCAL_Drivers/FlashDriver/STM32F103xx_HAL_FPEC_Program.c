/*
 * STM32F103xx_HAL_FPEC_Program.c
 *
 *  Created on: Jul 29, 2023
 *      Author: shady
 */
#include "Library/STD_TYPES.h"
#include "Library/BIT_MATH.h"
#include "MCAL_Drivers/FLASH_DRIVER/STM32F103xx_HAL_FPEC_Private.h"
#include "MCAL_Drivers/FLASH_DRIVER/STM32F103xx_HAL_FPEC_Cfg.h"


void FPEC_voidInit(void)
{
	FPEC->FLASH_ACR= (wait_state & wait_state_MSK);
}



void FPEC_u8WriteFlash(u32 Copy_U32MemoryAddress,u16 *Address_u16Data,u16 Copy_u16DataLength)
{
	u8 DataCounter=0;
	while(GET_BIT((FPEC->FLASH_SR),BSY)==FLASH_BSY);
	if(GET_BIT((FPEC->FLASH_CR),LOCK) == FPEC_LOCKED)
	{
		FPEC->FLASH_KEYR=OPTKEY1;
		FPEC->FLASH_KEYR=OPTKEY2;
	}
	for(DataCounter=0;DataCounter<Copy_u16DataLength;DataCounter++)
	{
		SET_BIT((FPEC->FLASH_CR),PG);
		WriteData(Copy_U32MemoryAddress,Address_u16Data[DataCounter]);
		Copy_U32MemoryAddress+=2;
		while(GET_BIT((FPEC->FLASH_SR),BSY)==FLASH_BSY);
		SET_BIT((FPEC->FLASH_SR),EOP);
		CLR_BIT((FPEC->FLASH_CR),PG);
	}
}


void FPEC_u8FlashPageErase(u8 Copy_u8PageNumber)
{
	while(GET_BIT((FPEC->FLASH_SR),BSY)==FLASH_BSY);
	if(GET_BIT((FPEC->FLASH_CR),LOCK) == FPEC_LOCKED)
	{
		FPEC->FLASH_KEYR=OPTKEY1;
		FPEC->FLASH_KEYR=OPTKEY2;
	}
	SET_BIT(FPEC->FLASH_CR,PER);
	FPEC->FLASH_AR=(Copy_u8PageNumber*FLASH_MEMORY_PAGE_SIZE)+FLASH_MEM_START_ADDRESS;
	SET_BIT(FPEC->FLASH_CR,STRT);
	while(GET_BIT((FPEC->FLASH_SR),BSY)==FLASH_BSY);
	SET_BIT((FPEC->FLASH_SR),EOP);
	CLR_BIT((FPEC->FLASH_CR),PG);
}


void FPEC_u8FlashMassErase(void)
{

	while(GET_BIT((FPEC->FLASH_SR),BSY)==FLASH_BSY);
	if(GET_BIT((FPEC->FLASH_CR),LOCK) == FPEC_LOCKED)
	{
		FPEC->FLASH_KEYR=OPTKEY1;
		FPEC->FLASH_KEYR=OPTKEY2;
	}
	SET_BIT(FPEC->FLASH_CR,MER);
	SET_BIT(FPEC->FLASH_CR,STRT);
	while(GET_BIT((FPEC->FLASH_SR),BSY)==FLASH_BSY);
	SET_BIT((FPEC->FLASH_SR),EOP);
	CLR_BIT((FPEC->FLASH_CR),PG);

}


void FPEC_voidEraseAPPArea(void)
{
	u8 i=0;
	for(i=7;i<64;i++)
	{
		FPEC_u8FlashPageErase(i);
	}
}
