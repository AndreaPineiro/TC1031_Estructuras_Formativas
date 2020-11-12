// =================================================================
//
// File: graph.h
// Author: Andrea Pineiro Cavazos
// Description: Esta clase contiene la implementación de un 
// Grafo, con los algoritmos de DFS y BFS
//
// =================================================================


#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

// =================================================================
// Definition of the Graph class
// =================================================================
class Graph {
	private:
		int nodes;
		vector<int> *adjList;
		int *adjMatrix;
		void addEdgeAdjList(string);
		void addEdgeAdjMatrix(string);
		void sortAdjList();
	public:
		Graph();
		void loadGraphMat(string, int, int);
		void loadGraphList(string, int, int);
		string printAdjList();
		string printAdjMat();
		string DFS(int, int);
		string BFS(int, int);
		void DFSHelper(int current, int goal, stack<int> &st, bool visited[], int paths[], vector<int> &visitedOrder);
		void BFSHelper(int current, int goal, queue<int> &qu, bool visited[], int paths[], vector<int> &visitedOrder);
		string printVisited(vector<int> &visitedOrder);
		string printPath(int path[], int inicio, int meta);

};

// =================================================================
// Constructor. Initializes the value of Graph. The number of nodes
// is initialized to 0;
// Complexity O(1) Constant
// =================================================================
Graph::Graph(){
	nodes = 0;
}

// =================================================================
// This functions loads the edges and stores them in an adjacency 
// list. It receives the name of the file, and 2 integers. 
// The new value of nodes is the number of vertex. 
// Complexity: O(n) Linear. n -> number of lines. 
// =================================================================
void Graph::loadGraphList(string file, int ver, int arc){
	nodes = ver; // Sets the new number of nodes
	adjList = new vector<int>[nodes]; // Creates a vector of arrays to store the connections.  
	// Reads the file
	string line; 
	ifstream lee (file);
	if (lee.is_open()){
		while (getline(lee, line)){
			addEdgeAdjList(line); // Calls the function to store 
			// this new relation in the vector.
		}
		lee.close(); // Closes the file
	} else {
		cout << "Unable to open file"; 
	}
}

// =================================================================
// This functions receives a string; with that it gets 2 integers
// which are connected. And it adds each number in the other number's
// array. 
// Complexity: O(1) Constant
// =================================================================
void Graph::addEdgeAdjList(string line){
	int u, v;
	//  Gets the 2 integers, and converts from string to int
	u = stoi(line.substr(1,1));
	v = stoi(line.substr(4,1));
	adjList[u].push_back(v); // Adds v in the position u of the vector
	adjList[v].push_back(u); // Adds u in the position v of the vector
}


// =================================================================
// This functions loads the edges and stores them in an adjacency 
// matrix. It receives the name of the file, and 2 integers. 
// The new value of nodes is the number of vertex. 
// Complexity: O(n) Linear. n -> number of lines. 
// =================================================================
void Graph::loadGraphMat(string file, int ver, int arc){
	nodes = ver;
	adjMatrix = new int[nodes*nodes]; // Creates a matrix with the size nodes*nodes
	for (int i = 0; i < nodes*nodes; i++){
		adjMatrix[i] = 0; // Sets every position to 0
	}
	// Reads the file
	string line;
	ifstream lee(file);
	
	if (lee.is_open()){
		while (getline(lee, line)){
			addEdgeAdjMatrix(line); // Calls the function to store
			// this relation in the matrix
		}
		lee.close(); // Closes the file
	} else {
		cout << "Unable to open file";
	}

}

// =================================================================
// This functions receives a string; with that it gets 2 integers
// which are connected. And it adds a 1 in the intersections of both
// numbers in the matrix. 1 means that the nodes are connected.
// Complexity: O(1) Constant
// =================================================================
void Graph::addEdgeAdjMatrix(string line){
	int u, v;
	//  Gets the 2 integers, and converts from string to int
	u = stoi(line.substr(1,1));
	v = stoi(line.substr(4,1));
	adjMatrix[u*nodes+v] = 1; // Sets the intersection of u and v to 1
	adjMatrix[v*nodes+u] = 1; // Sets the intersection of v and u to 1
}

