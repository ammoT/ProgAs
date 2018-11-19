#include "queue.h"
#include <iostream>
int main(int argc, char const *argv[]) {
  queue q(4);
  q.add(5);
  q.add(3);
  q.add(44);
  std::cout << q;
  return 0;
}
