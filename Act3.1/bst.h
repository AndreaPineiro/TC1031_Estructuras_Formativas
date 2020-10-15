// =================================================================
//
// File: bts.h
// Author: Andrea Pineiro Cavazos
// Description: Esta clase contiene la implementación de un 
// BST (Binary Search Tree)
//
// =================================================================

#ifndef BST_H_
#define BST_H_

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

template <class T> class BST;

// =================================================================
// Definition of the Node class
// =================================================================
template <class T>
class Node {
private:
	T value;
	Node *left, *right;

	Node<T>* succesor();

public:
	Node(T);
	Node(T, Node<T>*, Node<T>*);
	void add(T);
	bool find(T);
	int height() const;
	int whatlevelamI(T);
	void preorder(stringstream&) const;
	void inorder(stringstream&) const;
	void postorder(stringstream&) const;
	void levelbylevel(stringstream&) const;
	void printlevel(stringstream&, int) const;
  	bool ancestors(T, stringstream&) const;
  	void remove(T);
  	void removeChilds();

	friend class BST<T>;
};

// =================================================================
// Constructor. Initializes the value of Node. The pointers
// left and rigth are initialized to null.
// Complexity O(1)
// =================================================================
template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0) {}

// =================================================================
// Constructor. Initializes the value of the node, and both pointer
// right and left according to the parameters received. 
// Complexity O(1)
// =================================================================
template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri)
	: value(val), left(le), right(ri) {}


// =================================================================
// Adds a Node and places it in the rigth position on the BST 
// It receives an object. It compares the value with the Nodes
// that already exist on the tree to place it in the right position.
// Complexity O(n)
// =================================================================
template <class T>
void Node<T>::add(T val) {
	// If the value of the new node is smaller it moves to the node
	// in the left, where the smaller values are. If it is greater
	// it moves to the node in the left.
	// If it has not reached null it calls the function again. 
	// Else it creates a new node with the received value.

	if (val < value) { 
		if (left != 0) {
			left->add(val);
		} else {
			left = new Node<T>(val);
		}
	} else {
		if (right != 0) {
			right->add(val);
		} else {
			right = new Node<T>(val);
		}
	}
}


// =================================================================
// Search an element of the tree, by comparing the element with 
// the one received. It starts from the root and compares the value
// with the object received	
// If the value is smaller it moves to the Node in the left and 
// calls the function again. Else, it moves to the right where the 
// greater objects are.
// The function returns true if the element is on the list.
// Complexity O(n)
// =================================================================
template <class T>
bool Node<T>::find(T val) {
	if (val == value) {
		return true;
	} else if (val < value) {
		return (left != 0 && left->find(val));
	} else if (val > value) {
		return (right != 0 && right->find(val));
	}
	return -1;
}

// =================================================================
// Function which returns the height of the BST, according to how many
// levels the tree has.
// Complexity O(n)
// =================================================================
template <class T>
int Node<T>::height() const {

	// We declare 2 variables which will help to count the levels
	int level_left = 0;
	int level_right = 0;

	// If the node has an element on the left it calls the 
	// function again but for that element and adds + 1, so
	// that on the way back we add 1 to the counter.
	if (left != 0) {
		level_left = left->height() + 1;
	}
	// If the node has an element on the rigth it does the same
	// but with the right node.
	if (right != 0) {
		level_right= right->height() +1;
	}
	// If we dont have any objects to the left and to the right,
	// we return 1. This is the base case.
	if (level_left == 0 && level_right == 0)
		return 1;

	// The function returns the greater number between level_right
	// and level_left.
	if (level_right > level_left){
		return level_right;
	} else {
		return level_left;
	}
	//return (level_right > level_left) ? level_right : level_left;
}


// =================================================================
// Function which returns the level in which a data is found
// It moves using the pointers right and left and compares
// the elements with the one we are looking for 
// Complexity O(n)
// =================================================================
template <class T>
int Node<T>::whatlevelamI(T val) {
	// Base case for if we have found the value. If the value
	// is smaller we move to the element on the left, if it's 
	// bigger we move to the right; call the function again 
	// and add 1 on the way back to find the level.
	if (val == value) {
		return 1;
	} else if (val < value) {
		if(left != 0)
			return left->whatlevelamI(val) + 1;
	} else if (val > value) {
		if (right != 0)
		return right->whatlevelamI(val) + 1;
	}
	return -1;
}