// =================================================================
// This functions prints the adjacency list. It prints the number of
// the vertex, and every element on the list of that position in the vector
// Ej. vertex 0 : 1 2 vertex 1 : 0 2 vertex 2 : 0 1
// Complexity: O(n^2) Cuadratic.
// =================================================================
string Graph::printAdjList(){
	stringstream aux;
	sortAdjList(); // Calls the function to sort the lists
	for (int i = 0; i < nodes; i++){
		aux << "vertex " << i << " : "; // prints vertex and the number
		for (int j = 0; j < adjList[i].size();j++){
			aux << adjList[i][j] << " "; 
			// prints each element on the list at the position i on the vector.
		}
	}
	return aux.str(); // returns the string
}

// =================================================================
// This functions sorts all the elements inside a list, it does it 
// for every list of each node. 
// Complexity O(n^2 log(n))
// =================================================================
void Graph::sortAdjList(){
	for (int i = 0; i < nodes; i++){
		sort(adjList[i].begin(), adjList[i].end()); //Complexity O(n log(n))
	}
}

// =================================================================
// This functions prints the adjacency matrix. It prints the number of
// each intersection (0 or 1). If it's 0 it's not connected, if it's 1 
// it is.
// Ej. 0 0 1 1 0 0 0 
// Complexity O(n^2) Cuadratic
// =================================================================
string Graph::printAdjMat(){
	stringstream aux;
	for (int i = 0; i < nodes; i++){
		for (int j = 0; j < nodes; j++){
			aux << adjMatrix[i*nodes+j] << " ";
			// Prints every element on the matrix
		}
	}
	return aux.str(); // Returns the string
}

// =================================================================
// This functions prints the DFS search (depth) starting from an initial
// node to the goal. 
// It uses an stack to keep track of the elements.
// Complexity O(V+E) V -> vertices   E -> edges 
// =================================================================
string Graph::DFS(int inicio, int meta){
	stringstream aux;
	stack<int> st; // Uses a stack to see which element is next
	bool visited[nodes]; // Creates an boolean array to know which nodes were visited
	vector<int> visitedOrder; // To print it in order, it uses a vector
	int path[nodes]; // Uses an array to store the parent of each node
	for (int i = 0; i < nodes; i++){
		visited[i] = false; // Sets each node to not visited
		path[i] = -1; // Sets each parent to be -1
	}
	st.push(inicio); // Adds the first node to the stack
	DFSHelper(inicio, meta, st, visited, path, visitedOrder); // Calls the aux function
	aux << printVisited(visitedOrder) << printPath(path, inicio, meta);
	// Prints the nodes visited, and the path from the start to the goal.
	return aux.str();
}

// =================================================================
// This functions prints is an auxiliar for the DFS search (depth) 
// It uses the stack. It pushes the element, stores it, pops the 
// element from the stack and pushes all the children of that node
// Becuase it is a stack, it uses the element last added.
// Complexity O(V+E) V -> vertices   E -> edges 
// =================================================================
void Graph::DFSHelper(int current, int goal, stack<int> &st, bool visited[], int paths[], vector<int> &visitedOrder){
	if (current == goal){
		return;
		// If it has reached the goal, it stops
	} else if (st.empty()){
		cout << "Node not found"; // In case it does not find the node
	} else {
		current = st.top(); // The current node is the one on the top
		st.pop(); // Pops the element on the top of the stack
		visited[current] = true; // Sets it to visited
		visitedOrder.push_back(current); // Adds the visited node to the vector
		// It checks every element connected to a node
		for (int i = 0; i < adjList[current].size(); i++){
			if (visited[adjList[current][i]] == false){
				st.push(adjList[current][i]);
				// It pushes the children of a node if it has not been visited
				paths[adjList[current][i]] = current; // Sets the children's node to be current
			}
		}
		DFSHelper(current, goal, st, visited, paths, visitedOrder); // Recursive function
	}
}

