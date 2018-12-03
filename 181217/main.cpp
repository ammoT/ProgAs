#include <iostream>
#include "fifo.h"

#include <vector>

using namespace std;
int main(int argc, char const *argv[]) {
  std::cout << std::endl;
  std::cout << "Progetto 17/12/2018 - Coda F.I.F.O. - Tommasini Stefano 810929" << std::endl;
  std::cout << endl;
  fifo<int> fi;
  fifo<std::string> fs;
  fi.accoda(1);
  fi.accoda(2);
  fi.accoda(3);
  fi.accoda(4);
  fi.accoda(4);

  fifo<int> fc;

  for (int i = 0 ; i < 1000; i++) {
    fc.accoda(i);
  }
  std::cout << fc.trova(666) << std::endl;
  std::cout << fc << std::endl;

  if(fi.trova(2))
    std::cout << "Trovato" <<std::endl ;

  fifo<int> copia;
  fifo<int> a = fi;
  copia = fi;

  copia.rimuovi();

  fs.accoda("a");
  fs.accoda("B");
  fs.accoda("C");
  fs.accoda("CIAO");

  std::cout << fi << std::endl << std::endl;
  std::cout << "COPIA DI fi : " <<std::endl;
  std::cout << copia << std::endl << std::endl;
  //std::cout << "COPIA DI fi : "<< copia << std::endl << std::endl;
  std::cout << fs << std::endl;
  std::cout << a.rimuovi() << std::endl;
  std::cout << a.rimuovi() << std::endl;
  std::cout << a.rimuovi() << std::endl;
  std::cout << a << std::endl;

  std::vector<double> v;

  v.push_back(1.1);
  v.push_back(2.2);
  v.push_back(3.3);
  v.push_back(4.4);

  fifo<double> fd(v.begin(),v.end());

  std::cout << fd << std::endl;

  return 0;
}