// =================================================================
// Function which returns the preorder of the BST. It prints 
// first all the nodes on the left and then moves back up 
// to print the ones on the rigth for every node
// Complexity O(n)
// =================================================================
template <class T>
void Node<T>::preorder(stringstream &aux) const {
	aux << value;
	// If it has a node on the left it moves to that node and
	// calls the function again, adding the element on the aux.
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	// If it has a node on the right it moves to that node and
	// calls the function again, adding the element on the aux.
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

// =================================================================
// Function which returns the inorder of the BST. It prints 
// first the node on the last level to the left. Then Moves
// up and prints that node and the childs on the right.
// Complexity O(n)
// =================================================================
template <class T>
void Node<T>::inorder(stringstream &aux) const {
	// If there'a a node on the left it calls the function
	// again but without adding anything on the aux.
	if (left != 0) {
		left->inorder(aux);
	}
	// Tellp returns the current “put” position of the pointer 
	// in the stream. If it is not in the first position it 
	// adds " " to the stream.
	if (aux.tellp() != 1) {
		aux << " ";
	}
	// When it has reached the end it adds the value to the
	// stream
	aux << value;
	// Then it does the same but with the elements on the right.
	if (right != 0) {
		right->inorder(aux);
	}
}

// =================================================================
// Function which returns the postorder of the BST. It prints 
// first the node on the last level to the left. Then Moves
// up and prints the childs on the right starting from the 
// one in the last level, the it prints the parent node.
// Complexity O(n)
// =================================================================
template <class T>
void Node<T>::postorder(std::stringstream &aux) const {
	
	// If there'a a node on the left it calls the function
	// again but without adding anything on the aux.
	if (left != 0) {
		left->postorder(aux);
	}

	// Then, if there'a a node on the rigth it calls the function
	// again.
	if (right != 0) {
		right->postorder(aux);
	}
	// Tellp returns the current “put” position of the pointer 
	// in the stream. If it is not in the first position it 
	// adds " " to the stream.
	if (aux.tellp() != 1) {
			aux << " ";
	}
	aux << value;
}

// =================================================================
// Function which prints every object in an specific level of the
// tree.
// =================================================================
template <class T>
void Node<T>::printlevel(stringstream &aux, int level) const {

	if(level == 0){
		if (aux.tellp() != 1) {
				aux << " ";
		}
		aux << value;
	}
	if (left != 0) {
		left->printlevel(aux, level -1);
	}
	if (right != 0) {
		right->printlevel(aux, level -1);
	}

}

// =================================================================
// Function which returns the levelbylevel order of the BST. 
// It prints first all the nodes in the first level, then the second
// and so on until the last level.
// Complexity O(n)
// =================================================================
template <class T>
void Node<T>::levelbylevel(stringstream &aux) const {
	// It looks for the heigth of the tree
	int level = height();
	// It prints the elements of every level with printlevel
	for(int i = 0; i < level; i++){
			printlevel(aux, i);
	}
}

// =================================================================
// Function which returns the ancestors of a node. 
// Complexity O(n)
// =================================================================
template <class T>
bool Node<T>::ancestors(T val, stringstream &aux) const{
	// First it looks for the object, and it looks for 
	// it ancestors by calling the function again. 
	if (val == value) {
	  return true;
	} else if (val < value) {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << value;
		// It moves to the node on the left
		return (left != 0 && left->ancestors(val,aux));
	} else if (val > value) {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << value;
		// Moves to the node on the right.
		return (right != 0 && right->ancestors(val,aux));
	}
	return -1;
}

template <class T>
void Node<T>::removeChilds() {
	if (left != 0) {
		left->removeChilds();
		delete left;
		left = 0;
	}
	if (right != 0) {
		right->removeChilds();
		delete right;
		right = 0;
	}
}




// =================================================================
// Definition of BST class
// =================================================================
template <class T>
class BST {
private:
	Node<T> *root;

public:
	BST();
	~BST();
	bool empty() const;
	void add(T);
	bool find(T) const;
	int  whatlevelamI(T) const;
	void remove(T);
	void removeAll();
	string inorder() const;
	string preorder() const;
	string postorder() const;
	string levelbylevel() const;
	string visit();
	string ancestors(T) const;
	int height() const;
};

// =================================================================
// Constructor. Initializes the root to zero.
// Complexity O(1)
// =================================================================
template <class T>
BST<T>::BST() : root(0) {}

// =================================================================
// Destructor. Removes all items from the tree.
// Complexity O(1) It only calls the removeAll function.
// =================================================================
template <class T>
BST<T>::~BST() {
	removeAll();
}

// =================================================================
// Sets the root to null, when the tree is empty
// Complexity O(1) It only calls the removeAll function.
// =================================================================
template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}


