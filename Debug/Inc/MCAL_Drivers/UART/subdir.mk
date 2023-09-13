################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/MCAL_Drivers/UART/STM32F103xx_HAL_UART_Cfg.c 

OBJS += \
./Inc/MCAL_Drivers/UART/STM32F103xx_HAL_UART_Cfg.o 

C_DEPS += \
./Inc/MCAL_Drivers/UART/STM32F103xx_HAL_UART_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/MCAL_Drivers/UART/%.o Inc/MCAL_Drivers/UART/%.su Inc/MCAL_Drivers/UART/%.cyclo: ../Inc/MCAL_Drivers/UART/%.c Inc/MCAL_Drivers/UART/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-MCAL_Drivers-2f-UART

clean-Inc-2f-MCAL_Drivers-2f-UART:
	-$(RM) ./Inc/MCAL_Drivers/UART/STM32F103xx_HAL_UART_Cfg.cyclo ./Inc/MCAL_Drivers/UART/STM32F103xx_HAL_UART_Cfg.d ./Inc/MCAL_Drivers/UART/STM32F103xx_HAL_UART_Cfg.o ./Inc/MCAL_Drivers/UART/STM32F103xx_HAL_UART_Cfg.su

.PHONY: clean-Inc-2f-MCAL_Drivers-2f-UART

