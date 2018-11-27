#ifndef TRIANGOLO_H
#define TRIANGOLO_H

#include "forma.h"

class Triangolo : public Forma {
  punto _v1, _v2, _v3;
public:
  //Triangolo();
  ~Triangolo();
  Triangolo(const std::string &id, Color c, bool filled, punto v1, punto v2, punto v3);
  Triangolo(const Triangolo &other);
  Triangolo &operator=(const Triangolo &other);
  punto v1(void) const;
  punto v2(void) const;
  punto v3(void) const;
  void swap(Triangolo &other);
  double perimetro(void) const;
  void set_vertices(const punto &p1, const punto &p2, const punto &p3);
};

std::ostream &operator<<(std::ostream &os, const Triangolo &t);
#endif
