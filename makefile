CC = g++
DEBUG = -g
CFLAGS = -Wall -o2 -c $(DEBUG) -Iinclude 
LFLAGS = -Wall $(DEBUG) -leddi-commons 

eddivm : eddi.o VirtualMachine.o
	$(CC) $(LFLAGS) -o bin/eddivm bin/eddi.o bin/VirtualMachine.o

eddi.o : src/eddi.cpp include/VirtualMachine.h
	$(CC) $(CFLAGS) -o bin/eddi.o src/eddi.cpp

VirtualMachine.o : include/VirtualMachine.h src/VirtualMachine.cpp
	$(CC) $(CFLAGS) -o bin/VirtualMachine.o src/VirtualMachine.cpp

clean:
	rm -f bin/*
	rm main.v

