#ifndef RUBRICA_H
#define RUBRICA_H
#include "voce.h"
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
};

#endif
