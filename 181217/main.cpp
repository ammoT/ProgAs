#include <iostream>
#include "fifo.h"
using namespace std;
int main(int argc, char const *argv[]) {

  std::cout << "Progetto 17/12/2018 - Coda F.I.F.O. - Tommasini Stefano 810929" << std::endl;

  fifo<int> fi;
    fifo<std::string> fs;
    fi.accoda(1);
    fi.accoda(2);
    fi.accoda(3);
    fi.accoda(4);
    fi.accoda(4);
    fi.rimuovi();

    fs.accoda("a");
    fs.accoda("B");
    fs.accoda("C");
    fs.accoda("CIAO");

    std::cout << fi << std::endl;
    std::cout << fs << std::endl;
  return 0;
}
