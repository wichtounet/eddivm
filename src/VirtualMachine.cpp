//=======================================================================
// Copyright Baptiste Wicht 2011.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

#include <commons/Timer.h>

#include "VirtualMachine.h"
#include "Stack.h"
#include "Variables.h"
#include "StringPool.h"

using std::cout;
using std::endl;
using std::string;

int VirtualMachine::run(string file){
	cout << "Run " << file << endl;

	Timer timer;

	ByteCodeFileReader reader(file);

	if(reader.isNotOpen()){
		cout << "Unable to open " << file << endl;
		
		return 1;
	}

	int code = runFile(reader);

	cout << "Run took " << timer.elapsed() << "ms" << endl;

	reader.close();
	
	return code;
}

int VirtualMachine::runFile(ByteCodeFileReader& reader){
	int header = reader.readHeader();

	if(header != ('E' + 'D' + 'D' + 'I')){
		cout << "Not an EDDI compiled file" << endl;
		return 1;
	}

	StringPool pool;

	int strings = reader.readInt();

	for(int i = 0; i < strings; i++){
		int index = reader.readInt();
		string value = reader.readLitteral();

		pool.add(index, value);
	}	

	Stack stack;
	Variables variables;

	while(reader.hasMore()){
		ByteCode bytecode = reader.readByteCode();
	
		switch(bytecode){
			case LDCS:
			case LDCI:{
				int value = reader.readInt();

				stack.push(value);

				break;
			}
			case PRINTI:
				cout << stack.pop() << endl;

				break;
			case PRINTS:
				cout << pool.get(stack.pop()) << endl;

				break;
			case SSTORE:
			case ISTORE:{
				unsigned int variable = reader.readVariable();
				
				variables.assign(variable, stack.pop());
				
				break;
			}
			case SLOAD:
			case ILOAD:{
				unsigned int variable = reader.readVariable();

				stack.push(variables.get(variable));	
				
				break;
			}
			case END:
				return 0;
		}
	}

	cout << "Unexpected end of file" << endl;

	return 0;
}
