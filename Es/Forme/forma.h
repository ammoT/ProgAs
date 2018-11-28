#ifndef forma_H
#define forma_H
#include <ostream>
#include <string>
#include <cmath>

enum Color {clBlack, clWhite, clRed};

class Forma {
	std::string _id;
	bool 		_isfilled;
	Color 		_color;
public:

	//Forma();

	~Forma(void);

	Forma(const Forma &other);

	Forma &operator=(const Forma &other);

	Forma(
		const std::string &s,
		bool filled,
		Color c);

	void swap(Forma &other);

	std::string id(void) const;

	bool filled(void) const;

	Color color(void) const;

	void set_color(Color c);

	void set_filled(bool b);

	virtual double perimetro(void) const = 0;
};

std::ostream &operator<<(std::ostream& os, const Forma &f);

struct punto {
	double x;
	double y;

	punto(void);

	punto(double xx, double yy);
};

std::ostream &operator<<(std::ostream &os, const punto &p);

inline double operator-(const punto &p1, const punto &p2) {
	return std::sqrt((p1.x-p2.x)*(p1.x-p2.x) +
									 (p1.y-p2.y)*(p1.y-p2.y));
}

#endif
