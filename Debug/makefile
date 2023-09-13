################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/PARSER/subdir.mk
-include Src/MCAL_Drivers/UART/subdir.mk
-include Src/MCAL_Drivers/TIMERS/subdir.mk
-include Src/MCAL_Drivers/RCC/subdir.mk
-include Src/MCAL_Drivers/PWM/subdir.mk
-include Src/MCAL_Drivers/GPIO/subdir.mk
-include Src/MCAL_Drivers/FlashDriver/subdir.mk
-include Src/HAL_Drivers/WIFI/subdir.mk
-include Src/HAL_Drivers/Ultrasonic/subdir.mk
-include Src/HAL_Drivers/DC_Motor/subdir.mk
-include Src/CortexM3/subdir.mk
-include Src/subdir.mk
-include Inc/MCAL_Drivers/UART/subdir.mk
-include Inc/MCAL_Drivers/TIMERS/subdir.mk
-include Inc/MCAL_Drivers/PWM/subdir.mk
-include Inc/MCAL_Drivers/GPIO/subdir.mk
-include Inc/MCAL_Drivers/FLASH_DRIVER/subdir.mk
-include Inc/HAL_Drivers/WIFI/subdir.mk
-include Inc/HAL_Drivers/Ultrasonic/subdir.mk
-include Inc/HAL_Drivers/DC_MOTOR/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Fix_Drivers
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Fix_Drivers.elf \

MAP_FILES += \
Fix_Drivers.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Fix_Drivers.list \

OBJCOPY_HEX += \
Fix_Drivers.hex \


# All Target
all: main-build

# Main-build Target
main-build: Fix_Drivers.elf secondary-outputs

# Tool invocations
Fix_Drivers.elf Fix_Drivers.map: $(OBJS) $(USER_OBJS) D:\Arm\ Workspace\Fix_Drivers\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Fix_Drivers.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Arm Workspace\Fix_Drivers\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Fix_Drivers.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Fix_Drivers.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Fix_Drivers.list"
	@echo 'Finished building: $@'
	@echo ' '

Fix_Drivers.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Fix_Drivers.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Fix_Drivers.elf Fix_Drivers.hex Fix_Drivers.list Fix_Drivers.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
