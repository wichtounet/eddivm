//=======================================================================
// Copyright Baptiste Wicht 2011.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

#include "Stack.hpp"

void Stack::push(int value){
	stack.push(value);
}

int Stack::pop(){
	int value = stack.top();
	stack.pop();
	return value;
}
