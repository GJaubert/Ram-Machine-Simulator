#include "../../include/instructions/JUMP.h"

JUMPInstruction::JUMPInstruction(std::string instructionText, std::string tag, int line) : Instruction(tag, line){
  operator_ = "JUMP";
  parseInstruction(instructionText);
}

JUMPInstruction::~JUMPInstruction() {}

void JUMPInstruction::parseInstruction(std::string instructionText) {
  std::istringstream lineOfText(instructionText);
  std::string token;
  std::regex isNumber("([0-9]+)|(-[0-9]+)");
  lineOfText >> token;
  if ((lineOfText >> token) && (!std::regex_match(token,isNumber))) {
    type_ = '\0';
    operand_ = token;
  } else {
      std::cout << "Tras u salto debe haber una etiqueta\n";
  }
  if (lineOfText >> token) {
    std::cout << "Solo puede haber una etiqueta y nada mas que una etiqueta tras un salto\n";
  }
}

void JUMPInstruction::execute(Memory* memory,  InputTape* iTape, OutputTape* oTape, std::map<std::string,int> tagMap, int pc) {
}