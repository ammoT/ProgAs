#include "voce.h"
#include <algorithm>
voce::voce() : nome(""), cognome(""), ntel("") {}

voce::voce(const std::string &n,
     const std::string &c,
     const std::string &nt) : nome(n), cognome(c), ntel(nt){}

voce::voce(const voce &other) :
  nome(other.nome),
  cognome(other.cognome),
  ntel(other.ntel) {}

voce& voce::operator=(const voce &other) {
  if(this != &other) {
    voce tmp(other);
    tmp.swap(*this);
  }
  return *this;
}
voce::~voce() {}

void voce::swap(voce &other) {
  std::swap(nome, other.nome);
  std::swap(cognome, other.cognome);
  std::swap(ntel, other.ntel);
}

std::ostream &operator<<(std::ostream &os,const voce &v) {
  os << " [ " << v.nome ;
  os << ", " << v.cognome ;
  os << ", " << v.ntel << " ]";
  return os;
}
