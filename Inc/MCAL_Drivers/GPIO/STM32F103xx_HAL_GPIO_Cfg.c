/*
 * STM32F103xx_HAL_GPIO_Cfg.c
 *
 *  Created on: Jul 19, 2023
 *      Author: shady
 */

#include"MCAL_Drivers/GPIO/STM32F103xx_HAL_GPIO_Cfg.h"
/*
 **********************    GPIO MODES    ****************************
	InputMode_AnalogMode
	Outputmodespeed2MHz_PushPull
	Outputmodespeed50MHz_PushPull
	InputMode_FloatingInput
	Outputmodespeed10MHz_Open_drain
	Outputmodespeed2MHz_Open_drain
	Outputmodespeed50MHz_Open_drain
	InputMode_Input_pullup_pull_down
	Outputmodespeed10MHz_AF_Push_pull
	Outputmodespeed2MHz_AF_Push_pull
	Outputmodespeed50MHz_AF_Push_pull
	InputMode_Reserved
	Outputmodespeed10MHz_AF_Open_drain
	Outputmodespeed2MHz_AF_Open_drain
	Outputmodespeed50MHz_AF_Open_drain
 ************************************************************************/


PIN_State State={PINA0,Outputmodespeed2MHz_PushPull};
PIN_State State2={PINA1,Outputmodespeed2MHz_AF_Push_pull};
PIN_State State3={PINA6,Outputmodespeed2MHz_AF_Push_pull};
PIN_State State4={PINB6,Outputmodespeed2MHz_AF_Push_pull};
PIN_State State5={PINA7,Outputmodespeed2MHz_PushPull};
PIN_State State6={PINA8,Outputmodespeed2MHz_PushPull};
