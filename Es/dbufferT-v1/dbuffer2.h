#ifndef DBUFFER_H
#define DBUFFER_H

#include <ostream> // std::ostream
#include <iostream>
#include <cassert> // assert
#include <iterator> // std::forward_iterator_tag
#include <cstddef>  // std::ptrdiff_t


/**
@file dbuffer.h 
@brief Dichiarazione della classe dbuffer
**/

/**
@brief Array dinamico di dati generici

Classe che rappresenta un array dinamico di dati generici. 
La dimensione puo' essere scelta in fase di costruzione.

In questa versione sono stati implementati, a scopo didattico, gli iteratori
di tipo forward_iterator. 
**/
template <typename T=int> // Se non specificato dbufferT contiene interi
class dbufferT {

public:
	typedef unsigned int size_type; ///< Definzione del tipo corrispondente a size

private:
	size_type _size; ///< Puntatore all'array di dati di tipo generico T
	T * _buffer;  ///< Dimensione dell'array

	void init(size_type sz) {
		_buffer = new T[sz];
		_size = sz;
	}

public:
	/**
		@brief Costruttore di default (METODO FONDAMENTALE)

		Costruttore di default per istanziare un dbufferT vuoto. E' l'unico costruttore
		che puo' essere usato per create un array di dbufferT!
	**/
	dbufferT() : _size(0), _buffer(0) { 
		#ifndef NDEBUG 
		std::cout << "dbufferT()" << std::endl;
		#endif
	}

	/**
		@brief Costruttore secondario

		Costruttore secondario. Permette di istanziare un dbufferT con una data dimensione.
		@param size Dimensione del dbuffer da istanziare 
	**/
	explicit dbufferT(size_type sz) : _size(0), _buffer(0) {
		#ifndef NDEBUG 
		std::cout << "dbufferT(sz)" << std::endl;
		#endif
		init(sz);
	}

	/**
		@brief Costruttore secondario

		Costruttore secondario. Permette di istanziare un dbufferT con una data dimensione
		e di inizializzare le celle dell'array con il valore dato
		@param size Dimensione del dbufferT da istanziare
		@param value Valore da usare per inizizalizzare le celle dell'array
	**/
	dbufferT(size_type sz, const T &value) : _size(0), _buffer(0) {
		#ifndef NDEBUG 
		std::cout << "dbufferT(sz,value)" << std::endl;
		#endif

		init(sz);

		try {
		for(size_type i =0; i< _size;++i)
			_buffer[i] = value;
		}
		catch(...) {
			delete[] _buffer;
			_buffer = 0;
			_size = 0;
			throw;
		}
	}

	/**
		@brief Copy constructor (METODO FONDAMENTALE)

		Costruttore di copia. Permette di istanziare un dbufferT con i valori
		presi da un altro dbufferT.
		@param other dbufferT da usare per creare quello corrente
	**/
	dbufferT(const dbufferT &other) : _size(0), _buffer(0) {
		#ifndef NDEBUG 
		std::cout << "dbufferT(dbufferT)" << std::endl;
		#endif

		init(other._size);
		try {
		for (size_type i = 0; i<_size ; ++i)
			_buffer[i] = other._buffer[i];
		}
		catch(...) {
			delete[] _buffer;
			_buffer = 0;
			_size = 0;
			throw;
		}
	}

	/**
		@brief Operatore di assegnamento (METODO FONDAMENTALE)

		Operatore di assegnamento. Permette la copia tra dbufferT.
		@param other dbufferT sorgente
		@return Riferimento a this
	**/
	dbufferT& operator=(const dbufferT &other) {

		if (this != &other) {
			dbufferT tmp(other);
			(*this).swap(tmp); 
			// oppure this->swap(tmp); 
			// oppure tmp.  assert(index < _size); // pre-condizioni
		}
		return *this;
	}

	/**
		@brief Distruttore (METODO FONDAMENTALE)

		Distruttore. Rimuove la memoria allocata da dbuffer.
	**/
	~dbufferT() {
		#ifndef NDEBUG 
		std::cout << "~dbufferT()" << std::endl;
		#endif
		delete[] _buffer;
		_buffer = 0;
		_size = 0;
	}

	/**
		@brief Dimensione dell'array  

		Ritorna la dimensione dell'array dinamico.
		@return La dimensione dell'array dinamico
	**/
	size_type size(void) const {
		return _size;
	}


	/**
		@brief Accesso ai dati in lettura/scrittura (stile C++ con operatore)

		Metodo per leggere/scrivere il valore index-esimo dell'array. 

		@pre E' necessario che index < size
		@param index Indice della cella dell'array da leggere/scrivere
		@return il contenuto della cella index-esima
	**/
	T &operator[](size_type index) {
		assert(index < _size); // pre-condizioni
		return _buffer[index];
	}

	/**
		@brief Accesso ai dati in lettura (stile C++ con operatore)

		Metodo per leggere il valore index-esimo dell'array. 

		@pre E' necessario che index < size
		@param index Indice della cella dell'array da leggere
		@return il contenuto della cella index-esima
	**/
	const T &operator[](size_type index) const {
		assert(index < _size); // pre-condizioni
		return _buffer[index];
	}


	/**
		@brief Scambia il contenuto di due dbufferT

		Scambia il contenuto di due dbufferT.

		@param other dbufferT con il quale scambiare i dati 
	**/
	void swap(dbufferT &other) {
		std::swap(_buffer, other._buffer);
		std::swap(_size, other._size);
	}

