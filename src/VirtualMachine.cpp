#include <iostream>
#include <iomanip>
#include <fstream>

#include <commons/ByteCode.h>
#include <commons/Timer.h>

#include "VirtualMachine.h"

using namespace std;

int VirtualMachine::run(string file){
	cout << "Run " << file << endl;

	Timer timer;

	ifstream inFile;
	inFile.open(file.c_str());

	if(!inFile){
		cout << "Unable to open " << file << endl;
		
		return 1;
	}

	int code = runFile(&inFile);

	cout << "Run took " << timer.elapsed() << "ms" << endl;

	inFile.close();
	
	return code;
}

int VirtualMachine::runFile(ifstream* inStream){
	
	return 0;
}
