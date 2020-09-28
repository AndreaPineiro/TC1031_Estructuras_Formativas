// =================================================================
//
// File: list.h
// Author: Andrea Piñeiro Cavazos
// Description: This file contains the implementation of a TDA List
//
// =================================================================

#ifndef LIST_H
#define LIST_H

#include <string>
#include <sstream>
#include "exception.h"

template <class T> class List;

// =================================================================
// Definition of the Link class
// =================================================================

template <class T>
class Link {
	private:
		Link(T);
		Link(T, Link<T>*);

		T value;
		Link<T> * next;

		friend class List<T>;
};

// =================================================================
// Constructor. Initializes the value of link. The variable next 
// (pointer) is initialized to null.
// Complexity O(1)
// =================================================================
template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

// =================================================================
// Constructor. Initializes the value of link and the value of next.
// Complexity O(1)
// =================================================================
template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}


// =================================================================
// Definition of the List class
// =================================================================
template <class T>
class List {
	private:
		Link<T> *head;
		int size;

	public:
		List();
		~List();

		void add(T) throw (OutOfMemory);
		int find(T);
		void update(int, T) throw (IndexOutOfBounds);

		T remove(int) throw (IndexOutOfBounds);

		void clear();
		std::string toString() const;
};

// =================================================================
// Constructor. Initializes both variables to zero.
// Complexity O(1)
// =================================================================
template <class T>
List<T>::List() : head(0), size(0) {}

// =================================================================
// Destructor. Remove all items from the list.
// Complexity O(1) It only calls the clear function.
// =================================================================
template <class T>
List<T>::~List(){
	clear();
}

// =================================================================
// Adds an Link object to the list on the last position. It receives
// an object.
// The function doesn't return anything.
// Complexity O(n)
// =================================================================
template <class T>
void List<T>::add(T val) throw (OutOfMemory) {
	Link<T> *newLink, *p;

	newLink = new Link<T>(val);
	if (newLink == 0) {
		throw OutOfMemory();
	}

	if (size == 0){
		newLink -> next = head;
		head = newLink;
		size ++;
		return;
	}

	p = head;
	while (p -> next != 0) {
		p = p -> next;
	}

	newLink -> next = 0;
	p -> next = newLink;
	size++;
}

// =================================================================
// Search an element of the list, by comparing each element with 
// the one received
// The function returns the postion of the element
// Complexity O(n)
// =================================================================
template <class T>
int List<T>::find(T val) {
	Link<T> *p;

	int cont = 0;
	p = head;
	while (p != 0){
		if (p -> value == val) {
			return cont ;
		}
		cont++;
		p = p -> next;
	}
	return -1;
}

// =================================================================
// Updates the value of an element in the list, with the one received.
// The function doesn't return anything
// Complexity O(n)
// =================================================================
template <class T>
void List<T>::update(int index, T val) throw (IndexOutOfBounds) {
	Link<T> *p;

	p = head;

	if (index > size) {
		throw OutOfMemory();
	}

	int pos = 0;
	while (p != 0){
		if (pos == index){
			p -> value = val;
		}
		pos++;
		p = p -> next;
	}
}

// =================================================================
// It receives an index and removes the element in that position.
// The function returns the object removed.
// Complexity O(n)
// =================================================================
template <class T>
T List<T>::remove(int index) throw (IndexOutOfBounds){
	T aux;
	Link<T> *p, *q;

	if (index > size) {
		throw IndexOutOfBounds();
	}

	p = head;

	if (index == 0){
		aux = p -> value;
		head = p -> next;
		delete p;
	}

	for (int i = 1; i <= index; i++){
		if (index == i){
			q = p -> next;
			aux = q -> value;
			p -> next = q -> next;
			delete q;
		}else{
			p = p -> next;
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
void List<T>::clear() {
	Link<T> *p, *q;

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
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;

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

#endif /* LIST_H */

