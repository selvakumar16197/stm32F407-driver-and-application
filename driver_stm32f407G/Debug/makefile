################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include driver/Src/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
driver_stm32f407G.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
driver_stm32f407G.list \

OBJCOPY_BIN += \
driver_stm32f407G.bin \


# All Target
all: driver_stm32f407G.elf secondary-outputs

# Tool invocations
driver_stm32f407G.elf: $(OBJS) $(USER_OBJS) D:\workspace\ STM\driver_stm32f407G\STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "driver_stm32f407G.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\workspace STM\driver_stm32f407G\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="driver_stm32f407G.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

driver_stm32f407G.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "driver_stm32f407G.list"
	@echo 'Finished building: $@'
	@echo ' '

driver_stm32f407G.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "driver_stm32f407G.bin"
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
