################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/cs43l22/cs43l22.c 

OBJS += \
./Drivers/BSP/Components/cs43l22/cs43l22.o 

C_DEPS += \
./Drivers/BSP/Components/cs43l22/cs43l22.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/cs43l22/%.o Drivers/BSP/Components/cs43l22/%.su Drivers/BSP/Components/cs43l22/%.cyclo: ../Drivers/BSP/Components/cs43l22/%.c Drivers/BSP/Components/cs43l22/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu99 -DSTM32 -DSTM32F407xx -DSTM32F407G_DISC1 -DUSE_STM32F4_DISCO -DUSE_HAL_DRIVER -DSTM32F4 -DSTM32F407VGTx -D__PV_LANGUAGE_MANDARIN__ -c -I../Inc -I../../../../../sdk/mcu/include -I../Middlewares/ST/STM32_Audio/Addons/PDM/Inc -I../Drivers/CMSIS/Include -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/BSP/STM32F4-Discovery -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-cs43l22

clean-Drivers-2f-BSP-2f-Components-2f-cs43l22:
	-$(RM) ./Drivers/BSP/Components/cs43l22/cs43l22.cyclo ./Drivers/BSP/Components/cs43l22/cs43l22.d ./Drivers/BSP/Components/cs43l22/cs43l22.o ./Drivers/BSP/Components/cs43l22/cs43l22.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-cs43l22

