#ifndef DBUFF_H
#define DBUFF_H
namespace dbuff{
  typedef unsigned int size_type;
  /**
    Struttura dati che definisce un buffer dinamico
  */
  struct dynamic_buffer {
    unsigned int size;  ///< dimensione del buffer
    int *buffer;  ///< puntatore all'array degli elementi
  };

  /**
    Stampa il contenuto di un Dynamic Buffer.
    @param db dynamic buffer da stampare.
  */
  void print_dynamic_buffer(const dynamic_buffer &db);
  /**
    Inizializza il contenuto del buffer a 0.
    @param db dynamic buffer da inizializzare.
  */
  void init_dynamic_buffer(dynamic_buffer &db);
  /**
    Alloca un Dynamic Buffer ad una dimensione specifica.
    @param db dynamic buffer da allocare.
    @param sz dimensione del dynamic buffer.
  */
  void allocate_dynamic_buffer(dynamic_buffer &db, size_type sz = 5);
  /**
    Dealloca un Dynamic Buffer.
    @param db dynamic buffer da deallocare
  */
  void deallocate_dynamic_buffer(dynamic_buffer &db);
  /**
    Immette nel dynamic buffer i valori.
    @param db dynamic buffer da riempire.
    @param values array di valori che saranno inseriti nel buffer.
  */
  void set_value_dynamic_buffer(dynamic_buffer &db,int values[]);
  /**
    Copia un dynamic buffer.
    @param db dynamic buffer da copiare.
    @return una copia del dynamic buffer
  */
  dynamic_buffer clone_dynamic_buffer(const dynamic_buffer &src);
  /**
    Copia un dynamic buffer.
    @param db dynamic buffer da copiare.
    @return un puntatore ad una copia del dynamic buffer
  */
  dynamic_buffer* clone2_dynamic_buffer(const dynamic_buffer &src);
}
#endif
