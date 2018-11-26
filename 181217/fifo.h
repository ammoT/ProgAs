#ifndef FIFO_H
#define FIFO_H

#include <ostream>
#include <cassert>

template <typename T>
class fifo {
private:
  struct nodo {
    T value;
    nodo *next;

    nodo(T val) : value(val), next(0) {}
  };
public:
  nodo *_inizio;
  nodo *_fine;

  //Costruttore default
  fifo() {
    #ifndef NDEBUG
    std::cout << "fifo()" << std::endl;
    #endif
    _inizio = 0;
    _fine = 0;
  }

  //distruttore
  ~fifo() {
    #ifndef NDEBUG
    std::cout << "~fifo()" << std::endl;
    #endif
    unsigned int n = conta_ele();
    for(unsigned int i = 0; i < n; i++)
      rimuovi();
  }

  fifo(const fifo &other) {
    _inizio = other._inizio;
    _fine = other._fine;
  }

  fifo &operator=(const fifo &other) {
    fifo tmp = fifo(other);
    while(other._inizio != 0){
      accoda(tmp.rimuovi());
    }
    return *this;
  }

  //accoda elemento
  void accoda(T value) {
    nodo *tmp = new nodo(value);
    if (_inizio != 0)
      _fine -> next = tmp;
    else
      _inizio = tmp;
    _fine = tmp;
  }

  T rimuovi(void) {
    assert(_inizio != 0);
    nodo *tmp = _inizio;
    T ris = _inizio -> value;
    _inizio = _inizio -> next;
    delete tmp;
    return ris;
  }

  unsigned int conta_ele(void) const {
    unsigned int cont = 0;
    if (_inizio == 0)
      return cont;
    nodo *tmp = _inizio;
    while(tmp != _fine) {
      cont++;
      tmp = tmp -> next;
    }
    return cont + 1; //almeno un ele
  }


};

//operatore di stampa
template <typename T>
std::ostream &operator<<(std::ostream &os, const fifo<T> &f) {
  fifo<T> tmp;
  tmp = f;
  os << " [ ";
  while(tmp._inizio != 0)
    os << tmp.rimuovi() << " ";
  os << "] ";
  return os;
}

/*
template <typename T>
class fifo{
private:
  unsigned int _occ; //n. di valori dentro la coda
  unsigned int _size; //dimensione della coda
  unsigned int _elder; //indice elemento + vecchio
  unsigned int _young; // indice elemento inserito per ultimo
  T* _queue;
public:
  //Costruttore di default
  fifo() : _size(0) , _occ(0) , _elder(0), _young(0){
    #ifndef NDEBUG
    std::cout << "fifo()" << std::endl;
    #endif
  }

  //Costruttore a partire da una dimensione
  explicit fifo(unsigned int n) {
    #ifndef NDEBUG
    std::cout << "fifo(n);" << std::endl;
    #endif
    init(n);
  }

  //copy constructor
  fifo(const fifo &other) : _size(0), _queue(0), _occ(0) {
    std::cout << "fifo(other);" << std::endl;
    init(other._size);
    _occ = other._occ;
    for (unsigned int i = 0; i < _occ ; i++)
      _queue[i] = other._queue[i];
  }

  ~fifo() {
    #ifndef NDEBUG
    std::cout << "~fifo()" << std::endl;
    #endif
    delete[] _queue;
    init(0);
  }

  //operatore [] per accedere alla coda
  T &operator[](unsigned int index) {
    assert(index < _size);
    return _queue[index];
  }

  //operatore [] costante
  const T &operator[](unsigned int index) const {
    assert(index < _size);
    return _queue[index];
  }

  //operatore =
  fifo& operator=(const fifo &other) {
    if (this != &other) {
      fifo<T> tmp(other);
      (*this).swap(tmp);
    }
    return *this;
  }

  //funzione init
  void init(unsigned int n) {
    #ifndef NDEBUG
    std::cout << "init(n)" << std::endl;
    #endif
    _size = n;
    if (_size > 0)
      _queue = new T[_size];
    _occ = 0;
    _young = 0;
    _elder = 0;
  }

  unsigned int filled(void) const {
    return _occ;
  }

  void push(T value) {
    #ifndef NDEBUG
    std::cout << "add(v)" << std::endl;
    #endif
    _queue[_occ] = value;
    _young = _occ;
    _occ++;
  }

  void pop(void) {
    #ifndef NDEBUG
    std::cout << "remove" << std::endl;
    #endif
    assert(_occ > 0);
    fifo<T> tmp(_size);
    for (unsigned int i = 0; i < _occ - 1; i++) {
      tmp._queue[i] = _queue[i + 1];
      tmp._occ++;
    }
    _occ--;
    (*this).swap(tmp);
  }

  //Funzione per lo swap
  void swap(fifo<T> &other) {
    std::swap(_queue, other._queue);
    std::swap(_size, other._size);
    std::swap(_occ, other._occ);
  }
};

//operatore di stampa
template <typename T>
std::ostream &operator<<(std::ostream &os, const fifo<T> &f) {
  os << " [ ";
  for (unsigned int i = 0; i < f.filled(); i++) {
    os << f[i] << " ";
  }
  os << "] ";
  return os;
}
*/

#endif
