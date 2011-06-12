//=======================================================================
// Copyright Baptiste Wicht 2011.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

#ifndef BYTECODE_FILE_READER_H
#define BYTECODE_FILE_READER_H

#include <iostream>
#include <iomanip>
#include <fstream>

#include <commons/ByteCode.h>

using namespace std;

class ByteCodeFileReader {
  public:
	ByteCodeFileReader(string path);
	ByteCode readByteCode();
	char readConstantType();
	string readLitteral();
	int readHeader();
	void close();
	bool isNotOpen();
	bool hasMore();
  private:
    ifstream stream;
};

#endif
