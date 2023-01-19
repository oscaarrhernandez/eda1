/*

<> Oscar Hernandez Hernandez
<> https://github.com/oscaarrhernandez

*/
#ifndef __RADIXSORT_H
#define __RADIXSORT_H

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

int radixSort(Lista *l, tipoElemento nGrupos, tipoElemento nCifras);
tipoElemento obtenerCifra(tipoElemento num, tipoElemento n);

#endif
