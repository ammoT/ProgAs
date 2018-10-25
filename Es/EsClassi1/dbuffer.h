#ifndef DBUFFER_H
#define DBUFFER_H
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

  //costruttore secondario
  dbuffer(size_type sz);
  dbuffer(size_type sz, int value);
  int getValue(size_type index);
  void setValue(size_type index, int value);
  int& value(size_type index);
  void print();
};
#endif