// =================================================================
// This functions prints the BFS search (breadth) starting from an initial
// node to the goal. 
// It uses an queue to keep track of the elements.
// Complexity O(V+E) V -> vertices   E -> edges 
// =================================================================
string Graph::BFS(int inicio, int meta){
	stringstream aux;
	queue <int> qu; // Uses a queue to see which element is next
	bool visited[nodes]; // Creates an boolean array to know which nodes were visited
	vector<int> visitedOrder; // To print it in order, it uses a vector
	int path[nodes]; // Uses an array to store the parent of each node
	for (int i = 0; i < nodes; i++){
		visited[i] = false; // Sets each node to not visited
		path[i] = -1; // Sets each parent to be -1
	}
	qu.push(inicio); // Adds the first node to the queue
	BFSHelper(inicio, meta, qu, visited, path, visitedOrder); // Calls the aux function
	aux << printVisited(visitedOrder) << printPath(path, inicio, meta);
	// Prints the nodes visited, and the path from the start to the goal.
	return aux.str();
}

// =================================================================
// This functions prints is an auxiliar for the BFS search (breath) 
// It uses the queue. It pushes the element, stores it, pops the 
// element from the queue and pushes all the children of that node
// Becuase it is a queue, it uses the element first added.
// Complexity O(V+E) V -> vertices   E -> edges 
// =================================================================
void Graph::BFSHelper(int current, int goal, queue<int> &qu, bool visited[], int paths[], vector<int> &visitedOrder){
	if (current == goal){
		return;
		// If it has reached the goal, it stops
	} else if (qu.empty()){
		cout << "Node not found"; // In case it does not find the node
	} else {
		current = qu.front(); // The current node is the one on the front
		qu.pop(); // Pops the element on the front of the queue
		visited[current] = true; // Sets it to visited
		visitedOrder.push_back(current); // Adds the visited node to the vector
		// It checks every element connected to a node
		for (int i = 0; i < adjList[current].size(); i++){
			if (visited[adjList[current][i]] == false){
				qu.push(adjList[current][i]);
				// It pushes the children of a node if it has not been visited
				// If the element on the path list is set to one it replaces the
				// value. If it has already been replaced it leaves it that way.
				if (paths[adjList[current][i]] == -1){
					paths[adjList[current][i]] = current;
				}
			}
		}
		BFSHelper(current, goal, qu, visited, paths, visitedOrder); // Recursive function
	}
}

// =================================================================
// This functions prints all the elements which were visited in order. 
// It prints all the elements in the vector visitedOrder.
// Complexity: O(n) Linear.
// =================================================================
string Graph::printVisited(vector<int> &visitedOrder){
	stringstream aux;
	aux << "visited:"; 
	for (int i = 0; i < visitedOrder.size(); i++){
		aux << " " << visitedOrder[i]; // Adds every visited node
		// to the stream
	}
	return aux.str();
}

// =================================================================
// This functions prints the path from the initial node to the goal. 
// It goes backwards to find the path and then prints it with a stack
// Complexity: O(2n) .
// =================================================================
string Graph::printPath(int path[], int inicio, int meta){
	stringstream aux;

	stack<int> reverse; // Creates a stack to print the path reversed
	int node = meta; // Starts at the goal
	// It keeps going until it's reached the begining
	while (node != inicio){
		reverse.push(node); // Adds the node to the stack 
		node = path[node]; // The new node is the value of path, which 
		//contains the parent of that node. 
	}
	reverse.push(inicio); // It adds the first node to the stack
	aux << " path:";
	// While there's an element on the stack it prints the last one
	while (!reverse.empty()) {
		aux << " " << reverse.top();
		reverse.pop();
	}
	return aux.str();
}

#endif