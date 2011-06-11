#include <iostream>
#include <iomanip>
#include <fstream>

#include <commons/IO.h>
#include <commons/ByteCode.h>
#include <commons/Timer.h>

#include "ByteCodeFileReader.h"

using namespace std;

ByteCodeFileReader::ByteCodeFileReader(string path){
	stream.open(path.c_str(), ios::binary);
	stream.unsetf(ios_base::skipws);
}

bool ByteCodeFileReader::isNotOpen(){
	return !stream;
}

bool ByteCodeFileReader::hasMore(){
	return !stream.eof();
}

ByteCode ByteCodeFileReader::readByteCode(){
	int bytecode;
	binary_read(&stream, bytecode);
	return (ByteCode) bytecode;
}

int ByteCodeFileReader::readHeader(){
	int header;
	binary_read(&stream, header);
	return header;
}

char ByteCodeFileReader::readConstantType(){
	char type;
	binary_read(&stream, type);
	return type;
}

string ByteCodeFileReader::readLitteral(){
	size_t size;
	binary_read(&stream, size);
	
	char* buffer = new char[size + 1];
	stream.read(buffer, size);
	buffer[size] = 0;
	string litteral = buffer;
	delete[] buffer;	

	return litteral;
}

void ByteCodeFileReader::close(){
	stream.close();
}
