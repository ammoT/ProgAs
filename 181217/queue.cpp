#include "queue.h"
#include <iostream>
queue::queue() {
  _dim = 0;
  _fifo = 0;
}

queue::queue(const queue &other) {
  _dim = other._dim;
  _occ = other._occ;
  delete[] _fifo;
  _fifo = 0;
  _fifo = other._fifo;
}

queue::queue(int v) {
  _dim = v;
  _fifo = new int[_dim];
}

queue::~queue() {
  delete[] _fifo;
  _dim = 0;
}

queue& queue::operator=(const queue &other) {
  if (this != &other) {
    queue tmp(other);
    (*this).swap(tmp);
  }
  return *this;
}

std::ostream &operator<<(std::ostream &os, const queue &q) {
  os << "Dimensione : "<< q._dim << std::endl;
  for (int i = 0; i < q._occ ;i++)
    os << "[ " << q._fifo[i] << " ]";
  return os;
}

void queue::swap(queue &other) {
  std::swap(_fifo, other._fifo);
  std::swap(_dim, other._dim);
  std::swap(_occ, other._occ);
}

void queue::add(int value) {
  if(_occ < _dim) {
    _fifo[_occ] = value;
    _occ++;
  }
}
