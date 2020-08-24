/*
 * main.cpp
 *
 *  Created on: 23/08/2020
 *      Author: Andrea Piñeiro Cavazos
 */

#include <iostream>

using namespace std;

class Funciones{
	private:
		int n;

	public:
		long sumaIterativa(int n);
		long sumaRecursiva(int n);
		long sumaDirecta(int n);
};

// Esta función realiza la suma iterativa de 1 hasta n, 
// recibe un entero positivo, en caso de recibir un número
// negativo, retorna 0

// Complejidad: O(n) LINEAL
long Funciones::sumaIterativa(int n){
	long sum = 0;
	if (n > 0){
		for (int i = 1; i <= n; i++){
			sum += i;
		}
	} else {
		sum = 0;
	}
	return sum;
}

// La segunda función realiza la suma recursiva de 1 hasta n,
// recibe un entero positivo, en caso de recibir un número
// negativo, retorna 0.

// Complejidad: O(n) LINEAL
long Funciones::sumaRecursiva(int n){
	if (n > 0){	
		if (n <= 1){
			return 1;
		} else {
			return n + sumaRecursiva(n - 1);
		}
	} else {
		return 0;
	}
}

// La tercer función realiza una suma directa con un método
// matemático. (n * (n + 1)) / 2
// Si recibe un número negativo, retorna 0. 

// Complejidad: O(1) CONSTANTE
long Funciones::sumaDirecta(int n){
	if (n > 0){
		return (n * (n + 1)) / 2;
	} else {
		return 0;
	}
}