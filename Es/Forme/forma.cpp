#include "forma.h"
#include <ostream>

//Forma() : _id(""), _color(clBlack), _isFilled(false){}
Forma::~Forma(){}
Forma::Forma(const Forma &other) : _id(other._id),
                            _color(other._color),
                            _isFilled(other._isFilled) {}

Forma &Forma::operator=(const Forma &other) {
  if (this != &other) {
    _id = other._id;
    _color = other._color;
    _isFilled = other._isFilled;
  }
  return *this;
}

Forma::Forma(const std::string &s, bool filled, Color c) : _id(s),
                                                    _color(c),
                                                    _isFilled(filled)  {}
void Forma::swap(Forma &other) {
  std::swap(_id, other._id);
  std::swap(_color, other._color);
  std::swap(_isFilled, other._isFilled);
}

std::string Forma::id() const {
  return _id;
}
bool Forma::filled() const {
  return _isFilled;
}
Color Forma::color() const {
  return _color;
}

void Forma::set_color(Color c) {
  _color = c;
}
void Forma::set_filled(bool b) {
  _isFilled = b;
}

//double Forma::perimetro() const {}

std::ostream &operator<<(std::ostream &os, const Forma &f) {
  os << "Id : " << f.id() << std::endl;
  os << "Color : " << f.color() << std::endl;
  os << "Filled : " << f.filled();
  return os;
}

punto::punto() : x(0), y(0) {}
punto::punto(double xx, double yy) : x(xx), y(yy) {}
