/**
 ******************************************************************************
 * @file           : STM32F103xx_HAL_PWM_Private.h
 * @author         : Shady Taha
 * @brief          : PWM private header file
 ******************************************************************************
*/

#ifndef MCAL_DRIVERS_PWM_STM32F103XX_HAL_PWM_PRIVATE_H_
#define MCAL_DRIVERS_PWM_STM32F103XX_HAL_PWM_PRIVATE_H_


/******************************* Macro Declarations Start ****************************/
#define TIMER2_BASE 0x40000000
#define TIMER_2 ((TIMERS_TypeDef*)TIMER2_BASE)

#define TIMER3_BASE 0x40000400
#define TIMER_3 ((TIMERS_TypeDef*)TIMER3_BASE)

#define TIMER4_BASE 0x40000800
#define TIMER_4 ((TIMERS_TypeDef*)TIMER4_BASE)

#define TIMER5_BASE 0x40000C00
#define TIMER_5 ((TIMERS_TypeDef*)TIMER5_BASE)



#define CC1S_MSK 0x03
#define CC2S_MSK 0x300
#define CC3S_MSK 0x03
#define CC4S_MSK 0x300

#define ARPE		  7
#define DIRECTION     4
#define UDIS  		  1
#define CEN 		  0
#define UG    		  0

#define OC1M 	4
#define OC1PE 	3
#define OC1FE 	2

#define OC2M 	12
#define OC2PE 	11
#define OC2FE   10

#define OC3M 	4
#define OC3PE 	3
#define OC3FE 	2

#define OC4M 	12
#define OC4PE 	11
#define OC4FE   10

#define CC1E 	0
#define CC2E 	4
#define CC3E 	8
#define CC4E 	12



#define MCU_Frequency 8000000
/******************************* Macro Declarations END ****************************/

/******************************* Data Type Declarations Start ************************/
typedef enum{
	PWM_PRELOAD_OFF=0,
	PWM_PRELOAD_ON=1
}PWM_PRELOAD_Types;

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


#endif /* MCAL_DRIVERS_PWM_STM32F103XX_HAL_PWM_PRIVATE_H_ */
