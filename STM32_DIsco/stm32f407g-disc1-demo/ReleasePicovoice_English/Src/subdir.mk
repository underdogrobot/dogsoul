################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/pv_audio_rec.c \
../Src/pv_st_f407.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c \
../Src/syscalls.c \
../Src/system_stm32f4xx.c \
../Src/uartSendInit.c 

OBJS += \
./Src/main.o \
./Src/pv_audio_rec.o \
./Src/pv_st_f407.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o \
./Src/syscalls.o \
./Src/system_stm32f4xx.o \
./Src/uartSendInit.o 

C_DEPS += \
./Src/main.d \
./Src/pv_audio_rec.d \
./Src/pv_st_f407.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d \
./Src/syscalls.d \
./Src/system_stm32f4xx.d \
./Src/uartSendInit.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc -g3 "$<" -mcpu=cortex-m4 -std=gnu99 -DSTM32 -DSTM32F407xx -DSTM32F407G_DISC1 -DUSE_STM32F4_DISCO -DUSE_HAL_DRIVER -DSTM32F4 -DSTM32F407VGTx -D__PV_LANGUAGE_ENGLISH__ -c -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/USB_HOST/App" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/USB_HOST/Target" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/sdk/mcu/include" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/Inc" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/Middlewares/ST/STM32_Audio/Addons/PDM/Inc" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/Drivers/CMSIS/Include" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/Drivers/BSP/STM32F4-Discovery" -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/pv_audio_rec.cyclo ./Src/pv_audio_rec.d ./Src/pv_audio_rec.o ./Src/pv_audio_rec.su ./Src/pv_st_f407.cyclo ./Src/pv_st_f407.d ./Src/pv_st_f407.o ./Src/pv_st_f407.su ./Src/stm32f4xx_hal_msp.cyclo ./Src/stm32f4xx_hal_msp.d ./Src/stm32f4xx_hal_msp.o ./Src/stm32f4xx_hal_msp.su ./Src/stm32f4xx_it.cyclo ./Src/stm32f4xx_it.d ./Src/stm32f4xx_it.o ./Src/stm32f4xx_it.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/system_stm32f4xx.cyclo ./Src/system_stm32f4xx.d ./Src/system_stm32f4xx.o ./Src/system_stm32f4xx.su ./Src/uartSendInit.cyclo ./Src/uartSendInit.d ./Src/uartSendInit.o ./Src/uartSendInit.su

.PHONY: clean-Src

