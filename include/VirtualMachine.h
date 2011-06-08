#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

#include <iostream>
#include <iomanip>
#include <fstream>

class VirtualMachine {
  public:
    int run (std::string file);
  private:
    int runFile (std::ifstream* inStream);
};

#endif
