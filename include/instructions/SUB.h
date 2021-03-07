#include "../Instruction.h"

class SUBInstruction : public Instruction {
  public:
    SUBInstruction(std::string instructionText, std::string tag, int line);
    virtual ~SUBInstruction();
    virtual void parseInstruction(std::string instructionText);
    virtual void execute(Memory* memory,  InputTape* iTape, OutputTape* oTape, std::map<std::string,int> tagMap, int pc);
};