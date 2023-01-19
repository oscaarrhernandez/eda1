___
Autor: [Oscar Hernández Hernández](https://github.com/oscaarrhernandez)
___
# [Cola](https://github.com/oscaarrhernandez)
- [Cola](#cola)
	- [Explicacion cola.c](#explicacion-colac)
		- [CrearCola](#crearcola)
		- [ColaVacia](#colavacia)
		- [Inserta](#inserta)
		- [Eliminar](#eliminar)
		- [Cabeaza](#cabeaza)
	- [ColaMain](#colamain)

## Explicacion cola.c  
El codigo de cola.c corresponde a una implementación de una cola (queue en inglés), una estructura de datos que permite almacenar y gestionar elementos de forma que el primero en ser añadido es el primero en ser eliminado (principio FIFO, "first in, first out").

La cola se implementa mediante una lista enlazada, en la que se añaden elementos al final y se eliminan del principio.   
___
### CrearCola
```c
Cola crearCola()
```
Esta función crea una cola vacía y devuelve una estructura de tipo Cola con los punteros `frente` y `fondo` inicializados a `NULL`.
___
### ColaVacia
```c
int colaVacia(Cola *c)
```
Esta función recibe como parámetro una cola y devuelve `1` si la cola está vacía o `0` en caso contrario.
___
### Inserta
```c
void insertar(tipoElemento elemento, Cola *c)
```
Esta función recibe como parámetros un elemento y una cola, y añade el elemento a la cola. Se reserva memoria para almacenar una nueva celda en la cola, se almacena el elemento en la celda y se añade al final de la cola.
___
### Eliminar
```c
tipoElemento eliminar(Cola *c)
```
Esta función recibe como parámetro una cola y elimina el elemento que está al principio de la cola. Se devuelve el elemento eliminado. Si la cola está vacía, la función no realiza ninguna acción.
___
### Cabeaza
```c
tipoElemento cabeza(Cola *c)
```
Esta función recibe como parámetro una cola y devuelve el elemento que está al principio de la cola, sin eliminarlo. Si la cola está vacía, la función devuelve un valor de error.
___
## ColaMain
```c
#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main(void)
{
    Cola c;
    int elemento;

    // Creamos una cola vacía
    c = crearCola();

    // Insertamos algunos elementos en la cola
    insertar(1, &c);
    insertar(2, &c);
    insertar(3, &c);

    // Mostramos la cola
    printf("Cola: ");
    while (!colaVacia(&c))
    {
        elemento = eliminar(&c);
        printf("%d ", elemento);
    }
    printf("\n");

    return 0;
}
```
El programa crea una cola vacía, añade tres elementos y luego los elimina uno a uno mientras muestra su contenido. La salida del programa sería:
```c
Cola: 1 2 3
```
