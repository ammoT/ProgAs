#ifndef VOCE_H
#define VOCE_H
#include <string>
#include <ostream>
struct voce {
  std::string nome;
  std::string cognome;
  std::string ntel;

  voce();
  voce(const std::string &n,
       const std::string &c,
       const std::string &nt);
  voce(const voce &other);
  voce &operator=(const voce &other);
  ~voce();
  void swap(voce &other);
};
std::ostream &operator<<(std::ostream &os,const voce &v);
#endif
