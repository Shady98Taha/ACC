################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL_Drivers/DC_Motor/DCMotor_Program.c 

OBJS += \
./Src/HAL_Drivers/DC_Motor/DCMotor_Program.o 

C_DEPS += \
./Src/HAL_Drivers/DC_Motor/DCMotor_Program.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL_Drivers/DC_Motor/%.o Src/HAL_Drivers/DC_Motor/%.su Src/HAL_Drivers/DC_Motor/%.cyclo: ../Src/HAL_Drivers/DC_Motor/%.c Src/HAL_Drivers/DC_Motor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-HAL_Drivers-2f-DC_Motor

clean-Src-2f-HAL_Drivers-2f-DC_Motor:
	-$(RM) ./Src/HAL_Drivers/DC_Motor/DCMotor_Program.cyclo ./Src/HAL_Drivers/DC_Motor/DCMotor_Program.d ./Src/HAL_Drivers/DC_Motor/DCMotor_Program.o ./Src/HAL_Drivers/DC_Motor/DCMotor_Program.su

.PHONY: clean-Src-2f-HAL_Drivers-2f-DC_Motor

