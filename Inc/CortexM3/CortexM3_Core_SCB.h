/**
 ******************************************************************************
 * @file           : CortexM3_Core_SCB
 * @author         : Shady Taha
 * @brief          : System Control Block header file
 ******************************************************************************
*/

#ifndef CORTEXM3_CORE_SCB_H_
#define CORTEXM3_CORE_SCB_H_

/******************************* Includes Start **************************************/
#include "Library/STD_TYPES.h"
#include "Library/BIT_MATH.h"
/******************************* Includes End ****************************************/

/******************************* Macro Declarations Start ****************************/
#define SCB_Base (0xE000ED00UL)
#define SCB ((SCB_Types*)SCB_Base)





#define SCB_AIRCR_PRIGROUP_POS		8
#define SCB_AIRCR_PRIGROUP_MSK      (0x7UL <<SCB_AIRCR_PRIGROUP_POS)


#define SCB_AIRCR_VECTKEYSTAT_POS	16
#define SCB_AIRCR_VECTKETSTAT_MSK   (0xFFFFUL<<SCB_AIRCR_VECTKEYSTAT_POS)

#define VECTKEY 0x5FA
/******************************* Macro Declarations End ******************************/

/******************************* Macro functions Declarations Start ******************/
/******************************* Macro functions Declarations End ********************/

/******************************* Data Type Declarations Start ************************/
typedef struct{
	volatile u32 CPUID;
	volatile u32 ICSR;
	volatile u32 VTOR;
	volatile u32 AIRCR;
	volatile u32 SCR;
	volatile u32 CCR;
	volatile u32 SHPR1;
	volatile u32 SHPR2;
	volatile u32 SHPR3;
	volatile u32 SHCSR;
	volatile u32 CFSR;
}SCB_Types;


typedef enum{
	SCB_PRIORITYGROUP_0		=7,
	SCB_PRIORITYGROUP_1		=6,
	SCB_PRIORITYGROUP_2		=5,
	SCB_PRIORITYGROUP_3		=4,
	SCB_PRIORITYGROUP_4		=3
}SCB_PRIORITYGROUP_Types;
/******************************* Data Type Declarations End **************************/

/******************************* Software interfaces Declarations Start **************/
void SCB_SetPriorityGrouping(SCB_PRIORITYGROUP_Types PriorityGroup);
u32 SCB_GetPriorityGrouping(void);
/******************************* Software interfaces Declarations End ****************/


#endif /* CORTEXM3_CORE_SCB_H_ */
