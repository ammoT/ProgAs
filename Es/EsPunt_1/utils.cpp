#include <iostream>
#include "utils.h"
//Parte I
void print_string(const char s[]){
  for(; *s != '\0'; s++) {
    std::cout << *s;
  }
  std::cout << std::endl;
}
/*
int length_string(const char s[]) {
  int i = 0;
  for(; *s != '\0'; s++)
  return i;
}
*/
//Parte II
int length_string(const char s[]) {
  const char *start = s;
  while (*s != '\0') {
    ++s;
  }
  return s - start;
}
//Parte III
void reverse_string(char s[]) {
  int sz = length_string(s) - 1;
  for (int i = 0; i <= sz/2; i++)
    std::swap(s[i],s[sz - i]);
  print_string(s);
}
//Parte IV
const char* copy_string(const char s[]) {
  int sz = length_string(s) + 1; // senza + 1 valgrind da errori strani
  char *p = new char[sz];
  for (int i = 0; i < sz ;i++) {
    p[i] = s[i];
  }
  return p;
}
