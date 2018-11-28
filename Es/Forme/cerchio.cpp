#include "cerchio.h"
#include <cmath>

Cerchio::Cerchio(
		const std::string &id,
		Color c,
		bool filled,
		const punto &center,
		double radius) : Forma(id,filled,c), 
						_center(center), _radius(radius) {}

Cerchio::Cerchio(const Cerchio &other) 
	: Forma(other), _center(other._center), _radius(other._radius) {}

Cerchio &Cerchio::operator=(const Cerchio &other) {
	if (this != &other) {
		Cerchio tmp(other);
		this->swap(tmp);
	}	

	return *this;
}

void Cerchio::swap(Cerchio &other) {
	Forma::swap(other);
	std::swap(_center,other._center);
	std::swap(_radius,other._radius);
}

const punto& Cerchio::center(void) const {
	return _center;
}

double Cerchio::radius(void) const {
	return _radius;
}

void Cerchio::set_center(const punto &c) {
	_center = c;
}
		
void Cerchio::set_radius(double r) {
	_radius = r;
}

void Cerchio::set(const punto &c,double r) {
	_center = c;
	_radius = r;
}


double Cerchio::perimetro(void) const {
	return 2*M_PI*_radius;
}	

std::ostream &operator<<(std::ostream &os, 
	const Cerchio &c) {

	os << static_cast<const Forma &>(c) << std::endl;

	os << "center: " << c.center() << std::endl;
	os << "radius: " << c.radius() << std::endl;

	return os;	
}


