#include <iostream>
#include "fifo.h"
using namespace std;
int main(int argc, char const *argv[]) {

  std::cout << "Progetto 17/12/2018 - Coda F.I.F.O. - Tommasini Stefano 810929" << std::endl;

  fifo<int> fi,fi2;

  fi.accoda(1);
  fi.accoda(2);
  fi.accoda(3);
  fi.accoda(4);
  fi.accoda(5);
  std::cout << "Numero di Elementi : " << fi.conta_ele() << std::endl;
  fi2 = fi;
  std::cout << fi2 << std::endl;
  fi.rimuovi();
  fi.rimuovi();
  fi.rimuovi();
  std::cout << fi << std::endl;
  return 0;
}
