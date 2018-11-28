#include "forma.h"
#include <algorithm>

//Forma::Forma() : _id(""), _color(clBlack), _isfilled(false) {}
	
Forma::~Forma(void) { }
	
Forma::Forma(const Forma &other) :
 _id(other._id), _isfilled(other._isfilled), _color(other._color) {}
	
Forma &Forma::operator=(const Forma &other) {
	if (this != &other) {
		_id = other._id;
		_color = other._color;
		_isfilled = other._isfilled;
	}	

	return *this;
}
	
Forma::Forma(const std::string &s, bool filled, Color c)
: _id(s), _isfilled(filled), _color(c) {}

void Forma::swap(Forma &other) {
	std::swap(_id, other._id);
	std::swap(_color, other._color);
	std::swap(_isfilled, other._isfilled);
}

std::string Forma::id(void) const {
	return _id;
}

bool Forma::filled(void) const {
	return _isfilled;
}

Color Forma::color(void) const {
	return _color;
}

void Forma::set_color(Color c) {
	_color = c;
}

void Forma::set_filled(bool b) {
	_isfilled = b;
}

std::ostream &operator<<(std::ostream& os, const Forma &f) {
	os << "id: " << f.id() << std::endl;
	os << "color: " << f.color() << std::endl;
	os << "filled: " << f. filled();
	return os;
}


punto::punto(void) : x(0), y(0) {}

punto::punto(double xx, double yy) 
	: x(xx), y(yy) {}


std::ostream &operator<<(std::ostream &os, const punto &p) {
	os << "[" << p.x << " " << p.y << "]";

	return os;
}



