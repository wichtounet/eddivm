//=======================================================================
// Copyright Baptiste Wicht 2011.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

#include <commons/IO.h>

#include "ByteCodeFileReader.h"

using std::string;
using std::ios;
using std::ios_base;

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

unsigned int ByteCodeFileReader::readVariable(){
	unsigned int variable;
	binary_read(&stream, variable);
	return variable;
}

char ByteCodeFileReader::readConstantType(){
	char type;
	binary_read(&stream, type);
	return type;
}

string ByteCodeFileReader::readLitteral(){
	string:size_type size;
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
