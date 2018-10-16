#include <iostream>
#include <stdlib.h>
int main (void) {
  int i1 = 1, i2 = 2, i3 = 3;
  int *p = 0;
  std::cout << "&i1 : "<< &i1 << std::endl;
  std::cout << "&i2 : " << &i2 << std::endl;
  std::cout << "&i3 : "<< &i3 << std::endl;
  std::cout << "&p : "<< &p << std::endl;

  std::cout << "i1 : "<< i1 << std::endl;
  std::cout << "i2 : " << i2 << std::endl;
  std::cout << "i3 : "<< i3 << std::endl;
  std::cout << "p : "<< p << std::endl;
  return 0;
}
