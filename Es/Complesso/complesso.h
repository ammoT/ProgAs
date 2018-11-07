#ifndef COMPLESSO_H
#define COMPLESSO_H
#include <ostream>
struct complesso {
  double re;
  double im;

  complesso();
  complesso(double r, double i);
  complesso(const complesso &other);
  ~complesso();
  complesso& operator=(const complesso &other);
  complesso operator+(const complesso &dx) const;
  //complesso operator*(const complesso &dx);
  double operator!(void) const; //operatore modulo


};
std::ostream &operator<<(std::ostream &os, const complesso &other);
//complesso operator+(const complesso &sx, const complesso &dx); //se non è interno alla classe
complesso operator*(const complesso &sx, const complesso &dx);
complesso operator*(const complesso &sx, const double dx);
complesso operator*(const double dx, const complesso &sx);
complesso operator*(const complesso &dx); //coniugato
complesso operator/(const complesso &dx, const complesso &sx);
#endif
