// =================================================================
//
// File: dlist.h
// Author: Andrea Piñeiro Cavazos
// Description: This file contains the implementation of a TDA Double
// Linked List
//
// =================================================================

#ifndef DLIST_H
#define DLIST_H

#include <string>
#include <sstream>
#include "exception.h"

//template <class T> class DLink;
template <class T> class DList;

// =================================================================
// Definition of the Double Link class
// =================================================================

template <class T>
class DLink {
	private:
		DLink(T);
		DLink(T, DLink<T>*, DLink<T>*);

		T value;
		DLink<T> * next;
		DLink<T> * previous;

		friend class DList<T>;
};

// =================================================================
// Constructor. Initializes the value of double link. The variable 
// next and previous (pointers) is initialized to null.
// Complexity O(1)
// =================================================================
template <class T>
DLink<T>::DLink(T val) : value(val), next(0), previous(0) {}

// =================================================================
// Constructor. Initializes the value of double link, the value of 
// next and previous.
// Complexity O(1)
// =================================================================
template <class T>
DLink<T>::DLink(T val, DLink* nxt, DLink<T>* prev) : value(val), next(nxt), previous(prev) {}


// =================================================================
// Definition of the Double List class
// =================================================================
template <class T>
class DList {
	private:
		DLink<T> *head;
		DLink<T> *tail;
		int size;

	public:
		DList();
		~DList();

		void add(T) throw (OutOfMemory);
		int find(T);
		void update(int, T) throw (IndexOutOfBounds);

		T remove(int) throw (IndexOutOfBounds);

		void clear();
		std::string toStringForward() const;
		std::string toStringBackward() const; 
};

// =================================================================
// Constructor. Initializes all variables to zero.
// Complexity O(1)
// =================================================================
template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}

// =================================================================
// Destructor. Remove all items from the list.
// Complexity O(1) It only calls the clear function.
// =================================================================
template <class T>
DList<T>::~DList(){
	clear();
}

// =================================================================
// Adds an Double Link object to the list on the last position. 
// It receives an object.
// The function doesn't return anything.
// Complexity O(1)
// =================================================================
template <class T>
void DList<T>::add(T val) throw (OutOfMemory) {
	DLink<T> *newLink;

	newLink = new DLink<T>(val);
	if (newLink == 0) {
		throw OutOfMemory();
	}

	// If the list is empty, the head and tail of the list point to 
	// the new object. And "next" and "previous" ob newLink are set
	// to null.
	if (size == 0){
		newLink -> next = head;  
		newLink -> previous = tail;
		head = newLink;
		tail = newLink;
		size ++;
		return;
	}

	// If the list is not empty, "next" of newLink has to point towards
	// null and "previous" towards the tail of the list; so it points to 
	// the last object
	newLink -> next = 0;  
	newLink -> previous = tail;
	tail -> next = newLink;
	tail = newLink;
	size++;
}

// =================================================================
// Search an element of the list, by comparing each element with 
// the one received. It starts from the head and tail, so it doesn't	
// have to get through all the list.
// It uses 2 pointers, p moves forward starting form the head, and q
// moves backward starting from the tail.
// The function returns the postion of the element
// Complexity O(n/2) -> O(n)
// =================================================================
template <class T>
int DList<T>::find(T val) {
	DLink<T> *p, *q;

	// ContH is the counter of position starting from the head
	// and ContT is the position starting from the tail
	int contH = 0, contT = size - 1;
	p = head;
	q = tail;
	
	while (p != 0){
		// If the object is closer to the begining of the list 
		// the pointer p finds if first, and returns the contH
		if (p -> value == val) { 
			return contH;
		}
		// If the object is closer to the end of the list 
		// the pointer q finds if first, and returns the contT
		if (q -> value == val) {
			return contT;
		}
		contH++; 
		contT--;
		p = p -> next;
		q = q -> previous;
	}
	return -1;
}

// =================================================================
// Updates the value of an element in the list, with the object and
// index received. 
// The function doesn't return anything
// It starts from the head if the index is closer to the beggining of 
// the list, or starts from the tail if it's closer to the end.
// Complexity O(n/2) -> O(n)
// =================================================================
template <class T>
void DList<T>::update(int index, T val) throw (IndexOutOfBounds) {
	DLink<T> *p;
	int pos;

	if (index > size) {
		throw OutOfMemory();
	}

	// If the index is closer to the beggining, the pointer p starts
	// from the head.
	if (index <= size - 1 / 2){
		p = head;
		pos = 0;
		// While the pointer doesn't points to null, if we've reached the
		// index we set the object's value to the value received.
		while (p != 0){
			if (pos == index){
				p -> value = val;
			}
			pos++;
			p = p -> next;
		}
	} else {
	// If the index is closer to the end the pointer starts from the end 
	// and moves backwards using previous. The position starts at size - 1.	
		p = tail;
		pos = size - 1;
		while (p != 0){
			if (pos == index){
				p -> value = val;
			}
			pos--;
			p = p -> previous;
		}
	}
}

// =================================================================
// It receives an index and removes the element in that position.
// The function returns the object removed.
// Complexity O(n)
// =================================================================
template <class T>
T DList<T>::remove(int index) throw (IndexOutOfBounds){
	T aux;
	DLink<T> *p, *q, *r;
	int pos;

	if (index > size) {
		throw IndexOutOfBounds();
	}

	// If the index is 0, the head changes to the next element, and  
	// previous points to 0.
	if (index == 0){
		p = head;
		aux = p -> value;
		head = p -> next;
		head -> previous = 0;
		delete p;

	// If the index is the last element in the list, the tail changes
	// to the previous element, and next points to 0.
	} else if (index == size - 1) {
		p = tail;
		aux = p -> value;
		tail = p -> previous;
		tail -> next = 0;
		delete p;

	} 

	else if (index < size-1 ){
    	p = head;
		for (int i = 1; i <= index; i++){
			if (index == i){
				q = p -> next;
				aux = q -> value;
				p -> next = q -> next;
				q -> next -> previous = q -> previous;
				delete q;
			} else {
				p = p -> next;
			}
		}	   
	}  
		

	size--;
	return aux;
}

// =================================================================
// Removes every element on the list.
// The function doesn't receive or return anything. It is used in the 
// destructor.
// Complexity O(n)
// =================================================================
template <class T>
void DList<T>::clear() {
	DLink<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p -> next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}


// =================================================================
// String representation of the elements in the list. The function 
// returns a string with the values of the elements
// Complexity O(n)
// =================================================================
template <class T>
	std::string DList<T>::toStringForward() const {
		std::stringstream aux;
		DLink<T> *p;
		p = head;
		aux << "[";
		while (p != 0) {
			aux << p->value;
			if (p->next != 0) {
				aux << ", ";
			}
			p = p->next;
		}
		aux << "]";
		return aux.str();
	}

	template <class T>
	std::string DList<T>::toStringBackward() const {
		std::stringstream aux;
		DLink<T> *p;
		p = tail;
		aux << "[";
		while (p != 0) {
			aux << p->value;
			if (p->previous != 0) {
				aux << ", ";
			}
			p = p->previous;
		}
		aux << "]";
		return aux.str();
	}

#endif /* LIST_H */

