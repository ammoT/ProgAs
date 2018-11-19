#include "dbuffer.h"
#include <cassert> // assert
#include <iostream> // cout
#include <algorithm> // std::swap

dbuffer::dbuffer() : _size(0), _buffer(0) { 
	#ifndef NDEBUG 
	std::cout << "dbuffer()" << std::endl;
	#endif
}

dbuffer::dbuffer(size_type sz) : _size(0), _buffer(0) {
	#ifndef NDEBUG 
	std::cout << "dbuffer(sz)" << std::endl;
	#endif
	init(sz);
}

dbuffer::dbuffer(size_type sz, int value) : _size(0), _buffer(0) {
	#ifndef NDEBUG 
	std::cout << "dbuffer(sz,value)" << std::endl;
	#endif

	init(sz);

	for(size_type i =0; i< _size;++i)
		_buffer[i] = value;
}

dbuffer::dbuffer(const dbuffer &other) : _size(0), _buffer(0) {
	#ifndef NDEBUG 
	std::cout << "dbuffer(dbuffer)" << std::endl;
	#endif

	init(other._size);
	for (size_type i = 0; i<_size ; ++i)
		_buffer[i] = other._buffer[i];
}

void dbuffer::init(size_type sz) {
	_buffer = new int[sz];
	_size = sz;
}

dbuffer::~dbuffer() {
	#ifndef NDEBUG 
	std::cout << "~dbuffer()" << std::endl;
	#endif
	delete[] _buffer;
	_buffer = 0;
	_size = 0;
}

dbuffer& dbuffer::operator=(const dbuffer &other){

	if (this != &other) {
		dbuffer tmp(other);
		(*this).swap(tmp); 
		// oppure this->swap(tmp); 
		// oppure tmp.swap(*this);
	}

	return *this;
}

int& dbuffer::operator[](size_type index) {
	assert(index < _size); // pre-condizioni
	return _buffer[index];
}

const int& dbuffer::operator[](size_type index) const {
	assert(index < _size); // pre-condizioni
	return _buffer[index];
}

dbuffer::size_type dbuffer::size(void) const {
	return _size;
}

void dbuffer::swap(dbuffer &other){
	std::swap(_buffer, other._buffer);
	std::swap(_size, other._size);
}


std::ostream &operator<<(std::ostream &os, 
	const dbuffer &db) {

	os << "size: " << db.size() << std::endl;
	for (dbuffer::size_type i = 0; i < db.size(); ++i)
		os << db[i] << " ";

	return os;
}





