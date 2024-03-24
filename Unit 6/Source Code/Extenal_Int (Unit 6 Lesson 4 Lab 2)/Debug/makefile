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
Extenal_Int.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Extenal_Int.list \

OBJCOPY_BIN += \
Extenal_Int.bin \


# All Target
all: Extenal_Int.elf secondary-outputs

# Tool invocations
Extenal_Int.elf: $(OBJS) $(USER_OBJS) D:\kerollos\ diploma\ stuff\Assignment\ Codes\Unit\ 6\Source\ Code\Extenal_Int\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "Extenal_Int.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\kerollos diploma stuff\Assignment Codes\Unit 6\Source Code\Extenal_Int\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Extenal_Int.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Extenal_Int.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Extenal_Int.list"
	@echo 'Finished building: $@'
	@echo ' '

Extenal_Int.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Extenal_Int.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
