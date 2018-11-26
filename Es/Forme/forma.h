#ifndef FORMA_H
#define FORMA_H
enum Color = {clBlack, clRed, clWhite};
class Forma {
private:
  std::string _id;
  bool _isFilled;
  Color _color;
public:
  Forma();
  ~Forma();
  Forma(const Forma &other);
  Forma &operator=(const Forma &other);

  Forma(const std::string &s, bool filled, Color c);
  swap(Forma &other);

  std::string id() const;
  bool filled() const;
  Color color() const;

  void set_color(Color c);
  void set_filled(bool b);

  double perimetro() const;
};
#endif
