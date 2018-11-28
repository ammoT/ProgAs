#include "triangolo.h"

Triangolo::Triangolo(
		const std::string &id,
		Color c,
		bool filled,
		const punto &v1,
		const punto &v2,
		const punto &v3) : Forma(id,filled,c), 
								_v1(v1), _v2(v2), _v3(v3) {}

Triangolo::Triangolo(const Triangolo &other) 
	: Forma(other), _v1(other._v1), _v2(other._v2), _v3(other._v3) {}

Triangolo &Triangolo::operator=(const Triangolo &other) {
	if (this != &other) {
		Triangolo tmp(other);
		this->swap(tmp);
		/*
		Forma::operator=(other);
		_v1 = other._v1;
		_v2 = other._v2;
		_v3 = other._v3;
		*/
	}	

	return *this;
}

void Triangolo::swap(Triangolo &other) {
	Forma::swap(other);
	std::swap(_v1,other._v1);
	std::swap(_v2,other._v2);
	std::swap(_v3,other._v3);
}

const punto& Triangolo::v1(void) const {
	return _v1;	
}

const punto& Triangolo::v2(void) const {
	return _v2;
}

const punto& Triangolo::v3(void) const {
	return _v3;
}

void Triangolo::set_v1(const punto &p1) {
	_v1 = p1;
}
		
void Triangolo::set_v2(const punto &p2) {
	_v2 = p2;
}

void Triangolo::set_v3(const punto &p3) {
	_v3 = p3;
}

void Triangolo::set_vertices(
			const punto &p1,
			const punto &p2,
			const punto &p3) {
	_v1 = p1;
	_v2 = p2;
	_v3 = p3;
}

double Triangolo::perimetro(void) const {
	double l1 = _v1 - _v2;
	double l2 = _v2 - _v3;
	double l3 = _v3 - _v1;

	return l1 + l2 + l3;
}	

std::ostream &operator<<(std::ostream &os, 
	const Triangolo &t) {

//	os << "id: " << t.id() << std::endl;
//	os << "color: " << t.color() << std::endl;
//	os << "filled: " << t.filled() << std::endl;

	os << static_cast<const Forma &>(t) << std::endl;
	//os << *(static_cast<const Forma *>(&t)) << std::endl;

	os << "v1: " << t.v1() << std::endl;
	os << "v2: " << t.v2() << std::endl;
	os << "v3: " << t.v3();

	return os;	
}


