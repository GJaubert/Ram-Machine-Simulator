#include "../Instruction.h"

class WRITEInstruction : public Instruction {
  public:
    WRITEInstruction(std::string instructionText, std::string tag, int line);
    virtual ~WRITEInstruction();
    virtual void parseInstruction(std::string instructionText);
    virtual void execute(Memory* memory,  InputTape* iTape, OutputTape* oTape, std::map<std::string,int> tagMap, int pc);
};