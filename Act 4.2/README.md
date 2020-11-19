## ISTREE
	** Análisis de complejidad temporal **
	Esta función devuelve un valor booleano que es verdadero si el grafo tiene la estructura de un árbol; esto es si no tiene ciclos y si todos sus nodos están conectados. 
	En esta función tenemos primero un ciclo que va de 0 hasta V (número de nodos), para inicializar primero la lista de nodos visitados.
	Después manda a llamar la función isCycle para saber si hay ciclos; y para finalizar vuelve a realizar otro ciclo que recorre todo el arreglo de nodos visitados, si encuentra uno que no haya sido visitado, significa que no esta conectado.
	En el peor de los casos este algoritmo recorrerá todos los caminos y pasará por cada nodo; y llegará en la meta en el último o no lo encontratá en el grafo. Por lo que tendrá que pasar una vez por todos los vértices y todos los arcos. 
	Complejidad: O(V+E) V -> Vertex    E -> Edges


## ISCYCLE
	** Análisis de complejidad temporal **
	Esta es la función auxiliar que manda llamar IsTree; lo que hace es recorrer los nodos hasta encontrar un ciclo dentro del grafo; o hasta terminar sin encontrar un ciclo, y en dado caso devuelve falso.
	La función sigue el orden que lo haría DFS (Depth First Search), pasando por cada camino y luego regresando si no encuentra un ciclo.
	Cuando encuentra un ciclo, sale de la función por lo que no siemore tendrá que recorrer todos los nodos. Sin embargo, en el caso que no haya ciclos o que se encuentre en el último nodo, tendremos que pasar por cada uno de los vértices y arcos.
	Complejidad: O(V+E) V -> Vertex    E -> Edges


## TOPOLOGICAL SORT
	** Análisis de complejidad temporal **
	Para el ordenamiento topológico, se usa la misma lógica que DFS (Depth First Search); avanzar hasta llegar al final del grafo por alguna de sus ramas, y volver a hacer lo mismo hasta llegar a la meta.
	Cuando llega al final de un camino comienza a imprimir los nodos comenzando por el último, cuando llega a un nodo con más hijos se va por el siguiente camino. Y al llegar al final vuelve a imprimir desde el último nodo hacia atrás. 
	Al igual que DFS, este algoritmo puede tener dos diferentes complejidades dependiendo de si se usa la lista de adyacencia o si se usa la matriz de adyacenia.
	Si se usa la matriz, tendrá una complejidad de O(V^2), donde V es el número de vértices del grafo. En cambio si se usa la lista de adyacencia, la complejidad es de O(V+E).
	Usa un stack para almacenar los elementos y poder sacar al siguiente, que sería el último agregado. Primero se agrega un elemento, se saca, y se mete al stack los hijos de este; y se vuelve a hacer lo mismo con el que esta hasta arriba hasta llegar a la meta o recorrer todos los elementos. 
	En este caso usé la lista de adyacencia, en el peor de los casos recorrerá todos los caminos; y llegará en la meta en el último o no lo encontratá en el grafo; teniendo que pasar por todos los vértices y todos las aristas. Por lo que tendrá que pasar una vez por todos los vértices y todos los arcos. 
	Complejidad: O(V+E) V -> Vertex    E -> Edgesad: O(V+E)


