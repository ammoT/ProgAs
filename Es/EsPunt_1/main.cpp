//ES Puntatori
#include <iostream>
#include <algorithm>
#include "utils.h"

int main(int argc, char *argv[]) {
  const char *ris = NULL; // puntatore per risultato
  if (argc >= 2) {
    print_string(argv[1]);
    std::cout << "Lunghezza Stringa :" << length_string(argv[1]) << std::endl;
    reverse_string(argv[1]);
    ris = copy_string(argv[1]);
    print_string(ris);
  }
  delete[] ris;
  ris = 0;
  return 0;
}
