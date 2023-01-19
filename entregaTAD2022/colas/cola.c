/*

<> Oscar Hernandez Hernandez
<> https://github.com/oscaarrhernandez

*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"

Cola crearCola()
{
	Cola c;
	c.frente = NULL;
	c.fondo = NULL;
	return c;
}

int colaVacia(Cola *c)
{
	return c->frente == NULL;
}

void insertar(tipoElemento elemento, Cola *c)
{
	tipoCelda *nueva = (tipoCelda *)malloc(sizeof(tipoCelda));
	nueva->elemento = elemento;
	nueva->sig = NULL;
	if (colaVacia(c))
	{
		c->frente = nueva;
	}
	else
	{
		c->fondo->sig = nueva;
	}
	c->fondo = nueva;
}

tipoElemento eliminar(Cola *c)
{
	tipoCelda *aux = c->frente;
	tipoElemento elemento = aux->elemento;
	c->frente = aux->sig;
	free(aux);
	if (c->frente == NULL)
	{
		c->fondo = NULL;
	}
	return elemento;
}

tipoElemento cabeza(Cola *c)
{
	return c->frente->elemento;
}
