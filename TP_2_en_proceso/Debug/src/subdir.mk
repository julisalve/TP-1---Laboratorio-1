################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ArrayEmployees.c \
../src/BIblioteca_general.c \
../src/TP_2_en_proceso.c 

OBJS += \
./src/ArrayEmployees.o \
./src/BIblioteca_general.o \
./src/TP_2_en_proceso.o 

C_DEPS += \
./src/ArrayEmployees.d \
./src/BIblioteca_general.d \
./src/TP_2_en_proceso.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


