#ifndef DBUFFER_H
#define DBUFFER_H


#include <iostream>
#include <ostream> // std::ostream

template <typename T>
class dbufferT {

public:
	typedef unsigned int size_type;

private:
	size_type _size;
	T * _buffer;


public:


	dbufferT() : _size(0), _buffer(0) {
		#ifndef NDEBUG
		std::cout << "dbuffer()" << std::endl;
		#endif
	}

	dbufferT(size_type sz) : _size(0), _buffer(0) {
		#ifndef NDEBUG
		std::cout << "dbufferT(sz)" << std::endl;
		#endif
		init(sz);
	}

	dbufferT(size_type sz,const T &value) : _size(0), _buffer(0) {
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

	dbufferT(const dbufferT &other) : _size(0), _buffer(0) {
		#ifndef NDEBUG
		std::cout << "dbuffer(dbuffer)" << std::endl;
		#endif

		init(other._size);
		try {
			for(size_type i =0; i< _size;++i)
				_buffer[i] = other._buffer[i];
		}
		catch(...) {
			delete[] _buffer;
			_buffer = 0;
			_size = 0;
			throw;
		}
	}

	void init(size_type sz) {
		_buffer = new T[sz];
		_size = sz;
	}

	~dbufferT() {
		#ifndef NDEBUG
		std::cout << "~dbufferT()" << std::endl;
		#endif
		delete[] _buffer;
		_buffer = 0;
		_size = 0;
	}

	dbufferT& operator=(const dbufferT &other){

		if (this != &other) {
			dbufferT tmp(other);
			(*this).swap(tmp);
			// oppure this->swap(tmp);
			// oppure tmp.swap(*this);
		}
		return *this;
	}

	T& operator[](size_type index) {
		assert(index < _size); // pre-condizioni
		return _buffer[index];
	}

	const T& operator[](size_type index) const {
		assert(index < _size); // pre-condizioni
		return _buffer[index];
	}

	size_type size(void) const {
		return _size;
	}

	void swap(dbufferT &other){
		std::swap(_buffer, other._buffer);
		std::swap(_size, other._size);
	}
};
template <typename T>
	std::ostream &operator<<(std::ostream &os,
		const dbufferT<T> &db) {

		os << "size: " << db.size() << std::endl;
		for (typename dbufferT<T>::size_type i = 0; i < db.size(); ++i)
			os << db[i] << " ";

		return os;
	}
//std::ostream &operator<<(std::ostream &os, const dbufferT &db);

#endif
