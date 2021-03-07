#include "../Instruction.h"

class STOREInstruction : public Instruction {
  public:
    STOREInstruction(std::string instructionText, std::string tag, int line);
    virtual ~STOREInstruction();
    virtual void parseInstruction(std::string instructionText);
    virtual void execute(Memory* memory,  InputTape* iTape, OutputTape* oTape, std::map<std::string,int> tagMap, int pc);
};