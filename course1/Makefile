#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#
#      	main.i - preprocessed output of main.c program
#	   	memory.i - preprocessed output of memory.c program
#		interrupts_msp432p401r_gcc.i - preprocessed output of interrupts_msp432p401r_gcc.c program
#		startup_msp432p401r_gcc.i - preprocessed output of startup_msp432p401r_gcc.c program
#		system_msp432p401r.i - preprocessed output of system_msp432p401r.c program
#
#      	main.asm - assembly output of main.c program
#	   	memory.asm - assembly output of memory.c program
#		interrupts_msp432p401r_gcc.asm - assembly output of interrupts_msp432p401r_gcc.c program
#		startup_msp432p401r_gcc.asm - assembly output of startup_msp432p401r_gcc.c program
#		system_msp432p401r.asm - assembly output of system_msp432p401r.c program
#		c1m2.asm - assembly output of final output executable
#
#      	main.o - Generate the object file for main.c program (No linking done)
#	   	memory.o - Generate the object file for memory.c program (No linking done)
#		interrupts_msp432p401r_gcc.o - Generate the object file for interrupts_msp432p401r_gcc.c program (No linking done)
#		startup_msp432p401r_gcc.o - Generate the object file for startup_msp432p401r_gcc.c program (No linking done)
#		system_msp432p401r.o - Generate the object file for system_msp432p401r.c program (No linking done)

#		compile-all - compiles all c files into object files. (No linking done)
#		build - Compile all object files and link into a final executable
#		all - Compile all object files and link into a final executable
#		clean - Removes all compiled objects, preprocessed outputs, assembly outputs, executable files and build output files
# 
#Platform Overrides:

#	
#		CPU - ARM Cortex Architecture
#		ARCH - ARM Architecture
#		SPECS - Specs file to give the linker
#		OBJCMD - Which version of objdump to run
#
#------------------------------------------------------------------------------
include sources.mk

BASEFLAGS = -Wall -Werror -O0 -g -std=c99
MSP432_INCLUDE = -I../include/msp432
CMSIS_INCLUDE = -I../include/CMSIS
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs
TARGET = c1m2

ifeq ($(PLATFORM), HOST)
	CC = gcc
	CFLAGS = $(BASEFLAGS) -DHOST -I$(INCLUDES) 
	LDFLAGS = -Wl,-Map=$(TARGET).map
	OBJS = $(SOURCES1:.c=.o)
	OBJCMD = objdump
else
 	CC = arm-none-eabi-gcc
 	LD = arm-none-eabi-ld
 	LINKER_FILE = ../msp432p401r.lds
 	OBJS = $(SOURCES2:.c=.o)
 	OBJCMD = arm-linux-gnueabi-objdump

 	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
 	CFLAGS = $(BASEFLAGS) -DMSP432 -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -I$(INCLUDES) $(MSP432_INCLUDE) $(CMSIS_INCLUDE)

endif



%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@
	$(CC) -MM $(CFLAGS) $*.c > $*.d

#######################################################################

#######################################################################

main.i: main.c
	$(CC) -E main.c $(CFLAGS) -o main.i

memory.i: memory.c
	$(CC) -E memory.c $(CFLAGS) -o memory.i

interrupts_msp432p401r_gcc.i: interrupts_msp432p401r_gcc.c
	$(CC) -E interrupts_msp432p401r_gcc.c $(CFLAGS) -o interrupts_msp432p401r_gcc.i

startup_msp432p401r_gcc.i: startup_msp432p401r_gcc.c
	$(CC) -E startup_msp432p401r_gcc.c $(CFLAGS) -o startup_msp432p401r_gcc.i

system_msp432p401r.i: system_msp432p401r.c
	$(CC) -E system_msp432p401r.c $(CFLAGS) -o system_msp432p401r.i

#######################################################################

#######################################################################

main.asm: main.c
	$(CC) -c $(CFLAGS) main.c -o main.o
	$(OBJCMD) -Sx main.o > main.asm 

memory.asm: memory.c
	$(CC) -c $(CFLAGS) memory.c -o memory.o
	$(OBJCMD) -Sx memory.o > memory.asm 

interrupts_msp432p401r_gcc.asm: interrupts_msp432p401r_gcc.c
	$(CC) -c  $(CFLAGS) interrupts_msp432p401r_gcc.c -o interrupts_msp432p401r_gcc.o
	$(OBJCMD) -Sx interrupts_msp432p401r_gcc.o > interrupts_msp432p401r_gcc.asm 

startup_msp432p401r_gcc.asm: startup_msp432p401r_gcc.c
	$(CC) -c $(CFLAGS) startup_msp432p401r_gcc.c -o startup_msp432p401r_gcc.i
	$(OBJCMD) -Sx startup_msp432p401r_gcc.o > startup_msp432p401r_gcc.asm 

system_msp432p401r.asm: system_msp432p401r.c
	$(CC) -c $(CFLAGS) system_msp432p401r.c -o system_msp432p401r.o
	$(OBJCMD) -Sx system_msp432p401r.o > system_msp432p401r.asm 

c1m2.asm: c1m2.out
	$(OBJCMD) -Sx c1m2.out > c1m2.asm 


#######################################################################

#######################################################################

main.o: main.c
	$(CC) -c main.c $(CFLAGS) -o main.o

memory.o: memory.c
	$(CC) -c memory.c $(BASEFLAGS) -DHOST -I$(INCLUDES) -o memory.o

interrupts_msp432p401r_gcc.o: interrupts_msp432p401r_gcc.c
	arm-none-eabi-gcc -c interrupts_msp432p401r_gcc.c \
	$(BASEFLAGS) -DMSP432 -mcpu=$(CPU) \
	-march=$(ARCH) --specs=$(SPECS) \
	-mfpu=fpv4-sp-d16 -mfloat-abi=hard \
	-mthumb -I$(INCLUDES) $(MSP432_INCLUDE)\
	 $(CMSIS_INCLUDE) -o interrupts_msp432p401r_gcc.o

startup_msp432p401r_gcc.o: startup_msp432p401r_gcc.c
	arm-none-eabi-gcc -c startup_msp432p401r_gcc.c \
	$(BASEFLAGS) -DMSP432 -mcpu=$(CPU) \
	-march=$(ARCH) --specs=$(SPECS) \
	-mfpu=fpv4-sp-d16 -mfloat-abi=hard \
	-mthumb -I$(INCLUDES) $(MSP432_INCLUDE)\
	 $(CMSIS_INCLUDE) -o startup_msp432p401r_gcc.o

system_msp432p401r.o: system_msp432p401r.c
	arm-none-eabi-gcc -c system_msp432p401r.c \
	$(BASEFLAGS) -DMSP432 -mcpu=$(CPU) \
	-march=$(ARCH) --specs=$(SPECS) \
	-mfpu=fpv4-sp-d16 -mfloat-abi=hard \
	-mthumb -I$(INCLUDES) $(MSP432_INCLUDE)\
	 $(CMSIS_INCLUDE) -o system_msp432p401r.o

#######################################################################

######################################################################

.PHONY: compile-all
compile-all: main.o memory.o system_msp432p401r.o startup_msp432p401r_gcc.o interrupts_msp432p401r_gcc.o


.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@



.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map *.d *.i *.asm

