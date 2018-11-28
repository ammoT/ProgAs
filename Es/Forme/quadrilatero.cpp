#include "quadrilatero.h"

Quadrilatero::Quadrilatero(
		const std::string &id,
		Color c,
		bool filled,
		const punto &v1,
		const punto &v2,
		const punto &v3,
		const punto &v4) : Forma(id,filled,c),
							_v1(v1), _v2(v2), _v3(v3), _v4(v4) {}

Quadrilatero::Quadrilatero(const Quadrilatero &other)
	: Forma(other), _v1(other._v1), _v2(other._v2), _v3(other._v3), _v4(other._v4) {}

Quadrilatero &Quadrilatero::operator=(const Quadrilatero &other) {
	if (this != &other) {
		Quadrilatero tmp(other);
		this->swap(tmp);
	}

	return *this;
}

void Quadrilatero::swap(Quadrilatero &other) {
	Forma::swap(other);
	std::swap(_v1,other._v1);
	std::swap(_v2,other._v2);
	std::swap(_v3,other._v3);
	std::swap(_v4,other._v4);
}

const punto &Quadrilatero::v1(void) const {
	return _v1;
}

const punto &Quadrilatero::v2(void) const {
	return _v2;
}

const punto &Quadrilatero::v3(void) const {
	return _v3;
}

const punto &Quadrilatero::v4(void) const {
	return _v4;
}

void Quadrilatero::set_v1(const punto &p1) {
	_v1 = p1;
}

void Quadrilatero::set_v2(const punto &p2) {
	_v2 = p2;
}

void Quadrilatero::set_v3(const punto &p3) {
	_v3 = p3;
}

void Quadrilatero::set_v4(const punto &p4) {
	_v4 = p4;
}

void Quadrilatero::set_vertices(
			const punto &p1,
			const punto &p2,
			const punto &p3,
			const punto &p4) {
	_v1 = p1;
	_v2 = p2;
	_v3 = p3;
	_v4 = p4;
}

double Quadrilatero::perimetro(void) const {
	double l1 = _v1 - _v2;
	double l2 = _v2 - _v3;
	double l3 = _v3 - _v4;
	double l4 = _v4 - _v1;

	return l1 + l2 + l3 + l4;
}

std::ostream &operator<<(std::ostream &os,
	const Quadrilatero &t) {


	os << static_cast<const Forma &>(t) << std::endl;

	os << "v1: " << t.v1() << std::endl;
	os << "v2: " << t.v2() << std::endl;
	os << "v3: " << t.v3() << std::endl;
	os << "v4: " << t.v4();

	return os;
}
