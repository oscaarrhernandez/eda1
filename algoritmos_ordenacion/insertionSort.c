void insertionSort(int *array, int arraySize)
{
	int i, j;
	typeof(array[0]) temp;

	for (i = 1; i <= arraySize - 1; i++)
	{
		temp = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > temp)
		{
			swap(array, j, j + 1);
			j--;
		}
		array[j + 1] = temp;
	}
}

void swap(int *array, int i, int j)
{
	typeof(array[0]) temp;
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
