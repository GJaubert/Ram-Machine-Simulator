#include "../Instruction.h"

class JGTZInstruction : public Instruction {
  public:
    JGTZInstruction(std::string instructionText, std::string tag, int line);
    virtual ~JGTZInstruction();
    virtual void parseInstruction(std::string instructionText);
    virtual void execute(Memory* memory,  InputTape* iTape, OutputTape* oTape, std::map<std::string,int> tagMap, int pc);
};