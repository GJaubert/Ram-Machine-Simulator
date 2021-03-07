#include "../include/RamMachine.h"

//Constructor de la clase RamMachine
RamMachine::RamMachine(std::string program, std::string iTape, std::string oTape, bool debuggingMode) {
  reader_ = new Reader(program);
  program_ = reader_->parseText();
  iTape_ = new InputTape(iTape);
  oTape_ = new OutputTape(oTape);
  memory_ = new Memory();
  error = false;
  pc = 0;
  iTape_->printInputTape();
}

//Destructor de la clase RamMachine
RamMachine::~RamMachine() {
  delete reader_;
  delete oTape_;
  delete memory_;
  delete iTape_;
}

void RamMachine::compute() {
  std::map<std::string, int> map;
  program_[0]->execute(memory_, iTape_, oTape_, map, pc++);
  program_[1]->execute(memory_, iTape_, oTape_, map, pc++);
  program_[2]->execute(memory_, iTape_, oTape_, map, pc++);
  program_[3]->execute(memory_, iTape_, oTape_, map, pc++);
  std::cout << memory_->getRegister(2) << std::endl;
  program_[4]->execute(memory_, iTape_, oTape_, map, pc++);
  program_[5]->execute(memory_, iTape_, oTape_, map, pc++);
  program_[6]->execute(memory_, iTape_, oTape_, map, pc++);
  std::cout << memory_->getRegister(2) << std::endl;
  // for (int i = 0; i < program_.size(); i++) {

  // }
}