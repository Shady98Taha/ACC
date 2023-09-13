/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Shady Taha
 * @brief          : Main program body
 ******************************************************************************
 */






#include"Library/STD_TYPES.h"
#include"Library/BIT_MATH.h"
#include"MCAL_Drivers/GPIO/STM32F103xx_HAL_GPIO_Interface.h"
#include"CortexM3/CortexM3_Core_SysTick.h"
#include"MCAL_Drivers/RCC/STM32F103xx_HAL_RCC.h"
#include"MCAL_Drivers/TIMERS/STM32F103xx_HAL_TIMERS_Interface.h"
#include"HAL_Drivers/Ultrasonic/Ultrasonic_Initerface.h"
#include"HAL_Drivers/DC_MOTOR/DcMotor_Interface.h"


RCC_OscInitTypeDef RCC_Init={RCC_OSCILLATORTYPE_HSI,RCC_HSE_OFF,RCC_LSE_OFF,RCC_HSI_ON,RCC_LSI_OFF,HSI};;
RCC_ClkInitTypeDef RCC_CLK_Init={AHB_divided_by_1, APB_divided_by_1,APB_divided_by_1};;
Enable_Clock_values Clock_values={RCC_APB2ENR,IOPAEN};
Enable_Clock_values Clock_values1={RCC_APB2ENR,IOPBEN};
Enable_Clock_values Clock_values2={RCC_APB1ENR,TIMER_2};
Enable_Clock_values Clock_values3={RCC_APB1ENR,TIMER_3};
Enable_Clock_values Clock_values4={RCC_APB1ENR,TIMER_4};
SYSTICK_Init Sys_Tick_init={CLKSOURCE_external_clock,15};
extern PIN_State State;
extern PIN_State State2;
extern PIN_State State3;
extern PIN_State State4;
extern PIN_State State5;
extern PIN_State State6;
extern PWM_init TimersPwmInit;
extern PWM_init TimersPwmInit2;
int main(void)
{

	u16 Receive_distance=0;

	/*initialize the RCC*/
	HAL_RCC_OscConfig(&RCC_Init);
	HAL_RCC_ClockConfig(&RCC_CLK_Init);

	/* set clock of GPIOA*/
	HAL_RCC_ClockEnable(&Clock_values);

	/* set clock of GPIOB*/
	HAL_RCC_ClockEnable(&Clock_values1);

	/*set clock of TIMER2 ICU */
	HAL_RCC_ClockEnable(&Clock_values2);

	/*set clock of TIMER3 PWM 1*/
	HAL_RCC_ClockEnable(&Clock_values3);

	/*set clock of TIMER4 PWM 2*/
	HAL_RCC_ClockEnable(&Clock_values4);

	/*initialize sys-tick timer*/
	Systick_Init(&Sys_Tick_init);

	/*select configuration of trigger pin*/
	GPIO_VoidSetPinDirection(&State);

	/*select configuration of ICU pin*/
	GPIO_VoidSetPinDirection(&State2);

	/*select configuration of PWM1 pin*/
	GPIO_VoidSetPinDirection(&State3);

	/*select configuration of PWM1 direction pin*/
	GPIO_VoidSetPinDirection(&State5);

	/*select configuration of PWM1 direction pin*/
	GPIO_VoidSetPinDirection(&State6);

	/*select configuration of PWM2 pin*/
	GPIO_VoidSetPinDirection(&State4);

	/*Ultra-sonic sensor initialization*/
	Ultrasonic_VoidInit();

	/*initialize PWM 1*/
	DC_MotorVoidInit(TimersPwmInit,1000,100);
	/*initialize PWM 2*/
	DC_MotorVoidInit(TimersPwmInit2,1000,100);

	while(1)
	{
		Receive_distance=Ultrasonic_readDistance();
		if(Receive_distance <= 1)
		{
			DC_MOTOR_ON(0, TIM3, CC1,MOTOR_Forward);
			DC_MOTOR_ON(0, TIM4, CC1,MOTOR_Forward);

		}else if(Receive_distance > 1 && Receive_distance <= 3)
		{
			DC_MOTOR_ON(20, TIM3, CC1,MOTOR_Forward);
			DC_MOTOR_ON(20, TIM4, CC1,MOTOR_Forward);
		}else if(Receive_distance > 3 && Receive_distance <= 5)
		{
			DC_MOTOR_ON(50, TIM3, CC1,MOTOR_Forward);
			DC_MOTOR_ON(50, TIM4, CC1,MOTOR_Forward);
		}else if(Receive_distance > 5 && Receive_distance <= 6)
		{
			DC_MOTOR_ON(80, TIM3, CC1,MOTOR_Forward);
			DC_MOTOR_ON(80, TIM4, CC1,MOTOR_Forward);
		}else if(Receive_distance > 6)
		{
			DC_MOTOR_ON(100, TIM3, CC1,MOTOR_Forward);
			DC_MOTOR_ON(100, TIM4, CC1,MOTOR_Forward);
		}
		Systick_WaitBlocking(1000000);
	}
}












