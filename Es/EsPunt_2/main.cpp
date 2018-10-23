#include "dbuff.h"
int main(int argc, char *argv[]) {
  dbuff::dynamic_buffer db;
  dbuff::dynamic_buffer *db_test;
  int values[] = {1,2,3,4,5};
  dbuff::init_dynamic_buffer(db);
  dbuff::allocate_dynamic_buffer(db,5);
  dbuff::set_value_dynamic_buffer(db, values);
  dbuff::print_dynamic_buffer(db);
  db_test = dbuff::clone2_dynamic_buffer(db);
  dbuff::print_dynamic_buffer(*db_test);
  dbuff::deallocate_dynamic_buffer(db);
  dbuff::deallocate_dynamic_buffer(*db_test);
  delete db_test;
  return 0;
}
