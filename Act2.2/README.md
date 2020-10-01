## ADD
	** Análisis de complejidad temporal **
	Gracias a previous, la función ya no tiene que recorrer todos los elementos para llegar al final. Este apuntador nos permite llegar directamente, y ligar el "next" del nuevo objeto a 0, y el previous del objeto al "tail" anterior. 
	Para agregar el objeto no hacemos ningún recorrido, lo obtenemos directamente. 
	Complejidad: O(1)

## FIND
	** Análisis de complejidad temporal **
	La función compara cada uno de los elementos con el que recibimos. En este algoritmo lo que se hace es usar dos apuntadores, uno que empiece en "head" que recorrerá la lista hacia delante y otro en "tail" que la recorrerá hacia atrás. 
	En cada ciclo se van a estar comparando 2 números gracias a los dos apuntadores; si el número esta más cerca del inicio será encontrado por el que comenzó en head, si esta más cerca del final por el que comenzó en tail.
	De esta manera el algortimo si recorre todos los elementos pero 2 a la vez, por lo que la complejidad es O(n/2), sin embargo se redondea. 
	Complejidad: O(n)


## UPDATE
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta llegar al índice del elemento que queremos cambiar. 
	En este algoritmo, si el índice se encuentra en la primer mitad de los elementos empezamos desde head; si se encuentra en la segunda mitad, empezamos desde el tail. 
	Para hacer esto se usa un while que recorre los elementos hasta llegar a la posición con un apuntador auxiliar 'p', y los compara con el índice que recibimos. Avanza de uno en uno por que se utilizan los apuntadores de cada objeto para llegar al siguiente, o al anterior en dado caso; pero al dividir la lista en 2 la complejidad es O(n/2) que se redondea.
	Complejidad: O(n)


## REMOVE
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta llegar al índice del elemento que queremos eliminar.
	Si el índice es el 0, solo cambiamos el apuntador de la cabeza hacia el siguiente elemento. Y el de previous lo apuntamos a 0.
	Si el índice es 1, el apuntador de la cola debe apuntar hacia el previous, y next hacia 0.
	Si se encuentra en algún otro, usa un ciclo for que va desde 1 hasta el índice que queremos encontrar. Recorre los elementos uno por uno con un apuntador auxiliar 'p', y los compara con el índice que recibimos. Cuando nos encontramos con el número anterior al índice, usamos otro apuntador 'q' que apunte al objeto en el índice que queremos eliminar. Cambiamos el apuntador del objeto en p para que vaya hacia el siguiente de q; y eliminamos el objeto al que apunta q.
	El algoritmo avanza de uno en uno por que se utilizan los apuntadores de cada objeto para llegar al siguiente. 
	Por lo que el algoritmo recorrerá todos los elementos en el peor de los casos. 
	Complejidad: O(n)


## CLEAR
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta el final.
	Avanza elemento por elemento usando los apuntadores de cada objeto.
	Esta función llega hasta el final de la lista con un ciclo while. 
	Complejidad: O(n)

## TOSTRING
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta el final. Avanza elemento por elemento usando los apuntadores de cada objeto para obtener el valor de cada uno y añadirlo a una string con todos los elementos de la lista
	Complejidad: O(n)