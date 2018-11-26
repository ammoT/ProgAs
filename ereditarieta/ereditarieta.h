#ifndef EREDITARIETA_H
#define EREDITARIETA_H

/**
	Esempio di classe per lo studio dell'ereditarieta'
	La classe sara' usata come classe base di una gerarchia
*/
class Base {
	// Eventuali dati membro
public:
	/**
		Costruttore di default
	*/
	Base();

	/**
		Costruttore secondario
		@param a parametro
	*/
	explicit Base(int a);

	/**
		Costruttore di copia
		@param other oggetto da copiare
	*/
	Base(const Base &other);

	/**
		Operatore di assegnamento
		@param other operando di destra
		@return un riferimento a this
	*/
	Base& operator=(const Base &other);

	/**
		Distruttore
	*/
	~Base();

	/**
		Metodo di swap
		@param other dato da swappare
	*/
	void swap(Base &other);
};

/**
	Esempio di classe per lo studio dell'ereditarieta'
	La classe sara' usata per istanziare un oggetto membro di un'altra classe
*/
class Member {
	// Eventuali dati membro
public:
	/**
		Costruttore di default
	*/
	Member();

	/**
		Costruttore decondario
		@param a parametro
		@param b parametro
	*/
	Member(int a, int b);

	/**
		Costruttore di copia
		@param other oggetto da copiare
	*/
	Member(const Member &other);

	/**
		Operatore di assegnamento
		@param other operando di destra
		@return un riferimento a this
	*/
	Member& operator=(const Member &other);

	/**
		Distruttore
	*/
	~Member();

	/**
		Metodo di swap
		@param other dato da swappare
	*/
	void swap(Member &other);
};

/**
	Esempio di classe per lo studio dell'ereditarieta'
	La classe eredita da Base e include al suo interno un dato membro di tipo
	Member
*/
class Derived : public Base {

	Member m;

public:
	/**
		Costruttore di default
	*/
	Derived();

	/**
		Costruttore decondario
		@param a parametro
		@param b parametro
		@param c parametro
	*/
	Derived(int a, int b, int c);

	/**
		Costruttore di copia
		@param other oggetto da copiare
	*/
	Derived(const Derived &other);

	/**
		Operatore di assegnamento
		@param other operando di destra
		@return un riferimento a this
	*/
	Derived& operator=(const Derived &other);

	/**
		Distruttore
	*/
	~Derived();

	/**
		Metodo di swap
		@param other dato da swappare
	*/
	void swap(Derived &other);
};

#endif
