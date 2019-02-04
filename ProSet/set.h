#ifndef SET_H
#define SET_H
template <typename T>
class mySet {
private:
  unsigned int _size;
  unsigned int _occ;
  T * _data;

  void init(unsigned int n) {
    _data = new T(n);
    _size = n;
    _occ = 0;
  }

public:
  mySet() {
    init(5);
  }
  mySet(unsigned int sz) {
    init(sz);
  }

  mySet(const mySet &other) : _size(0), _data(0), _occ(0) {
    init(other._size);
    for (unsigned int i = 0; i < other._occ; i++) {
      _data[i] = other._data[i];
    }
    _occ = other._occ;
  }

  mySet& operator=(const mySet &other) {
    if(this != &other) {
      mySet tmp(other);
      (*this).swap(tmp);
    }
    return *this;
  }

  ~mySet() {
    delete[] _data;
    init(0);
  }

  void swap(mySet &other) {
    std::swap(_data, other._data);
    std::swap(_size, other._size);
    std::swap(_occ, other._occ);
  }

  void add(T val) {
    if(chkSet(val)) {
      _data[_occ] = val;
      //std::cout << _data[_occ] << std::endl;
      _occ++;
    }
    else {
      std::cout << "Valore gia presente" << std::endl;
    }
  }

  unsigned int size(void) const {
    return _size;
  }

  unsigned int filled(void) const {
    return _occ;
  }

  const T &operator[](unsigned int index) const {
		assert(index < _size); // pre-condizioni
		return _data[index];
	}

  bool chkSet(const T val) {
    bool chk = true;
    for (unsigned int i = 0; i < _occ; i++) {
      if (val == _data[i])
        chk = false;
      }
    return chk;
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const mySet<T> &st) {
  os << "size: " << st.size() << std::endl;
  os << "[ ";
  for (unsigned int i = 0; i < st.filled(); ++i) {
    if (i!=0)
      os << ", ";
    os << st[i] ;
  }
  os << " ] ";

	return os;
}

#endif
