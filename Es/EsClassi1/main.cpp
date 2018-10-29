#include "dbuffer.h"

void f(dbuffer db){
  //viene utilizzato il costruttore di copia
}

int main(int argc, char const *argv[]) {
  dbuffer buff = dbuffer(5, 10);
  buff.value(2) = 3;
  buff.print();
  dbuffer db4(buff);
  db4.print();
  f(db4);
  dbuffer db5[3];
  dbuffer *db6ptr = new dbuffer[3];
  delete[] db6ptr;
  dbuffer db7 = dbuffer(5,99);
  buff = db7;
  buff.print();
  return 0;
}
