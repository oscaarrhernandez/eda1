/*

<> Oscar Hernandez Hernandez
<> https://github.com/oscaarrhernandez

*/
#ifndef __PILA_H
#define __PILA_H

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

typedef tipoCelda *Pila;

int pilaCreaVacia(Pila *p);
int pilaVacia(Pila *p);
int pilaInserta(Pila *p, tipoElemento elemento);
tipoElemento pilaSuprime(Pila *p);

#endif
/*
Crear una pila vacía: Esta función creará una pila vacía asignando el puntero a NULL.

Pila crearPila() {
	return NULL;
}
Comprobar si la pila está vacía: Esta función devolverá 1 si la pila está vacía y 0 en caso contrario.

int pilaVacia(Pila p) {
	return p == NULL;
}
Insertar un elemento en la pila: Esta función insertará un elemento en la cima de la pila.

Pila push(tipoElemento elemento, Pila p) {
	tipoCelda *nueva = (tipoCelda *) malloc(sizeof(tipoCelda));
	nueva->elemento = elemento;
	nueva->sig = p;
	return nueva;
}
Eliminar el elemento de la cima de la pila: Esta función eliminará el elemento de la cima de la pila y lo devolverá.

tipoElemento pop(Pila *p) {
	tipoCelda *aux = *p;
	tipoElemento elemento = aux->elemento;
	*p = aux->sig;
	free(aux);
	return elemento;
}
Obtener el elemento de la cima de la pila: Esta función devolverá el elemento de la cima de la pila sin eliminarlo.

tipoElemento cima(Pila p) {
	return p->elemento;
}

*/
