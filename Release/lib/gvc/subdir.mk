################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/gvc/gvc.c \
../lib/gvc/gvconfig.c \
../lib/gvc/gvcontext.c \
../lib/gvc/gvdevice.c \
../lib/gvc/gvevent.c \
../lib/gvc/gvjobs.c \
../lib/gvc/gvlayout.c \
../lib/gvc/gvloadimage.c \
../lib/gvc/gvplugin.c \
../lib/gvc/gvrender.c \
../lib/gvc/gvtextlayout.c \
../lib/gvc/gvtool_tred.c \
../lib/gvc/gvusershape.c 

OBJS += \
./lib/gvc/gvc.o \
./lib/gvc/gvconfig.o \
./lib/gvc/gvcontext.o \
./lib/gvc/gvdevice.o \
./lib/gvc/gvevent.o \
./lib/gvc/gvjobs.o \
./lib/gvc/gvlayout.o \
./lib/gvc/gvloadimage.o \
./lib/gvc/gvplugin.o \
./lib/gvc/gvrender.o \
./lib/gvc/gvtextlayout.o \
./lib/gvc/gvtool_tred.o \
./lib/gvc/gvusershape.o 

C_DEPS += \
./lib/gvc/gvc.d \
./lib/gvc/gvconfig.d \
./lib/gvc/gvcontext.d \
./lib/gvc/gvdevice.d \
./lib/gvc/gvevent.d \
./lib/gvc/gvjobs.d \
./lib/gvc/gvlayout.d \
./lib/gvc/gvloadimage.d \
./lib/gvc/gvplugin.d \
./lib/gvc/gvrender.d \
./lib/gvc/gvtextlayout.d \
./lib/gvc/gvtool_tred.d \
./lib/gvc/gvusershape.d 


# Each subdirectory must supply rules for building sources it contributes
lib/gvc/%.o: ../lib/gvc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


