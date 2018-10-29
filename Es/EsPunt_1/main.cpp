//ES Puntatori
#include <iostream>
#include <algorithm>
#include "utils.h"

int main(int argc, char *argv[]) {
  const char *ris = NULL; // puntatore per risultato
  if (argc > 2) {
    std::cout << "INPUT : ";
    print_string(argv[1]);
    std::cout << "Lunghezza Stringa : " << length_string(argv[1]) << std::endl;
    reverse_string(argv[1]);
    std::cout << "Contrario Stringa : ";
    print_string(argv[1]);
    reverse_string(argv[1]);
    ris = copy_string(argv[1]);
    std::cout << "Copia di "<< argv[1] << " : ";
    print_string(ris);
    delete [] ris;
    ris = NULL;
    ris = concat_string(argv[1],argv[2]);
    std::cout << "Concatenazione di " << argv[1] << " con " << argv[2] << " : ";
    print_string(ris);
    delete [] ris;
    ris = token_string(argv[1],argv[2]);
    std::cout << "Occorrenza Token nella stringa : ";
    print_string(ris);
    ris = sub_string(argv[1],argv[2]);
    print_string(ris);
    delete[] ris;
    std::cout << "Sostituisco "<< argv[2] << " con " << argv[3] << " : "<<std::endl;
    ris = sub_string2(argv[1],argv[2],argv[3]);
    print_string(ris);
    delete[] ris;
  }
  ris = 0;
  return 0;
}
