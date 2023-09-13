/*
 * STM32F103xx_HAL_RCC.h
 *
 *  Created on: Jul 16, 2023
 *      Author: shady
 */

#ifndef HAL_DRIVERS_RCC_STM32F103XX_HAL_RCC_H_
#define HAL_DRIVERS_RCC_STM32F103XX_HAL_RCC_H_

/******************************* Includes Start **************************************/
#include "Library/STD_TYPES.h"
#include "Library/BIT_MATH.h"
#include "MCAL_Drivers/Common/STM32F103xx_HAL_Def.h"
/******************************* Includes End ****************************************/

/******************************* Macro Declarations Start ****************************/

/******************** ADDRESS for memory map start ****************************/

#define PERIPH_BASE 0x40000000
#define AHB1_BASE (PERIPH_BASE+0x00020000)
#define RCC_BASE (AHB1_BASE+0x1000)
#define RCC ((RCC_Typedef*)RCC_BASE)

/******************** ADDRESS for memory map END *****************************/

/************************GPIO clock enable bits start*************************/
#define IOPAEN 2
#define IOPAENMSK ( 1 << IOPAEN )

#define IOPBEN 3
#define IOPBENMSK ( 1 << IOPBEN )

#define IOPCEN 4
#define IOPCENMSK ( 1 << IOPCEN )

#define IOPDEN 5
#define IOPDENMSK ( 1 << IOPDEN )

#define IOPEEN 6
#define IOPEENMSK ( 1 << IOPEEN )

#define IOPFEN 7
#define IOPFENMSK ( 1 << IOPFEN )

#define IOPGEN 8
#define IOPGENMSK ( 1 << IOPGEN )


#define UART1EN 14
#define FPECEN 	4
#define TIMER_2 0
#define TIMER_3	1
#define TIMER_4	2
#define TIMER_5	3

/************************GPIO clock enable bits end*************************/


/***********************clock source types start****************************/
#define HSEON 16
#define HSEON_MSK (1<<HSEON)

#define HSION 0
#define HSION_MSK (1<<HSION)

#define LSION 0
#define LSION_MSK (1<<LSION)

#define LSEON 0
#define LSEON_MSK (1<<LSEON)

#define PLLON 24
#define PLLON_MSK (1<<PLLON)
#define PLLON_MUL 18
#define PLLON_MUL_MSK (0x0F<<PLLON_MUL)
#define PLLSRC 16
#define PLLSRC_MSK (1<<16)
#define PLLXTPRE 17
#define PLLXTPRE_MSK (1<<PLLXTPRE)
/***********************clock source types END****************************/


/*********************** BUS Prescaler Bits*******************************/
#define HPRE 4
#define HPRE_MSK (0X0F<<HPRE)


#define PPRE1 8
#define PPRE1_MSK (0x07<<PPRE1)

#define PPRE2 11
#define PPRE2_MSK (0x07<<PPRE2)
/******************************* Macro Declarations End ******************************/
#define SW 0
#define SW_MSK (0x03<<SW)
/******************************* Macro functions Declarations Start ******************/



/******************************* Macro functions Declarations End ********************/

/******************************* Data Type Declarations Start ************************/
typedef struct{
volatile u32 CR;
volatile u32 CFGR;
volatile u32 CIR;
volatile u32 APB2RSTR;
volatile u32 APB1RSTR;
volatile u32 AHBENR;
volatile u32 APB2ENR;
volatile u32 APB1ENR;
volatile u32 BDCR;
volatile u32 CSR;
}RCC_Typedef;

typedef enum{
	RCC_OSCILLATORTYPE_NONE	= (u8)0,
	RCC_OSCILLATORTYPE_HSE	= (u8)1,
	RCC_OSCILLATORTYPE_HSI	= (u8)2,
	RCC_OSCILLATORTYPE_LSE	= (u8)4,
	RCC_OSCILLATORTYPE_LSI	= (u8)8,
}RCC_OSCILLATORTYPE;

typedef enum{
	RCC_HSE_OFF= (u8)0,
	RCC_HSE_ON= (u8)1
}RCC_HSE_CONFIG;

