#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <vector>

class Stack {
	public:
	void push(std::string value);
	std::string pop();
	private:
	std::stack<std::string, std::vector<std::string> > stack;
};

#endif
