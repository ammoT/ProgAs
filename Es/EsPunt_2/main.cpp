#include <iostream>
namespace dbuff {
  typedef unsigned int size_type;
  struct dynamic_buffer{
    unsigned int size;
    int *buffer;
  };

  void print_dynamic_buffer(const dynamic_buffer &db) {
    std::cout << std::endl << "Dynamic_buffer : [ ";
    for (unsigned int i = 0; i < db.size; ++i) {
      std::cout << db.buffer[i] << " ";
    }
    std::cout << "]" << std::endl;
  }

  void init_dynamic_buffer(dynamic_buffer &db) {
    db.size = 0;
    db.buffer = 0;
  }

  void allocate_dynamic_buffer(dynamic_buffer &db, size_type sz = 5){
    if (db.buffer != NULL){
      delete[] db.buffer;
      db.size = 0;
      db.buffer = 0;
    }
    db.buffer = new int[sz];
    db.size = sz;
  }

  void deallocate_dynamic_buffer(dynamic_buffer &db){
    delete[] db.buffer;
    init_dynamic_buffer(db);
  }
  void set_value_dynamic_buffer(dynamic_buffer &db,int values[]) {
    for(size_type i = 0; i < db.size; i++) {
      db.buffer[i] = values[i];
    }
  }
  void copy_dynamic_buffer(dynamic_buffer &db, dynamic_buffer &db2) {
    for (size_type i = 0; i < db2.size; i++) {
      db.buffer[i] = db2.buffer[i];
    }
  }
}

int main(int argc, char *argv[]) {
  dbuff::dynamic_buffer db;
  dbuff::dynamic_buffer db_test;
  int values[] = {1,2,3,4,5};
  dbuff::init_dynamic_buffer(db);
  dbuff::init_dynamic_buffer(db_test);
  dbuff::allocate_dynamic_buffer(db,5);
  dbuff::allocate_dynamic_buffer(db_test,3);
  dbuff::set_value_dynamic_buffer(db, values);
  int valuesB[] = {5,1,2};
  dbuff::set_value_dynamic_buffer(db_test, valuesB);
  dbuff::print_dynamic_buffer(db);
  dbuff::print_dynamic_buffer(db_test);
  dbuff::copy_dynamic_buffer(db,db_test);
  dbuff::print_dynamic_buffer(db);
  dbuff::deallocate_dynamic_buffer(db);
  dbuff::deallocate_dynamic_buffer(db_test);
  dbuff::copy_dynamic_buffer(db,db_test);
  return 0;
}
