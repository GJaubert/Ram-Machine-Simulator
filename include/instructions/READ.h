#include "../Instruction.h"

class READInstruction : public Instruction {
  public:
    READInstruction(std::string instructionText, std::string tag, int line);
    virtual ~READInstruction();
    virtual void parseInstruction(std::string instructionText);
    virtual void execute(Memory* memory,  InputTape* iTape, OutputTape* oTape, std::map<std::string,int> tagMap, int pc);
};