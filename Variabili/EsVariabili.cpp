#include <iostream>
struct pippo {
  int vi;
  double *pd;
};
pippo pip;
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
int fc(const int v) { //const protegge i dati dalla scrittura
  return 0;
}
int fdef(int i3 = 199){ //valore di default, ritorno per copia
  return 0;
}
int *fret() { //ritorno di un puntatore
  //int tmp;
  //return &tmp; // ERRORE logico, puntatore a variabile locale che poi
  //non esiste fuori dalla funzione
  //usare per tornare puntatori a variabili dinamiche ma ricordare di fare
  //la delete nel chiamante
  int *tmp = new int;
  return &tmp;
}

double arr[10][4];
void arrfun(double (*arr)[4]);
//void arrfun(double arr[][4]);
int *fret(int *p) {
  return p; //rindondante ma utilizzabile
}

inline int fi(double d) { //convertite in codice e lo copia al posto della funzione
  //ogni chiamata viene duplicato il codice
  return 0;
}
int fa(char *parray); // array sempre passati per puntatore
//int fa(char parray[]);
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
  fdef(); // è uguale a fare fdef(199);
  return 0;
}
