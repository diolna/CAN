################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../atmega.cpp \
../main.cpp \
../mcp2515.cpp \
../serial.cpp \
../spi.cpp 

OBJS += \
./atmega.o \
./main.o \
./mcp2515.o \
./serial.o \
./spi.o 

CPP_DEPS += \
./atmega.d \
./main.d \
./mcp2515.d \
./serial.d \
./spi.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega8 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


