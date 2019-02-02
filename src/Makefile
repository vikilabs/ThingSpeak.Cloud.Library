#Compiler
CC = gcc

#OBJECT
OBJECT = ../lib/libThingSpeak.o

#DEFINITIONS
DEFS = -DTRACES_VERIFICATION 
DEFS += -DDEBUG_TRACES

#Source Files
SOURCE_FILE = main_prog.c
SOURCE_FILE += ThingSpeak.c
#SOURCE_FILE += x.c

#INCLUDE
#INCLS = -I../include
#LIBS to include
LIBS = -lcurl
LIBS += -ldl 
#STRIP
#ARM_STRIP = arm-none-linux-gnueabi-strip

all:
	$(CC) -Wall $(DEFS) -o$(OBJECT) $(SOURCE_FILE) $(INCLS) $(LIBS)
	$(OBJECT)