#if 0
#include"Library/STD_TYPES.h"
#include"Library/BIT_MATH.h"
#include"MCAL_Drivers/GPIO/STM32F103xx_HAL_GPIO_Interface.h"
#include"CortexM3/CortexM3_Core_SysTick.h"
#include"MCAL_Drivers/RCC/STM32F103xx_HAL_RCC.h"
#include"MCAL_Drivers/TIMERS/STM32F103xx_HAL_TIMERS_Interface.h"
#include"HAL_Drivers/Ultrasonic/Ultrasonic_Initerface.h"
#include"HAL_Drivers/DC_MOTOR/DcMotor_Interface.h"


RCC_OscInitTypeDef RCC_Init={RCC_OSCILLATORTYPE_HSI,RCC_HSE_OFF,RCC_LSE_OFF,RCC_HSI_ON,RCC_LSI_OFF,HSI};;
RCC_ClkInitTypeDef RCC_CLK_Init={AHB_divided_by_1, APB_divided_by_1,APB_divided_by_1};;
Enable_Clock_values Clock_values={RCC_APB2ENR,IOPAEN};
Enable_Clock_values Clock_values1={RCC_APB2ENR,IOPBEN};
Enable_Clock_values Clock_values2={RCC_APB1ENR,TIMER_2};
Enable_Clock_values Clock_values3={RCC_APB1ENR,TIMER_3};
Enable_Clock_values Clock_values4={RCC_APB1ENR,TIMER_4};
SYSTICK_Init Sys_Tick_init={CLKSOURCE_external_clock,15};
extern PIN_State State;
extern PIN_State State2;
extern PIN_State State3;
extern PIN_State State4;
extern PIN_State State5;
extern PIN_State State6;
extern PWM_init TimersPwmInit;
extern PWM_init TimersPwmInit2;
int main(void)
{
	HAL_RCC_OscConfig(&RCC_Init);
	HAL_RCC_ClockConfig(&RCC_CLK_Init);

	/*initialize sys-tick timer*/
	Systick_Init(&Sys_Tick_init);

	/* set clock of GPIOA*/
	HAL_RCC_ClockEnable(&Clock_values);

	/* set clock of GPIOB*/
	HAL_RCC_ClockEnable(&Clock_values1);

	/*set clock of TIMER3 PWM 1*/
	HAL_RCC_ClockEnable(&Clock_values3);

	/*set clock of TIMER4 PWM 2*/
	HAL_RCC_ClockEnable(&Clock_values4);

	/*select configuration of PWM1 pin*/
	GPIO_VoidSetPinDirection(&State3);

	/*select configuration of PWM1 direction pin*/
	GPIO_VoidSetPinDirection(&State5);

	/*select configuration of PWM1 direction pin*/
	GPIO_VoidSetPinDirection(&State6);

	/*select configuration of PWM2 pin*/
	GPIO_VoidSetPinDirection(&State4);

	/*initialize PWM 1*/
	DC_MotorVoidInit(TimersPwmInit,1000,100);
	/*initialize PWM 2*/
	DC_MotorVoidInit(TimersPwmInit2,1000,100);
	while(1)
	{
		DC_MOTOR_ON(0, TIM3, CC1,MOTOR_Forward);
		DC_MOTOR_ON(0, TIM4, CC1,MOTOR_Forward);
	}
}
/********************UART & Flash driver & GPIO TEST******************************/

