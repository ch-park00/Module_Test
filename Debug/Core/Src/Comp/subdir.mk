################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Comp/LED.c \
../Core/Src/Comp/MotorPWM.c \
../Core/Src/Comp/SwitchControl.c \
../Core/Src/Comp/SystemTimer.c \
../Core/Src/Comp/Uart_Printf.c 

OBJS += \
./Core/Src/Comp/LED.o \
./Core/Src/Comp/MotorPWM.o \
./Core/Src/Comp/SwitchControl.o \
./Core/Src/Comp/SystemTimer.o \
./Core/Src/Comp/Uart_Printf.o 

C_DEPS += \
./Core/Src/Comp/LED.d \
./Core/Src/Comp/MotorPWM.d \
./Core/Src/Comp/SwitchControl.d \
./Core/Src/Comp/SystemTimer.d \
./Core/Src/Comp/Uart_Printf.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Comp/%.o Core/Src/Comp/%.su: ../Core/Src/Comp/%.c Core/Src/Comp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Core/Inc/App -I../Core/Inc/Comp -I../Core/Inc/Driver -I../Core/Inc/Msp -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Comp

clean-Core-2f-Src-2f-Comp:
	-$(RM) ./Core/Src/Comp/LED.d ./Core/Src/Comp/LED.o ./Core/Src/Comp/LED.su ./Core/Src/Comp/MotorPWM.d ./Core/Src/Comp/MotorPWM.o ./Core/Src/Comp/MotorPWM.su ./Core/Src/Comp/SwitchControl.d ./Core/Src/Comp/SwitchControl.o ./Core/Src/Comp/SwitchControl.su ./Core/Src/Comp/SystemTimer.d ./Core/Src/Comp/SystemTimer.o ./Core/Src/Comp/SystemTimer.su ./Core/Src/Comp/Uart_Printf.d ./Core/Src/Comp/Uart_Printf.o ./Core/Src/Comp/Uart_Printf.su

.PHONY: clean-Core-2f-Src-2f-Comp

