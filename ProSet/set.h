#ifndef SET_H
#define SET_H
template <typename T>
class Set {
private:
  unsigned int _size;
  unsigned int _occ;
  T * _data;

  void init(unsigned int n) {
    _occ = 0;
    _size = n;
    _data = new T(n);
  }

public:
  Set() {
    init(5);
  }
  Set(unsigned int sz) {
    init(sz);
  }
  ~Set() {
    delete[] _data;
    init(0);
  };

  void add(T val) {
    _data[_occ] = val;
    //std::cout << _data[_occ] << std::endl;
    _occ++;

  }

};
#endif
