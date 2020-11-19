// =================================================================
//
// File: graph.h
// Author: Andrea Pineiro Cavazos
// Description: Esta clase contiene la implementación de los  
// algoritmos complementarios de un Grafo.
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
#include <stack>
#include <queue>
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
        bool isCycle(int node, bool visited[], int parent);
        void topologicalSortHelper(int v, stack<int> &st, bool visited[]);
    public:
        Graph();
        void loadGraphList(string, int, int);
        void loadGraphMat(string, int, int);
        string printAdjList();
        string printAdjMat();
        bool isTree();
        string topologicalSort();
        bool bipartiteGraph();
        
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
void Graph::loadGraphList(string file, int ver, int arc) {
    nodes = ver; // Sets the new number of nodes
    adjList = new vector<int>[nodes]; // Creates a vector of arrays to store the connections.
    // Reads the file
    string line;
    ifstream lee(file);
    if (lee.is_open()){
        while(getline(lee, line)){
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
void Graph::loadGraphMat(string file, int ver, int arc) {
    nodes = ver;
    adjMatrix = new int[nodes*nodes]; // Creates a matrix with the size nodes*nodes
    for (int i = 0; i < nodes*nodes; i++){
        adjMatrix[i] = 0; // Sets every position to 0
    }
    // Reads the file
    string line;
    ifstream lee(file);
    if (lee.is_open()) {
        while (getline(lee, line)) {
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
void Graph::addEdgeAdjMatrix(string line) {
    int u, v;
    //  Gets the 2 integers, and converts from string to int
    u = stoi(line.substr(1,1));
    v = stoi(line.substr(4,1));
    adjMatrix[u * nodes + v] = 1; // Sets the intersection of u and v to 1
    adjMatrix[v * nodes + u] = 1; // Sets the intersection of v and u to 1
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
    for (int i = 0; i < nodes; i++) {
        aux << "vertex " << i << " : "; // prints vertex and the number
        for (int j = 0; j < adjList[i].size(); j++) {
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
    for (int i = 0; i < nodes; i++) {
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
string Graph::printAdjMat() {
    stringstream aux;
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; i < nodes; j++) {
            aux << adjMatrix[i *nodes + j] << " ";
            // Prints every element on the matrix
        }
    }
    return aux.str(); // Returns the string
}

// =================================================================
// This functions returns true if theres a cycle in the graph. If there
// is a cycle, the graph cannot be a tree.
// It receives the starting node, the list of visited nodes and the 
// parent of that node.
// Complexity O() 
// =================================================================
bool Graph::isCycle(int node, bool visited[], int parent) {
    visited[node] = true; // Sets the node to visited
    // Goes through all the vertex adj to node
    for (int v = 0; v < adjList[node].size(); v++){
        if (!visited[adjList[node][v]]) {
            if (isCycle(adjList[node][v], visited, node)) {
                return true; // If it is not visited, it calls the function
                // again in that node; and if it finds a cicle there it returns true.
            }
        } else if (adjList[node][v] != parent){
            return true; // If the adjacent node has been visited but 
            // it is not the parent, there is a cycle.
        }
    }
    return false; 
}

// =================================================================
// This functions returns true if the graph is a tree. It can only
// be a tree if there is not any cycle and if every node is connected.
// Complexity O(V+E) 
// =================================================================
bool Graph::isTree(){
    bool visited[nodes]; // Declares the array for visited nodes
    for (int i = 0; i < nodes; i++){
        visited[i] = false; // Sets every node as not visited
    }
    if (isCycle(0, visited, -1)){
        return false; // If there is a cycle on the graph, it returns false
    }
    // Checks every element on the array visited
    for (int i = 0; i < nodes; i++) {
        if (!visited[i]){
            return false; // If there is a node that has not been visited,
            // it returns false;
        }
    }
    return true;
}

// =================================================================
// This functions returns the topological sort of the graph. It uses DFS
// it follows a path until it reaches the end of it, and then moves 
// backwards to follow a different path.
// This function only calls the Helper function and initializes the 
// data structures. And then prints the sort.
// Complexity O(V+E) The algorith is DFS with a stack to print the 
// order so it is the same as DFS 
// ================================================================
string Graph::topologicalSort() {
    stringstream aux;
    stack<int> st; // Uses a stack to print the sorting
    bool visited[nodes]; // Creates an boolean array to know which nodes were visited
    for (int i = 0; i < nodes; i++) {
        visited[i] = false; // Sets each node to not visited
    }
    for (int i = 0; i < nodes; i++){
        if (visited[i] == false){
            topologicalSortHelper(i, st, visited); // Calls the Helper function
        }
    }
    while (!st.empty()) {
        if (st.size() == 1){
            aux << st.top(); // If it is the last element. It does not print the 
            // last space.
        } else{
            aux << st.top() << " "; //It prints the element on top of the stack
        }
        st.pop(); // Removes that element

    }
    return aux.str();
}

// =================================================================
// This is an auxiliar function for the topological sort. It receives
// the node for the sort, the stack and the array of visited nodes.
// Complexity O(V+E) 
// ================================================================
void Graph::topologicalSortHelper(int v, stack<int> &st, bool visited[]) {
    visited[v] = true; // Sets the node to visited
    // It checks every adjacent node
    for (int i = 0; i < adjList[v].size(); i++) {
        if (!visited[adjList[v][i]]) {
            topologicalSortHelper(adjList[v][i], st, visited);
            // It calls the function again on the childs of a node if they
            // have not been visited.
        }
    }
    st.push(v); // It adds the node to the stack once all it's children have
    // been analysed.
}

// =================================================================
// This functions returns true if the graph is bipartite. It can only
// be a bipartite if its vertex can be dividen into 2 sets.
// To check it, the algorithm is similar to BFS and it colors a
// node and then its childs have to be coloured with the 2nd colour. 
// Complexity O(V+E) 
// =================================================================
bool Graph::bipartiteGraph(){
    queue<int> qu;

    int color[nodes]; // We create an array to store colors of each node
    //1 and 0 are the 2 different colors. -1 means it has not been coloured.
    // 1 = red. 0 = blue
    for (int i = 0; i < nodes; i++) {
        color[i] = -1; // It sets every colour to not coloured.
    }
    color[0] = 1; // The first node will be coloured in red (1)

    qu.push(0); // It adds the node to the queue
    // Runs if there are nodes in the queue
    while (!qu.empty()){
        int current = qu.front(); // The current node is the one on the front 
        qu.pop(); // We remove this element
        // If there's a 1 in the intersection of current & current
        // we have a self-loop, and it is not bipartite.
        if (adjMatrix[current*nodes+current] == 1){
            return false; 
        }
        // Looks at all adjacent nodes.
        for (int v = 0; v < adjList[current].size(); v++){
            // If they are not coloured, it sets its colour to be the  
            // opposite to their parent's colour.
            if (color[adjList[current][v]] == -1){
                if (color[current] == 1){
                    color[adjList[current][v]] = 0;
                } else if (color[current] == 0){
                    color[adjList[current][v]] = 1;
                }
                qu.push(v); // Adds this node to the queue
            } else if (color[adjList[current][v]] == color[current]){
                return false; // Returns false if the node it has to colour has already
                // been coloured with the same colour as it's parent
            }
        }
    }
    // True if every adjacent vertex has an alternate colour.
    return true;
}

#endif