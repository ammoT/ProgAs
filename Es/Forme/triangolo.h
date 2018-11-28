#ifndef triangolo_H
#define triangolo_H

#include "forma.h"
#include <ostream>
#include <string>

class Triangolo : public Forma {
	punto _v1, _v2, _v3;

public:

	//Triangolo(); 

	Triangolo(
		const std::string &id,
		Color c,
		bool filled,
		const punto &v1,
		const punto &v2,
		const punto &v3);

	Triangolo(const Triangolo &other);

	Triangolo &operator=(const Triangolo &other);

	void swap(Triangolo &other);

	const punto& v1(void) const;

	const punto& v2(void) const;

	const punto& v3(void) const;

	void set_v1(const punto &p1);
		
	void set_v2(const punto &p2);

	void set_v3(const punto &p3);

	void set_vertices(
			const punto &p1,
			const punto &p2,
			const punto &p3);

	double perimetro(void) const;	
};

std::ostream &operator<<(std::ostream &os, 
	const Triangolo &t); 


#endif
