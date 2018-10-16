#include <iostream>
#include <cmath>
#include "nsqrt.h"
int main (void) {
  double x;
  std::cout << "Inserire X : " << std::endl;
  std::cin >> x;
  std::cout << "SQRT : " << std::sqrt(x) << std::endl;
  std::cout << "NSQRT : " << nsqrt(x, 100) << std::endl;
  return 0;
}
