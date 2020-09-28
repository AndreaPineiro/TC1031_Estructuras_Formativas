## ADD
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos de la lista en orden, para poder llegar hasta el último elemento y ligarlo con el que queremos añadir. 
	Para hacer esto se usa un ciclo que va usando los apuntadores para recorrer cada elemento hasta que no haya ninguno más.
	Complejidad: O(n)

## FIND
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta llegar al final, o hasta encontrar el número dentro de la lista. 
	Para hacer esto se usa un while que recorre los elementos uno por uno, y los compara con el objeto que recibimos. 
	En el peor de los casos, el elemento se encontrará en la última posición de la lista, o no se encontrará; por lo que el algoritmo recorrerá todos los elementos. 
	Complejidad: O(n)

## UPDATE
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta llegar al índice del elemento que queremos cambiar.
	Para hacer esto se usa un while que recorre los elementos uno por uno con un apuntador auxiliar 'p', y los compara con el índice que recibimos. Avanza de uno en uno por que se utilizan los apuntadores de cada objeto para llegar al siguiente. 
	En el peor de los casos, el índice que queremos encontrar será la última posición de la lista; por lo que el algoritmo recorrerá todos los elementos. 
	Complejidad: O(n)


## REMOVE
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta llegar al índice del elemento que queremos eliminar.
	Si el índice es el 0, solo cambiamos el apuntador de la cabeza hacia el siguiente elemento.
	Si se encuentra en algún otro, usa un ciclo for que va desde 1 hasta el índice que queremos encontrar. Recorre los elementos uno por uno con un apuntador auxiliar 'p', y los compara con el índice que recibimos. Cuando nos encontramos con el número anterior al índice, usamos otro apuntador 'q' que apunte al objeto en el índice que queremos eliminar. Cambiamos el apuntador del objeto en p para que vaya hacia el siguiente de q; y eliminamos el objeto al que apunta q.
	El algoritmo avanza de uno en uno por que se utilizan los apuntadores de cada objeto para llegar al siguiente. 
	En el peor de los casos, el índice que queremos encontrar será la última posición de la lista; por lo que el algoritmo recorrerá todos los elementos. 
	Complejidad: O(n)


## CLEAR
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta el final.
	Avanza elemento por elemento usando los apuntadores de cada objeto.
	Esta función llega hasta el final de la lista con un ciclo while. 
	Complejidad: O(n)

## CLEAR
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta el final. Avanza elemento por elemento usando los apuntadores de cada objeto para obtener el valor de cada uno y añadirlo a una string con todos los elementos de la lista
	Complejidad: O(n)
