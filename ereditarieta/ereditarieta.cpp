#include "ereditarieta.h"
#include <iostream>

// ********* IMPLEMENTAZIONE DI BASE *********

Base::Base() {
	std::cout<<"Base()"<<std::endl;
	// Istruzioni del costruttore di Base
}

Base::Base(int a) {
	std::cout<<"Base(int)"<<std::endl;
	// Istruzioni del costruttore di Base
}

Base::Base(const Base &other) {
	std::cout<<"Base(const Base&)"<<std::endl;
	// Istruzioni del costruttore di copia di Base
}

Base& Base::operator=(const Base &other) {
	std::cout<<"operator=(Base&)"<<std::endl;
	// Istruzioni dell'assegnamento di Base
	return *this;
}

Base::~Base() {
	std::cout<<"~Base()"<<std::endl;
	// Istruzioni del distruttore di Base
}

void Base::swap(Base &other) {
	std::cout<<"Base::swap(Base&)"<<std::endl;
	// Istruzioni della swap di Base
}

// ********* IMPLEMENTAZIONE DI MEMBER *********

Member::Member() {
	std::cout<<"Member()"<<std::endl;
	// Istruzioni del costruttore di Member
}

Member::Member(int a,int b) {
	std::cout<<"Member(int,int)"<<std::endl;
	// Istruzioni del costruttore di Member
}

Member::Member(const Member &other) {
	std::cout<<"Member(const Member&)"<<std::endl;
	// Istruzioni del costruttore di copia di Member
}

Member& Member::operator=(const Member &other) {
	std::cout<<"operator=(const Member&)"<<std::endl;
	// Istruzioni dell'assegnamento di Member
	return *this;
}

Member::~Member() {
	std::cout<<"~Member()"<<std::endl;
	// Istruzioni del distruttore di Member
}

void Member::swap(Member &other) {
	std::cout<<"Member::swap(Member&)"<<std::endl;
	// Istruzioni della swap di Base
}

// ********* IMPLEMENTAZIONE DI DERIVED *********

// In questo costruttore sono chiamati automaticamente i costruttori di default
// della classe base e dell'oggetto membro
// Equivalente a
//Derived::Derived() : Base(), m() {
Derived::Derived() {
	std::cout<<"Derived()"<<std::endl;
	// Istruzioni del costruttore di Derived
}

// Vengono chiamati automaticamente i distruttori dei dati membro
// e della classe base.
Derived::~Derived() {
	std::cout<<"~Derived()"<<std::endl;
	// Istruzioni del distruttore di Derived
}

// Nei vari costruttori si possono chiamare anche costruttori diversi
// da quelli di default per le classe base e gli oggetti membro
// Basta chiamarli nella initialization list
Derived::Derived(int a,int b,int c) : Base(a), m(b,c) {
	std::cout<<"Derived(int,int,int)"<<std::endl;
}

// Nel copy constructor, i dati membro e la classe base devono essere esplicitamente
// costruiti chiamando i loro copy constructor nella initialization list
Derived::Derived(const Derived &other) : Base(other), m(other.m) {
	std::cout<<"Derived(const Derived&)"<<std::endl;
}

// Nell'operatore di assegnamento i dati della classe Base e i dati membro devono essere
// esplicitamente assegnati usando i loro operatori di assegnamento
Derived& Derived::operator=(const Derived &other) {
	std::cout<<"operator=(const Derived&)"<<std::endl;

	if (this != &other) {
		// Versione 1
		m = other.m;
		Base::operator=(other);

		// Versione 2
		//Derived tmp(other);
		//this->swap(tmp);
	}

	return *this;
}

// Dobbiamo chiamare le funzioni di swap dei dati membro e della classe base
void Derived::swap(Derived &other) {
	std::cout<<"Derived::swap(Derived&)"<<std::endl;
	m.swap(other.m);
	Base::swap(other);
}
