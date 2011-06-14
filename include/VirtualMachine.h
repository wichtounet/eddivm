//=======================================================================
// Copyright Baptiste Wicht 2011.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

#include <iostream>
#include <iomanip>
#include <fstream>

#include "ByteCodeFileReader.h"

class VirtualMachine {
  public:
    int run (std::string file);
  private:
    int runFile (ByteCodeFileReader& inStream);
};

#endif
