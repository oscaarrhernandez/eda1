void selectionSort(int *array, int arraySize)
{
	int i, j;
	int posSelection;
	typeof(array[0]) valueSelection;

	for (i = 0; i <= arraySize - 2; i++)
	{
		posSelection = i;

		for (j = i + 1; j <= arraySize - 1; j++)
		{
			if (array[j] < array[posSelection])
			{
				posSelection = j;
			}
		}

		swap(array, posSelection, i);
	}
}

void swap(int *array, int i, int j)
{
	typeof(array[0]) temp;
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
