/*
 * STM32F103xx_HAL_UART_Private.h
 *
 *  Created on: Jul 29, 2023
 *      Author: shady
 */

#ifndef HAL_DRIVERS_UART_STM32F103XX_HAL_UART_PRIVATE_H_
#define HAL_DRIVERS_UART_STM32F103XX_HAL_UART_PRIVATE_H_




/******************************* Includes Start **************************************/
#include"Library/STD_TYPES.h"
/******************************* Includes End ****************************************/

/******************************* Macro Declarations Start ****************************/
#define UART_BASE 0x40013800
#define UART ((UART_Typedef*)UART_BASE)



#define UART_Enable 13
#define TX_Enable 	3
#define RX_Enable 	2
#define TC 			6
#define RXNE 		5
/******************************* Macro Declarations End ******************************/

/******************************* Macro functions Declarations Start ******************/
/******************************* Macro functions Declarations End ********************/

/******************************* Data Type Declarations Start ************************/
typedef struct{
	volatile u32 UART_SR;
	volatile u32 UART_DR;
	volatile u32 UART_BRR;
	volatile u32 UART_CR1;
	volatile u32 UART_CR2;
	volatile u32 UART_CR3;
	volatile u32 UART_GTPR;
}UART_Typedef;

/******************************* Data Type Declarations End **************************/

/******************************* Software interfaces Declarations Start **************/
/******************************* Software interfaces Declarations End ****************/



#endif /* HAL_DRIVERS_UART_STM32F103XX_HAL_UART_PRIVATE_H_ */
