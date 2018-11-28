#ifndef quadrilatero_H
#define quadrilatero_H

#include "forma.h"
#include <ostream>
#include <string>

class Quadrilatero : public Forma {
	punto _v1, _v2, _v3, _v4;

public:

	Quadrilatero(
		const std::string &id,
		Color c,
		bool filled,
		const punto &v1,
		const punto &v2,
		const punto &v3,
		const punto &v4);

	Quadrilatero(const Quadrilatero &other);

	Quadrilatero &operator=(const Quadrilatero &other);

	void swap(Quadrilatero &other);

	const punto &v1(void) const;

	const punto &v2(void) const;

	const punto &v3(void) const;

	const punto &v4(void) const;

	void set_v1(const punto &p1);
		
	void set_v2(const punto &p2);

	void set_v3(const punto &p3);

	void set_v4(const punto &p3);

	void set_vertices(
			const punto &p1,
			const punto &p2,
			const punto &p3,
			const punto &p4);

	double perimetro(void) const;	
};

std::ostream &operator<<(std::ostream &os, 
	const Quadrilatero &t); 


#endif
