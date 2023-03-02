################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/FreeRTOS/Source/croutine.c \
../Core/FreeRTOS/Source/event_groups.c \
../Core/FreeRTOS/Source/list.c \
../Core/FreeRTOS/Source/queue.c \
../Core/FreeRTOS/Source/stream_buffer.c \
../Core/FreeRTOS/Source/tasks.c \
../Core/FreeRTOS/Source/timers.c 

OBJS += \
./Core/FreeRTOS/Source/croutine.o \
./Core/FreeRTOS/Source/event_groups.o \
./Core/FreeRTOS/Source/list.o \
./Core/FreeRTOS/Source/queue.o \
./Core/FreeRTOS/Source/stream_buffer.o \
./Core/FreeRTOS/Source/tasks.o \
./Core/FreeRTOS/Source/timers.o 

C_DEPS += \
./Core/FreeRTOS/Source/croutine.d \
./Core/FreeRTOS/Source/event_groups.d \
./Core/FreeRTOS/Source/list.d \
./Core/FreeRTOS/Source/queue.d \
./Core/FreeRTOS/Source/stream_buffer.d \
./Core/FreeRTOS/Source/tasks.d \
./Core/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Core/FreeRTOS/Source/%.o Core/FreeRTOS/Source/%.su: ../Core/FreeRTOS/Source/%.c Core/FreeRTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/FreeRTOS/Source/include -I../Core/FreeRTOS/Source -I../Core/FreeRTOS -I../Core/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-FreeRTOS-2f-Source

clean-Core-2f-FreeRTOS-2f-Source:
	-$(RM) ./Core/FreeRTOS/Source/croutine.d ./Core/FreeRTOS/Source/croutine.o ./Core/FreeRTOS/Source/croutine.su ./Core/FreeRTOS/Source/event_groups.d ./Core/FreeRTOS/Source/event_groups.o ./Core/FreeRTOS/Source/event_groups.su ./Core/FreeRTOS/Source/list.d ./Core/FreeRTOS/Source/list.o ./Core/FreeRTOS/Source/list.su ./Core/FreeRTOS/Source/queue.d ./Core/FreeRTOS/Source/queue.o ./Core/FreeRTOS/Source/queue.su ./Core/FreeRTOS/Source/stream_buffer.d ./Core/FreeRTOS/Source/stream_buffer.o ./Core/FreeRTOS/Source/stream_buffer.su ./Core/FreeRTOS/Source/tasks.d ./Core/FreeRTOS/Source/tasks.o ./Core/FreeRTOS/Source/tasks.su ./Core/FreeRTOS/Source/timers.d ./Core/FreeRTOS/Source/timers.o ./Core/FreeRTOS/Source/timers.su

.PHONY: clean-Core-2f-FreeRTOS-2f-Source

