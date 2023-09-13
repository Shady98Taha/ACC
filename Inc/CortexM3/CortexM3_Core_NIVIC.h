/**
 ******************************************************************************
 * @file           : CortexM3_Core_NIVIC
 * @author         : Shady Taha
 * @brief          : NVIC header file
 ******************************************************************************
*/
#ifndef CORTEXM3_CORE_NIVIC_H_
#define CORTEXM3_CORE_NIVIC_H_

/******************************* Includes Start **************************************/
#include "Library/STD_TYPES.h"
#include "Library/BIT_MATH.h"
/******************************* Includes End ****************************************/

/******************************* Macro Declarations Start ****************************/
#define NVIC_BASE 0xE000E100
#define NVIC ((NVIC_Types*)NVIC_BASE)

#define register_bits 32
#define NVIC_PRIO_BITS 4
/******************************* Macro Declarations End ******************************/

/******************************* Macro functions Declarations Start ******************/
/******************************* Macro functions Declarations End ********************/

/******************************* Data Type Declarations Start ************************/
typedef struct{
	volatile u32 ISER[8];
	u32 Reserved0[24];
	volatile u32 ICER[8];
	u32 Reserved1[24];
	volatile u32 ISPR[8];
	u32 Reserved2[24];
	volatile u32 ICPR[8];
	u32 Reserved3[24];
	volatile u32 IABR[8];
	u32 Reserved4[56];
	volatile u8 IP[24];
	u32 Reserved5[644];
	volatile u32 STIR;
}NVIC_Types;


typedef enum{
/******************************* Cortex-M3 Processor Exceptions Numbers***************/
	NonMaskableInt_IRQn			=-14,
	MemoryManagment_IRQn		=-12,
	BusFault_IRQn				=-11,
	UsageFault_IRQn				=-10,
	SVCall_IRQn					=-5,
	DebugMonitor_IRQn			=-4,
	PendSV_IRQn					=-2,
	SysTick_IRQn				=-1,
/******************************* STM32 Specific Interrupt Numbers*********************/
	WWDG_IRQn					=0,
	PVD_IRQn					=1,
	TAMPER_IRQn					=2,
	RTC_IRQn					=3,
	FLASH_IRQn					=4,
	RCC_IRQn					=5,
	EXTI0_IRQn					=6,
	EXTI1_IRQn					=7,
	EXTI2_IRQn					=8,
	EXTI3_IRQn					=9,
	EXTI4_IRQn					=10,
	DMA1_Channel1_IRQn			=11,
	DMA1_Channel2_IRQn			=12,
	DMA1_Channel3_IRQn			=13,
	DMA1_Channel4_IRQn			=14,
	DMA1_Channel5_IRQn			=15,
	DMA1_Channel6_IRQn			=16,
	DMA1_Channel7_IRQn			=17,
	ADC1_2_IRQn					=18,
	USB_HP_CAN_TX_IRQn			=19,
	USB_LP_CAN_RX0_IRQn			=20,
	CAN_RX1_IRQn				=21,
	CAN_SCE_IRQn				=22,
	EXTI9_5_IRQn				=23,
	TIM1_BRK_IRQn				=24,
	TIM1_UP_IRQn				=25,
	TIM1_TRG_COM_IRQn			=26,
	TIM1_CC_IRQn				=27,
	TIM2_IRQn					=28,
	TIM3_IRQn					=29,
	TIM4_IRQn					=30,
	I2C1_EV_IRQn				=31,
	I2C1_ER_IRQn				=32,
	I2C2_EV_IRQn				=33,
	I2C2_ER_IRQn				=34,
	SPI1_IRQn					=35,
	SPI2_IRQn					=36,
	USART1_IRQn					=37,
	USART2_IRQn					=38,
	USART3_IRQn					=39,
	EXTI15_10_IRQn				=40,
	RTCAlarm_IRQn				=41,
	USBWakeup_IRQn				=42,
	TIM8_BRK_IRQn				=43,
	TIM8_UP_IRQn				=44,
	TIM8_TRG_COM_IRQn			=45,
	TIM8_CC_IRQn				=46,
	ADC3_IRQn					=47,
	FSMC_IRQn					=48,
	SDIO_IRQn					=49,
	TIM5_IRQn					=50,
	SPI3_IRQn					=51,
	UART4_IRQn					=52,
	UART5_IRQn					=53,
	TIM6_IRQn					=54,
	TIM7_IRQn					=55,
	DMA2_Channel1_IRQn			=56,
	DMA2_Channel2_IRQn			=57,
	DMA2_Channel3_IRQn			=58,
	DMA2_Channel4_5_IRQn		=59
}IRQn_Types;



typedef enum{
	OK=1,
	NOT_OK=0
}ERROR_State;
/******************************* Data Type Declarations End **************************/

/******************************* Software interfaces Declarations Start **************/
ERROR_State NVIC_EnableIRQ(IRQn_Types IRQn);
ERROR_State NVIC_DisableIRQ(IRQn_Types IRQn);
void NVIC_SetPendingIRQ(IRQn_Types IRQn);
void NVIC_ClearPendingIRQ(IRQn_Types IRQn);
u32  NVIC_GetActive(IRQn_Types IRQn);
void NVIC_SetPriority(IRQn_Types IRQn, u32 Priority);
u32 NVIC_GetPriority(IRQn_Types IRQn);
/******************************* Software interfaces Declarations End ****************/


#endif /* CORTEXM3_CORE_NIVIC_H_ */
