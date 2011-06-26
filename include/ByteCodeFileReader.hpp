//=======================================================================
// Copyright Baptiste Wicht 2011.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

#ifndef BYTECODE_FILE_READER_H
#define BYTECODE_FILE_READER_H

#include <fstream>

#include <commons/ByteCode.hpp>

class ByteCodeFileReader {
  public:
	ByteCodeFileReader(std::string path);
	ByteCode readByteCode();
	unsigned int readVariable();
	char readConstantType();
	std::string readLitteral();
	int readHeader();
	int readInt();
	void close();
	bool isNotOpen();
	bool hasMore();
  private:
    std::ifstream stream;
};

#endif
