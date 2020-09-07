/*
 * sorts.h

 *
 *  Created on: 06/09/2020
 *      Author: Andrea Piñeiro Cavazos
 */

#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <list>
using namespace std;


// Clase llamada Sorts con template, que contiene todas las funciones
template <class T>
class Sorts {
	public:
		void ordenaSeleccion(vector<int> &original);
		void ordenaBurbuja(vector<int> &original);
		void ordenaMerge(vector<int> &original);
		int busqSecuencial(const vector<int>, int);
		int busqBinaria(const vector<int>, int);

	// Funciones privadas, que serán usadas como auxiliares
	private:
		void swap(vector<int>&, int, int);
		void mergeSplit(vector<int>&, vector<int>&, int, int);
		void mergeArray(vector<int>&, vector<int>&, int, int, int);
		void copyArray(vector<int>&, vector<int>&, int, int);
};

// Esta función auxiliar realiza un cambio entre 2 índices del vector;
// el dato del primero pasa al segundo y viceversa. 

// Complejidad: O(1) CONSTANTE
template <class T>
void Sorts<T>::swap(vector<int> &original, int x, int y){
	int temp = original[x];
	original[x] = original[y];
	original[y] = temp;
}

// Esta función auxiliar recibe dos vectores y dos números, los datos
// entre ambos índices se copian del primero al segundo.

// Complejidad: O(n) LINEAL
template <class T>
void Sorts<T>::copyArray(vector<int> &A, vector<int> &B, int low, int high){
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}


// Está función implementa el algoritmo SelectionSort, en el cual
// se recorre el arreglo, se busca el elemento más pequeño de todo arreglo
// y después se le coloca en la primera posición.
// Recibe el vector y lo devuelve ordenado

// Complejidad: O(n^2) CUADRÁTICA
template <class T>
void Sorts<T>::ordenaSeleccion(vector<int> &original){
	int pos;
	for (int i = 0; i < original.size(); i++){
		pos = i;
		for (int j = i; j < original.size(); j++){
			if (original[j] < original[pos]){
				pos = j;
			}
		}
		if (pos != i){
			swap(original, pos, i);
		}
	}
}


// Esta función implementa el algoritmo BubbleSort; en el cuál se hace swap
// si el primer elemento es mayor al siguiente; al final del primer ciclo
// el número más grande estará en el final, y después debe repetirse. 
// Recibe el vector y lo devuelve ordenado

// Complejidad: O(n^2) CUADRÁTICA
template <class T>
void Sorts<T>::ordenaBurbuja(vector<int> &original){
	for (int i = original.size() - 1; i > 0; i--){
		for (int j = 0; j < i; j++){
			if (original[j] > original[j + 1]){
				swap(original, j, j + 1);
			}
		}
	}
} 

// Esta función auxiliar para MergeSort lo que hace es recibir 2 vectores y 3 números; los
// números están divididos entre los datos desde low a mid, y desde mid+1 a high.
// Lo que hace la función es ordenar los datos entre ambos segmentos en el vector B,

// Complejidad: O(log (n) LOGARÍTMICA
template <class T>
void Sorts<T>::mergeArray(vector<int> &A, vector<int> &B, int low, int mid, int high){
	int i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid && j<= high){
		if(A[i] < A[j]){
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}

	if (i > mid){
		for (; j <= high; j++){
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++){
			B[k++] = A[i];
		}
	}
}


// Esta función auxiliar para mergeSort, recibe 2 vectores y 2 números; lo que hace es
// dividir en 2 segmentos esa parte del arreglo de forma recursiva, hasta que tengamos 
// 1 solo elemento. Cuando se ha llegado al caso base, se manda llamar a MergeArray para
// ordenar los números y a copyArray para copiarlo en el vector original. 
// La complejidad del split es de O(n), y la de mergeArray que se manda a llamar O(log(n))

// Complejidad del split: O(n) LINEAL
template <class T>
void Sorts<T>::mergeSplit(vector<int> &A, vector<int> &B, int low, int high){
	int mid;
	if ((high - low) < 1){
		return;
	} else {
		mid = (high + low) / 2;
		mergeSplit(A, B, low, mid);
		mergeSplit(A, B, mid + 1, high);
		mergeArray(A, B, low, mid, high);
		copyArray(A, B, low, high);
	}
}


// Esta es la función pública que solo recibe un vector; en esta se crea el segundo
// vector que es en el que se estarán haciendo los cambios para después actualizar el
// vector original. En esta función se manda llamar la anterior función auxiliar 
// una sola vez.

// Complejidad: O(1) CONSTANTE
template <class T>
void Sorts<T>::ordenaMerge(vector<int> &original){
	vector<int> b(original.size());
	mergeSplit(original, b, 0, original.size() - 1);
}


// Esta función lo que hace es una búsqueda recorriendo todos los números
// del vector y comparándolos con el número que buscamos. 

// Complejidad: O(n) LINEAL
template <class T>
int Sorts<T>::busqSecuencial(const vector<int> original, int x){
	for (int i = 0; i < original.size(); i++){
		if (original[i] == x){
			return i;
		}
	}
	return -1;
}


// Esta función lo que hace es dividir el vector por la mitad, si el número
// en la mitad es igual al número que buscamos, regresamos su índice, pues ya lo
// hemos encontrado. Si es menor llama la función de nuevo desde low hasta mid-1; si es mayor
// la llama desde mid+1 hasta high. 

//Complejidad: O(log (n)) LOGARÍTMICA
template <class T>
int Sorts<T>::busqBinaria(const vector<int> original, int x){
	int mid;
	int low = 0;
	int high = original.size() - 1;

	while (low < high){
		mid = (low + high) / 2;
		if(x == original[mid]){
			return mid;
		} else if (x < original[mid]){
			high = mid - 1;
		} else if (x > original[mid]){
			low = mid + 1;
		} 
	}
	return low;
}

#endif 