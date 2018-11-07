#include <iostream>
#include "complesso.h"
int main(int argc, char const *argv[]) {
  complesso a(6655,2), b(3,4);
  std::cout << a + b << std::endl;
  std::cout << a * b << std::endl;
  std::cout << a / b << std::endl;
  return 0;
}
