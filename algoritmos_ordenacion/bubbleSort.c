void bubbleSort(int *array, int arraySize)
{
	int i, j;

	for (i = 0; i <= arraySize - 2; i++)
	{
		for (j = arraySize - 2; j >= i; j--)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j, j + 1);
			}
		}
	}
}

void swap(int *array, int i, int j)
{
	typeof(array[0]) temp;
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
