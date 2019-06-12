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
#		VERBOSE - used to debug program. prints out the data
#		COURSE - used to run course1 function in main.c
#
#------------------------------------------------------------------------------
include sources.mk

BASEFLAGS = -Wall -Werror -O0 -g -std=c99
MSP432_INCLUDE = -Iinclude/msp432
CMSIS_INCLUDE = -Iinclude/CMSIS
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs
TARGET = final

# If DEBUG=1 then set VERBOSE. This will print out the data array for each test in course1 using print_array. 
ifeq ($(DEBUG),1)
	VERBOSE = -DVERBOSE
else
	VERBOSE = 
endif

#If RUN=1 then set COURSE. This will run the course1 function in main.c
ifeq ($(RUN),1)
	COURSE = -DCOURSE1
else
	COURSE = 
endif

ifeq ($(PLATFORM), HOST)
	CC = gcc
	CFLAGS = $(BASEFLAGS) -DHOST $(COURSE) $(VERBOSE) -I$(INCLUDES) 
	LDFLAGS = -Wl,-Map=$(TARGET).map
	OBJS = $(SOURCES1:.c=.o)
	OBJCMD = objdump
else
 	CC = arm-none-eabi-gcc
 	LD = arm-none-eabi-ld
 	LINKER_FILE = msp432p401r.lds
 	OBJS = $(SOURCES2:.c=.o)
 	OBJCMD = arm-linux-gnueabi-objdump

 	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
 	CFLAGS = $(BASEFLAGS) -DMSP432 $(COURSE) $(VERBOSE) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) \
 			-mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -I$(INCLUDES) $(MSP432_INCLUDE) $(CMSIS_INCLUDE)

endif



%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@


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

