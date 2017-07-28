################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/cgraph/agerror.c \
../lib/cgraph/agxbuf.c \
../lib/cgraph/apply.c \
../lib/cgraph/attr.c \
../lib/cgraph/cmpnd.c \
../lib/cgraph/edge.c \
../lib/cgraph/flatten.c \
../lib/cgraph/grammar.c \
../lib/cgraph/graph.c \
../lib/cgraph/id.c \
../lib/cgraph/imap.c \
../lib/cgraph/io.c \
../lib/cgraph/main.c \
../lib/cgraph/mem.c \
../lib/cgraph/node.c \
../lib/cgraph/obj.c \
../lib/cgraph/pend.c \
../lib/cgraph/rec.c \
../lib/cgraph/refstr.c \
../lib/cgraph/scan.c \
../lib/cgraph/subg.c \
../lib/cgraph/tester.c \
../lib/cgraph/utils.c \
../lib/cgraph/write.c \
../lib/cgraph/y.tab.c 

OBJS += \
./lib/cgraph/agerror.o \
./lib/cgraph/agxbuf.o \
./lib/cgraph/apply.o \
./lib/cgraph/attr.o \
./lib/cgraph/cmpnd.o \
./lib/cgraph/edge.o \
./lib/cgraph/flatten.o \
./lib/cgraph/grammar.o \
./lib/cgraph/graph.o \
./lib/cgraph/id.o \
./lib/cgraph/imap.o \
./lib/cgraph/io.o \
./lib/cgraph/main.o \
./lib/cgraph/mem.o \
./lib/cgraph/node.o \
./lib/cgraph/obj.o \
./lib/cgraph/pend.o \
./lib/cgraph/rec.o \
./lib/cgraph/refstr.o \
./lib/cgraph/scan.o \
./lib/cgraph/subg.o \
./lib/cgraph/tester.o \
./lib/cgraph/utils.o \
./lib/cgraph/write.o \
./lib/cgraph/y.tab.o 

C_DEPS += \
./lib/cgraph/agerror.d \
./lib/cgraph/agxbuf.d \
./lib/cgraph/apply.d \
./lib/cgraph/attr.d \
./lib/cgraph/cmpnd.d \
./lib/cgraph/edge.d \
./lib/cgraph/flatten.d \
./lib/cgraph/grammar.d \
./lib/cgraph/graph.d \
./lib/cgraph/id.d \
./lib/cgraph/imap.d \
./lib/cgraph/io.d \
./lib/cgraph/main.d \
./lib/cgraph/mem.d \
./lib/cgraph/node.d \
./lib/cgraph/obj.d \
./lib/cgraph/pend.d \
./lib/cgraph/rec.d \
./lib/cgraph/refstr.d \
./lib/cgraph/scan.d \
./lib/cgraph/subg.d \
./lib/cgraph/tester.d \
./lib/cgraph/utils.d \
./lib/cgraph/write.d \
./lib/cgraph/y.tab.d 


# Each subdirectory must supply rules for building sources it contributes
lib/cgraph/%.o: ../lib/cgraph/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


