################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include MCAL/subdir.mk
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
USART_Project.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
USART_Project.list \

OBJCOPY_HEX += \
USART_Project.hex \

OBJCOPY_BIN += \
USART_Project.bin \


# All Target
all:
	+@make --no-print-directory main-build && make --no-print-directory post-build

# Main-build Target
main-build: USART_Project.elf secondary-outputs

# Tool invocations
USART_Project.elf: $(OBJS) $(USER_OBJS) D:\kerollos\ diploma\ stuff\Assignment\ Codes\Unit\ 8\Lectures\UART\ Lecture\STM32\ Project\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "USART_Project.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\kerollos diploma stuff\Assignment Codes\Unit 8\Lectures\UART Lecture\STM32 Project\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="USART_Project.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

USART_Project.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "USART_Project.list"
	@echo 'Finished building: $@'
	@echo ' '

USART_Project.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "USART_Project.hex"
	@echo 'Finished building: $@'
	@echo ' '

USART_Project.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "USART_Project.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	cp  USART_Project.elf  "USART_Project.axf"
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
