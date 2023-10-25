################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/Q_BSP.c 

OBJS += \
./Inc/Q_BSP.o 

C_DEPS += \
./Inc/Q_BSP.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o Inc/%.su Inc/%.cyclo: ../Inc/%.c Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DSTM32H743ZITx -DSTM32 -DSTM32H7SINGLE -DSTM32H7 -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Inc

clean-Inc:
	-$(RM) ./Inc/Q_BSP.cyclo ./Inc/Q_BSP.d ./Inc/Q_BSP.o ./Inc/Q_BSP.su

.PHONY: clean-Inc

