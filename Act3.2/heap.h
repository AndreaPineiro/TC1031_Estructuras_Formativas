// =================================================================
//
// File: heap.h
// Author: Andrea Piñeiro Cavazos
// Description: This file contains the implementation of a Heap
//
// =================================================================

#include <string>
#include <sstream>
#include <iostream>
#include "exception.h"

template <class T>
class Heap {
	private:
		T *data;
		unsigned int hSize;
		unsigned int count;
		unsigned int parent(unsigned int) const;
		unsigned int left(unsigned int) const;
		unsigned int right(unsigned int) const;
		bool full() const;
		void swap (unsigned int, unsigned int);
		void heapify(unsigned int);

	public:
		Heap(unsigned int) throw (OutOfMemory);
		~Heap();
		bool empty () const;
		void push(T) throw (Overflow);
		void pop() throw (NoSuchElement);
		T top() throw (NoSuchElement);
		int size();
		void clear();
		std::string toString() const;
};

// =================================================================
// Constructor. Creates an array for the heap, this constructor  
// receives the size of the array. And initializes the count to 0.
// Complexity O(1)
// =================================================================
template <class T>
Heap<T>::Heap(unsigned int isize) throw (OutOfMemory){
	hSize = isize;
	data = new T[hSize];
	//If to check if we were able to create the Heap
	if (data == 0){
		throw OutOfMemory();
	}
	count = 0; //The spaces used when we create the array are 0
}

// =================================================================
// Destructor. Destroys the list and sets the arguments to 0
// Complexity O(1)
// =================================================================
template <class T>
Heap<T>::~Heap() {
	delete [] data;
	data = 0;
	hSize = 0;
	count = 0;
}

// =================================================================
// Returns the position of the parent of a given object. It receives
// the position of that object.
// Complexity O(1)
// =================================================================
template <class T>
unsigned int Heap<T>::parent(unsigned pos) const {
	return (pos - 1) / 2;
}

// =================================================================
// Returns the position of the object to the left of a given object. 
// It receives the position of that object.
// Complexity O(1)
// =================================================================
template <class T>
unsigned int Heap<T>::left(unsigned pos) const {
	return (pos * 2) + 1;
}

// =================================================================
// Returns the position of the object to the right of a given object. 
// It receives the position of that object.
// Complexity O(1)
// =================================================================
template <class T>
unsigned int Heap<T>::right(unsigned pos) const {
	return (pos * 2) + 2;
}

// =================================================================
// Swaps the objects in 2 positions. It receives the position of the
// objects we want to swap
// Complexity O(1)
// =================================================================
template <class T>
void Heap<T>::swap(unsigned i, unsigned j) {
	T aux = data[i]; //Saves the object in a temporary variable
	data[i] = data[j]; //Changes the object in j to position i
	data[j] = aux; 
}

// =================================================================
// Checks if the heap is full, if spaces used are the same amount 
// as the size of the array.
// Complexity O(1)
// =================================================================
template <class T>
bool Heap<T>::full() const {
	if (hSize == count)
		return true;
	return false;
}

// =================================================================
// Checks if the heap is empty, if the count (spaces used) is 0.
// Complexity O(1)
// =================================================================
template <class T>
bool Heap<T>::empty() const {
	if (count == 0)
		return true;
	return false;
}

// =================================================================
// Checks if the heap is ordered correctly, that means if the element 
// on the top is smaller than the elements on the right and on the
// left. If it's not, it swaps the elements.
// Complexity O(log(n))
// =================================================================
template <class T>
void Heap<T>::heapify(unsigned int pos) {
	unsigned int templeft = left(pos); //Looks for the elem on the left
	unsigned int tempright = right(pos); //Looks for the elem on the right
	unsigned int min = pos;
	//Checks if the element in the left is smaller than the one
	//we received; if it is it stores it as min.
	if (templeft <= count && data[templeft] < data[min]) {
		min = templeft;
	} 
	//Checks if the element in the right is smaller than the one
	//we received and the element on the left one; if it is it 
	//stores it as min.
	if (tempright <= count && data[tempright] < data[min]){
		min = tempright;
	}
	//If the smaller element is not the one received we swap it with the min
	if (min != pos){
		swap(pos, min);
		heapify(min); //Call the function again, to continue. 
	}
}

// =================================================================
// Adds an element to the heap it places it starts from the last
// position and moves it accodrding to its value.
// Complexity O(log(n))
// =================================================================
template <class T>
void Heap<T>::push(T val) throw (Overflow) {
	unsigned int pos;
	// If the list is full you can't add another object
	if (full() == true){
		throw Overflow();
	}
	pos = count;
	count++; //Adds 1 to the count of elements
	//Moves the object up until it's in the right place, the objects
	//to its left and right are greater.
	while (pos > 0 && val < data[parent(pos)]) {
		data[pos] = data[parent(pos)];
		pos = parent(pos);
	}
	data[pos] = val;
}

// =================================================================
// Removes an element from the heap; as it is orderer by priorities,
// it removes the object on the top of the heap (the one with greater
// priority)
// Complexity O(1)
// =================================================================
template <class T>
void Heap<T>::pop() throw (NoSuchElement){
	//If there's no element on the list
	if (empty() == true){
		throw NoSuchElement();
	}
	//Sets the top to be the last object added to the heap
	data[0] = data[--count];
	//Orders the heap by priorities
	heapify(0);
}

// =================================================================
// Returns the element with the greatest priority of the heap.
// Complexity O(1)
// =================================================================
template <class T>
T Heap<T>::top() throw (NoSuchElement) {
	//If there's no element on the list
	if (empty() == true){
		throw NoSuchElement();
	}
	return data[0];
}

// =================================================================
// Returns the number of elements on the array
// Complexity O(1)
// =================================================================
template <class T>
int Heap<T>::size(){
	return count;
}

// =================================================================
// Sets the count to 0
// Complexity O(1)
// =================================================================
template <class T>
void Heap<T>::clear(){
	count = 0;
}

// =================================================================
// String representation of the elements in the heap. The function 
// returns a string with the values of the elements
// Complexity O(n)
// =================================================================
template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;
	aux << "[";	for (unsigned int i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		} aux << data[i];
	} aux << "]";
	return aux.str();
}
