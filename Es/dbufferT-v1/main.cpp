#include <iostream>
#include <string>
#include "voce.h"
#include <algorithm> // std::swap, std::count_if

/*
  NOTA: Vi ho fornito tre versioni di dbufferT che differiscono
  per come sono implementati gli iteratori:
  
  dbuffer.h:  iteratori di tipo random
  dbuffer2.h: iteratori di tipo forward che contengono un puntatore ai dati T
  dbuffer3.h: iteratori di tipo forward che contengono un puntatore alla classe dbufferT 

*/

#include "dbuffer3.h" // dbufferT

// Nostra reimplementazione della funzione di swap 
// della libreria standard. E' il piu' semplice algoritmo
// generico che possiamo creare.
template <typename T>
void myswap(T &a, T &b) {
	T tmp(a);
	a = b;
	b = tmp;
}

// Rudefinizione dell'operatore maggiore 
// Se un tipo di dato non possiede un operatore
// possiamo ridefinirlo usando una funzione operator globale
bool operator>(const voce &dx, const voce &sx) {
	return dx.cognome > sx.cognome;
}


// Funtore per il confronto tra due voci sul campo cognome
// Un funtore e' un oggetto che contiene un metodo operator()
// Simula una funzione. L'operatore puo' avere un numero variabile 
// di parametri. 
struct compare_voce_by_cognome {
	bool operator()(const voce &dx, const voce &sx) const {
		return dx.cognome > sx.cognome;		
	}
};


// Funtore per il confronto tra due voci sul campo nome
struct compare_voce_by_nome {
	bool operator()(const voce &dx, const voce &sx) const {
		return dx.nome > sx.nome;		
	}
};

// Funzione che esegue il sort (in place) dei dati contenuti
// in un dbufferT di interi.  
void mysort(dbufferT<int> &db) {
	typename dbufferT<int>::size_type sz,i,j;
	sz = db.size();
	for(i = 0; i < sz; ++i) {
		for (j = 0; j < sz-1; ++j) {
			if (db[j]>db[j+1]) 
				myswap(db[j],db[j+1]);
		}
	}	
}

// Funzione generica che esegue il sort (in place) dei dati contenuti
// in un dbufferT. Dato che il confronto tra due dati T non e' noto a 
// priori, usiamo un secondo parametro templato per definire il tipo
// (ignoto) del funtore da usare per eseguire il confronto.  
template <typename T, typename F>
void mysort(dbufferT<T> &db, F compare) {
	typename dbufferT<T>::size_type sz,i,j;
	sz = db.size();
	for(i = 0; i < sz; ++i) {
		for (j = 0; j < sz-1; ++j) {
			if (compare(db[j],db[j+1])) 
				myswap(db[j],db[j+1]);
		}
	}	
}

// Funtore che valuta la linghezza del campo cognome dei una voce
// e ritorna true se la lunghezza e' maggiore di una soglia
// passata come parametro del costruttore della classe
class valuta_cognome {
	int soglia;
public:
	explicit valuta_cognome(int s) : soglia(s) {}
	bool operator()(const voce &v) const {
		return v.cognome.size() > soglia;	
	}	
};


// Funzione generica che stampa una voce contenuta nel dbufferT se 
// una generica condizione, espressa usando un funtore F, e' soddisfatta
template <typename F>
void stampa_voci(
	const dbufferT<voce> &db,
	F funct) {
	dbufferT<voce>::size_type sz = db.size(), i;

	for(i=0; i<sz; ++i)
		if (funct(db[i])) 
			std::cout << db[i] << std::endl;
}

// Funzione generica che conta il numero di elementi di una generica
// sequenza di dati, espressa usando due iteratori, che soddisfano
// una generica condizione, espressa con un funtore F.
template <typename IT, typename F>
int conta_elementi(IT inizio, IT fine, F eval) {
	int count = 0;	
	for(; inizio != fine; ++inizio) 
		if (eval(*inizio)) 
			count++;

	return count;
}

