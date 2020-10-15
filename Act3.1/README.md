## ADD
	** Análisis de complejidad temporal **
	La función va avanzando en el árbol binario, si el objeto que queremos agregar es más chico que el nodo en el que estamos se moverá a la izquierda y si no a la derecha.
	Con esto en el mejor de los casos no tendrá que cruzar toda la lista, sino que reducirá el tiempo a O(log(n)).
	Sin embargo, en el caso de que al agregar elementos el árbol solo comience a crecer de un lado, por que todos son o más chicos o más grandes que la ráiz; para el peor de los casos se tendrá que recorrer todos los elementos.
	Complejidad: O(n)

## FIND
	** Análisis de complejidad temporal **
	La función va avanzando en el árbol binario, si el objeto que queremos encontrar es más chico que el nodo en el que estamos se moverá a la izquierda y si no a la derecha, hasta encontrar el objeto que estamos buscando, o hasta llegar al final.
	Con esto en el mejor de los casos no tendrá que cruzar toda la lista, sino que reducirá el tiempo a O(log(n)).
	Sin embargo, en el caso de que el árbol solo tenga elemtos a la izqueirda o derecha de la raíz, para el peor de los casos se tendrá que recorrer todos los elementos.
	Complejidad: O(n)


## HEIGHT
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro deL árbol anidada hasta llegar al último nivel.
	En este algoritmo no solo recorre los elementos a la izqueirda o a la derecha, si no que recorre ambos para encontrar cuál es el más grande y así saber cuál es la altura de nuestro árbol 
	Para hacer esto se usan los apuntadores de right y de left para movernos en el árbol.
	Complejidad: O(n)


## WHATLEVELAMI
	** Análisis de complejidad temporal **
	Esta función busca el elemento del cuál queremos encontrar su nivel. Lo hace con la misma lógica anterior, si el objeto es menor se mueve a la izquierda y si es mayor se mueve a la derecha.
	Después de eso se vuelve a llamar a la función; en el mejor de los casos podría tener una complejidad de O(log(n)), sin embargo si volvemos al caso en el que el árbol no este balanceado y todos sus elementos se encuentren a la derecha o izquierda uno después del otro el algoritmo tendrá que recorrer cada uno de los objetos en el árbol.
	Complejidad: O(n)


## CLEAR
	** Análisis de complejidad temporal **
	La función busca el elemento del cual queremos obtener sus ancestros con la misma lógica de los anteriores algoritmos; moviendose a la izqueirda o derecha dependiendo del valor a buscar. 
	Al encontrar el elemento tenemos que recorrer cada uno de sus padres, esto lo hacemos llamando de nuevo a la función de ancestros para recorrer desde el nodo hasta la raíz. 
	Para el peor de los casos tendremos el mismo problema mencionado anteriormente, que todos los elementos se encuentren de un solo lado al buscar el objeto, y si queremos desplegar los ancestros de el elemento en el nivel más bajo con este caso tendremos una Complejidad de O(n)


## PREORDER
	** Análisis de complejidad temporal **
	La función imprime todos los nodos comenzando con los que se encuentran a la izquierda, luego sube e imprime los nodos que se encuentran a la derecha de los que ya habíamos visitado anteriormente.
	Para este algoritmo, si recorremos todos los elementos dentro del árbol usando una función recursiva para cada nodo que visitamos.
	Complejidad de O(n)


## INORDER
	** Análisis de complejidad temporal **
	La función imprime todos los nodos comenzando con el del último último nivel a la izquierda izquierda, luego sube e imprime ese nodo y sus hijos a la derecha.
	Para este algoritmo, si recorremos todos los elementos dentro del árbol usando una función recursiva para cada nodo que visitamos.
	Complejidad de O(n)


## POSTORDER
	** Análisis de complejidad temporal **
	La función imprime todos los nodos comenzando con el del último último nivel a la izquierda izquierda, luego sube e imprime los hijos de la derecha comenzando por el que esta en el nivel más bajo.
	Para este algoritmo, si recorremos todos los elementos dentro del árbol usando una función recursiva para cada nodo que visitamos.
	Complejidad de O(n)


## LEVELBYLEVEL
	** Análisis de complejidad temporal **
	La función imprime todos los nodos de cada nivel; comenzando por los que están en el primer nivel, luego con el segundo nivel hasta llegar al último.
	Para este algoritmo, si recorremos todos los elementos dentro del árbol usando una función recursiva para cada nodo que visitamos.
	Complejidad de O(n)