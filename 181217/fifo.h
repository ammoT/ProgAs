#ifndef FIFO_H
#define FIFO_H

#include <ostream>

template <typename T>
class fifo{
private:
  unsigned int _occ; //n. di valori dentro la coda
  unsigned int _size; //dimensione della coda
  T* _queue;
public:
  //Costruttore di default
  fifo() : _size(0) , _occ(0) {
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
      fifo tmp(other);
      (*this).swap(tmp);
    }
    return *this;
  }

  //funzione init
  void init(unsigned int n) {
    _size = n;
    _queue = new T[_size];
    _occ = 0;
  }

  unsigned int filled(void) const {
    return _occ;
  }

  void add(T value) {
    _queue[_occ] = value;
    _occ++;
  }

  //Funzione per lo swap
  void swap(fifo &other) {
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

#endif