################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/cdt/dtclose.c \
../lib/cdt/dtdisc.c \
../lib/cdt/dtextract.c \
../lib/cdt/dtflatten.c \
../lib/cdt/dthash.c \
../lib/cdt/dtlist.c \
../lib/cdt/dtmethod.c \
../lib/cdt/dtopen.c \
../lib/cdt/dtrenew.c \
../lib/cdt/dtrestore.c \
../lib/cdt/dtsize.c \
../lib/cdt/dtstat.c \
../lib/cdt/dtstrhash.c \
../lib/cdt/dttree.c \
../lib/cdt/dttreeset.c \
../lib/cdt/dtview.c \
../lib/cdt/dtwalk.c 

OBJS += \
./lib/cdt/dtclose.o \
./lib/cdt/dtdisc.o \
./lib/cdt/dtextract.o \
./lib/cdt/dtflatten.o \
./lib/cdt/dthash.o \
./lib/cdt/dtlist.o \
./lib/cdt/dtmethod.o \
./lib/cdt/dtopen.o \
./lib/cdt/dtrenew.o \
./lib/cdt/dtrestore.o \
./lib/cdt/dtsize.o \
./lib/cdt/dtstat.o \
./lib/cdt/dtstrhash.o \
./lib/cdt/dttree.o \
./lib/cdt/dttreeset.o \
./lib/cdt/dtview.o \
./lib/cdt/dtwalk.o 

C_DEPS += \
./lib/cdt/dtclose.d \
./lib/cdt/dtdisc.d \
./lib/cdt/dtextract.d \
./lib/cdt/dtflatten.d \
./lib/cdt/dthash.d \
./lib/cdt/dtlist.d \
./lib/cdt/dtmethod.d \
./lib/cdt/dtopen.d \
./lib/cdt/dtrenew.d \
./lib/cdt/dtrestore.d \
./lib/cdt/dtsize.d \
./lib/cdt/dtstat.d \
./lib/cdt/dtstrhash.d \
./lib/cdt/dttree.d \
./lib/cdt/dttreeset.d \
./lib/cdt/dtview.d \
./lib/cdt/dtwalk.d 


# Each subdirectory must supply rules for building sources it contributes
lib/cdt/%.o: ../lib/cdt/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


