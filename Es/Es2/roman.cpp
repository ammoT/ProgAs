#include "roman.h"
#include <iostream>
void print_roman(int n) {
  int I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000;
  int cont = 0;
  while( n / M >= 1){
    std::cout << "M";
    n = n - M;
  }
  if (n >= 900) {
    std::cout << "CM";
    n -= 900;
  }
  if ( n / D >= 1) {
    std::cout << "D";
    n -= 500;
  }
  if( n > 399 && n < D) {
    std::cout << "CD";
    n = n - 400;
  }
  while( n/C >= 1) {
    std::cout << "C";
    n -= C;
  }

  if (n >= 90) {
    std::cout << "XC";
    n -= 90;
  }
  if( n / L >=1 ) {
    std::cout << "L";
    n -= L;
  }
  if( n > 39 && n < L) {
    std::cout << "XL";
    n -= 40;
  }
  while (n / X >= 1) {
    std::cout << "X";
    n -= 10;
  }
  if (n > 8) {
    std::cout << "IX";
    n -= 9;
  }
  if (n/V >= 1) {
    std::cout << "V";
    n -= V;
  }
  if(n > 3 && n < 5) {
    std::cout << "IV";
    n -= 4;
  }
  while(n > 0) {
    std::cout << "I";
    n--;
  }
  std::cout << std::endl;
}
