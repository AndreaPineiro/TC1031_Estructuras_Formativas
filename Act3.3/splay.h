// =================================================================
//
// File: splay.h
// Author: Andrea Pineiro Cavazos
// Description: Esta clase contiene la implementación de un 
// BST (Binary Search Tree)
//
// =================================================================

#ifndef SPLAY_H_
#define SPLAY_H_

#include <string>
#include <sstream>
#include "exception.h"
#include <iostream>

template <class T> class SplayTree;

// =================================================================
// Definition of the Node class
// =================================================================
template <class T>
class Node {
	private:
		T value;
		Node *left, *right, *parent;

		Node<T>* succesor();
		Node<T>* rot_right(Node<T>*);
		Node<T>* rot_left(Node<T>*);

	public:
		Node (T);
		Node (T, Node<T>*, Node<T>*, Node<T>*);
		Node<T>* add(T);
		Node<T>* find(T);
		Node<T>* remove(T);
		void removeChilds();
		void inorder(std::stringstream&) const;
		void print_tree(std::stringstream &aux) const;
		void preorder(std::stringstream &aux) const;
		Node<T>* splay(Node<T>*, Node<T>*);

		friend class SplayTree<T>;
};



// =================================================================
// Constructor. Initializes the value of Node. The pointers
// left, right and parent are initialized to null.
// Complexity O(1)
// =================================================================
template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0), parent(0) {}

// =================================================================
// Constructor. Initializes the value of the node, and the three 
// pointers: right, left and paren according to the parameters 
// received. 
// Complexity O(1)
// =================================================================
template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri, Node<T> *p):
	value(val), left(le), right(ri), parent(p) {}


// =================================================================
// This functions finds the succesor of the node. This function is 
// not asked for the assignment but it's important for the remove
// function
// 
// =================================================================
template <class T>
Node<T>* Node<T>::succesor() {
	// Pointers which start at the element to the left and to the right
	Node<T> *le, *ri;
	le = left;
	ri = right;

	// If there's no right child the left one becomes the root of the tree
	if (right == 0) {
		if (left != 0) {
			left = 0;
		}
		if (le) 
			le -> parent = 0; // It becomes the root
		return le;
	}

	if (right -> left == 0) {
		right = right -> right;
		// If there's an element to the right right, the parent of this
		// one, becomes the parent of the element we're at
		if (right)
			right -> parent = parent;
		// If the element to the right is not null.
		if (ri) {
			ri -> right = 0; 
			ri -> parent = 0;
		}
		return ri;
	}


	Node<T> *p, *c;
	p = right;
	c = right -> left;
	// It keeps moving in the right branch until it reaches the end,
	// on the left side
	while (c -> left != 0) {
		p = c;
		c = c -> left;
	}
	
	// It moves to the object in the right of c an attaches it 
	// with p
	p -> left = c -> right;
	if (p -> left != 0) 
		p -> left -> parent = p;
	c -> right = 0;
	return c;
}

// =================================================================
// This functions rotates to left, this will helps us later in the
// splay function. It receives one element and moves it to the left;
// the child on the right now becomes the parent.
// 
// =================================================================
template <class T>
Node<T>* Node<T>::rot_left(Node<T>* x){
	Node<T> *y = x -> right;
  	
  	x->right = y->left;
  	// If the element to the right has a child in the left, this chils
  	// parent is now x
  	if(y->left){
    	y->left->parent = x;
  	}

  	y->left = x; //The pointer of y to the left now points to 
  	// the original node

  	y->parent = x->parent; // Attach the parent of y with the parent of x
  	x->parent = y; // Attach x's parent with y
  	
  	// If y has a parent
  	if (y->parent) {
    	// Sets the left child to be y, instead of x
    	if (y->parent->left && y->parent->left->value == x->value)
      		y->parent->left = y;
    	else
      		y->parent->right = y;  // Sets the right child of parent to be y
  	}
  return y;
}

// =================================================================
// This functions rotates to right, this will helps us later in the
// splay function. It receives one element and moves it to the rigth;
// the child on the right now becomes the parent.
// 
// =================================================================
template <class T>
Node<T>* Node<T>::rot_right(Node<T>* x){
  	Node<T> *y = x->left;
  	
  	x->left = y->right;
  	
  	if(y->right)
    	y->right->parent = x;
  	y->right = x;

  	y->parent = x->parent; // Attach the parent of y with the parent of x
  	x->parent = y; // Attach x's parent with y

  	if (y->parent){
    	if (y->parent->left && y->parent->left->value == x->value)
      		y->parent->left = y;
    	else
      		y->parent->right = y;  
  	}
  	return y;
}

