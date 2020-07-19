################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/Src/stm32f407xx_gpiodriver.c \
../driver/Src/stm32f407xx_rcc_driver.c \
../driver/Src/stm32f407xx_spidriver.c \
../driver/Src/stm32f407xx_uartdriver.c 

OBJS += \
./driver/Src/stm32f407xx_gpiodriver.o \
./driver/Src/stm32f407xx_rcc_driver.o \
./driver/Src/stm32f407xx_spidriver.o \
./driver/Src/stm32f407xx_uartdriver.o 

C_DEPS += \
./driver/Src/stm32f407xx_gpiodriver.d \
./driver/Src/stm32f407xx_rcc_driver.d \
./driver/Src/stm32f407xx_spidriver.d \
./driver/Src/stm32f407xx_uartdriver.d 


# Each subdirectory must supply rules for building sources it contributes
driver/Src/stm32f407xx_gpiodriver.o: ../driver/Src/stm32f407xx_gpiodriver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"D:/workspace STM/driver_stm32f407G/driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"driver/Src/stm32f407xx_gpiodriver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
driver/Src/stm32f407xx_rcc_driver.o: ../driver/Src/stm32f407xx_rcc_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"D:/workspace STM/driver_stm32f407G/driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"driver/Src/stm32f407xx_rcc_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
driver/Src/stm32f407xx_spidriver.o: ../driver/Src/stm32f407xx_spidriver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"D:/workspace STM/driver_stm32f407G/driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"driver/Src/stm32f407xx_spidriver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
driver/Src/stm32f407xx_uartdriver.o: ../driver/Src/stm32f407xx_uartdriver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"D:/workspace STM/driver_stm32f407G/driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"driver/Src/stm32f407xx_uartdriver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

