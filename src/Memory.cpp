#include "../include/Memory.h"
#include <iostream>

//Constructor de la clase Memory
Memory::Memory() {
  registers_.resize(1);
  acc_ = &registers_[0];
}

//Destructor de la clase Memory
Memory::~Memory() {}

int Memory::getRegister(int registerNumber) {
  return registers_[registerNumber]; 
}

void Memory::setRegister(int registerNumber, int value) {
  registers_.resize(registerNumber);
  registers_[registerNumber] = value;
}

int Memory::getAcc() {
  return registers_[0];
}

void Memory::setAcc(int value) {
  registers_[0] = value;
}