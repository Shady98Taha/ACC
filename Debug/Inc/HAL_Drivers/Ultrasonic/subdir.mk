################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/HAL_Drivers/Ultrasonic/Ultrasonic_cf.c 

OBJS += \
./Inc/HAL_Drivers/Ultrasonic/Ultrasonic_cf.o 

C_DEPS += \
./Inc/HAL_Drivers/Ultrasonic/Ultrasonic_cf.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/HAL_Drivers/Ultrasonic/%.o Inc/HAL_Drivers/Ultrasonic/%.su Inc/HAL_Drivers/Ultrasonic/%.cyclo: ../Inc/HAL_Drivers/Ultrasonic/%.c Inc/HAL_Drivers/Ultrasonic/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-HAL_Drivers-2f-Ultrasonic

clean-Inc-2f-HAL_Drivers-2f-Ultrasonic:
	-$(RM) ./Inc/HAL_Drivers/Ultrasonic/Ultrasonic_cf.cyclo ./Inc/HAL_Drivers/Ultrasonic/Ultrasonic_cf.d ./Inc/HAL_Drivers/Ultrasonic/Ultrasonic_cf.o ./Inc/HAL_Drivers/Ultrasonic/Ultrasonic_cf.su

.PHONY: clean-Inc-2f-HAL_Drivers-2f-Ultrasonic

