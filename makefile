CC = g++
DEBUG = -g
CFLAGS = -Wall -o2 -c $(DEBUG) -Iinclude 
LFLAGS = -Wall $(DEBUG) -leddi-commons 

bin/eddivm : bin/eddi.o bin/VirtualMachine.o bin/Stack.o bin/ByteCodeFileReader.o bin/Variables.o
	$(CC) $(LFLAGS) -o bin/eddivm bin/eddi.o bin/VirtualMachine.o  bin/Stack.o bin/ByteCodeFileReader.o bin/Variables.o

bin/eddi.o : src/eddi.cpp include/VirtualMachine.h
	$(CC) $(CFLAGS) -o bin/eddi.o src/eddi.cpp

bin/VirtualMachine.o : include/VirtualMachine.h src/VirtualMachine.cpp
	$(CC) $(CFLAGS) -o bin/VirtualMachine.o src/VirtualMachine.cpp

bin/Stack.o : include/Stack.h src/Stack.cpp
	$(CC) $(CFLAGS) -o bin/Stack.o src/Stack.cpp

bin/Variables.o : include/Variables.h src/Variables.cpp
	$(CC) $(CFLAGS) -o bin/Variables.o src/Variables.cpp

bin/ByteCodeFileReader.o : include/ByteCodeFileReader.h src/ByteCodeFileReader.cpp
	$(CC) $(CFLAGS) -o bin/ByteCodeFileReader.o src/ByteCodeFileReader.cpp

clean:
	rm -f bin/*
	rm main.v

