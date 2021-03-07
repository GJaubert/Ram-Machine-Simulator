#ifndef OUTPUTTAPE
#define OUTPUTTAPE

#include <string>
#include <fstream>
#include "Tape.h"

class OutputTape : public Tape {
  public:
    OutputTape(std::string fileName);
    ~OutputTape();
    void loadOnFile(std::string fileName);
    void writeOnMemory(int value);
};

#endif