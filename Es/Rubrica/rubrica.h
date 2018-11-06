#ifndef RUBRICA_H
#define RUBRICA_H
#include "voce.h"

class set_voce_exception {};
class voce_duplicated {};
class rubrica_full {};
class voce_not_found_exception {};
class rubrica {
private:
  voce *_voci; ///< puntatore all'array di voci
  unsigned int _capacity; ///< dimensione dell'array massima
  unsigned int _count; ///< numero di voci registrate

public:
  rubrica();
  rubrica(const rubrica &other);
  rubrica& operator=(const rubrica &other);
  ~rubrica();

  explicit rubrica(unsigned int cap);
  void set_capacity(unsigned int cap);
  void swap(rubrica &other);

  unsigned int get_capacity() const;
  unsigned int get_count() const;

  const voce &operator[](unsigned int index) const; ///< legge solo una voce
  void set_voce(unsigned int index, const voce &value);

  void add(const voce &v);
  void add(const std::string &n,
           const std::string &c,
           const std::string &nt);
  const voce &find(const std::string &nt) const;
  void clear(void);
  void save(const std::string &nomefile);
  void load(const std::string &nomefile);
};

std::ostream& operator<<(std::ostream& os, const rubrica& r);

#endif
