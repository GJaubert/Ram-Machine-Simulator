#include "../Instruction.h"

class DIVInstruction : public Instruction {
  public:
    DIVInstruction(std::string instructionText, std::string tag, int line);
    virtual ~DIVInstruction();
    virtual void parseInstruction(std::string instructionText);
    virtual void execute(Memory* memory,  InputTape* iTape, OutputTape* oTape, std::map<std::string,int> tagMap, int pc);
};