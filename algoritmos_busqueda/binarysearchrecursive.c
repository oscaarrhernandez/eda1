/*
! NECESITAS QUE EL ARRAY ESTÉ ORDENADO
* Divide el array en 2 partes obteniendo el elemento del medio y lo compara con el valor que se busca.
* Si el valor es menor que el elemento medio, repite el proceso con la parte izquierda del array donde los numeros son menores al elemento medio (si el valor fuera mas grande pues lo mismo pero con la parte derecha)

*/
int binaryRecursiveSearch(int value, int *array, int firstElement, int lastElement)
{
	if (firstElement > lastElement)
		return -1;

	else
	{
		int i = firstElement;
		int j = lastElement;
		int k = (i + j) / 2;
		if (value < array[k])
		{
			j = k - 1;
		}
		else if (value > array[k])
		{
			i = k + 1;
		}
		else if (value == array[k])
		{
			return k;
		}

		return binaryRecursiveSearch(value, array, i, j);
	}
}
