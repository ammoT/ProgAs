#include "complesso.h"
#include "cmath"
complesso::complesso() : re(0), im(0) {}
complesso::complesso(double r, double i) : re(r), im(i) {}
complesso::complesso(const complesso &other)
  : re(other.re) , im(other.im) {}
complesso& complesso::operator=(const complesso &other) {
  re = other.re;
  im = other.im;
  return *this;
}
complesso::~complesso() {}

std::ostream &operator<<(std::ostream &os, const complesso &other) {
  os << other.re << " + i"<< other.im ;
  return os;
}

complesso complesso::operator+(const complesso &dx) const {
  complesso ris(re + dx.re, im + dx.im);
  return ris;
}

complesso operator*(const complesso &sx, const complesso &dx) {
  complesso ris;
  ris.re = sx.re * dx.re - sx.im * dx.im;
  ris.im = sx.re * dx.im + sx.im * dx.re;
  return ris;
}

complesso operator*(const complesso &sx, const double dx) {
  complesso ris;
  ris.re = sx.re * dx;
  ris.im = sx.im * dx;
  return ris;
}
complesso operator*(const double sx, const complesso &dx) {
  return dx * sx;
}

double complesso::operator!(void) const {
  return std::sqrt(re * re + im * im);
}
//c1 = (*c2);
complesso operator*(const complesso &dx) { //coniugato prefisso
  complesso ris(dx.re, -dx.im);
  return ris;
}

complesso operator/(const complesso &sx, const complesso &dx) {
  complesso ris;
  double m = (!dx);
  ris = (sx * (*dx)) * (1.0 / (m * m));
  return ris;
}
