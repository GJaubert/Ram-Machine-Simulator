#include "../Instruction.h"

class JUMPInstruction : public Instruction {
  public:
    JUMPInstruction(std::string instructionText, std::string tag, int line);
    virtual ~JUMPInstruction();
    virtual void parseInstruction(std::string instructionText);
    virtual void execute(Memory* memory,  InputTape* iTape, OutputTape* oTape, std::map<std::string,int> tagMap, int pc);
};