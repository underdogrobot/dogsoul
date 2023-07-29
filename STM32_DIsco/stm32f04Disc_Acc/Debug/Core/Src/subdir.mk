################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/LIS3DSH.c \
../Core/Src/main.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/LIS3DSH.o \
./Core/Src/main.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/LIS3DSH.d \
./Core/Src/main.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
<<<<<<< Updated upstream
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Core/Inc" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/CMSIS/Include" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/BSP/STM32F4-Discovery" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
=======
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Core/Inc" -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
>>>>>>> Stashed changes

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/LIS3DSH.cyclo ./Core/Src/LIS3DSH.d ./Core/Src/LIS3DSH.o ./Core/Src/LIS3DSH.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su

.PHONY: clean-Core-2f-Src

