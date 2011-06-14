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
#include "Variables.h"

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

int VirtualMachine::runFile(ByteCodeFileReader& reader){
	int header = reader->readHeader();

	if(header != ('E' + 'D' + 'D' + 'I')){
		cout << "Not an EDDI compiled file" << endl;
		return 1;
	}

	Stack stack;
	Variables variables;

	while(reader->hasMore()){
		ByteCode bytecode = reader.readByteCode();
		
		switch(bytecode){
			case PUSHS:{
				char type = reader.readConstantType();

				if(type == 'S'){
					string litteral = reader.readLitteral();

					stack.push(litteral);
				}

				break;
			}
			case PUSHV:{
				int variable = reader.readVariable();

				stack.push(variables.get(variable));

				break;
			}
			case ASSIGN:{
				int variable = reader.readVariable();

				variables.assign(variable, stack.pop());

				break;
			}
			case PRINT:
				cout << stack.pop() << endl;
				break;
			case END:
				return 0;
		}
	}

	cout << "Unexpected end of file" << endl;

	return 0;
}
