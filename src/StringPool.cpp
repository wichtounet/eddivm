//=======================================================================
// Copyright Baptiste Wicht 2011.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

#include "StringPool.h"

using std::string;

void StringPool::add(int index, string value){
	strings[index] = value;
}

int StringPool::addNew(string value){
	int index = strings.size() + 1;	

	strings[index] = value;

	return index;
}

string StringPool::get(int index){
	return strings[index];
}
