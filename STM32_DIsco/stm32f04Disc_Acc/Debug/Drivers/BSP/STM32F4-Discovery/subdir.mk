################################################################################
# Automatically-generated file. Do not edit!
<<<<<<< Updated upstream
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
=======
# Toolchain: GNU Tools for STM32 (11.3.rel1)
>>>>>>> Stashed changes
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
<<<<<<< Updated upstream
../Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.c 

OBJS += \
./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.o 

C_DEPS += \
./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.d 
=======
../Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.c \
../Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_accelerometer.c \
../Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.c 

OBJS += \
./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.o \
./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_accelerometer.o \
./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.o 

C_DEPS += \
./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.d \
./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_accelerometer.d \
./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.d 
>>>>>>> Stashed changes


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32F4-Discovery/%.o Drivers/BSP/STM32F4-Discovery/%.su Drivers/BSP/STM32F4-Discovery/%.cyclo: ../Drivers/BSP/STM32F4-Discovery/%.c Drivers/BSP/STM32F4-Discovery/subdir.mk
<<<<<<< Updated upstream
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Core/Inc" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/CMSIS/Include" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/BSP/STM32F4-Discovery" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
=======
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Core/Inc" -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
>>>>>>> Stashed changes

clean: clean-Drivers-2f-BSP-2f-STM32F4-2d-Discovery

clean-Drivers-2f-BSP-2f-STM32F4-2d-Discovery:
<<<<<<< Updated upstream
	-$(RM) ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.cyclo ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.d ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.o ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.su
=======
	-$(RM) ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.cyclo ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.d ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.o ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.su ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_accelerometer.cyclo ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_accelerometer.d ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_accelerometer.o ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_accelerometer.su ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.cyclo ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.d ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.o ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.su
>>>>>>> Stashed changes

.PHONY: clean-Drivers-2f-BSP-2f-STM32F4-2d-Discovery

