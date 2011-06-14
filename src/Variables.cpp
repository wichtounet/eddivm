//=======================================================================
// Copyright Baptiste Wicht 2011.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

#include "Variables.h"

void Variables::assign(unsigned int variable, std::string value){
	variables[variable] = value;
}

std::string Variables::get(unsigned int variable){
	return variables[variable];
}