// =================================================================
// Adds a Node and places it in the right position on the Splay Tree 
// It receives an object. It compares the value with the Nodes
// that already exist on the tree to place it in the right position.
// It returns the new state of the tree.
// Complexity O(n)
// =================================================================
template <class T>
Node<T>* Node<T>::add(T val) {
	// If the value of the new node is smaller it moves to the node
	// in the left, where the smaller values are. If it is greater
	// it moves to the node in the left.
	// If it has not reached null it calls the function again. 
	// Else it creates a new node with the received value.
	if (val < value) {
		if (left != 0) {
			return left -> add(val);
		} else {
			left = new Node<T>(val);
			//The parent of the new object is the one we're at
			left -> parent = this; 
			return left;
		}
	} else {
		if (right != 0) {
			return right -> add(val);
		} else {
			right = new Node<T>(val);
			right -> parent = this;
			return right;
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
Node<T>* Node<T>::find(T val) {
	if (val == value) {
		return this;
	} else if (val < value) {
		if (left != 0) {
			return (left -> find(val));
		} else {
			return this;
		}
	} else if (val > value) {
		if (right != 0) {
			return (right -> find(val));
		} else {
			return this;
		}
	}
	return 0;
}

// =================================================================
// This function receives an element, it looks for it comparing it's
// value with the objects in the tree.
// If the value is smaller it moves to the Node in the left and 
// calls the function again. Else, it moves to the right where the 
// greater objects are.
// This function calls succesor, so we can know which element to attach
// now with the previous one to keeps with the condition of the tree
// Complexity O(n)
// =================================================================
template <class T>
Node<T>* Node<T>::remove(T val) {
	Node <T> * succ, *old;
	// If the value is smaller it moves to the left, else it moves
	// to the right
	if (val < value) {
		if (left != 0) {
			if (left -> value == val) {
				old = left;
				// To find the one that will be attached now
				succ = left -> succesor();
				if (succ != 0) {
					// We link the succesor with the elements
					succ -> left = old -> left;
					succ -> right = old -> right;
					succ -> parent = old -> parent;
					if (succ -> left) {
						succ -> left -> parent = succ;
					}
					if (succ -> right){
						succ -> right -> parent = succ;
					}
				}
				left = succ;
				delete old; // Delete the element
				return this;
			} else {
				// It keeps looking for the element
				return left -> remove(val);
			}
		}
	} else if (val > value) {
		if (right != 0) {
			if (right -> value == val) {
				old = right;
				// To find the one that will be attached now
				succ = right -> succesor();
				if (succ != 0) {
					// We link the succesor with the elements
					succ -> left = old -> left;
					succ -> right = old -> right;
					succ -> parent = old -> parent;
					if (succ -> left){
						succ -> left -> parent = succ;
					}
					if (succ -> right){
						succ -> right -> parent = succ; 
					}
				}
				right = succ;
				delete old; // Delete the element
				return this;
			} else {
				// It keeps looking for the element
				return right -> remove(val);
			}
		}  
	}
	return 0;
}

// =================================================================
// This function removes the childs of a node. This will help to 
// remove all the elements on the splay tree
// Complexity O(n)
// =================================================================
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
// This function receives the root of the tree and the element which
// we want to splay. It first looks at were we are according to the
// root, if we have already reached the root we do a simple rotation
// else, we check in which case we're at.
// 
// =================================================================
template <class T>
Node<T>* Node<T>::splay(Node<T>* root,Node<T>* x) { 
  	while (x->parent != 0){
	
		// If the parent of the element is the root, if the element
  		// is at the left of the parent, we rotate to the right
  		//Else we rotate to the left.
    	if(x->parent->value == root->value) {
      		if(x->parent->left && x->parent->left->value == x->value){
        		rot_right(x->parent); // Case 1
      		} else {
        		rot_left(x->parent); // Case 2
      		}
		} else{
        	Node<T>*p = x->parent; //padre
        	Node<T>*g = p->parent; //abuelo
		
        	// Case 3, node is at the left of the parent, and the parent at the left
        	// of the granpa. We rotate two times to the right.
        	// First with the granparent and then with the parent.
        	if(p->left && g->left && x->value == p->left->value && p->value == g->left->value){
		  		rot_right(g);
          		rot_right(p);
        	} else if (p->right && g->right && x->value == p->right->value && p->value == g->right->value){
		  		// Case 4, node is at the right of the parent, and the parent at the right
        		// of the granpa. We rotate two times to the left.
        		// First with the granparent and then with the parent.
		  		rot_left(g);
          		rot_left(p);
        	} else if (p->left && g-> right && x->value == p->left->value && p->value == g->right->value){
		  		// Case 5, node is at the left of the parent, and the parent at the right
        		// of the granpa. We rotate first to the right, then left
        		// First we rotate the parent and then the granparent.
		  		rot_right(p);
          		rot_left(g);
        	} else {
		  		// Case 6, node is at the right of the parent, and the parent at the left
        		// of the granpa. We rotate first to the left, then right
        		// First we rotate the parent and then the granparent.
		  		rot_left(p);
          		rot_right(g);
        	}
      	}
    }
    return x;
}

// =================================================================
// Function which returns the inorder of the Splay Tree. It prints 
// first the node on the last level to the left. Then Moves
// up and prints that node and the childs on the right.
// Complexity O(n)
// =================================================================
template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
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
// Auxiliar functions to print the tree. This will be used to grade.
// =================================================================

template <class T>
void Node<T>::print_tree(std::stringstream &aux) const {
	if (parent != 0){
		aux << "\n node " << value;
		aux << " parent " << parent->value;
	}else
		aux << "\n root " << value;
	if (left != 0)
		aux << " left " << left->value;
	if (right != 0)
		aux << " right " << right->value;
	aux << "\n";
	if (left != 0) {
		left->print_tree(aux);
	}
	if (right != 0) {
		right->print_tree(aux);
	}
}

template <class T>
void Node<T>::preorder(std::stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

// =================================================================
// Definition of BST class
// =================================================================
template <class T>
class SplayTree {
	private:
		Node<T> *root;
		unsigned int count;

	public:
		SplayTree();
		~SplayTree();
		bool empty() const;
		void add(T);
		bool find(T);
		void remove(T);
		void removeAll();
		std::string inorder() const;
		std::string preorder() const;
		std::string print_tree() const;
		int size();
};

// =================================================================
// Constructor. Initializes the root to zero and the count to 0
// Complexity O(1)
// =================================================================
template <class T>
SplayTree<T>::SplayTree() : root(0), count(0) {}

// =================================================================
// Destructor. Removes all items from the tree.
// Complexity O(1) It only calls the removeAll function.
// =================================================================
template <class T>
SplayTree<T>::~SplayTree() {
	removeAll();
}

// =================================================================
// Sets the root to null, when the tree is empty
// Complexity O(1) It only calls the removeAll function.
// =================================================================
template <class T>
bool SplayTree<T>::empty() const {
  	return (root == 0);
}

// =================================================================
// Adds a Node and places it in the right position on the Splay Tree 
// It receives an object. This function calls add from the node class.
// Complexity O(n)
// =================================================================
template <class T>
void SplayTree<T>::add(T val) {
  	// If the root is not 0 and if the object is not
	// already on the list it calls the function add from node.
  	if ( root != 0) {
    	Node<T>* added = root->add(val);
    	// It splays the tree
    	root = root->splay(root,added);
  	} 
  	else {
    	root = new Node<T>(val);
  	}
  	count++; // Adds 1 to the count of elements
}


// =================================================================
// Removes an element from the Splay tree
// Complexity O(n)
// =================================================================
template <class T>
void SplayTree<T>::remove(T val) {
  if (root != 0) {
    if (val == root->value) {
      Node<T> *succ = root->succesor();
      if (succ != 0) {
        succ->left = root->left;
        succ->right = root->right;
        // The only difference from BST is we modify parent
        succ->parent = 0;
        if (succ->left)
          	succ->left->parent = succ;
        if (succ->right)
          	succ->right->parent = succ;
      	}
      delete root; // Delete the object
      root = succ;
    } else {
      Node<T>* p = root->remove(val);
      root = root->splay(root,p); //We splay the tree receiving the parent
    }
  }
  count--;
}

// =================================================================
// Removes all the elements on the three by callind removeChilds
// Complexity O(n)
// =================================================================
template <class T>
void SplayTree<T>::removeAll() {
	if (root != 0) {
		root -> removeChilds();
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
bool SplayTree<T>::find(T val) {
  	if (root != 0) {
    	Node<T>* found = root->find(val);
    	root = root->splay(root,found); // Calls splay on the found object
    	return (root->value == val);
  	} else {
    	return false;
  	}
}

// =================================================================
// Function which returns the inorder of the BST. It calls the inorder
// function from the node class if the tree is not empty.
// Complexity O(n)
// =================================================================
template <class T>
std::string SplayTree<T>::inorder() const {
  	std::stringstream aux;

  	aux << "[";
  	if (!empty()) {
    	root->inorder(aux);
  	}
  	aux << "]";
  	return aux.str();
}

// =================================================================
// Returns the number of elements on the array
// Complexity O(1)
// =================================================================
template <class T>
int SplayTree<T>::size(){
	return count;
}

// =================================================================
// Auxiliar functions to print the tree. This will be used to grade.
// =================================================================
template <class T>
std::string SplayTree<T>::print_tree() const {
  	std::stringstream aux;

  	aux << "\n ================================ ";
  	if (!empty()) {
    	root->print_tree(aux);
  	}
  	aux << " ================================== \n";
  	return aux.str();
}

template <class T>
std::string SplayTree<T>::preorder() const {
  	std::stringstream aux;

  	aux << "[";
  	if (!empty()) {
    	root->preorder(aux);
  	}
  	aux << "]";
  	return aux.str();
}

#endif