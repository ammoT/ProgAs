#include <iostream>
#include "fifo.h"
using namespace std;
int main(int argc, char const *argv[]) {

  std::cout << "Progetto 17/12/2018 - Coda F.I.F.O. - Tommasini Stefano 810929" << std::endl;

  fifo<int> fi(7);
  fi.add(8);
  fi.add(1);
  fi.add(34);
  std::cout << fi << std::endl;
  return 0;
}
