#include "../include/OutputTape.h"

//Constructor de la clase OutputTape
OutputTape::OutputTape(std::string fileName) : Tape(fileName) {
  loadOnFile(fileName);
}

//Funcion load que abre un fichero y rellena la cinta de entrada
void OutputTape::loadOnFile(std::string fileName) {
  std::ofstream file(fileName_);
  if (!file.is_open()) {
    std::cout << "No se pudo abrir el fichero\n";
  }
  for (int i = 0; i < values_.size(); i++) {
    file << values_[i] << std::endl;
  }
}

//Destructor de la clase InpuTape
OutputTape::~OutputTape() {
}

//Imprime la cinta de entrada almacenada
void OutputTape::writeOnMemory(int value) {
  values_.push_back(value);
  index_++;
}