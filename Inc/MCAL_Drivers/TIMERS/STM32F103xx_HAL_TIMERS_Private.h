/*
 * STM32F103xx_HAL_TIMERS_Private.h
 *
 *  Created on: Aug 23, 2023
 *      Author: shady
 */

#ifndef HAL_DRIVERS_TIMERS_STM32F103XX_HAL_TIMERS_PRIVATE_H_
#define HAL_DRIVERS_TIMERS_STM32F103XX_HAL_TIMERS_PRIVATE_H_

/******************************* Includes Start **************************************/
/******************************* Includes End ****************************************/

/******************************* Macro Declarations Start ****************************/
#define TIMER2_BASE 0x40000000
#define TIMER_2 ((TIMERS_TypeDef*)TIMER2_BASE)

#define TIMER3_BASE 0x40000400
#define TIMER_3 ((TIMERS_TypeDef*)TIMER3_BASE)

#define TIMER4_BASE 0x40000800
#define TIMER_4 ((TIMERS_TypeDef*)TIMER4_BASE)

#define TIMER5_BASE 0x40000C00
#define TIMER_5 ((TIMERS_TypeDef*)TIMER5_BASE)


/************************TIMx_CCMR1 register bits******************************/
#define ARPE	7
#define DIR     4
#define UDIS    1
#define CEN 	0
/**********************TIMx_CCMR1 register bits*********************************/
#define CC1S 	0
#define IC1PSC 	2
#define IC1F	4
#define CC2S	8
#define CC2S_MSK
#define IC2PSC	10
#define IC2F	12

/**********************TIMx_CCMR2 register bits*********************************/
#define CC3S 	0
#define IC3PSC 	2
#define IC3F	4
#define CC4S	8
#define IC4PSC	10
#define IC4F	12

/*********************TIMC_CCER register bits**********************************/
#define	CC1E 0
#define CC1P 1
#define CC1P_MSK 0x02
#define CC2E 4
#define CC2P 5
#define CC2P_MSK 0x20
#define	CC3E 8
#define CC3P 9
#define CC3P_MSK 0x200
#define CC4E 12
#define CC4P 13
#define CC4P_MSK 0x2000
/*******************************************************************************/

/******************************* Macro Declarations End ******************************/

/******************************* Macro functions Declarations Start ******************/

/******************************* Macro functions Declarations End ********************/

/******************************* Data Type Declarations Start ************************/
typedef struct{
	u32 TIMx_CR1;
	u32 TIMx_CR2;
	u32 TIMx_SMCR;
	u32 TIMx_DIER;
	u32 TIMx_SR;
	u32 TIMx_EGR;
	u32 TIMx_CCMR1;
	u32 TIMx_CCMR2;
	u32 TIMx_CCER;
	u32 TIMx_CNT;
	u32 TIMx_PSC;
	u32 TIMx_ARR;
	u32 Reserved;
	u32 TIMx_CCR1;
	u32 TIMx_CCR2;
	u32 TIMx_CCR3;
	u32 TIMx_CCR4;
	u32 Reserved2;
	u32 TIMx_DCR;
	u32 TIMx_DMAR;
}TIMERS_TypeDef;
/******************************* Data Type Declarations End **************************/

/******************************* Software interfaces Declarations Start **************/
/******************************* Software interfaces Declarations End ****************/



#endif /* HAL_DRIVERS_TIMERS_STM32F103XX_HAL_TIMERS_PRIVATE_H_ */
