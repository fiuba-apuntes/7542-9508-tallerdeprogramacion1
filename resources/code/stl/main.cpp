#include <vector>
#include <iostream>

int main(){
	// Declaro un vector dinámico para almacenar ints
	std::vector<int> vectNumeros;
	// El vector se inicia vacío
	std::cout << "El tamaño de mi vector es de " \
		 << vectNumeros.size() << std::endl;
	// Agrego 3 números, uno a uno.
	vectNumeros.push_back(0);
	vectNumeros.push_back(3);
	vectNumeros.push_back(5);
	// El tamaño final del vector es 3
	std::cout << "El tamaño de mi vector es de " \
		 << vectNumeros.size() << std::endl;
	// Declaro un iterador para recorrer el vector secuencialmente.
	std::vector<int>::iterator it;
	for (it = vectNumeros.begin(); it != vectNumeros.end(); ++it){
		//Muestro en pantalla el elemento sobre el que estoy iterando.
		std::cout << "Iterando sobre " << *it << std::endl;
	}
}
