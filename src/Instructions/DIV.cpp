#include "../../include/instructions/DIV.h"

DIVInstruction::DIVInstruction(std::string instructionText, std::string tag, int line) : Instruction(tag, line){
  operator_ = "DIV";
  parseInstruction(instructionText);
}

DIVInstruction::~DIVInstruction() {}

void DIVInstruction::parseInstruction(std::string instructionText) {
  std::istringstream lineOfText(instructionText);
  std::string token;
  std::regex isNumber("([0-9]+)|(-[0-9]+)");
  lineOfText >> token;
  if ((lineOfText >> token) && ((token[0] == '=') || (token[0] == '*'))) {
    type_ = token[0];
    token.erase(token.begin() + 0);
  } else {
    type_ = 'd';
  }
  if (std::regex_match(token,isNumber)) {
      operand_ = token;
  } else {
      std::cout << "El operando no es un numero\n";
  }
}

void DIVInstruction::execute(Memory* memory,  InputTape* iTape, OutputTape* oTape, std::map<std::string,int> tagMap, int pc) {
}