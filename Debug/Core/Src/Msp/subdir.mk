################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Msp/Msp.c \
../Core/Src/Msp/stm32f1xx_hal_msp.c \
../Core/Src/Msp/stm32f1xx_it.c \
../Core/Src/Msp/syscalls.c \
../Core/Src/Msp/sysmem.c \
../Core/Src/Msp/system_stm32f1xx.c 

OBJS += \
./Core/Src/Msp/Msp.o \
./Core/Src/Msp/stm32f1xx_hal_msp.o \
./Core/Src/Msp/stm32f1xx_it.o \
./Core/Src/Msp/syscalls.o \
./Core/Src/Msp/sysmem.o \
./Core/Src/Msp/system_stm32f1xx.o 

C_DEPS += \
./Core/Src/Msp/Msp.d \
./Core/Src/Msp/stm32f1xx_hal_msp.d \
./Core/Src/Msp/stm32f1xx_it.d \
./Core/Src/Msp/syscalls.d \
./Core/Src/Msp/sysmem.d \
./Core/Src/Msp/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Msp/%.o Core/Src/Msp/%.su: ../Core/Src/Msp/%.c Core/Src/Msp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Core/Inc/App -I../Core/Inc/Comp -I../Core/Inc/Driver -I../Core/Inc/Msp -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Msp

clean-Core-2f-Src-2f-Msp:
	-$(RM) ./Core/Src/Msp/Msp.d ./Core/Src/Msp/Msp.o ./Core/Src/Msp/Msp.su ./Core/Src/Msp/stm32f1xx_hal_msp.d ./Core/Src/Msp/stm32f1xx_hal_msp.o ./Core/Src/Msp/stm32f1xx_hal_msp.su ./Core/Src/Msp/stm32f1xx_it.d ./Core/Src/Msp/stm32f1xx_it.o ./Core/Src/Msp/stm32f1xx_it.su ./Core/Src/Msp/syscalls.d ./Core/Src/Msp/syscalls.o ./Core/Src/Msp/syscalls.su ./Core/Src/Msp/sysmem.d ./Core/Src/Msp/sysmem.o ./Core/Src/Msp/sysmem.su ./Core/Src/Msp/system_stm32f1xx.d ./Core/Src/Msp/system_stm32f1xx.o ./Core/Src/Msp/system_stm32f1xx.su

.PHONY: clean-Core-2f-Src-2f-Msp

