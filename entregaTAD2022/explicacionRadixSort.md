___
Autor: [Oscar Hernández Hernández](https://github.com/oscaarrhernandez)
___
# [RadixSort](https://github.com/oscaarrhernandez)
- [RadixSort](#radixsort)
	- [Explicacion RadixSort.c](#explicacion-radixsortc)
		- [RadixSort](#radixsort-1)
		- [ObtenerCifra](#obtenercifra)
	- [Analisis teorico](#analisis-teorico)
	- [ResultadosLista.txt](#resultadoslistatxt)

## Explicacion RadixSort.c

El codigo que se encuentra en radixSort.c corresponde a una implementación del algoritmo de ordenamiento "Radix Sort", que es una variante del algoritmo de ordenamiento "Counting Sort". El algoritmo de "Radix Sort" se utiliza para ordenar una lista de números enteros.

El algoritmo funciona de la siguiente manera:

1. Se divide la lista en varios grupos, cada uno de los cuales representa un dígito diferente (por ejemplo, el grupo 0 representa los números que tienen un 0 como su última cifra, el grupo 1 representa los números que tienen un 1 como su última cifra, y así sucesivamente).

2. Se recorre cada cifra de cada número en la lista, empezando por la cifra menos significativa (es decir, la cifra más a la derecha). Para cada número, se determina a qué grupo pertenece y se mueve a ese grupo.

3. Una vez que se han movido todos los números a sus grupos correspondientes, se concatenan los grupos en el orden correcto para formar la lista ordenada.

4. Se repite este proceso para cada cifra, empezando por la cifra más significativa (es decir, la cifra más a la izquierda) y terminando con la cifra menos significativa.

El algoritmo de "Radix Sort" es muy eficiente para ordenar grandes cantidades de números enteros, ya que tiene un tiempo de ejecución lineal en el número de elementos en la lista. Sin embargo, es menos eficiente para ordenar otros tipos de elementos, como cadenas de caracteres o estructuras de datos más complejas.

___

### RadixSort

```c
void radixSort(Lista *lista, tipoElemento nGrupos, tipoElemento nCifras)
```

Esta función es el corazón del algoritmo de ordenación por distribución, que se utiliza para ordenar una lista de números enteros.

1. La función "radixSort" toma como argumentos una lista y dos números enteros "nGrupos" y "nCifras". Esta función es la encargada de llevar a cabo el algoritmo de "Radix Sort".

2. Se define un arreglo de listas "ptGrupos" que tendrá "nGrupos" elementos. Cada elemento de este arreglo representa un grupo de números con una cierta cifra en común.

3. Se inicializan todas las listas en el arreglo "ptGrupos" con la función "creaVacia".

4. Se itera sobre cada cifra de cada número en la lista, empezando por la cifra menos significativa (es decir, la cifra más a la derecha). En cada iteración, se determina a qué grupo pertenece cada número y se mueve a ese grupo.

5. Una vez que se han movido todos los números a sus grupos correspondientes, se concatenan los grupos en el orden correcto para formar la lista ordenada.

6. Se repite este proceso para cada cifra, empezando por la cifra más significativa (es decir, la cifra más a la izquierda) y terminando con la cifra menos significativa.

7. La función "obtenerCifra" se utiliza para determinar a qué grupo pertenece cada número. Toma como argumentos un número "num" y un entero "n", y devuelve la cifra "n" del número "num". Por ejemplo, si "num" es 123 y "n" es 1, la función devolvería el valor 2. Si "n" es 0, la función devolvería el valor 3.

___

### ObtenerCifra

```c
tipoElemento obtenerCifra(tipoElemento num, tipoElemento n)
```

Esta función recibe como parámetros un número y una cifra y devuelve el valor de la cifra indicada del número. Por ejemplo, si llamamos a `obtenerCifra(12345, 3)`, se devolverá el valor `4`, ya que la cifra de las unidades de mil del número `12345` es `4`.

___

## Analisis teorico

La complejidad temporal del código es O(n * c), donde "n" es el número de elementos en la lista y "c" es el número de cifras en cada número. Esto se debe a que el algoritmo itera sobre cada cifra de cada número en la lista, lo que lleva a un tiempo de ejecución proporcional al número de elementos y al número de cifras.

Para calcular la complejidad temporal del código, podemos seguir los siguientes pasos:

1. La complejidad temporal del bucle "for" en la línea 30 es O(nCifras), ya que itera sobre cada cifra de cada número en la lista.

2. La complejidad temporal del bucle "for" en la línea 33 es O(nGrupos), ya que itera sobre cada grupo del arreglo "ptGrupos".

3. La complejidad temporal del bucle "while" en la línea 42 es O(n), ya que itera sobre cada elemento de la lista.

4. La complejidad temporal de la llamada a la función "recupera" en la línea 45 es O(1), ya que solo se necesita acceder a una posición específica en la lista.

5. La complejidad temporal de la llamada a la función "obtenerCifra" en la línea 49 es O(1), ya que solo se necesita realizar algunas operaciones aritméticas simples.

6. La complejidad temporal de la llamada a la función "traspasarNodo" en la línea 53 es O(1), ya que solo se necesita realizar algunas operaciones simples para mover un elemento de una lista a otra.

7. La complejidad temporal del bucle "for" en la línea 60 es O(nGrupos), ya que itera sobre cada grupo del arreglo "ptGrupos".

8. La complejidad temporal de la llamada a la función "concatenarListas" en la línea 61 es O(n), ya que se concatenan dos listas que tienen una longitud total de "n" elementos.

Si sumamos todas estas complejidades temporales, obtenemos una complejidad temporal total de O(n * c), donde "n" es el número de elementos en la lista y "c" es el número de cifras en cada número.

___

## ResultadosLista.txt

Aqui nos encontramos con el tiempo que tarda en ordenar una lista. 

- Tiempo usado para ordenar una lista de 100 elementos = 0.000000 y el numero de interacciones realizadas es de 2739

- Tiempo usado para ordenar una lista de 500 elementos = 0.015625 y el numero de interacciones realizadas es de 13920

- Tiempo usado para ordenar una lista de 800 elementos = 0.015625 y el numero de interacciones realizadas es de 22151

- Tiempo usado para ordenar una lista de 1000 elementos = 0.046875 y el numero de interacciones realizadas es de 27581

- Tiempo usado para ordenar una lista de 2500 elementos = 0.375000 y el numero de interacciones realizadas es de 69322

- Tiempo usado para ordenar una lista de 4000 elementos = 1.078125 y el numero de interacciones realizadas es de 109413

- Tiempo usado para ordenar una lista de 6000 elementos = 2.609375 y el numero de interacciones realizadas es de 165369

- Tiempo usado para ordenar una lista de 8000 elementos = 4.828125 y el numero de interacciones realizadas es de 219101

- Tiempo usado para ordenar una lista de 10000 elementos = 8.203125 y el numero de interacciones realizadas es de 275394
