#include "../include/Tape.h"

//Constructor de la clase Tape
Tape::Tape(std::string fileName) {
  fileName_ = fileName;
  index_ = 0;
  values_.resize(0);
}