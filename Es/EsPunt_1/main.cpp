//ES Puntatori
#include <iostream>
#include <algorithm>
//parte I
void print_string(const char s[]);
//parte II
int length_string(const char s[]);
//parte III
void reverse_string(char s[]);
//parte IV
char* copy_string(const char s[]);

int main(int argc, char *argv[]) {
  char * cop;
  if (argc >= 2) {
    print_string(argv[1]);
    std::cout << length_string(argv[1]) << std::endl;
    reverse_string(argv[1]);
    cop = copy_string(argv[1]);
    print_string(cop);
    delete[] cop;
  }

  return 0;
}
void print_string(const char s[]){
  for(; *s != '\0'; s++) {
    std::cout << *s << std::endl;
  }
}
/*
int length_string(const char s[]) {
  int i = 0;
  for(; *s != '\0'; s++)
  return i;
}
*/
int length_string(const char s[]) {
  const char *start = s;
  while (*s != '\0') {
    ++s;
  }
  return s - start;
}
void reverse_string(char s[]) {
  //char *rev = new char[20];
  //const char *start = s;
  int sz = length_string(s) - 1;
  for (int i = 0; i < sz/2 + 1; i++)
    std::swap(s[i],s[sz - i]);
  print_string(s);
}
char* copy_string(const char s[]) {
  char *p = new char[length_string(s)];
  for (int i = 0; i < length_string(s) ;i++) {
    p[i] = s[i];
  }
  return p;
}
