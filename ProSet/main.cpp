#include <iostream>
#include "set.h"
int main(void) {
  std::cout << "----<Stefano Tommasini 810929>----" << std::endl;
  mySet<int> si;
  si.add(1);
  si.add(2);
  std::cout << si << std::endl;
  return 0;
}
