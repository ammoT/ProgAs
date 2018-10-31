#include <iostream>
#include "voce.h"
#include <cassert>
void test_voce(void) {
  voce v;
  std::cout << v << std::endl;
  assert(v.nome == "");
  assert(v.cognome == "");
  assert(v.ntel == "");

  voce v2("Paolino","Paperino","313");
  std::cout << v2 << std::endl;
  assert(v2.nome == "Paolino");
  assert(v2.cognome == "Paperino");
  assert(v2.ntel == "313");

  voce v3(v2);
  std::cout << v3 << std::endl;
  assert(v3.nome == "Paolino");
  assert(v3.cognome == "Paperino");
  assert(v3.ntel == "313");

  v.nome = "Topo";
  v.cognome = "Lino";
  v.ntel = "456";
  assert(v.nome == "Topo");
  assert(v.cognome == "Lino");
  assert(v.ntel == "456");
  v2.swap(v);
  std::cout << v2 << std::endl;
  assert(v2.nome == "Topo");
  assert(v2.cognome == "Lino");
  assert(v2.ntel == "456");
  v = v3;
  std::cout << v3 << std::endl;
  assert(v.nome == "Paolino");
  assert(v.cognome == "Paperino");
  assert(v.ntel == "313");
}
int main(int argc, char const *argv[]) {
  test_voce();
  return 0;
}
