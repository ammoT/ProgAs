#include <iostream>
#include "date.h"
int main(void) {
  int y1, y2, m1, m2, d1, d2 = 0;
  std::cout << "Inserire anno : ";
  std::cin >> y1;
  std::cout << "Inserire mese : ";
  std::cin >> m1;
  std::cout << "Inserire giorno : ";
  std::cin >> d1;
  std::cout << "Inserire anno : ";
  std::cin >> y2;
  std::cout << "Inserire mese : ";
  std::cin >> m2;
  std::cout << "Inserire giorno : ";
  std::cin >> d2;

  std::cout << "Diff : " << date_difference( y1, m1, d1, y2, m2, d2) << std::endl;

  return 0;
}
