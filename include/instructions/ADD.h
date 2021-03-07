#include "../Instruction.h"

class ADDInstruction : public Instruction {
  public:
    ADDInstruction(std::string instructionText, std::string tag, int line);
    virtual ~ADDInstruction();
    virtual void parseInstruction(std::string instructionText);
    virtual void execute(Memory* memory,  InputTape* iTape, OutputTape* oTape, std::map<std::string,int> tagMap, int pc);
};