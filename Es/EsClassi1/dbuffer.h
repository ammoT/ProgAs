#ifndef DBUFFER_H
#define DBUFFER_H
#include <ostream>
class dbuffer {
public:
  typedef unsigned int size_type;

private:
  size_type _size;
  int * _buffer;

  void init(size_type sz);

public:
  //Metodi Fondamentali
  dbuffer(); //costruttore di default
  ~dbuffer();
  dbuffer(const dbuffer &other); //copy constructor
  dbuffer& operator=(const dbuffer &other);
  int& operator[](size_type index);
  const int& operator[](size_type index) const;
  //costruttore secondario
  explicit dbuffer(size_type sz); //con explicit funziona solo il cast esplicito
  dbuffer(size_type sz, int value);
  int getValue(size_type index) const;
  void setValue(size_type index, int value);
  int& value(size_type index);
  const int& value(size_type index) const;
  void print() const;
  size_type size() const;
  void swap(dbuffer &other);
};

std::ostream &operator<<(std::ostream &os, const dbuffer &db);
#endif
