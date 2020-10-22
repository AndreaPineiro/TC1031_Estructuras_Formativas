## ADD
	** Análisis de complejidad temporal **
	La función va avanzando en el árbol con recursividad, si el objeto que queremos agregar es más chico que el nodo en 
	el que estamos se moverá a la izquierda y si no a la derecha.
	Con esto en el mejor de los casos no tendrá que cruzar toda la lista, sino que reducirá el tiempo a O(log(n)).
	Debido a que no hay splay dentro de la función, si no que se realiza el add y luego se llama el splay, puede haber un 
	caso en el que el árbol este desbalanceado. Si hicieramos el splay dentro de la función tendría una complejidad 
	O(log(n)), sin embargo primero lo estamos tratando como un binary tree, y luego realizamos el Splay.
	Complejidad: O(n)

## REMOVE
	** Análisis de complejidad temporal **
	Al igual que la anterior, la función va avanzando en el árbol con recursividad, hasta encontrar el objeto a borrar.
	Con esto en el mejor de los casos no tendrá que cruzar toda la lista, sino que reducirá el tiempo a O(log(n)).
	Debido a que no hay splay dentro de la función, si no que se realiza el remove y luego se llama el splay; como en la 
	función anterior, puede haber un caso en el que el árbol este desbalanceado. Si hicieramos el splay dentro de la 
	función tendría una complejidad O(log(n)), sin embargo primero lo estamos tratando como un binary tree, y luego 
	realizamos el Splay.
	Complejidad: O(log(n))

## FIND
	** Análisis de complejidad temporal **
	La función va avanzando en el árbol binario, si el objeto que queremos encontrar es más chico que el nodo en el que 
	estamos se moverá a la izquierda y si no a la derecha, hasta encontrar el objeto que estamos buscando, o hasta llegar 
	al final.
	Nuevamente no estamos haciendo un splay dentro de la función; por lo que en el peor de los casos podría recorrer los n 
	elementos. Al tratar el árbol como binary tree y luego llamar el splay, en el peor de los casos la complejidad aumenta. 
	Complejidad: O(n)

## INORDER
	** Análisis de complejidad temporal **
	La función imprime todos los nodos comenzando con el del último último nivel a la izquierda izquierda, luego sube e 
	imprime ese nodo y sus hijos a la derecha.
	Para este algoritmo, si recorremos todos los elementos dentro del árbol usando una función recursiva para cada nodo que 
	visitamos.
	Complejidad de O(n)

## SIZE
	** Análisis de complejidad temporal **
	La función obtiene el número de elementos que hay en el heap. Para esto, revisa el atributo count, que indica cuántos 
	elementos hay. 
	La función no realiza ningún ciclo, solo obtiene el valor del atributo count, por lo que la complejidad es constante.
	Complejidad: O(1)
