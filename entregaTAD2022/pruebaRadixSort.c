/*

<> Oscar Hernandez Hernandez
<> https://github.com/oscaarrhernandez

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listas/lista.h"
#include "radixSort.h"

#define NUM 100000

int main(int argc, char *argv[])
{
	FILE *f = fopen("resultadoslista.txt", "a");
	if (f == NULL)
		return -3;

	double time_spent = 0.0;
	Lista miLista;
	tipoPosicion p;
	int numElementos = 20, codigoError, i;
	srand(time(NULL));

	if (argc > 2)
	{
		printf("\n Uso: ./pruebaRadixSort <número de elementos de la lista>\n\n");
		return -1;
	}
	if (argc == 2)
		numElementos = atoi(argv[1]);

	printf("Creando lista vacía: %d\n", creaVacia(&miLista));
	printf("Se crea una lista de %d elementos\n", numElementos);

	p = primero(&miLista);
	for (i = 0; i < numElementos; i++)
	{
		codigoError = inserta(rand() % NUM, p, &miLista);
		p = siguiente(p, &miLista);
	}

	imprime(&miLista);
	clock_t begin = clock();
	int interacciones = radixSort(&miLista, 10, 5);
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nLista Ordenada \n");
	imprime(&miLista);
	printf("\nTiempo usado para ordenar una lista de %d elementos = %f\n y el numero de interacciones realizadas es de %d\n", numElementos, time_spent, interacciones);
	fprintf(f, "\nTiempo usado para ordenar una lista de %d elementos = %f y el numero de interacciones realizadas es de %d\n\n", numElementos, time_spent, interacciones);

	fclose(f);
	anula(&miLista);

	destruye(&miLista);
	return 0;
}
