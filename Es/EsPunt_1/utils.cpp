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
}
//Parte IV
const char* copy_string(const char s[]) {
  int sz = length_string(s) + 1;
  char *p = new char[sz];
  for (int i = 0; i < sz ;i++) {
    p[i] = s[i];
  }
  return p;
}
//Parte V
char* concat_string(const char s1[], const char s2[]) {
  int sz1 = length_string(s1);
  int sz2 = length_string(s2);
  int sz = sz1 + sz2 + 1;
  char *p = new char[sz];
  for (int i = 0; i < sz1; i++) {
    p[i] = s1[i];
  }
  for (int i = 0; i <= sz2; i++) { // <= per il carattere terminatore
    p[i + sz1] = s2[i];
  }
  return p;
}
//Parte VI
const char* token_string(const char t[], const char pat[]) {
  return NULL;
}
