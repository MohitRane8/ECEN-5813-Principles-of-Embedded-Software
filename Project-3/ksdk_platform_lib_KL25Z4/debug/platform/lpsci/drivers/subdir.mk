################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Freescale/KSDK_1.3.0/platform/drivers/src/lpsci/fsl_lpsci_common.c \
C:/Freescale/KSDK_1.3.0/platform/drivers/src/lpsci/fsl_lpsci_dma_driver.c \
C:/Freescale/KSDK_1.3.0/platform/drivers/src/lpsci/fsl_lpsci_driver.c 

OBJS += \
./platform/lpsci/drivers/fsl_lpsci_common.o \
./platform/lpsci/drivers/fsl_lpsci_dma_driver.o \
./platform/lpsci/drivers/fsl_lpsci_driver.o 

C_DEPS += \
./platform/lpsci/drivers/fsl_lpsci_common.d \
./platform/lpsci/drivers/fsl_lpsci_dma_driver.d \
./platform/lpsci/drivers/fsl_lpsci_driver.d 


# Each subdirectory must supply rules for building sources it contributes
platform/lpsci/drivers/fsl_lpsci_common.o: C:/Freescale/KSDK_1.3.0/platform/drivers/src/lpsci/fsl_lpsci_common.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -DDEBUG -DCPU_MKL25Z128VLK4 -I../../../../../platform/CMSIS/Include -I../../../../../platform/devices -I../../../../../platform/devices/MKL25Z4/include -I../../../../../platform/devices/MKL25Z4/startup -I../../../../../platform/utilities/inc -I../../../../../platform/hal/inc -I../../../../../platform/drivers/inc -I../../../../../platform/system/inc -I../../../../../platform/osa/inc -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

platform/lpsci/drivers/fsl_lpsci_dma_driver.o: C:/Freescale/KSDK_1.3.0/platform/drivers/src/lpsci/fsl_lpsci_dma_driver.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -DDEBUG -DCPU_MKL25Z128VLK4 -I../../../../../platform/CMSIS/Include -I../../../../../platform/devices -I../../../../../platform/devices/MKL25Z4/include -I../../../../../platform/devices/MKL25Z4/startup -I../../../../../platform/utilities/inc -I../../../../../platform/hal/inc -I../../../../../platform/drivers/inc -I../../../../../platform/system/inc -I../../../../../platform/osa/inc -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

platform/lpsci/drivers/fsl_lpsci_driver.o: C:/Freescale/KSDK_1.3.0/platform/drivers/src/lpsci/fsl_lpsci_driver.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -DDEBUG -DCPU_MKL25Z128VLK4 -I../../../../../platform/CMSIS/Include -I../../../../../platform/devices -I../../../../../platform/devices/MKL25Z4/include -I../../../../../platform/devices/MKL25Z4/startup -I../../../../../platform/utilities/inc -I../../../../../platform/hal/inc -I../../../../../platform/drivers/inc -I../../../../../platform/system/inc -I../../../../../platform/osa/inc -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


