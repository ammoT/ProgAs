#ifndef FIFO_H
#define FIFO_H

#include <iostream>
#include <cassert>

template <typename T>
class fifo {
  struct nodo {
    T value;
    nodo *next;
    explicit nodo(const T val) : value(val), next(0) {}
  };
private:
  nodo * _inizio;
  nodo * _fine;

public:
  fifo() : _inizio(0), _fine(0) {}
  ~fifo() {
    while(_inizio != 0)
      rimuovi();
    _inizio = 0;
    _fine = 0;
  }

  fifo(const fifo &other) : _inizio(0), _fine(0) {
    nodo *tmp = other._inizio;

    while (tmp != 0) {
      accoda(tmp -> value);
      tmp = tmp -> next;
    }
  }

  template <typename IT>
  fifo(IT inizio, IT fine) : _inizio(0), _fine(0) {
    for (;inizio != fine; inizio++)
    accoda(*inizio);
  }

  fifo &operator=(const fifo &other) {
    nodo *tmp = other._inizio;
    while(_inizio != 0) {
      rimuovi();
    }
    while (tmp != 0){
      accoda(tmp -> value);
      tmp = tmp -> next;
    }
    return *this;
  }

  void accoda(const T &value) {
    nodo *tmp = new nodo(value);
    if (_inizio != 0)
      _fine -> next = tmp;
    else
      _inizio = tmp;
      _fine = tmp;
  }

  T rimuovi(void) {
    assert( _inizio != 0);
    T val = _inizio -> value;
    nodo *tmp = _inizio;
    _inizio = _inizio -> next;
    delete tmp;
    return val;
  }

  unsigned int size(void) const {
    nodo *tmp = _inizio;
    unsigned int cont = 0;
    if (_inizio != 0) {
      while (tmp != 0) {
        tmp = tmp -> next;
        cont++;
      }
    }
    return cont;
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &os,const fifo<T> &f) {
  fifo<T> tmp = f;
  unsigned int sz = tmp.size();
  os << "SIZE : " << sz << std::endl;
  os << " [ ";
  for (unsigned int i = 0; i < sz; ++i) {
    if (i != 0)
      os << ", ";
    os << tmp.rimuovi();
  }
  os << " ] ";
  return os;
}

#endif //FIFO_H