## BIPARTITE GRAPH
	** Análisis de complejidad temporal **
	Este algoritmo pretende separar los nodos en dos subconjuntos diferentes. Para esto, se sigue la lógica de "colorear" de dos colores diferentes a cada nodo. Si el primero lo pintamos de rojo, sus hijos deben ser azules; y los hijos de sus hijos azules. 
	Un grafo es bipartito si podemos colorearlo de ambos colores sin que existan dos nodos adyacentes con el mismo color.
	Para realizarlo, el algoritmo sigue la misma lógica que la búsqueda BFS (Breadth First Search); que revisa todos los hijos de un nodo para encontrar el camino más corto de llegar a una meta. 
	Al igual que BFS, este algoritmo puede tener dos diferentes complejidades dependiendo de si se usa la lista de adyacencia o si se usa la matriz de adyacenia.
	Si se usa la matriz, tendrá una complejidad de O(V^2), donde V es el número de vértices del grafo. En cambio si se usa la lista de adyacencia, la complejidad es de O(V+E).
	Usa un queue para almacenar los elementos y poder sacar al siguiente, que sería el primero agregado. Esta es su única diferencia con DFS. Primero se agrega un elemento, se saca, y se mete al queue los hijos de este; y se vuelve a hacer lo mismo con el que esta hasta arriba hasta llegar a la meta o recorrer todos los elementos. 
	En este caso usé la lista de adyacencia, en el peor de los casos el elemento se encontratá en el último nivel, o no estará dentro del grafo. Por lo que tendrá que pasar una vez por todos los vértices y todos los arcos. 
	Complejidad: O(V+E) V -> Vertex    E -> Edges


# FUNCIONES AUXILIARES

##ADD EDGE ADJ LIST
	** Análisis de complejidad temporal **
	En esta función, se agrega una relación al vector de listas. Recibe una string y con esta obtiene 2 números que luego usa para agregar el primero a la lista del segundo y viceversa. 
	Para esto no se usa ningún ciclo. Solo se usa el índice para acceder al apuntador y escribir el valor.
	Complejidad: O(1) 


##ADD EDGE ADJ MATRIX
	** Análisis de complejidad temporal **
	En esta función, se agrega una relación a la matriz (lista de listas). Recibe una string y con esta obtiene 2 números que luego usa para agregar 1 en las dos intersecciones de los valores.  
	Para esto no se usa ningún ciclo. Solo se usa el índice para acceder al apuntador y escribir el valor.
	Complejidad: O(1) 

## LOAD GRAPH LIST
	** Análisis de complejidad temporal **
	La función lee los datos de un archivo, y con cada línea crea un edge, para guardar la relación entre ambos nodos. Va avanzando en el archivo hasta leer la última línea. Agrega estas conexiones en el vector de listas. 
	Debe recorrer todas las líneas para crear todos los edges. Y manda a llamar la función auxiliar addEdgeAdjList, con una complejidad constante. 
	Complejidad: O(n)


## LOAD GRAPH MAT
	** Análisis de complejidad temporal **
	Al igual que la anterior, la función lee los datos de un archivo, y con cada línea crea
	un edge, para guardar la relación entre ambos nodos. Va avanzando en el archivo hasta leer la última línea; para agregar las conexiones en la matriz.
	Debe recorrer todas las líneas para crear todos los edges. Y manda a llamar la función auxiliar addEdgeAdjMatrix, con una complejidad constante. 
	Complejidad: O(n)


## PRINT ADJ LIST
	** Análisis de complejidad temporal **
	La función imprime la lista de adjacencia; imprime cada una de las listas dentro del vector. Esto para mostrar el vértice, y todos los nodos a los que se puede llegar con éste. 
	Se usan dos ciclos for para imprimir todas las listas; la primera va avanzando entre cada una de las listas del vector, que son el número de nodos. 
	Y el segundo ciclo avanza por cada uno de los elementos de la lista dentro de esa posición del vector. En el peor de los casos, cada nodo tendrá conexión con todos los demas.
	Complejidad: O(n^2).   


## PRINT ADJ MAT
	** Análisis de complejidad temporal **
	La función imprime la matriz de adjacencia; imprime cada uno de los valores dentro de la matriz (listas anidadas). Esto para mostrar 1 en las intersecciones que tienen conección y 0 en las que no.
	Se usan dos ciclos for para imprimir todos los valores; la primera va avanzando entre cada una de las listas, que son el número de nodos. 
	Y el segundo ciclo avanza por cada elemento de las listas. En este caso al ser una matriz siempre va a recorrer n*n
	Complejidad: O(n^2)