#include"CortexM3/CORTEXM3_Interface.h"
#include "MCAL_Drivers/RCC/STM32F103xx_HAL_RCC.h"
#include "MCAL_Drivers/GPIO/STM32F103xx_HAL_GPIO_Interface.h"
#include "MCAL_Drivers/UART/STM32F103xx_HAL_UART_Interface.h"
#include "MCAL_Drivers/FLASH_DRIVER/STM32F103xx_HAL_FPEC_Interface.h"
RCC_OscInitTypeDef RCC_Init={RCC_OSCILLATORTYPE_HSE,RCC_HSE_ON,RCC_LSE_OFF,RCC_HSI_OFF,RCC_LSI_OFF,HSE};
RCC_ClkInitTypeDef RCC_CLK_Init={AHB_divided_by_1, APB_divided_by_1,APB_divided_by_1};
Enable_Clock_values Clock_values={RCC_APB2ENR,IOPAEN};
Enable_Clock_values Clock_values2={RCC_APB2ENR,UART1EN};
u32 counter=0;
extern PIN_State State;
extern PIN_State State1;
extern PIN_State State2;
u16 arr[2]={1,0}; /*because flash write 16 bit in one time*/
int main(void)
{
	HAL_RCC_OscConfig(&RCC_Init);
	HAL_RCC_ClockConfig(&RCC_CLK_Init);
	HAL_RCC_ClockEnable(&Clock_values);
	HAL_RCC_ClockEnable(&Clock_values2);
	MUSART1_VoidInit();
	FPEC_voidInit();
	GPIO_VoidSetPinDirection(&State);
	GPIO_VoidSetPinDirection(&State1);
	GPIO_VoidSetPinDirection(&State2);
	FPEC_u8WriteFlash(0x8001000,arr,2);
	while(1)
	{

		if(MUSART1_VoidReceive()==1)
		{
			GPIO_VoidSetPinValue(PINA0,GPIO_HIGH);
			MUSART1_VoidTransmit(1);
		}

	}

}


















/***************************************Ultra-sonic sensor Test****************************/


#include"Library/STD_TYPES.h"
#include"Library/BIT_MATH.h"
#include"MCAL_Drivers/GPIO/STM32F103xx_HAL_GPIO_Interface.h"
#include"CortexM3/CortexM3_Core_SysTick.h"
#include"MCAL_Drivers/RCC/STM32F103xx_HAL_RCC.h"
#include"HAL_Drivers/Ultrasonic/Ultrasonic_Initerface.h"

RCC_OscInitTypeDef RCC_Init={RCC_OSCILLATORTYPE_HSI,RCC_HSE_OFF,RCC_LSE_OFF,RCC_HSI_ON,RCC_LSI_OFF,HSI};;
RCC_ClkInitTypeDef RCC_CLK_Init={AHB_divided_by_1, APB_divided_by_1,APB_divided_by_1};;
Enable_Clock_values Clock_values={RCC_APB2ENR,IOPAEN};
Enable_Clock_values Clock_values2={RCC_APB1ENR,TIMER_2};
SYSTICK_Init Sys_Tick_init={CLKSOURCE_external_clock,15};
extern PIN_State State;
extern PIN_State State2;
int main(void)
{
	u16 Receive_distance=0;

	/*initialize the RCC*/
	HAL_RCC_OscConfig(&RCC_Init);
	HAL_RCC_ClockConfig(&RCC_CLK_Init);

	/* set clock of GPIO*/
	HAL_RCC_ClockEnable(&Clock_values);

	/*set clock of TIMER2*/
	HAL_RCC_ClockEnable(&Clock_values2);

	/*initialize sys-tick timer*/
	Systick_Init(&Sys_Tick_init);

	/*select configuration of trigger pin*/
	GPIO_VoidSetPinDirection(&State);

	/*select configuration of ICU pin*/
	GPIO_VoidSetPinDirection(&State2);

	/*Ultra-sonic sensor initialization*/
	Ultrasonic_VoidInit();

	while(1)
	{
		Receive_distance=Ultrasonic_readDistance();
		if(Receive_distance==0)
		{

		}

	}
}

#endif
