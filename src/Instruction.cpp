#include "../include/Instruction.h"

Instruction::Instruction(std::string tag, int line) {
  tag_ = tag;
  line_ = line;
}

std::string Instruction::getOperator() {
  return operator_;
}

std::string Instruction::getOperand() {
  return operand_;
}

std::string Instruction::getTag() {
  return tag_;
}

char Instruction::getType() {
  return type_;
}

int Instruction::getLine() {
  return line_;
}

void Instruction::printInstruction() {
  std::cout << "[ ";
  if (!tag_.empty()) {
    std::cout << tag_ << " ";
  }
  std::cout << operator_ << " ";
  if (type_ != '\0') {
    std::cout << type_;
  }
  if (!operand_.empty()) {
    std::cout <<  operand_;
  }
  std::cout << "] en la linea " << line_ << "\n";  
}