#include "dbuffer.h"
#include <iostream>
#include <cassert> //libreria assert

dbuffer::dbuffer() {
  _size = 0;
  _buffer = 0;
}

dbuffer::dbuffer(size_type sz) {
  init(sz);
}

dbuffer::dbuffer(size_type sz, int value) {
  init(sz);
  for (size_type i = 0; i < _size; i++) {
    _buffer[i] = value;
  }
}

void dbuffer::init(size_type sz) {
  _size = 0;
  _buffer = 0;

  _buffer = new int[sz];
  _size = sz;
}

int dbuffer::getValue(size_type index) {
  assert(index < _size); //pre-condizioni
  return _buffer[index];
}

void dbuffer::setValue(size_type index, int value) {
  assert(index < _size); //pre-condizioni
  _buffer[index] = value;
}

//set e get insieme
int& dbuffer::value(size_type index) {
  assert(index < _size); //pre-condizioni
  return _buffer[index];
}

void dbuffer::print() {
  std::cout << "Size :" << _size << std::endl;
  for (size_type i = 0; i < _size; i++)
    std::cout <<"Elemento dbuffer[" << i << "] :" << _buffer[i] << std::endl;
}
