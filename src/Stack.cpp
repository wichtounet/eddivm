//=======================================================================
// Copyright Baptiste Wicht 2011.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

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