// =================================================================
// Adds a Node and places it in the rigth position on the BST 
// It receives an object. This function calls add from the node class.
// Complexity O(n)
// =================================================================
template<class T>
void BST<T>::add(T val) {
	if (root != 0) {
		// If the root is not 0 and if the object is not
		// already on the list it calls the function add from node.
		if (!root->find(val)) {
			root->add(val);
		}
	} else {
		root = new Node<T>(val);
	}
}


// =================================================================
// Removes all the elements on the three by callind removeChilds
// Complexity O(n)
// =================================================================
template <class T>
void BST<T>::removeAll() {
	if (root != 0) {
		root->removeChilds();
	}
	delete root;
	root = 0;
}


// =================================================================
// Search an element of the list, by comparing the element with 
// the one received. It starts from the root and compares the value
// with the object received	by calling the find function from 
// the node class.
// The function returns true if the element is on the list.
// Complexity O(n)
// =================================================================
template <class T>
bool BST<T>::find(T val) const {
	if (root != 0) {
		return root->find(val);
	}
	else {
		return false;
	}
}


// =================================================================
// Function which returns the level in which a data is found
// It calls the function whatlevelamI from the node class.
// If it is negative it returns -1
// Complexity O(n)
// =================================================================
template <class T>
int BST<T>::whatlevelamI(T val) const {
	if (root != 0) {
	 	int num = root->whatlevelamI(val);
		if(num < 0) {
			return -1;
		} else {
			return num;
		}
	}
	else {
		return -1;
	}
}

// =================================================================
// Function which returns the preorder of the BST. It calls the preorder
// function from the node class if the tree is not empty.
// Complexity O(n)
// =================================================================
template <class T>
string BST<T>::preorder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}


// =================================================================
// Function which returns the inorder of the BST. It calls the inorder
// function from the node class if the tree is not empty.
// Complexity O(n)
// =================================================================
template <class T>
string BST<T>::inorder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}


// =================================================================
// Function which returns the postorder of the BST. It calls the 
// postorder function from the node class if the tree is not empty.
// Complexity O(n)
// =================================================================
template <class T>
string BST<T>::postorder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->postorder(aux);
	}
	aux << "]";
	return aux.str();
}


// =================================================================
// Function which returns the levelbylevel order of the BST. It 
// calls the levelbylevel function from the node class if 
// the tree is not empty.
// Complexity O(n)
// =================================================================
template <class T>
string BST<T>::levelbylevel() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->levelbylevel(aux);
	}
	aux << "]";
	return aux.str();
}

// =================================================================
// Function which returns the height of the BST. It 
// calls the height function from the node class.
// Complexity O(n)
// =================================================================
template <class T>
int BST<T>::height() const {
	return root->height();
}


// =================================================================
// Function which returns the ancestors of an object. It calls the 
// ancestors function from the node class if the tree is not empty.
// Complexity O(n)
// =================================================================
template <class T>
string BST<T>::ancestors(T val) const {
	stringstream aux;
	aux << "[";
	if (!empty()) {
		if(!root->ancestors(val, aux))
			return "[]";
	}
	aux << "]";
	return aux.str();
}

// =================================================================
// Function which returns the an string with the different orders of
// the BST. It calls the preorder, inorder, postorder and level order
// functions of the BST class and add them on a string separated by
// '\n' 
// Complexity O(1) // It only calls the other functions.
// =================================================================
template <class T>
string BST<T>::visit() {
	stringstream aux;
	aux << preorder() << "\n" << inorder() << "\n" << postorder() << "\n" << levelbylevel();
	return aux.str();
}


#endif /* BST_H_ */
