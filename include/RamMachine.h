#ifndef RAMMACHINE
#define RAMMACHINE

#include <memory>
#include "InputTape.h"
#include "OutputTape.h"
#include "Reader.h"
#include "Memory.h"

class RamMachine {
  private:
    InputTape* iTape_;
    OutputTape* oTape_;
    Reader* reader_;
    Memory* memory_;
    std::vector<std::shared_ptr<Instruction>> program_;
    int pc;
    bool error;
  public:
    RamMachine(std::string program, std::string iTape, std::string oTape, bool debuggingMode);
    ~RamMachine();
    void compute();
};

#endif