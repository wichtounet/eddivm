//=======================================================================
// Copyright Baptiste Wicht 2011.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

#ifndef VARIABLES_H
#define VARIABLES_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

class Variables {
	public:
	void assign(unsigned int variable, std::string value);
	std::string get(unsigned int variable); 
	private:
	std::map<unsigned int, std::string> variables;
};

#endif
