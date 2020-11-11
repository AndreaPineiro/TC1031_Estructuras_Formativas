## LOAD GRAPH LIST
	** Análisis de complejidad temporal **
	La función lee los datos de un archivo, y con cada línea crea un edge, para guardar la relación entre ambos nodos. 
	Va avanzando en el archivo hasta leer la última línea. Agrega estas conexiones en el vector de listas. 
	Debe recorrer todas las líneas para crear todos los edges. Y manda a llamar la función auxiliar addEdgeAdjList, 
	con una complejidad constante. 
	Complejidad: O(n)


## LOAD GRAPH MAT
	** Análisis de complejidad temporal **
	Al igual que la anterior, la función lee los datos de un archivo, y con cada línea crea
	un edge, para guardar la relación entre ambos nodos. Va avanzando en el archivo hasta leer la última línea; para 
	agregar las conexiones en la matriz.
	Debe recorrer todas las líneas para crear todos los edges. Y manda a llamar la función auxiliar addEdgeAdjMatrix, 
	con una complejidad constante. 
	Complejidad: O(n)


## PRINT ADJ LIST
	** Análisis de complejidad temporal **
	La función imprime la lista de adjacencia; imprime cada una de las listas dentro del vector. Esto para mostrar el 
	vértice, y todos los nodos a los que se puede llegar con éste. 
	Se usan dos ciclos for para imprimir todas las listas; la primera va avanzando entre cada una de las listas del 
	vector, que son el número de nodos. 
	Y el segundo ciclo avanza por cada uno de los elementos de la lista dentro de esa posición del vector. En el peor 
	de los casos, cada nodo tendrá conexión con todos los demas.
	Complejidad: O(n^2).   


## PRINT ADJ MAT
	** Análisis de complejidad temporal **
	La función imprime la matriz de adjacencia; imprime cada uno de los valores dentro de la matriz (listas anidadas). 
	Esto para mostrar 1 en las intersecciones que tienen conección y 0 en las que no.
	Se usan dos ciclos for para imprimir todos los valores; la primera va avanzando entre cada una de las listas, 
	que son el número de nodos. 
	Y el segundo ciclo avanza por cada elemento de las listas. En este caso al ser una matriz siempre va a recorrer n*n
	Complejidad: O(n^2)


## DFS HELPER
	** Análisis de complejidad temporal **
	La función realiza la búsqueda DFS (Depth First Search); que sigue la lógica de avanzar hasta llegar al final del 
	grafo por alguna de sus ramas, y volver a hacer lo mismo hasta llegar a la meta. 
	Este algoritmo puede tener dos diferentes complejidades dependiendo de si se usa la lista de adyacencia o si se 
	usa la matriz de adyacenia.
	Si se usa la matriz, tendrá una complejidad de O(V^2), donde V es el número de vértices del grafo. En cambio si se 
	usa la lista de adyacencia, la complejidad es de O(V+E).
	Usa un stack para almacenar los elementos y poder sacar al siguiente, que sería el último agregado. Primero se 
	agrega un elemento, se saca, y se mete al stack los hijos de este; y se vuelve a hacer lo mismo con el que esta 
	hasta arriba hasta llegar a la meta o recorrer todos los elementos. 
	En este caso usé la lista de adyacencia, en el peor de los casos recorrerá todos los caminos; y llegará en la meta 
	en el último o no lo encontratá en el grafo. Por lo que tendrá que pasar una vez por todos los vértices y todos 
	los arcos. 
	Complejidad: O(V+E)


## DFS
	Esta es la función que se manda llamar, en esta se inicializan todas las estructuras que se van a usar para la 
	búsqueda. En esta se manda llamar la función DFShelper, que es la que tiene la complejidad de la búsqueda DFS. Al 
	final también se manda a llamar las funciones que imprimen el vector de nodos visitados y el camino para llegar del 
	inicio a la meta.
	Complejidad: O(1) Debido a que solo llama otras funciones

## BFS HELPER
	La función realiza la búsqueda BFS (Breadth First Search); que sigue la lógica de revisar todos los hijos de un 
	nodo para encontrar el camino más corto de llegar a una meta. 
	Este algoritmo puede tener dos diferentes complejidades dependiendo de si se usa la lista de adyacencia o si se 
	usa la matriz de adyacenia.
	Si se usa la matriz, tendrá una complejidad de O(V^2), donde V es el número de vértices del grafo. En cambio si se 
	usa la lista de adyacencia, la complejidad es de O(V+E).
	Usa un queue para almacenar los elementos y poder sacar al siguiente, que sería el primero agregado. Esta es su 
	única diferencia con el anterior Primero se agrega un elemento, se saca, y se mete al stack los hijos de este; y se 
	vuelve a hacer lo mismo con el que esta hasta arriba hasta llegar a la meta o recorrer todos los elementos. 
	En este caso usé la lista de adyacencia, en el peor de los casos el elemento se encontratá en el último nivel, o no 
	estará dentro del grafo. Por lo que tendrá que pasar una vez por todos los vértices y todos los arcos. 
	Complejidad: O(V+E)

## BFS
	Esta es la función que se manda llamar, en esta se inicializan todas las estructuras que se van a usar para la búsqueda. 
	En esta se manda llamar la función BFShelper, que es la que tiene la complejidad de la búsqueda BFS. Al final también 
	se manda a llamar las funciones que imprimen el vector de nodos visitados y el camino para llegar del inicio a la meta.
	Complejidad: O(1) Debido a que solo llama otras funciones


# FUNCIONES AUXILIARES

## ADD EDGE ADJ LIST
	En esta función, se agrega una relación al vector de listas. Recibe una string y con esta obtiene 2 números que luego 
	usa para agregar el primero a la lista del segundo y viceversa. 
	Para esto no se usa ningún ciclo. Solo se usa el índice para acceder al apuntador y escribir el valor.
	Complejidad: O(1) 


## ADD EDGE ADJ MATRIX
	En esta función, se agrega una relación a la matriz (lista de listas). Recibe una string y con esta obtiene 2 números 
	que luego usa para agregar 1 en las dos intersecciones de los valores.  
	Para esto no se usa ningún ciclo. Solo se usa el índice para acceder al apuntador y escribir el valor.
	Complejidad: O(1) 


## PRINT VISITED
	En esta función se imprimen todos los elementos que fueron visitados, en el orden en el que se les visitó. Para esto 
	se usa un ciclo for, que va desde 0 hasta el tamaño del vector de visitados; y se imprime en orden cada uno de los 
	valores. 
	En el peor de los casos se deben imprimir todos los nodos, pues todos fueron visitados. 
	Complejidad: O(n) n -> número de nodos

## PRINT PATH
	En esta función se imprime el camino desde el nodo inicial hasta la meta. Va recorriendo de atrás para adelante y mete 
	cada uno de los nodos dentro de un stack; después pasa al padre de este nodo y lo mete en el stack, hasta llegar al 
	inicio.
	Después de que todos esten en el stack, comienza a sacarlos y a imprimir su valor, para imprimirlo en el orden correct. 
	Debido a que se deben meter y sacar todos los elementos del camino; en el peor de los casos el camino esta formado por 
	todos los nodos. Por lo que se deben recorrer todos los nodos 2 veces
	Complejidad: O(2n). n -> número de nodos

