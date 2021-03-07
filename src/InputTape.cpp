#include "../include/InputTape.h"

//Constructor de la clase InputTape
InputTape::InputTape(std::string fileName) : Tape(fileName) {
  index_ = 0;
  load(fileName);
}

//Funcion load que abre un fichero y rellena la cinta de entrada
void InputTape::load(std::string fileName) {
  values_.clear();
  std::ifstream file(fileName_);
  std::string inputValue;
  std::regex isNumber("([0-9]+)|(-[0-9]+)");
  bool match;
  if (!file.is_open()) {
    std::cout << "No se pudo abrir el fichero\n";
  }
  while (file >> inputValue) {
    if (std::regex_match(inputValue,isNumber)) {
      values_.push_back(std::stoi(inputValue));
    } else {
      std::cout << "Se introdujo un valor que no es integer\n";
    }
  }
}

//Resetea la cinta de entrada
void InputTape::reset() {
  load(fileName_);
}

//Destructor de la clase InpuTape
InputTape::~InputTape() {}

//Imprime la cinta de entrada almacenada
void InputTape::printInputTape() {
  std::cout << "Cadena de entrada -> [";
  for (int i = 0; i < values_.size(); i++) {
    std::cout << " " << values_[i];
  }
  std::cout << " ]\n";
}

int InputTape::getElement() {
  return values_[index_++];
}

int InputTape::getIndex() {
  return index_;
}