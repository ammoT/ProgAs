#ifndef QUEUE_H
#define QUEUE_H
#include <ostream>
class queue {
public:
  int *_fifo;
  unsigned int _occ;
  unsigned int _dim;

  queue();
  queue(int v);
  ~queue();
  queue(const queue &other);
  queue& operator=(const queue &other);
  void swap(queue &other);
  void add(int value);
};
std::ostream &operator<<(std::ostream &os, const queue &q);
#endif
