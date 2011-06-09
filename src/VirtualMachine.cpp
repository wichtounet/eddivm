#include <iostream>
#include <iomanip>
#include <fstream>

#include <commons/ByteCode.h>
#include <commons/Timer.h>

#include "VirtualMachine.h"
#include "Stack.h"

using namespace std;

int VirtualMachine::run(string file){
	cout << "Run " << file << endl;

	Timer timer;

	ifstream inFile;
	inFile.open(file.c_str(), ios::binary);
	inFile.unsetf(ios_base::skipws);

	if(!inFile){
		cout << "Unable to open " << file << endl;
		
		return 1;
	}

	int code = runFile(&inFile);

	cout << "Run took " << timer.elapsed() << "ms" << endl;

	inFile.close();
	
	return code;
}

int VirtualMachine::runFile(ifstream* stream){
	Stack stack;

	while(!stream->eof()){
		ByteCode bytecode = readByteCode(stream);
		
		switch(bytecode){
			case PUSH:{
				char type = readConstantType(stream);

				if(type == 'S'){
					string litteral = readLitteral(stream);

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
