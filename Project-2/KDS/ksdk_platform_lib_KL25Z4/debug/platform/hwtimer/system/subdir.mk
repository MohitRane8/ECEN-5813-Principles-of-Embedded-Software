################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Mohit/Documents/0CUB/platform/system/src/hwtimer/fsl_hwtimer.c \
C:/Users/Mohit/Documents/0CUB/platform/system/src/hwtimer/fsl_hwtimer_pit.c \
C:/Users/Mohit/Documents/0CUB/platform/system/src/hwtimer/fsl_hwtimer_systick.c 

OBJS += \
./platform/hwtimer/system/fsl_hwtimer.o \
./platform/hwtimer/system/fsl_hwtimer_pit.o \
./platform/hwtimer/system/fsl_hwtimer_systick.o 

C_DEPS += \
./platform/hwtimer/system/fsl_hwtimer.d \
./platform/hwtimer/system/fsl_hwtimer_pit.d \
./platform/hwtimer/system/fsl_hwtimer_systick.d 


# Each subdirectory must supply rules for building sources it contributes
platform/hwtimer/system/fsl_hwtimer.o: C:/Users/Mohit/Documents/0CUB/platform/system/src/hwtimer/fsl_hwtimer.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -DDEBUG -DCPU_MKL25Z128VLK4 -I../../../../../platform/CMSIS/Include -I../../../../../platform/devices -I../../../../../platform/devices/MKL25Z4/include -I../../../../../platform/devices/MKL25Z4/startup -I../../../../../platform/utilities/inc -I../../../../../platform/hal/inc -I../../../../../platform/drivers/inc -I../../../../../platform/system/inc -I../../../../../platform/osa/inc -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

platform/hwtimer/system/fsl_hwtimer_pit.o: C:/Users/Mohit/Documents/0CUB/platform/system/src/hwtimer/fsl_hwtimer_pit.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -DDEBUG -DCPU_MKL25Z128VLK4 -I../../../../../platform/CMSIS/Include -I../../../../../platform/devices -I../../../../../platform/devices/MKL25Z4/include -I../../../../../platform/devices/MKL25Z4/startup -I../../../../../platform/utilities/inc -I../../../../../platform/hal/inc -I../../../../../platform/drivers/inc -I../../../../../platform/system/inc -I../../../../../platform/osa/inc -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

platform/hwtimer/system/fsl_hwtimer_systick.o: C:/Users/Mohit/Documents/0CUB/platform/system/src/hwtimer/fsl_hwtimer_systick.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -DDEBUG -DCPU_MKL25Z128VLK4 -I../../../../../platform/CMSIS/Include -I../../../../../platform/devices -I../../../../../platform/devices/MKL25Z4/include -I../../../../../platform/devices/MKL25Z4/startup -I../../../../../platform/utilities/inc -I../../../../../platform/hal/inc -I../../../../../platform/drivers/inc -I../../../../../platform/system/inc -I../../../../../platform/osa/inc -std=gnu99 -fno-common  -ffreestanding  -fno-builtin  -mapcs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


