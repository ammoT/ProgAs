#ifndef cerchio_H
#define cerchio_H

#include "forma.h"
#include <ostream>
#include <string>

class Cerchio : public Forma {
	punto _center;
	double _radius;

public:

	Cerchio(
		const std::string &id,
		Color c,
		bool filled,
		const punto &center,
		double radius);

	Cerchio(const Cerchio &other);

	Cerchio &operator=(const Cerchio &other);

	void swap(Cerchio &other);

	const punto& center(void) const;

	double radius(void) const;

	void set_center(const punto &c);
		
	void set_radius(double r);

	void set(const punto &c,double r);

	double perimetro(void) const;	
};

std::ostream &operator<<(std::ostream &os, 
	const Cerchio &c); 


#endif