typedef enum{
	RCC_LSE_OFF=(u8)0,
	RCC_LSE_ON=(u8)1
}RCC_LSE_CONFIG;

typedef enum{
	RCC_HSI_OFF=(u8)0,
	RCC_HSI_ON=(u8)1
}RCC_HSI_CONFIG;

typedef enum{
	RCC_LSI_OFF=(u8)0,
	RCC_LSI_ON=(u8)1
}RCC_LSI_CONFIG;

typedef enum{
	HSI			 	=0,
	HSE				=1,
	PLL				=2,
	NOT_ALLOWED		=3
}System_clock_switch;

typedef struct{
	RCC_OSCILLATORTYPE RCC_OSCILLATORTYPES;
	RCC_HSE_CONFIG HSE_STATE;
	RCC_LSE_CONFIG LSE_STATE;
	RCC_HSI_CONFIG HSI_STATE;
	RCC_LSI_CONFIG LSI_STATE;
	System_clock_switch Clock_switch;
}RCC_OscInitTypeDef;

typedef enum{
	 PLL_input_clock_x_2=(u8)0,
	 PLL_input_clock_x_3=(u8)1,
	 PLL_input_clock_x_4=(u8)2,
	 PLL_input_clock_x_5=(u8)3,
	 PLL_input_clock_x_6=(u8)4,
	 PLL_input_clock_x_7=(u8)5,
	 PLL_input_clock_x_8=(u8)6,
	 PLL_input_clock_x_9=(u8)7,
	 PLL_input_clock_x_10=(u8)8,
	 PLL_input_clock_x_11=(u8)9,
	 PLL_input_clock_x_12=(u8)10,
	 PLL_input_clock_x_13=(u8)11,
	 PLL_input_clock_x_14=(u8)12,
	 PLL_input_clock_x_15=(u8)13,
	 PLL_input_clock_x_16=(u8)14,
}RCC_PLL_CONFIG;


typedef enum{
	HSI_oscillator_clock   =(u8)0,
	HSE_oscillator_clock   =(u8)1,
	HSE_clock_divided_by_2 =(u8)2,
}PLL_CLKSource;

typedef struct{
	PLL_CLKSource CLKSource;
	RCC_PLL_CONFIG MUL_Value;
}PLL_CLKDEf;


typedef enum{
	APB_divided_by_1	=(u8)0,
	APB_divided_by_2	=(u8)4,
	APB_divided_by_4	=(u8)5,
	APB_divided_by_8	=(u8)6,
	APB_divided_by_16	=(u8)7
}APB_prescaler;

typedef enum{
	AHB_divided_by_1	=(u8)0,
	AHB_divided_by_2	=(u8)8,
	AHB_divided_by_4	=(u8)9,
	AHB_divided_by_8	=(u8)10,
	AHB_divided_by_16	=(u8)11,
	AHB_divided_by_64	=(u8)12,
	AHB_divided_by_128	=(u8)13,
	AHB_divided_by_256	=(u8)14,
	AHB_divided_by_512	=(u8)15,
}AHB_prescaler;



typedef enum{
	 RCC_AHBENR=0,
	 RCC_APB2ENR=1,
	 RCC_APB1ENR=2
}Bus_TypeDef;

typedef struct{
	Bus_TypeDef Bus_Type;
	u32 Value;
}Enable_Clock_values;

typedef struct{
	AHB_prescaler AHBCLKDivider;
	APB_prescaler APB1CLKDivider;
	APB_prescaler APB2CLKDivider;
}RCC_ClkInitTypeDef;
/******************************* Data Type Declarations End **************************/

/******************************* Software interfaces Declarations Start **************/
HAL_Error_State HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_Init);
HAL_Error_State HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_CLK_Init);
HAL_Error_State HAL_RCC_ClockEnable(Enable_Clock_values *Clock_values);
HAL_Error_State HAL_RCC_ClockDisable(Enable_Clock_values *Clock_values);
void HAL_RCC_PLLConfig(PLL_CLKDEf *PLL_Value);
/******************************* Software interfaces Declarations End ****************/

#endif /* HAL_DRIVERS_RCC_STM32F103XX_HAL_RCC_H_ */
