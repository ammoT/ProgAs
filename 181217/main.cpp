#include <iostream>
#include "fifo.h"
using namespace std;
int main(int argc, char const *argv[]) {

  std::cout << "Progetto 17/12/2018 - Coda F.I.F.O. - Tommasini Stefano 810929" << std::endl;

  fifo<int> fi(7);
  fi.add(1);
  fi.add(2);
  fi.add(3);
  fi.add(4);
  fi.add(5);
  //fi[3] = 22;
  std::cout << fi << std::endl;
  fi.remove();
  fi.remove();
  fi.remove();
  fi.add(1);
  fi.add(2);
  fi.add(3);
  std::cout << fi << std::endl;

  return 0;
}
