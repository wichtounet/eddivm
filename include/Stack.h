//=======================================================================
// Copyright Baptiste Wicht 2011.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

#ifndef STACK_H
#define STACK_H

#include <iostream>
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
