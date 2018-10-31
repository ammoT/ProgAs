#include "dbuffer.h"
#include <iostream>
#include <cassert> //libreria assert
#include <algorithm>

dbuffer::dbuffer() : _size(0), _buffer(0){
  #ifndef NDEBUG
  std::cout << "dbuffer()" << std::endl;
  #endif

  _size = 0;
  _buffer = 0;
}

dbuffer::dbuffer(size_type sz) {
  #ifndef NDEBUG
  std::cout << "dbuffer(size_type sz)" << std::endl;
  #endif
  init(sz);
}

dbuffer::dbuffer(size_type sz, int value) {
  #ifndef NDEBUG
  std::cout << "dbuffer(size_type sz, int value)" << std::endl;
  #endif
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

int dbuffer::getValue(size_type index) const{
  assert(index < _size); //pre-condizioni
  return _buffer[index];
}

void dbuffer::setValue(size_type index, int value) {
  assert(index < _size); //pre-condizioni
  _buffer[index] = value;
}

//set e get insieme
int& dbuffer::value(size_type index){
  assert(index < _size); //pre-condizioni
  return _buffer[index];
}

const int& dbuffer::value(size_type index) const{
  assert(index < _size); //pre-condizioni
  return _buffer[index];
}

void dbuffer::print() const {
  std::cout << "Size :" << _size << std::endl;
  for (size_type i = 0; i < _size; i++)
    std::cout <<"Elemento dbuffer[" << i << "] :" << _buffer[i] << std::endl;
}

dbuffer::~dbuffer() {
  #ifndef NDEBUG
  std::cout << "~dbuffer()" << std::endl;
  #endif
  delete[] _buffer;
  _buffer = 0;
  _size = 0;
}

dbuffer::dbuffer(const dbuffer &other) {
  #ifndef NDEBUG
  std::cout << "dbuffer(dbuffer)" << std::endl;
  #endif
  init(other._size);
  for (size_type i = 0; i < _size; i++)
    _buffer[i] = other._buffer[i];
}
/*
dbuffer& dbuffer::operator=(const dbuffer &other) {
  if(this != &other){
    size_type  tmpsize = _size;
  int *tmpbuffer = _buffer;
  if (this != &other) {
  if (_size > 0) {
      delete[] _buffer;
      _size = 0;
      _buffer = 0;

    try {
      init(other._size);
    }
    catch(...){
      _buffer = tmpbuffer;
      _size = tmpsize;
      throw;
    }
    for (size_type i = 0; i < _size; i++)
      _buffer[i] = other._buffer[i];
    delete[] tmpbuffer;
    tmpbuffer = 0;
  }
  return *this;
}
*/

dbuffer& dbuffer::operator=(const dbuffer &other) {
  if(this != &other){
    dbuffer tmp(other);
    (*this).swap(tmp);
    /*
    delete[] _buffer;
    _buffer = tmp._buffer;
    _size = tmp._size;
    tmp._buffer = 0;
    tmp._size = 0;
    */
  }
  return *this;
}

int& dbuffer::operator[](size_type index){
  assert(index < _size); //pre-condizioni
  return _buffer[index];
}

const int& dbuffer::operator[](size_type index) const{
  assert(index < _size); //pre-condizioni
  return _buffer[index];
}


dbuffer::size_type dbuffer::size() const {
  return _size;
}

std::ostream &operator<<(std::ostream &os, const dbuffer &db) {
  os << "Size :" << db.size() << std::endl;
  for (dbuffer::size_type i = 0; i <db.size(); i++)
    os <<"Elemento dbuffer[" << i << "] :"<< db[i] << std::endl;
  return os;
}

void dbuffer::swap(dbuffer &other) {
  std::swap(_buffer, other._buffer);
  std::swap(_size, other._size);
}
