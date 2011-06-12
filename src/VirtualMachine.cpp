//=======================================================================
// Copyright Baptiste Wicht 2011.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

#include <iostream>
#include <iomanip>
#include <fstream>

#include <commons/Timer.h>

#include "ByteCodeFileReader.h"
#include "VirtualMachine.h"
#include "Stack.h"

using namespace std;

int VirtualMachine::run(string file){
	cout << "Run " << file << endl;

	Timer timer;

	ByteCodeFileReader reader(file);

	if(reader.isNotOpen()){
		cout << "Unable to open " << file << endl;
		
		return 1;
	}

	int code = runFile(&reader);

	cout << "Run took " << timer.elapsed() << "ms" << endl;

	reader.close();
	
	return code;
}

int VirtualMachine::runFile(ByteCodeFileReader* reader){
	int header = reader->readHeader();

	if(header != ('E' + 'D' + 'D' + 'I')){
		cout << "Not an EDDI compiled file" << endl;
		return 1;
	}

	Stack stack;

	while(reader->hasMore()){
		ByteCode bytecode = reader->readByteCode();
		
		switch(bytecode){
			case PUSH:{
				char type = reader->readConstantType();

				if(type == 'S'){
					string litteral = reader->readLitteral();

					stack.push(litteral);
				}

				break;
			}
			case PRINT:
				cout << stack.pop() << endl;
				break;
			case END:
				return 0;
		}
	}

	return 0;
}
