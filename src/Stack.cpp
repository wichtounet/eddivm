#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>

#include "Stack.h"

void Stack::push(std::string value){
	stack.push(value);
}

std::string Stack::pop(){
	std::string value = stack.top();
	stack.pop();
	return value;
}
