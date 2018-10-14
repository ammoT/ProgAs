#include <iostream>
#include "includes/operazioni.h"
int main(void) {
  float a,b;
  std::cout << "Inserire numero : ";
  std::cin >> a;
  std::cout << "Inserire numero : ";
  std::cin >> b;
  std::cout << "Somma :" << somma(a,b) << std::endl;
  std::cout << "Sottrazione :" << sottr(a,b) << std::endl;
  std::cout << "Divisione :" << div(a,b) << std::endl;
  std::cout << "Moltiplicazione :" << mult(a,b) << std::endl;
}
