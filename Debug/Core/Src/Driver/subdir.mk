################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Driver/MotorDriver.c \
../Core/Src/Driver/SystemDriver.c 

OBJS += \
./Core/Src/Driver/MotorDriver.o \
./Core/Src/Driver/SystemDriver.o 

C_DEPS += \
./Core/Src/Driver/MotorDriver.d \
./Core/Src/Driver/SystemDriver.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Driver/%.o Core/Src/Driver/%.su: ../Core/Src/Driver/%.c Core/Src/Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Core/Inc/App -I../Core/Inc/Comp -I../Core/Inc/Driver -I../Core/Inc/Msp -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Driver

clean-Core-2f-Src-2f-Driver:
	-$(RM) ./Core/Src/Driver/MotorDriver.d ./Core/Src/Driver/MotorDriver.o ./Core/Src/Driver/MotorDriver.su ./Core/Src/Driver/SystemDriver.d ./Core/Src/Driver/SystemDriver.o ./Core/Src/Driver/SystemDriver.su

.PHONY: clean-Core-2f-Src-2f-Driver

