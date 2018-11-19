#include "dbuffer.h" //dbufferT
#include <iostream>
#include <string>
#include "voce.h"
#include <algorithm>

void mysort(dbufferT<int> &db){

  dbufferT<int>::size_type sz,i,j;
  sz = db.size();

  for(i = 0; i < sz ;++i)
    for(j = 0 ; j < sz - 1 ; ++j) {
      if(db[j] > db[j+1])
        std::swap(db[j],db[j+1]);
    }
}
int main(int argc, char const *argv[]) {
  dbufferT<int> db(4);

  db[0] = 2;
  db[1] = 4;
  db[2] = 34;
  db[3] = 23;

  dbufferT<double> dd(10,2.5);
  std::cout << dd << std::endl;
  dbufferT<std::string> ds(3);
  std::cout << ds << std::endl;
  dbufferT<voce> dv(5);
  dv[0] = voce ("Paolino","Paperino","123456789");
  std::cout << dv << std::endl;
  std::cout << db << std::endl;
  mysort(db);
  std::cout << "MySort" << std::endl;
  std::cout << db << std::endl;
  return 0;
}
