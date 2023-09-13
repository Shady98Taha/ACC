################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/HAL_Drivers/DC_MOTOR/DcMotor_cfg.c 

OBJS += \
./Inc/HAL_Drivers/DC_MOTOR/DcMotor_cfg.o 

C_DEPS += \
./Inc/HAL_Drivers/DC_MOTOR/DcMotor_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/HAL_Drivers/DC_MOTOR/%.o Inc/HAL_Drivers/DC_MOTOR/%.su Inc/HAL_Drivers/DC_MOTOR/%.cyclo: ../Inc/HAL_Drivers/DC_MOTOR/%.c Inc/HAL_Drivers/DC_MOTOR/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-HAL_Drivers-2f-DC_MOTOR

clean-Inc-2f-HAL_Drivers-2f-DC_MOTOR:
	-$(RM) ./Inc/HAL_Drivers/DC_MOTOR/DcMotor_cfg.cyclo ./Inc/HAL_Drivers/DC_MOTOR/DcMotor_cfg.d ./Inc/HAL_Drivers/DC_MOTOR/DcMotor_cfg.o ./Inc/HAL_Drivers/DC_MOTOR/DcMotor_cfg.su

.PHONY: clean-Inc-2f-HAL_Drivers-2f-DC_MOTOR

