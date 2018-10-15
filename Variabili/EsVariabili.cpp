#include <iostream>
int global; // variabile globale, aggiungere .h con extern (extern int global)
int f(int i2) { // i2 contiene una copia di global (Passaggio per valore)
  int b; //variabile locale nella funzione
  i2 = 90; //viene modificata la copia.
}
int f2(int *i2) { //passaggio per puntatore
  static int c; //rimane in memoria
  //controllare se il puntatore diverso da null per sicurezza
  *i2 = 90 // viene modificato il dato originale
}
int f3(int &value) { //passaggio per riferimento, le modifiche si propagano
  return 0;
}
int main(int argc, char const *argv[]) {
  f(global);
  f2(&global);
  f3(global);
  int v; //variabile locale
  double *p = new double[8000000]; //dati dinamici
  delete[] p; // rimuovere array dallo HEAP
  p = 0;
  float *fp = new float;
  delete fp;
  fp = 0; //per essere sicuri mettere sempre puntatore a null
  return 0;
}
