CC = g++
DEBUG = -g
CFLAGS = -Wall -o2 -c $(DEBUG) -Iinclude 
LFLAGS = -Wall $(DEBUG) -leddi-commons 

bin/eddivm : bin/eddi.o bin/VirtualMachine.o bin/Stack.o bin/ByteCodeFileReader.o bin/Variables.o bin/StringPool.o
	$(CC) $(LFLAGS) -o bin/eddivm bin/eddi.o bin/VirtualMachine.o  bin/Stack.o bin/ByteCodeFileReader.o bin/Variables.o bin/StringPool.o

bin/eddi.o : src/eddi.cpp include/VirtualMachine.hpp
	$(CC) $(CFLAGS) -o bin/eddi.o src/eddi.cpp

bin/VirtualMachine.o : include/VirtualMachine.hpp src/VirtualMachine.cpp
	$(CC) $(CFLAGS) -o bin/VirtualMachine.o src/VirtualMachine.cpp

bin/Stack.o : include/Stack.hpp src/Stack.cpp
	$(CC) $(CFLAGS) -o bin/Stack.o src/Stack.cpp

bin/Variables.o : include/Variables.hpp src/Variables.cpp
	$(CC) $(CFLAGS) -o bin/Variables.o src/Variables.cpp

bin/ByteCodeFileReader.o : include/ByteCodeFileReader.hpp src/ByteCodeFileReader.cpp
	$(CC) $(CFLAGS) -o bin/ByteCodeFileReader.o src/ByteCodeFileReader.cpp

bin/StringPool.o : include/StringPool.hpp src/StringPool.cpp
	$(CC) $(CFLAGS) -o bin/StringPool.o src/StringPool.cpp

clean:
	rm -f bin/*
	rm main.v

