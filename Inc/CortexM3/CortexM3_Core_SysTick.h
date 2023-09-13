/**
 ******************************************************************************
 * @file           : CortexM3_Core_Systick.h
 * @author         : Shady Taha
 * @brief          : System Control Block header file
 ******************************************************************************
*/

#ifndef CORTEXM3_CORTEXM3_CORE_SYSTICK_H_
#define CORTEXM3_CORTEXM3_CORE_SYSTICK_H_

/******************************* Includes Start **************************************/
#include "Library/STD_TYPES.h"
#include "Library/BIT_MATH.h"
#include "Library/CORTEXM3_Core_Def.h"
/******************************* Includes End ****************************************/

/******************************* Macro Declarations Start ****************************/

#define SYSTICK_BASE (0xE000E010)
#define SYSTICK ((SYSTICK_TypeDef*)SYSTICK_BASE)


/*************************SYST_CSRbits start*******************************/
#define COUNTFLAG 16
#define COUNTFLAG_MSK (1<<COUNTFLAG)

#define CLKSOURCE 2
#define CLKSOURCE__MSK (1<<CLKSOURCE)

#define TICKINT 1
#define TICKINT_MSK (1<<TICKINT)

#define ENABLE 0
#define ENABLE_MSK (1<<ENABLE)
/*************************SYST_CSRbits END*******************************/
#define SysTick_RELOAD 0
#define SysTick_RELOAD_MSK (0xFFFFFFF << SysTick_RELOAD)

/******************************* Macro Declarations End ******************************/

/******************************* Macro functions Declarations Start ******************/
/******************************* Macro functions Declarations End ********************/

/******************************* Data Type Declarations Start ************************/
typedef struct{
	u32 CSR;
	u32 RVR;
	u32 CVR;
	u32 CALIB;
}SYSTICK_TypeDef;



typedef enum{
	TICKINT_OFF	=(u8)0,
	TICKINT_ON	=(u8)1
}TICKINT_TypeDef;

typedef enum{
	CLKSOURCE_external_clock	=(u8)0,
	CLKSOURCE_processor_clock	=(u8)1
}CLKSOURCE_TypeDef;

typedef struct{
	CLKSOURCE_TypeDef CLOCKSOURCE;
	u32 Delay_Ticks;
}SYSTICK_Init;

typedef enum{
	SysTick_Single_Interval=0,
	SysTick_Periodic_Interval=1
}SysTick_ModeDef;
/******************************* Data Type Declarations End **************************/

/******************************* Software interfaces Declarations Start **************/
Core_Error_State Systick_Init(SYSTICK_Init *Sys_Tick_init);
void Systick_DEInit(void);
void Systick_WaitBlocking(u32 Delay_value);
void Systick_SingleInterval(u32 Delay_Ticks,void(* function)());
void Systick_PeriodicInterval(u32 Delay_Ticks, void(*function)());
u32 SysTick_GetRemainingTicks(void);
/******************************* Software interfaces Declarations End ****************/

#endif /* CORTEXM3_CORTEXM3_CORE_SYSTICK_H_ */
