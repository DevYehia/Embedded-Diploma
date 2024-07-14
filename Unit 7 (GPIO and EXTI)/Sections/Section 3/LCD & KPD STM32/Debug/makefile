################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
LCD.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
LCD.list \

OBJCOPY_HEX += \
LCD.hex \

OBJCOPY_BIN += \
LCD.bin \


# All Target
all: LCD.elf secondary-outputs

# Tool invocations
LCD.elf: $(OBJS) $(USER_OBJS) D:\kerollos\ diploma\ stuff\Assignment\ Codes\Unit\ 7\Sections\Section\ 3\LCD\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "LCD.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\kerollos diploma stuff\Assignment Codes\Unit 7\Sections\Section 3\LCD\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="LCD.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

LCD.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "LCD.list"
	@echo 'Finished building: $@'
	@echo ' '

LCD.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "LCD.hex"
	@echo 'Finished building: $@'
	@echo ' '

LCD.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "LCD.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
