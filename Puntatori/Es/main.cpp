#include <iostream>
int main(int argc, char const *argv[]) {
  //stampare in ordine inverso i caratteri di una stringa allocata come
  //array primitivo, usando i puntatori.
  char str[30] = "i topi non avevano nipoti";
  char *p = str;
  p = str + 24;

  for (int i = 0; i <= 24 ;i++) {
    std::cout << *(p - i);
  }
  std::cout << std::endl;
  p = str;
  std::cout << str << std::endl;
  for (int i = 0; i <= 24; i++) {
    if (*p == ' ')
      std::cout << i << std::endl;
    p++;
  }

  char *ptr = &(str[24]);
  for (; ptr >= str; --ptr) {
    std::cout << *ptr;
  }
  std::cout << std::endl;
  return 0;
}
