################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/App/App.c \
../Core/Src/App/MotorControl.c \
../Core/Src/App/SystemControl.c 

OBJS += \
./Core/Src/App/App.o \
./Core/Src/App/MotorControl.o \
./Core/Src/App/SystemControl.o 

C_DEPS += \
./Core/Src/App/App.d \
./Core/Src/App/MotorControl.d \
./Core/Src/App/SystemControl.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/App/%.o Core/Src/App/%.su: ../Core/Src/App/%.c Core/Src/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Core/Inc/App -I../Core/Inc/Comp -I../Core/Inc/Driver -I../Core/Inc/Msp -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-App

clean-Core-2f-Src-2f-App:
	-$(RM) ./Core/Src/App/App.d ./Core/Src/App/App.o ./Core/Src/App/App.su ./Core/Src/App/MotorControl.d ./Core/Src/App/MotorControl.o ./Core/Src/App/MotorControl.su ./Core/Src/App/SystemControl.d ./Core/Src/App/SystemControl.o ./Core/Src/App/SystemControl.su

.PHONY: clean-Core-2f-Src-2f-App

