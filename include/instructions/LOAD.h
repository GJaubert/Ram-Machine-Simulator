#include "../Instruction.h"

class LOADInstruction : public Instruction {
  public:
    LOADInstruction(std::string instructionText, std::string tag, int line);
    virtual ~LOADInstruction();
    virtual void parseInstruction(std::string instructionText);
    virtual void execute(Memory* memory,  InputTape* iTape, OutputTape* oTape, std::map<std::string,int> tagMap, int pc);
};