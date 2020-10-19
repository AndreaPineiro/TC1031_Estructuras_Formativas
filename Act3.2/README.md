## EMPTY
	** Análisis de complejidad temporal **
	La función revisa si el heap está vacío, es decir, si no contiene ningún elemento. Para esto, revisa el atributo 
	count, que indica cuántos elementos hay. Si count es igual a 0, significa que no hay ningún elemento en el heap. 
	La función no realiza ningún ciclo, solo obtiene el valor del atributo count, por lo que la complejidad es constante.
	Complejidad: O(1)

## EMPTY
	** Análisis de complejidad temporal **
	La función obtiene el número de elementos que hay en el heap. Para esto, revisa el atributo count, que indica cuántos 
	elementos hay. 
	La función no realiza ningún ciclo, solo obtiene el valor del atributo count, por lo que la complejidad es constante.
	Complejidad: O(1)

## PUSH
	** Análisis de complejidad temporal **
	Esta función agrega a la fila priorizada un elemento; cuando lo recibe lo coloca hasta el final de la lista, pero 
	con un while lo acomoda en el lugar correcto, para que no sea mayor que su padre.
	Gracias a que los elementos están ordenados equitativamente en cada rama, no hay necesidad de recorrer todos los 
	objetos. En el peor de los casos tendría que mover el elemento hasta la primer posición, pero solo pasaría por una 
	rama, por lo que la complejidad es logarítmica.
	Complejidad: O(log(n))


## POP
	** Análisis de complejidad temporal **
	Esta función saca de la fila priorizada el objeto con mayor prioridad, es decir el objeto que se encuentra al inicio 
	del arreglo; esto debido a que como es un heap ordenado, el primer elemento es el de mayor prioridad.
	La función sobreescribe el primer elemento del heap con el último que añadimos. Y manda a llamar la función Heapify.
	Como solo estamos mandando llamar la función, tiene una complejidad constante. O(1).

	Sin embargo, debido al algoritmo de Heapify la complejidad total al eliminar un elemento es
	Complejidad: O(log(n))
	En el apartado de Heapify se explica el análisis temporal


## HEAPIFY
	** Análisis de complejidad temporal **
	Esta función revisa que el heap este ordenado correctamente, es decir que el elemento que se encuentre al inicio sea 
	el de mayor prioridad. Esto lo hace comparando el valor de el elemento con sus vecinos en la derecha o en la izquierda; 
	si alguno de ellos es de mayor prioridad hace un swap por con el menor. 
	Esta función se llama recursivamente después que el primer elemento ya se ordeno; lo que hace es volverla a llamar pero 
	ahora con min. 
	Sin embargo, debido al acomodo de los elementos; es como se fuera un árbol balanceado; por lo que no tendrá que llamar 
	la función n veces. 
	En el peor de los casos se tendría que llegar hasta el final de una de las ramas, y como los elementos están ordenados 
	equitativamente en cada rama, no hay necesidad de recorrer todos los objetos; por lo que es logarítmica.
	Complejidad de O(log(n)


## TOP
	** Análisis de complejidad temporal **
	La función obtiene el objeto que se encuentra en el primer lugar del heap, es decir, el elemento con mayor prioridad. 
	La función no realiza ningún ciclo, solo obtiene el valor que se encuentra en la posición 0 del arreglo, por lo que 
	la complejidad es constante.
	Complejidad: O(1)


### FUNCIONES AUXILIARES

## SWAP
	** Análisis de complejidad temporal **
	La función recibe dos posiciones, e intercambia los objetos que se encuentran en ambas; el primer objeto lo pasa a la 
	segunda posición y viceversa. Para hacerlo guarda uno de los valores en una variable auxiliar. 
	La función no realiza ningún ciclo, solo obtiene el valor del las posiciones y los cambia.
	Complejidad de O(1)


## FULL
	** Análisis de complejidad temporal **
	La función obtiene el número de elementos que hay en el heap y lo compara con el tamaño de elementos máximo que acepta 
	el heap. Para esto, revisa el atributo count, que indica cuántos elementos hay y el de size (tamaño del arreglo); si 
	son iguales significa que el arreglo está lleno.
	La función no realiza ningún ciclo, solo obtiene el valor de los atributo, por lo que la complejidad es constante.
	Complejidad de O(1)


## PARENT, LEFT, RIGHT
	** Análisis de complejidad temporal **
	Estas funciones regresan la posición en la que se encuentra el padre, el objeto de la izquierda y el de la derecha 
	respectivamente. 
	La función no realiza ningún ciclo, solo realizan un cálculo para encontrar estas posiciones.
	Complejidad de O(1)

