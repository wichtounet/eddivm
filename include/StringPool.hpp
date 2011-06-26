//=======================================================================
// Copyright Baptiste Wicht 2011.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

#ifndef STRING_POOL_H
#define STRING_POOL_H

#include <string>
#include <map>

class StringPool {
	public:
		void add(int index, std::string value);
		int addNew(std::string value);
		std::string get(int index);
	private:
		std::map<int, std::string> strings;
};

#endif
