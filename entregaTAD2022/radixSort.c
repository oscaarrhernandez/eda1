#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listas/lista.h"
#include "radixSort.h"
/*
	Lista -> raiz
				-> ultimo

	tipoElemento -> int
	tipoPosicion -> *TipoCelda -> (*nodo)


	nGrupos: numero de grupos que queremos crear
	nCifras: numero maximo de cifras que tendrán los numeros a ordenar
*/

int radixSort(Lista *lista, tipoElemento nGrupos, tipoElemento nCifras)
{
	Lista ptGrupos[nGrupos];
	tipoElemento cifra, grupo, temp;
	tipoPosicion j, aux, pos;
	int contador = 0;
	for (grupo = 0; grupo < nGrupos; grupo++)
		creaVacia(&ptGrupos[grupo]);
	//*	La lista ptGrupos es el vector de grupos del radixsort normal
	//*	Los grupos son las 10 unidades: 0 1 2 3 4 5 6 7 8 9
	//* En cada elemento de ptGrupos creamos una lista vacia

	for (cifra = 0; cifra < nCifras; cifra++)
	{
		//* El primer for se mueve por las cifras: unidades, decenas, centenas...
		for (grupo = 0; grupo < nGrupos; grupo++)
		{
			//* Segundo for se mueve por los grupos, max nGrupos

			j = primero(&ptGrupos[grupo]);
			// j = null si no existe la lista o está vacia
			//		sino devuelve el primer elemento de la lista del grupo
			aux = lista->raiz;
			// aux = lista_desordenada->raiz
			while (aux->sig != NULL)
			{
				//* Recorrer lista
				contador++;
				temp = recupera(aux, lista);
				// temp = -1 si la lista no existe, está vacia o aux es NULL
				// 			= -2 si es la ultima posición
				// 			= valor del elemento guardado en el nodo aux
				temp = obtenerCifra(temp, cifra);
				// temp = valor de la unidad, decena, centena...
				if (temp == grupo)
					//* Si temp equivale al grupo que estamos estudiando lo traspasamos
					traspasarNodo(aux, lista, j, &ptGrupos[grupo]);
				// pasamos el nodo de la lista_desordenada a la lista del grupo
				else
					//* Si no pasamos al siguiente elemento de la lista_desordenada
					aux = aux->sig;
			}
		}
		for (grupo = 0; grupo < nGrupos; grupo++)
			concatenarListas(lista, &ptGrupos[grupo]);
	}
	return contador;
}

tipoElemento obtenerCifra(tipoElemento num, tipoElemento n)
{
	tipoElemento r;
	/*
		dividimos el numero entre 10 elevado a la cifra que estamos estudiando:
		Ejemplo centena: num=36835 n=2 -> r =  36835 / (10^2) = 368
										 r % 10 -> 368 / 10 y quedarse con el resto = 8
	*/
	r = num / pow(10, n);
	r = r % 10;
	return r;
}
