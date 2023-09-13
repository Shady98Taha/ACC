################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL_Drivers/RCC/STM32F103xx_HAL_RCC.c 

OBJS += \
./Src/MCAL_Drivers/RCC/STM32F103xx_HAL_RCC.o 

C_DEPS += \
./Src/MCAL_Drivers/RCC/STM32F103xx_HAL_RCC.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL_Drivers/RCC/%.o Src/MCAL_Drivers/RCC/%.su Src/MCAL_Drivers/RCC/%.cyclo: ../Src/MCAL_Drivers/RCC/%.c Src/MCAL_Drivers/RCC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-MCAL_Drivers-2f-RCC

clean-Src-2f-MCAL_Drivers-2f-RCC:
	-$(RM) ./Src/MCAL_Drivers/RCC/STM32F103xx_HAL_RCC.cyclo ./Src/MCAL_Drivers/RCC/STM32F103xx_HAL_RCC.d ./Src/MCAL_Drivers/RCC/STM32F103xx_HAL_RCC.o ./Src/MCAL_Drivers/RCC/STM32F103xx_HAL_RCC.su

.PHONY: clean-Src-2f-MCAL_Drivers-2f-RCC

