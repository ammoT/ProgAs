#include "rubrica.h"
#include <algorithm>
#include <cassert>
#include <fstream>
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
  if (_capacity >= cap) {
    for (unsigned int i = 0; i < _count ; i++)
      tmp._voci[i] = this->_voci[i];
    tmp.swap(*this);
  }
  tmp.swap(*this);
}

unsigned int rubrica::get_capacity() const {
  return _capacity;
}

unsigned int rubrica::get_count() const {
  return _count;
}

const voce &rubrica::operator[](unsigned int index) const {
  assert(index < _count);
  return _voci[index];
}
void rubrica::set_voce(unsigned int index, const voce &value) {
    assert(index < _count);
    //controlli di validità
    for (unsigned int i = 0; i < _count; i++)
      if (value.ntel == _voci[i].ntel && (value.nome != _voci[i].nome ||
        value.cognome != _voci[i].cognome)) {
            throw set_voce_exception();
          }
    _voci[index] = value;
}

void rubrica::add(const voce &v) {
  if (_count == _capacity)
    throw rubrica_full();
  for (unsigned int i = 0; i < _count; i++)
    if (v.ntel == _voci[i].ntel && v.nome == _voci[i].nome && v.cognome == _voci[i].cognome)
      throw voce_duplicated();
  _voci[_count] = v;
  _count++;}

void rubrica::add(const std::string &n,
         const std::string &c,
         const std::string &nt) {
           voce v(n, c, nt);
           add(v);
         }
const voce &rubrica::find(const std::string &nt) const {
  for (unsigned int i = 0;i < _count; i++)
    if (_voci[i].ntel == nt)
      return _voci[i];
  throw voce_not_found_exception();
}
void rubrica::clear(void) {
  _count = 0; // sovrascrivo le nuove voci
  //rubrica tmp(_capacity);
  //tmp.swap(*this);
}

std::ostream& operator<<(std::ostream& os, const rubrica& r) {
  os << "Contenuto della rubrica [" << r.get_count() << "] :" << std::endl;
  for (unsigned int i = 0; i < r.get_count(); i++) {
    os << r[i];
    if(i < r.get_count() - 1)
      os << std::endl;
  }
  return os;
}

void rubrica::save(const std::string &nomefile) {
  // _capacity
  //_count
  //_voci[i]
  std::ofstream ofs;

  ofs.open(nomefile.c_str());
  if (ofs.is_open()) {
    ofs << _capacity << std::endl;
    ofs << _count <<std::endl;
    for (unsigned int i = 0; i < _count ; ++i) {
      ofs << _voci[i].nome << std::endl;
      ofs << _voci[i].cognome << std::endl;
      ofs << _voci[i].ntel << std::endl;
    }
  }
  ofs.close();
}
void rubrica::load(const std::string &nomefile) {

  std::ifstream ifs;
  ifs.open(nomefile.c_str());
  if(ifs.is_open()) {
    rubrica tmp;
    unsigned int capacity;
    unsigned int count;
    ifs >> capacity >> count;
    tmp.set_capacity(capacity);
    for (unsigned int i = 0; i < count ; i++){
      voce v;
      ifs >> v.nome >> v.cognome >> v.ntel;
      tmp.add(v);
    }
    ifs.close();
    tmp.swap(*this);
  }

}
