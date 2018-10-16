#include "roman.h"
#include <iostream>
int main (void) {
  int n = 3;
  do {
    std::cout << "Inserire un numero : " << std::endl;
    std::cin >> n;
  } while ( n < 1 || n > 3999);
  print_roman(n);
  return 0;
}
