/*

<> Oscar Hernandez Hernandez
<> https://github.com/oscaarrhernandez

*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int creaVacia(Lista *l)
{
	if (l == NULL)
		return -2;
	else if (NULL == (l->raiz = l->ultimo = (tipoCelda *)malloc(sizeof(tipoCelda))))
		return -1;
	else
	{
		l->raiz->sig = NULL;
		return 0;
	}
}

int anula(Lista *l)
{
	tipoPosicion aux = l->raiz->sig, aBorrar;
	l->raiz->sig = NULL;

	if (l == NULL || l->raiz == NULL)
		return -1;
	else
	{
		while (aux != NULL)
		{
			aBorrar = aux;
			aux = aux->sig;
			free(aBorrar);
		}
		return 0;
	}
}

int vacia(Lista *l)
{
	if (l == NULL || l->raiz == NULL)
		return -1;
	else if (l->raiz->sig == NULL)
		return 1;
	else
		return 0;
}

int inserta(tipoElemento x, tipoPosicion p, Lista *l)
{
	tipoCelda *temp;

	if (l == NULL || l->raiz == NULL || p == NULL)
		return -1;
	else
	{
		if ((temp = (tipoCelda *)malloc(sizeof(tipoCelda))) == NULL)
			return -2;
		temp->elemento = x;
		temp->sig = p->sig;
		p->sig = temp;
	}
	return 0;
}

int suprime(tipoPosicion p, Lista *l)
{
	tipoCelda *aBorrar;

	if (l == NULL || l->raiz == NULL || p == NULL)
		return -1;
	else
	{
		aBorrar = p->sig;
		p->sig = aBorrar->sig;
		free(aBorrar);

		if (p->sig == NULL)
			l->ultimo = p;
	}
	return 0;
}

tipoPosicion localiza(tipoElemento x, Lista *l)
{
	tipoPosicion aux = l->raiz;

	if (l == NULL || l->raiz == NULL)
		return NULL;
	else
	{
		while (aux->sig != NULL)
		{
			if (aux->sig->elemento == x)
				return aux;
			aux = aux->sig;
		}
		return aux;
	}
}

tipoElemento recupera(tipoPosicion p, Lista *l)
{
	if (l == NULL || l->raiz == NULL || p == NULL)
		return -1;
	else if (p == fin(l))
		return -2;
	else
		return p->sig->elemento;
}

tipoPosicion primero(Lista *l)
{
	if (l == NULL || l->raiz == NULL)
		return NULL;
	else
		return l->raiz;
}

tipoPosicion siguiente(tipoPosicion p, Lista *l)
{
	if (l == NULL || l->raiz == NULL || p == NULL)
		return NULL;
	else if (p == fin(l))
		return l->ultimo;
	else
		return p->sig;
}

tipoPosicion anterior(tipoPosicion p, Lista *l)
{
	tipoCelda *anterior;

	if (l == NULL || l->raiz == NULL || p == NULL)
		return NULL;
	else if (p == l->raiz)
		return l->raiz;
	else
	{
		anterior = l->raiz;
		while (anterior->sig != p)
			anterior = anterior->sig;
		return anterior;
	}
}

tipoPosicion fin(Lista *l)
{
	tipoPosicion aux = l->raiz;

	if (l == NULL || l->raiz == NULL)
		return NULL;
	else
	{
		while (aux->sig != NULL)
			aux = aux->sig;
		return aux;
	}
}
void imprime(Lista *l)
{
	tipoCelda *aImprimir;
	if (l == NULL || l->raiz == NULL)
		return;
	else
	{
		int posicion = 1;
		aImprimir = l->raiz->sig;
		while (aImprimir != NULL)
		{
			printf("Valor: %5d en posicion: %8d\n", aImprimir->elemento, posicion++);
			aImprimir = aImprimir->sig;
		}
		printf("\n%d valores en la lista\n", posicion - 1);
	}
}

int destruye(Lista *l)
{
	if (l == NULL || l->raiz == NULL)
		return -1;
	else if (l->raiz->sig != NULL)
		return -2;
	else
	{
		free(l->raiz);
		l->raiz = l->ultimo = NULL;
		return 0;
	}
}

int traspasarNodo(tipoPosicion p, Lista *lA, tipoPosicion q, Lista *lB)
{
	tipoElemento elemento;
	tipoPosicion qAux;

	if (lA == NULL || lA->raiz == NULL || lB == NULL || lB->raiz == NULL)
		return -1;
	else
	{
		elemento = recupera(p, lA);

		qAux = fin(lB);
		inserta(elemento, qAux, lB);

		suprime(p, lA);
	}
	return 0;
}

int concatenarListas(Lista *lA, Lista *lB)
{
	if (lA == NULL || lA->raiz == NULL || lB == NULL || lB->raiz == NULL)
		return -1;
	else
	{
		while (!vacia(lB))
		{
			inserta(lB->raiz->sig->elemento, fin(lA), lA);
			suprime(lB->raiz, lB);
		}
	}
	return 0;
}

/*int concatenarListas(Lista *lA, Lista *lB)
{
	if (lA == NULL || lA->raiz == NULL || lB == NULL || lB->raiz == NULL)
		return -1;
	while (lB->raiz->sig != NULL)
	{
		tipoCelda *aux = (tipoCelda *)malloc(sizeof(tipoCelda)), *aBorrar = (tipoCelda *)malloc(sizeof(tipoCelda));
		if (aux == NULL || aBorrar == NULL)
			return -2;
		aux->elemento = lB->raiz->sig->elemento;
		aux->sig = lA->ultimo->sig;
		lA->ultimo->sig = aux;
		aBorrar = lB->raiz->sig;
		lB->raiz->sig = aBorrar->sig;
		free(aBorrar);
		if (lB->raiz->sig == NULL)
			lB->ultimo = lB->raiz;
	}
}
*/
