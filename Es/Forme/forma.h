#ifndef FORMA_H
#define FORMA_H

#include <cmath>
#include <string>
#include <ostream>

enum Color {clBlack, clRed, clWhite};
class Forma {
private:
  std::string _id;
  bool _isFilled;
  Color _color;

public:
  //Forma();
  ~Forma();
  Forma(const Forma &other);
  Forma &operator=(const Forma &other);

  Forma(const std::string &s, bool filled, Color c);
  void swap(Forma &other);

  std::string id() const;
  bool filled() const;
  Color color() const;

  void set_color(Color c);
  void set_filled(bool b);

  //double perimetro() const;
};
std::ostream &operator<<(std::ostream &os,const Forma &f);

struct punto {
  double x;
  double y;

  punto();
  punto(double xx, double yy);
};
std::ostream &operator<<(std::ostream &os, const punto &p) {
  os << "X : " << p.x << std::endl;
  os << "Y : " << p.y ;
  return os;
}
inline double operator-(const punto  &p1,const punto &p2) {
  return std::sqrt(p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}
#endif