// Funzione che ritorna true sse il nome della voce passata 
// finisce con la lettera 'a'
bool check_nome(const voce &v) {
	std::string nome = v.nome;

	char lastc = nome[nome.size()-1];
	return lastc == 'a';
}

// Funzione per testare i const_iterator della classe dbufferT
void f(const dbufferT<int> &dbi) {
	dbufferT<int>::const_iterator ci, cie;

	std::cout<<"*** Stampa di dbi usando i const_iterator: "<<std::endl;
	for(ci = dbi.begin(),cie=dbi.end(); ci!=cie; ++ci) 
		std::cout<<"ci: "<< *ci << std::endl;
}

int main() {

	dbufferT<int> db(5); // T diventa int

	db[0] = 2;
	db[1] = 1;
	db[2] = 20;
	db[3] = 12;
	db[4] = 26;

	std::cout << "*** Stampa di db prima del sort: " << std::endl;
	std::cout<< db << std::endl << std::endl;
	mysort(db);
	std::cout << "*** Stampa di db dopo il sort: "<< std::endl;
	std::cout << db << std::endl << std::endl;

	dbufferT<voce> dv(5);

	dv[0] = voce("paolino","paperino","3213");
	dv[1] = voce("aaaa","bbbb","5555");
	dv[2] = voce("hghjj","jgfj","765");
	dv[3] = voce("ttttt","zzzzz","3213");
	dv[4] = voce("ccccc","aaaaaa","3213");

	std::cout << "*** Stampa dv prima del sort: " << std::endl;
	std::cout << dv << std::endl << std::endl;

	// Istanzio il funtore per il confronto
	compare_voce_by_cognome cvc;
	mysort(dv,cvc);

	std::cout << "*** Stampa dv dopo il sort by cognome: " << std::endl;
	std::cout << dv << std::endl;

	// Istanzio un altro funtore per il confronto
	compare_voce_by_nome cvn;
	mysort(dv,cvn);

	std::cout << "*** Stampa dv dopo il sort by nome: " << std::endl;
	std::cout << dv << std::endl << std::endl;

	std::cout<< "*** Chiamata alla funzione stampa_voci con valuta_cognome(5):" << std::endl;
	stampa_voci(dv,valuta_cognome(5));
	std::cout << std::endl;

	// Test degli iteratori di dbufferT
	// Istanzio due oggetti iterator di dbufferT<voce>
	dbufferT<voce>::iterator it, ite;

	// Assegno a it l'inizio della sequenza di dati di dbufferT
	// Assegno a ite la fine della sequenza di dati di dbufferT
	it  = dv.begin();
	ite = dv.end();

	// Itero sulle voci e le stampo usando gli iteratori
	std::cout<<"*** Stampa di dv usando gli iteratori:"<<std::endl;
	for(; it != ite; ++it) 
		std::cout << "it: " << *it << std::endl; 
	std::cout << std::endl;

	int result = conta_elementi(
			dv.begin(),
			dv.end(),
			valuta_cognome(5)
	);

	std::cout<<"*** Risultato di conta_elementi con il funtore valuta_cognome(5): ";
	std::cout << result <<std::endl << std::endl;

	result = conta_elementi(
		dv.begin(),
		dv.end(),
		check_nome);	

	std::cout<<"*** Risultato di conta_elementi con la funzione check_nome: ";
	std::cout << result <<std::endl << std::endl;

	result = std::count_if(
		dv.begin(),
		dv.end(),
		check_nome);

	std::cout<<"*** Risultato di std::count_if con la funzione check_nome: ";
		std::cout << result <<std::endl << std::endl;

	int array[3] = {1,5,7};

	// Creo un dbufferT di interi prendendo i dati dall'array primitivo
	// I puntatori array e array+size definiscono due iteratori che possono
	// essere passati al costruttore generico
	dbufferT<int> dbi(array, array+3); 

	std::cout<<"*** Stampa di dbi creato da una sequenza di interi: "<<std::endl;
	std::cout<< dbi << std::endl << std::endl;

	// Test di const_iterator
	f(dbi);

	return 0;
}
