#include <iostream>
#include "triangolo.h"
#include "cerchio.h"
#include "quadrilatero.h"
#include <vector>

void f(const std::vector<Forma *> &forme) {

  std::vector<Forma *>::const_iterator i,ie;

  for (i = forme.begin(),ie = forme.end(); i != ie; ++i){
    std::cout << (*i) -> perimetro() << std::endl;
  }

  for (int i = 0; i < forme.size();i++) {
    std::cout << forme[i] -> id() << std::endl;
  }

}

int main(int argc, char const *argv[]) {

  Triangolo t1("t1",
                clBlack,
                false,
                punto(0,0),
                punto(10,10),
                punto(100,0));

  Triangolo t2("t2",
                clWhite,
                false,
                punto(2,3),
                punto(20,10),
                punto(50,0));

  Triangolo t3("t3",
                clRed,
                false,
                punto(6,7),
                punto(95,13),
                punto(70,20));

  Cerchio c1("c1", clBlack, false, punto(1,1), 12);

  Quadrilatero q1("q1",
                clWhite,
                false,
                punto(2,3),
                punto(20,10),
                punto(50,0),
                punto(12,42));

  //Forma f1("f1", false, clWhite);

  std::cout << t1 << std::endl << std::endl;
  std::cout << q1 << std::endl << std::endl;
  //std::cout << f1 << std::endl << std::endl;
  std::cout << c1 << std::endl << std::endl;

  std::vector<Forma *> forme;

  forme.push_back(&t1);
  forme.push_back(&t2);
  forme.push_back(&t3);
  forme.push_back(&c1);
  forme.push_back(&q1);

  f(forme);

  Triangolo *t = dynamic_cast<Triangolo *> (forme[0]);

  return 0;
}
