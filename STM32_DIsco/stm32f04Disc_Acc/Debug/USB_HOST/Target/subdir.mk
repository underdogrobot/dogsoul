################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../USB_HOST/Target/usbh_conf.c \
../USB_HOST/Target/usbh_platform.c 

OBJS += \
./USB_HOST/Target/usbh_conf.o \
./USB_HOST/Target/usbh_platform.o 

C_DEPS += \
./USB_HOST/Target/usbh_conf.d \
./USB_HOST/Target/usbh_platform.d 


# Each subdirectory must supply rules for building sources it contributes
USB_HOST/Target/%.o USB_HOST/Target/%.su USB_HOST/Target/%.cyclo: ../USB_HOST/Target/%.c USB_HOST/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Core/Inc" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/CMSIS/Include" -I"C:/Users/Frank/STM32CubeIDE/workspace_1.12.1/stm32f04Disc_Acc/Drivers/BSP/STM32F4-Discovery" -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../PDM2PCM/App -I../USB_HOST/App -I../USB_HOST/Target -I../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-USB_HOST-2f-Target

clean-USB_HOST-2f-Target:
	-$(RM) ./USB_HOST/Target/usbh_conf.cyclo ./USB_HOST/Target/usbh_conf.d ./USB_HOST/Target/usbh_conf.o ./USB_HOST/Target/usbh_conf.su ./USB_HOST/Target/usbh_platform.cyclo ./USB_HOST/Target/usbh_platform.d ./USB_HOST/Target/usbh_platform.o ./USB_HOST/Target/usbh_platform.su

.PHONY: clean-USB_HOST-2f-Target

