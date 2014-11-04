################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../lib/Correlacao.cc \
../lib/Tratamento_imagem.cc 

CC_DEPS += \
./lib/Correlacao.d \
./lib/Tratamento_imagem.d 

OBJS += \
./lib/Correlacao.o \
./lib/Tratamento_imagem.o 


# Each subdirectory must supply rules for building sources it contributes
lib/%.o: ../lib/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


