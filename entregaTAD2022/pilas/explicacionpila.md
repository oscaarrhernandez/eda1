___
Autor: [Oscar Hernández Hernández](https://github.com/oscaarrhernandez)
___
# [Pilas](https://github.com/oscaarrhernandez)
- [Pilas](#pilas)
	- [Explicacion de pila.c](#explicacion-de-pilac)
		- [PilaCrearVacia](#pilacrearvacia)
		- [PilaVacia](#pilavacia)
		- [PilaInserta](#pilainserta)
		- [PilaSuprime](#pilasuprime)
	- [PilaMain](#pilamain)
## Explicacion de pila.c

El codigo de pila.c corresponde a una implementación de una pila (stack en inglés), una estructura de datos que permite almacenar y gestionar elementos de forma que el último en ser añadido es el primero en ser eliminado (principio LIFO, "last in, first out").

La pila se implementa mediante una lista enlazada, en la que se añaden elementos al principio y se eliminan del principio también.

___
### PilaCrearVacia

```c
int pilaCreaVacia(Pila *p)
```
Esta función recibe como parámetro una pila y la inicializa para que quede vacía. Si el parámetro es `NULL`, se devuelve un valor de error. En caso contrario, se asigna el valor `NULL` al puntero de la pila, de forma que quede vacía. La función devuelve `0` si todo ha ido bien o `-1` en caso de error.
___
### PilaVacia
```c
int pilaVacia(Pila *p)
```
Esta función recibe como parámetro una pila y devuelve `1` si la pila está vacía o `0` en caso contrario. Si el parámetro es `NULL`, se devuelve un valor de error.
___
### PilaInserta
```c
int pilaInserta(Pila *p, tipoElemento elemento)
```
Esta función recibe como parámetro una pila y un elemento, y añade el elemento a la pila. Se reserva memoria para almacenar una nueva celda en la pila, se almacena el elemento en la celda y se añade al principio de la pila. Si el parámetro `p` es `NULL`, se devuelve un valor de error. Si no hay suficiente memoria disponible para reservar una nueva celda, se devuelve otro valor de error. En caso contrario, se devuelve `0`.
___
### PilaSuprime
```c
tipoElemento pilaSuprime(Pila *p)
```
Esta función recibe como parámetro una pila y elimina el elemento que está al principio de la pila. Se devuelve el elemento eliminado. Si el parámetro `p` es `NULL` o la pila está vacía, se devuelve un valor de error.  
___  
## PilaMain
```c
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main(void)
{
    Pila p;
    int elemento;

    // Inicializamos la pila
    pilaCreaVacia(&p);

    // Insertamos algunos elementos en la pila
    pilaInserta(&p, 1);
    pilaInserta(&p, 2);
    pilaInserta(&p, 3);

    // Mostramos la pila
    printf("Pila: ");
    while (!pilaVacia(&p))
    {
        elemento = pilaSuprime(&p);
        printf("%d ", elemento);
    }
    printf("\n");

    return 0;
}
```
El programa crea una pila vacía, añade tres elementos y luego los elimina uno a uno mientras muestra su contenido. La salida del programa sería:
```
Pila: 3 2 1
```
