/*
 * STM32F103xx_HAL_GPIO_Cfg.h
 *
 *  Created on: Jul 19, 2023
 *      Author: shady
 */

#ifndef HAL_DRIVERS_GPIO_STM32F103XX_HAL_GPIO_CFG_H_
#define HAL_DRIVERS_GPIO_STM32F103XX_HAL_GPIO_CFG_H_




typedef enum{
	Analog_mode					=0,
	Floating_input				=1,
	Input_pullup_pull_down		=2,
	Reserved					=3 /*not allowed*/
}input_mode_typedef;

typedef enum{
	push_pull				=0,
	Open_drain				=1,
	AF_Push_pull			=2,
	AF_Open_drain			=3
}output_mode_typedef;


typedef enum{
	InputMode_AnalogMode						=0,
	Outputmodespeed10MHz_PushPull				=1,
	Outputmodespeed2MHz_PushPull				=2,
	Outputmodespeed50MHz_PushPull				=3,
	InputMode_FloatingInput						=4,
	Outputmodespeed10MHz_Open_drain				=5,
	Outputmodespeed2MHz_Open_drain				=6,
	Outputmodespeed50MHz_Open_drain				=7,
	InputMode_Input_pullup_pull_down			=8,
	Outputmodespeed10MHz_AF_Push_pull			=9,
	Outputmodespeed2MHz_AF_Push_pull			=10,
	Outputmodespeed50MHz_AF_Push_pull			=11,
	InputMode_Reserved							=12,
	Outputmodespeed10MHz_AF_Open_drain			=13,
	Outputmodespeed2MHz_AF_Open_drain			=14,
	Outputmodespeed50MHz_AF_Open_drain			=15
}Port_mode;


typedef enum
{
	PINA0	=0,
	PINA1	=1,
	PINA2	=2,
	PINA3	=3,
	PINA4	=4,
	PINA5	=5,
	PINA6	=6,
	PINA7	=7,
	PINA8	=8,
	PINA9	=9,
	PINA10	=10,
	PINA11	=11,
	PINA12	=12,
	PINA13	=13,
	PINA14	=14,
	PINA15	=15,
	PINB0	=16,
	PINB1	=17,
	PINB2	=18,
	PINB3	=19,
	PINB4	=20,
	PINB5	=21,
	PINB6	=22,
	PINB7	=23,
	PINB8	=24,
	PINB9	=25,
	PINB10	=26,
	PINB11	=27,
	PINB12	=28,
	PINB13	=29,
	PINB14	=30,
	PINB15	=31,
	PINC13	=32,
	PINC14	=33,
	PINC15	=34
}GPIO_PINS;

typedef enum{
	GPIO_LOW	=0,
	GPIO_HIGH	=1
}GPIO_Value;

typedef struct
{
	GPIO_PINS Pins;
	Port_mode Mode;
}PIN_State;

#endif /* HAL_DRIVERS_GPIO_STM32F103XX_HAL_GPIO_CFG_H_ */
