#include "../Instruction.h"

class JZEROInstruction : public Instruction {
  public:
    JZEROInstruction(std::string instructionText, std::string tag, int line);
    virtual ~JZEROInstruction();
    virtual void parseInstruction(std::string instructionText);
    virtual void execute(Memory* memory,  InputTape* iTape, OutputTape* oTape, std::map<std::string,int> tagMap, int pc);
};