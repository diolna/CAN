################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../atmega.cpp \
../main.cpp \
../mcp2515.cpp \
../spi.cpp \
../spi_my.cpp 

OBJS += \
./atmega.o \
./main.o \
./mcp2515.o \
./spi.o \
./spi_my.o 

CPP_DEPS += \
./atmega.d \
./main.d \
./mcp2515.d \
./spi.d \
./spi_my.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega8 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


