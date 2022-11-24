/*
 * Este algoritmo compara uno a uno los elementos del arreglo hasta recorrerlo por completo indicando si el número buscado existe.
 * Retorna el indice donde el valor está localizado en el array

<> \param value valor que se desea buscar
<> \param[in] array array donde buscar
<> \param arraySize tamazo del array
<> \returns i posicion donde se encuentra el valor que se búsqueda
<> \returns -1 error, el valor que se busca no se encuentra en el array
*/
int linearSearch(int value, int *array, int arraySize)
{
	int i;
	for (i = 0; i < arraySize; i++)
	{
		if (array[i] == value)
			return i;
	}

	return -1;
}
