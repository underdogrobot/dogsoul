################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../USB_HOST/App/usb_host.c 

OBJS += \
./USB_HOST/App/usb_host.o 

C_DEPS += \
./USB_HOST/App/usb_host.d 


# Each subdirectory must supply rules for building sources it contributes
USB_HOST/App/%.o USB_HOST/App/%.su USB_HOST/App/%.cyclo: ../USB_HOST/App/%.c USB_HOST/App/subdir.mk
	arm-none-eabi-gcc -g3 "$<" -mcpu=cortex-m4 -std=gnu99 -DSTM32 -DSTM32F407xx -DSTM32F407G_DISC1 -DUSE_STM32F4_DISCO -DUSE_HAL_DRIVER -DSTM32F4 -DSTM32F407VGTx -D__PV_LANGUAGE_ENGLISH__ -c -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/USB_HOST/App" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/USB_HOST/Target" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/sdk/mcu/include" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/Inc" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/Middlewares/ST/STM32_Audio/Addons/PDM/Inc" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/Drivers/CMSIS/Include" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f407g-disc1-demo/Drivers/BSP/STM32F4-Discovery" -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-USB_HOST-2f-App

clean-USB_HOST-2f-App:
	-$(RM) ./USB_HOST/App/usb_host.cyclo ./USB_HOST/App/usb_host.d ./USB_HOST/App/usb_host.o ./USB_HOST/App/usb_host.su

.PHONY: clean-USB_HOST-2f-App

