# SUMA ITERATIVA
	**Análisis de complejidad temporal**
	El algoritmo recorre n pasos ya que usa un ciclo que va de i = 1 hasta n, incrementando +1; ysumando en 
	cada paso el valor de i. 
	Por lo que su complejidad es O(n) para el peor de los casos.

# SUMA RECURSIVA
	**Análisis de complejidad temporal**
	El algoritmo recorre n pasos ya que la función se manda llamar así mismo n veces, desde n hasta 1; en cada 
	llamada, decrementa 1 y se vuelve a llamar sumando en cada paso el valor de n. 
	Por lo que su complejidad es O(n) para el peor de los casos.

# SUMA DIRECTA
	**Análisis de complejidad temporal**
	El algoritmo solo usa el valor de n para realizar un cálculo matemático, la fórmula usada es (n * (n+1) / 2). 
	Por lo que el número de pasos no varía dependiendo del valor de n, y su complejidad es O(1).
	
