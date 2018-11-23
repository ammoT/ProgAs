#include <iostream>
#include "fifo.h"
using namespace std;
int main(int argc, char const *argv[]) {

  std::cout << "Progetto 17/12/2018 - Coda F.I.F.O. - Tommasini Stefano 810929" << std::endl;

  fifo<int> fi(4);
  fifo<int> fi2(fi);
  fi.add(1);
  fi.add(2);
  std::cout << fi << std::endl;
  fi2 = fi;
  std::cout << fi2 << std::endl;

  return 0;
}
