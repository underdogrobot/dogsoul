################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.c \
../Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.c 

OBJS += \
./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.o \
./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.o 

C_DEPS += \
./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.d \
./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32F4-Discovery/%.o Drivers/BSP/STM32F4-Discovery/%.su Drivers/BSP/STM32F4-Discovery/%.cyclo: ../Drivers/BSP/STM32F4-Discovery/%.c Drivers/BSP/STM32F4-Discovery/subdir.mk
	arm-none-eabi-gcc -g3 "$<" -mcpu=cortex-m4 -std=gnu99 -DSTM32 -DSTM32F407xx -DSTM32F407G_DISC1 -DUSE_STM32F4_DISCO -DUSE_HAL_DRIVER -DSTM32F4 -DSTM32F407VGTx -D__PV_LANGUAGE_ENGLISH__ -c -I../Inc -I../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/BSP/STM32F4-Discovery -I../sdk/mcu/include -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/USB_HOST/App" -I"C:/Users/fg/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/USB_HOST/Target" -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32F4-2d-Discovery

clean-Drivers-2f-BSP-2f-STM32F4-2d-Discovery:
	-$(RM) ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.cyclo ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.d ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.o ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery.su ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.cyclo ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.d ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.o ./Drivers/BSP/STM32F4-Discovery/stm32f4_discovery_audio.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32F4-2d-Discovery

