################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL_Drivers/WIFI/WIFI.c 

OBJS += \
./Src/HAL_Drivers/WIFI/WIFI.o 

C_DEPS += \
./Src/HAL_Drivers/WIFI/WIFI.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL_Drivers/WIFI/%.o Src/HAL_Drivers/WIFI/%.su Src/HAL_Drivers/WIFI/%.cyclo: ../Src/HAL_Drivers/WIFI/%.c Src/HAL_Drivers/WIFI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-HAL_Drivers-2f-WIFI

clean-Src-2f-HAL_Drivers-2f-WIFI:
	-$(RM) ./Src/HAL_Drivers/WIFI/WIFI.cyclo ./Src/HAL_Drivers/WIFI/WIFI.d ./Src/HAL_Drivers/WIFI/WIFI.o ./Src/HAL_Drivers/WIFI/WIFI.su

.PHONY: clean-Src-2f-HAL_Drivers-2f-WIFI

