################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/gpio.c \
../MCAL/rcc.c \
../MCAL/usart.c 

OBJS += \
./MCAL/gpio.o \
./MCAL/rcc.o \
./MCAL/usart.o 

C_DEPS += \
./MCAL/gpio.d \
./MCAL/rcc.d \
./MCAL/usart.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/gpio.o: ../MCAL/gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/rcc.o: ../MCAL/rcc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/rcc.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/usart.o: ../MCAL/usart.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/usart.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

