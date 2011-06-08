#include <iostream>
#include <iomanip>

#include "VirtualMachine.h"

using namespace std;

int main(int argc, const char* argv[]) {
	if(argc == 1){
		cout << "Not enough arguments. Provide a file to run" << endl;
	}

	VirtualMachine vm;
	
	return vm.run(argv[1]);
}
