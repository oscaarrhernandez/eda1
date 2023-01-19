/*

<> Oscar Hernandez Hernandez
<> https://github.com/oscaarrhernandez

*/
#ifndef __COLA_H
#define __COLA_H

#ifndef __TIPO_ELEMENTO
#define __TIPO_ELEMENTO
typedef int tipoElemento;
#endif

#ifndef __TIPO_CELDA
#define __TIPO_CELDA
typedef struct tipoCelda
{
	tipoElemento elemento;
	struct tipoCelda *sig;
} tipoCelda;
#endif

typedef struct
{
	tipoCelda *frente, *fondo;
} Cola;

Cola crearCola();															 // Crear una cola vacía: Esta función creará una cola vacía asignando el puntero a NULL.
int colaVacia(Cola *c);												 // Comprobar si la cola está vacía: Esta función devolverá 1 si la cola está vacía y 0 en caso contrario.
void insertar(tipoElemento elemento, Cola *c); // Insertar un elemento en la cola: Esta función insertará un elemento al final de la cola.
tipoElemento eliminar(Cola *c);								 // Eliminar el elemento de la cabeza de la cola: Esta función eliminará el elemento de la cabeza de la cola y lo devolverá.
tipoElemento cabeza(Cola *c);									 // Obtener el elemento de la cabeza de la cola : Esta función devolverá el elemento de la cabeza de la cola sin eliminarlo.

#endif
