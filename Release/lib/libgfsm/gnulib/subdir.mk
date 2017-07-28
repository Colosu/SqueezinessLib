################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/libgfsm/gnulib/asnprintf.c \
../lib/libgfsm/gnulib/asprintf.c \
../lib/libgfsm/gnulib/getdelim.c \
../lib/libgfsm/gnulib/printf-args.c \
../lib/libgfsm/gnulib/printf-parse.c \
../lib/libgfsm/gnulib/vasnprintf.c \
../lib/libgfsm/gnulib/vasprintf.c 

OBJS += \
./lib/libgfsm/gnulib/asnprintf.o \
./lib/libgfsm/gnulib/asprintf.o \
./lib/libgfsm/gnulib/getdelim.o \
./lib/libgfsm/gnulib/printf-args.o \
./lib/libgfsm/gnulib/printf-parse.o \
./lib/libgfsm/gnulib/vasnprintf.o \
./lib/libgfsm/gnulib/vasprintf.o 

C_DEPS += \
./lib/libgfsm/gnulib/asnprintf.d \
./lib/libgfsm/gnulib/asprintf.d \
./lib/libgfsm/gnulib/getdelim.d \
./lib/libgfsm/gnulib/printf-args.d \
./lib/libgfsm/gnulib/printf-parse.d \
./lib/libgfsm/gnulib/vasnprintf.d \
./lib/libgfsm/gnulib/vasprintf.d 


# Each subdirectory must supply rules for building sources it contributes
lib/libgfsm/gnulib/%.o: ../lib/libgfsm/gnulib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


