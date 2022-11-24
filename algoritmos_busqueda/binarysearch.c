int binarySearch(int value, int *array, int arraySize)
{
	int i = 0;
	int j = arraySize - 1;
	int k;
	while (i < j)
	{
		k = (i + j) / 2;
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
			i = k;
			j = k;
		}
	}

	if (value == array[i])
		return i;
	else
		return -1;
}
