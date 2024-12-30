################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tasks/microphone_task/microphone_task.c 

OBJS += \
./tasks/microphone_task/microphone_task.o 

C_DEPS += \
./tasks/microphone_task/microphone_task.d 


# Each subdirectory must supply rules for building sources it contributes
tasks/microphone_task/%.o tasks/microphone_task/%.su tasks/microphone_task/%.cyclo: ../tasks/microphone_task/%.c tasks/microphone_task/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/Users/ozana/STM32CubeIDE/workspace_1.15.1/voice-app/tasks" -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/ozana/STM32CubeIDE/workspace_1.15.1/voice-app/bsp/cs43l22" -I"C:/Users/ozana/STM32CubeIDE/workspace_1.15.1/voice-app/tasks/microphone_task" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tasks-2f-microphone_task

clean-tasks-2f-microphone_task:
	-$(RM) ./tasks/microphone_task/microphone_task.cyclo ./tasks/microphone_task/microphone_task.d ./tasks/microphone_task/microphone_task.o ./tasks/microphone_task/microphone_task.su

.PHONY: clean-tasks-2f-microphone_task

