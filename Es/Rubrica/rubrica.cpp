#include "rubrica.h"
#include <algorithm>
rubrica::rubrica() : _voci(0), _capacity(0), _count(0) {}

rubrica::rubrica(const rubrica &other) :
  _voci(0), _capacity(0), _count(0) {
    _voci = new voce[other._capacity];
    for (unsigned int i = 0; i < other._count; i++)
      _voci[i] = other._voci[i];
    _capacity = other._capacity;
    _count = other._count;
  }

  rubrica& rubrica::operator=(const rubrica &other) {
    if (this != &other) {
      rubrica tmp(other);
      tmp.swap(*this);
    }
    return *this;
  }

void rubrica::swap(rubrica &other) {
  std::swap(_voci, other._voci);
  std::swap(_capacity, other._capacity);
  std::swap(_count, other._count);
}

rubrica::~rubrica(void) {
  delete[] _voci;
  _voci = 0;
  _capacity = 0;
  _count = 0;
}

rubrica::rubrica(unsigned int cap) : _voci(0), _capacity(0), _count(0) {
  _voci = new voce[cap];
  _capacity = cap;
}

void rubrica::set_capacity(unsigned int cap) {
  rubrica tmp(cap);
  if (_capacity <= cap) {
    for (unsigned int i = 0; i < _count ; i++)
      tmp._voci[i] = this->_voci[i];
    tmp.swap(*this);
  }
    tmp.swap(*this);
}
