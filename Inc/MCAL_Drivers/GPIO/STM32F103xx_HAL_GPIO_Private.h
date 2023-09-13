/*
 * STM32F103xx_HAL_GPIO_Private.h
 *
 *  Created on: Jul 19, 2023
 *      Author: shady
 */

#ifndef HAL_DRIVERS_GPIO_STM32F103XX_HAL_GPIO_PRIVATE_H_
#define HAL_DRIVERS_GPIO_STM32F103XX_HAL_GPIO_PRIVATE_H_


/******************************* Includes Start **************************************/
/******************************* Includes End ****************************************/

/******************************* Macro Declarations Start ****************************/
#define GPIOA_BASE 0x40010800
#define GPIOA ((GPIO_Typedef*)GPIOA_BASE)

#define GPIOB_BASE 0x40010C00
#define GPIOB ((GPIO_Typedef*)GPIOB_BASE)

#define GPIOC_BASE 0x40011000
#define GPIOC ((GPIO_Typedef*)GPIOC_BASE)


#define PORTA 0
#define PORTB 1
#define PORTC 2


#define MODE_MSK 0x0F
/******************************* Macro Declarations End ******************************/

/******************************* Macro functions Declarations Start ******************/
/******************************* Macro functions Declarations End ********************/

/******************************* Data Type Declarations Start ************************/
typedef struct{
	u32 CRL;
	u32 CRH;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 BRR;
	u32 LCKR;
}GPIO_Typedef;
/******************************* Data Type Declarations End **************************/

/******************************* Software interfaces Declarations Start **************/
/******************************* Software interfaces Declarations End ****************/



#endif /* HAL_DRIVERS_GPIO_STM32F103XX_HAL_GPIO_PRIVATE_H_ */
