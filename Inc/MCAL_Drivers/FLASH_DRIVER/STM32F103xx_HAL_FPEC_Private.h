/*
 * STM32F103xx_HAL_FPEC_Private.h
 *
 *  Created on: Jul 29, 2023
 *      Author: shady
 */

#ifndef HAL_DRIVERS_FLASH_DRIVER_STM32F103XX_HAL_FPEC_PRIVATE_H_
#define HAL_DRIVERS_FLASH_DRIVER_STM32F103XX_HAL_FPEC_PRIVATE_H_


/******************************* Includes Start **************************************/
/******************************* Includes End ****************************************/

/******************************* Macro Declarations Start ****************************/

/*************************Memory Map start***************************************/
#define FPEC_BASE 0x40022000
#define FPEC ((FPEC_TypeDef*)FPEC_BASE)
/************************Memory Map END******************************************/

/*************************Wait state start***************************************/
#define wait_state Zero_wait_state
#define Zero_wait_state 0
#define One_wait_state  1
#define Two_wait_state  2
#define wait_state_MSK 0x7
/*************************Wait state END***************************************/
/****************************************************************************/

/*************************KEYS MACROS***************************************/
#define OPTKEY1 0x45670123
#define OPTKEY2 0xCDEF89AB
/*************************KEYS MACROS***************************************/
/****************************************************************************/

/*************************FLASH_SR Register bits start**********************/
#define BSY 		0
#define PGERR		2
#define WRPRTERR	4
#define EOP 		5
/*************************FLASH_SR Register bits END************************/
/****************************************************************************/

/************************FLASH_CR Register bits start***********************/
#define PG		0
#define PER		1
#define MER		2
#define OPTPG 	4
#define OPTER	5
#define STRT	6
#define LOCK	7
#define OPTWRE	9
#define ERRIE	10
#define EOPIE	12
/************************FLASH_CR Register bits END*************************/
/****************************************************************************/

/************************FLASH_OBR Register bits start***********************/
#define OPTERR 		0
#define RDPRT		1
#define WDG_SW		2
#define nRST_STOP	3
#define nRST_STDBY	4
/************************FLASH_OBR Register bits END***********************/

#define FLASH_BSY 1
#define FLASH_NOT_BSY 0


#define FLASH_MEM_START_ADDRESS     0x08000000
#define FLASH_MEMORY_PAGE_SIZE 		1024
/******************************* Macro Declarations End ******************************/

/******************************* Macro functions Declarations Start ******************/
#define WriteData(Copy_U32MemoryAddress,Data) *((volatile u16*)Copy_U32MemoryAddress)=Data
/******************************* Macro functions Declarations End ********************/

/******************************* Data Type Declarations Start ************************/
typedef struct{

	volatile u32 FLASH_ACR;
	volatile u32 FLASH_KEYR;
	volatile u32 FLASH_OPTKEYR;
	volatile u32 FLASH_SR;
	volatile u32 FLASH_CR;
	volatile u32 FLASH_AR;
	volatile u32 Reserved;
	volatile u32 FLASH_OBR;
	volatile u32 FLASH_WRPR;
}FPEC_TypeDef;

typedef enum{
	FPEC_LOCKED		=1,
	FPEC_UNLOCKED	=0
}Sequence_TypeDef;



/******************************* Data Type Declarations End **************************/

/******************************* Software interfaces Declarations Start **************/
/******************************* Software interfaces Declarations End ****************/





#endif /* HAL_DRIVERS_FLASH_DRIVER_STM32F103XX_HAL_FPEC_PRIVATE_H_ */
