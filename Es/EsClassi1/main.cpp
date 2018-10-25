#include "dbuffer.h"
int main(int argc, char const *argv[]) {
  dbuffer buff = dbuffer(5, 10);
  buff.print();
  return 0;
}
