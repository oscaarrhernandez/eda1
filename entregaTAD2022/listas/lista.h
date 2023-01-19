/*

<> Oscar Hernandez Hernandez
<> https://github.com/oscaarrhernandez

*/
#ifndef __LISTA_H
#define __LISTA_H

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

#ifndef __TIPO_LISTA
#define __TIPO_LISTA
typedef struct
{
	tipoCelda *raiz, *ultimo;
} Lista;
#endif

#ifndef __TIPO_POSICION
#define __TIPO_POSICION
typedef tipoCelda *tipoPosicion;
#endif

int creaVacia(Lista *l);
int anula(Lista *l);
int vacia(Lista *l);

int inserta(tipoElemento x, tipoPosicion p, Lista *l);
int suprime(tipoPosicion p, Lista *l);
tipoPosicion localiza(tipoElemento x, Lista *l);
tipoElemento recupera(tipoPosicion p, Lista *l);

tipoPosicion primero(Lista *l);
tipoPosicion siguiente(tipoPosicion p, Lista *l);
tipoPosicion anterior(tipoPosicion p, Lista *l);
tipoPosicion fin(Lista *l);

void imprime(Lista *l);
int destruye(Lista *l);
int traspasarNodo(tipoPosicion p, Lista *lA, tipoPosicion q, Lista *lB);
int concatenarListas(Lista *lA, Lista *lB);

#endif
/*
int traspasarNodo(tipoPosicion p, Lista *lA , Lista *lB, tipoPosicion q) {
	 Verifica si las posiciones p y q son válidas
	if (p == NULL || q == NULL) return -1;

	 Quita el nodo de la lista A
	if (p == lA->raiz) {
		lA->raiz = p->sig;
	} else {
		tipoPosicion prev = lA->raiz;
		while (prev->sig != p) prev = prev->sig;
		prev->sig = p->sig;
	}
	if (p == lA->ultimo) lA->ultimo = prev;

	 Añade el nodo a la lista B
	if (q == lB->ultimo) {
		q->sig = p;
		lB->ultimo = p;
	} else {
		p->sig = q->sig;
		q->sig = p;
	}

	return 0;
}
Esta función verifica si las posiciones p y q son válidas (no son NULL). Luego, quita el nodo de la lista A y lo añade a la lista B. Si la posición q es el último elemento de la lista B, entonces el nodo se añade al final de la lista. De lo contrario, el nodo se añade en la posición q.
*/

/*
void concatenate_lists(Lista *lA, Lista *lB) {
	if (lA->ultimo != NULL) {
		lA->ultimo->sig = lB->raiz;
		lA->ultimo = lB->ultimo;
	} else {
		lA->raiz = lB->raiz;
		lA->ultimo = lB->ultimo;
	}
}
Esta función concatena la lista lB a la lista lA, colocando todos los elementos de lB después de los elementos de lA. Si la lista lA es vacía, entonces la lista lB se convierte en la lista lA.
*/