	/**
		@brief Costruttore secondario

		Permette di creare un dbufferT e inizizalizzarne i valori
		prendendoli da una generica sequenza di dati 

		@param inizio iteratore di inizio sequenza
		@param fine iteratore di fine sequenza 
	**/
	template <typename IT>
	dbufferT(IT inizio, IT fine) {
		// Contiamo il numero di elementi nella sequenza
		IT tmp = inizio;
		int count = 0;
		for(; tmp != fine; tmp++)
			count++;

		// Inizializziamo lo stato dell'oggetto
		init(count);

		// Copiamo i valori dalla sequenza alle celle dell'array
		size_type pos=0;
		try {
			for(tmp=inizio; tmp != fine; ++tmp) {
				_buffer[pos] = static_cast<T>(*tmp);
				++pos;
			}
		}
		catch(...) { // In caso di problemi svuotiamo l'oggetto
			delete[] _buffer;
			_buffer = 0;
			_size = 0;
			throw;
		}
	}


	class const_iterator; // forward declaration

	class iterator {
	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		typedef ptrdiff_t                 difference_type;
		typedef T*                        pointer;
		typedef T&                        reference;
	
		iterator() : ptr(0) {}
		
		iterator(const iterator &other) 
			: ptr(other.ptr) { }

		iterator& operator=(const iterator &other) {
			ptr = other.ptr;
			return *this;
		}

		~iterator() {ptr=0;}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const {
			return *ptr;
		}

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const {
			return ptr;
		}

		// Operatore di iterazione post-incremento
		iterator operator++(int) {
			iterator tmp(*this);
			++ptr;
			return tmp;
		}

		// Operatore di iterazione pre-incremento
		iterator& operator++() {
			++ptr;
			return *this;
		}

		// Uguaglianza
		bool operator==(const iterator &other) const {
			return ptr == other.ptr;
		}

		// Diversita'
		bool operator!=(const iterator &other) const {
			return !(ptr == other.ptr); // !(*this==other);
		}
		
		// Nei due metodi seguenti iterator deve poter accedere ai dati provati di
		// di const_iterator e viceversa. Per questo motivo le due classi sono messe
		// friend a vicenda.
		friend class const_iterator;

		// Uguaglianza
		bool operator==(const const_iterator &other) const {
			return ptr == other.ptr;
		}

		// Diversita'
		bool operator!=(const const_iterator &other) const {
			return ptr != other.ptr;
		}

	private:
		T* ptr;

		// La classe container deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.
		friend class dbufferT; // !!! Da cambiare il nome!

		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		iterator(T* p) : ptr(p) { }
				
	}; // classe iterator
	
	// Ritorna l'iteratore all'inizio della sequenza dati
	iterator begin() {
		return iterator(_buffer);
	}
	
	// Ritorna l'iteratore alla fine della sequenza dati
	iterator end() {
		return iterator(_buffer+_size);
	}
	
	class const_iterator {
		//	
	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		typedef ptrdiff_t                 difference_type;
		typedef const T*                  pointer;
		typedef const T&                  reference;

		const_iterator() : ptr(0) {
			
		}
		
		const_iterator(const const_iterator &other) : ptr(other.ptr) {
			
		}

		const_iterator& operator=(const const_iterator &other) {
			ptr = other.ptr;
			return *this;
		}

		~const_iterator() {
			ptr = 0;
		}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const {
			return *ptr;
		}

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const {
			return ptr;
		}
		
		// Operatore di iterazione post-incremento
		const_iterator operator++(int) {
			const_iterator tmp(*this);
			ptr++;
			return tmp;
		}

		// Operatore di iterazione pre-incremento
		const_iterator& operator++() {
			ptr++;
			return *this;
		}

		// Uguaglianza
		bool operator==(const const_iterator &other) const {
			return ptr == other.ptr;
		}
		
		// Diversita'
		bool operator!=(const const_iterator &other) const {
			return ptr != other.ptr;
		}

		// Solo se serve anche iterator aggiungere le seguenti definizioni
		
		// Nei due metodi seguenti const_iterator deve poter accedere ai dati provati di
		// di iterator e viceversa. Per questo motivo le due classi sono messe
		// friend a vicenda.
		friend class iterator;

		// Uguaglianza
		bool operator==(const iterator &other) const {
			return ptr == other.ptr;
		}

		// Diversita'
		bool operator!=(const iterator &other) const {
			return ptr!= other.ptr;
		}

		// Costruttore di conversione iterator -> const_iterator
		const_iterator(const iterator &other) 
			: ptr(other.ptr) {			
		}

		// Assegnamento di un iterator ad un const_iterator
		const_iterator &operator=(const iterator &other) {
			ptr = other.ptr;
			return *this;
		}

	private:
		pointer ptr;

		// La classe container deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.
		friend class dbufferT; 

		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		const_iterator(pointer p) : ptr(p) { 
		}
				
	}; // classe const_iterator
	
	// Ritorna l'iteratore all'inizio della sequenza dati
	const_iterator begin() const {
		return const_iterator(_buffer);
	}
	
	// Ritorna l'iteratore alla fine della sequenza dati
	const_iterator end() const {
		return const_iterator(_buffer+_size);
	}

}; // classe dbufferT


/**
	@brief Operatore di stream

	Permette di spedire su uno stream di output il contenuto dell'array generico.
	E' una funzione templata perche' il parametro relativo a dbufferT e' templato

	@param os stream di output
	@param db dbuffer da utilizzare
	@return Il riferimento allo stream di output
**/
template <typename T>
std::ostream &operator<<(std::ostream &os, 
	const dbufferT<T> &db) {

	os << "size: " << db.size() << std::endl;
	for (typename dbufferT<T>::size_type i = 0; i < db.size(); ++i)
		os << db[i] << " ";

	return os;
}
 

#endif

