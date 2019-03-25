################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Mohit/Documents/0CUB/platform/drivers/src/i2c/fsl_i2c_slave_driver.c 

OBJS += \
./platform/i2c/drivers/slave/fsl_i2c_slave_driver.o 

C_DEPS += \
./platform/i2c/drivers/slave/fsl_i2c_slave_driver.d 


# Each subdirectory must supply rules for building sources it contributes
platform/i2c/drivers/slave/fsl_i2c_slave_driver.o: C:/Users/Mohit/Documents/0CUB/platform/drivers/src/i2c/fsl_i2c_slave_driver.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -DDEBUG -DCPU_MKL25Z128VLK4 -I../../../../../platform/CMSIS/Include -I../../../../../platform/devices -I../../../../../platform/devices/MKL25Z4/include -I../../../../../platform/devices/MKL25Z4/startup -I../../../../../platform/utilities/inc -I../../../../../platform/hal/inc -I../../../../../platform/drivers/inc -I../../../../../platform/system/inc -I../../../../../platform/osa/inc -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


