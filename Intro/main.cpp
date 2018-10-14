#include <iostream>
#include "utils.h"
int main (void){
	int input = 0;
	std::cout << "Hello World :^)" << std::endl;
	std::cout << "Inserire un numero : ";
	std::cin.exceptions(std::ios_base::failbit); //attiva la gestione delle eccezioni se fallisce la conversione della stringa.
	try {
	std::cin >> input;
	}
	catch(...) {
		std::cout << "Catturata" << std::endl;
	}
	std::cout << "Hai inserito : " << input << std::endl;
	std::cout << "Compute : " << compute(input) << std::endl;
	return 0;
}