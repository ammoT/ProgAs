#include <iostream>
#include "dbuff.h"
namespace dbuff {
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

  void allocate_dynamic_buffer(dynamic_buffer &db, size_type sz){
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

  dynamic_buffer clone_dynamic_buffer(const dynamic_buffer &src) {
    dynamic_buffer dst;
    init_dynamic_buffer(dst);
    allocate_dynamic_buffer(dst, src.size);
    for (size_type i = 0; i < dst.size; i++) {
      dst.buffer[i] = src.buffer[i];
    }
    return dst;
  }

  dynamic_buffer* clone2_dynamic_buffer(const dynamic_buffer &src) {
    dynamic_buffer *dst = new dynamic_buffer;
    init_dynamic_buffer(*dst);
    allocate_dynamic_buffer(*dst, src.size);
    for (size_type i = 0; i < dst->size; i++) {
      dst->buffer[i] = src.buffer[i];
    }
    return dst;
  }
}
