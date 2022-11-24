int ternary_search(int *array, int left, int right, int value)
{
	if (right >= left)
	{
		int mid1 = left + (right - left) / 3;
		int mid2 = right - (right - left) / 3;
		if (array[mid1] == value)
			return mid1;
		if (array[mid2] == value)
			return mid2;
		if (value < array[mid1])
			return ternary_search(array, left, mid1 - 1, value);
		else if (value > array[mid2])
			return ternary_search(array, mid2 + 1, right, value);
		else
			return ternary_search(array, mid1 + 1, mid2 - 1, value);
	}
	return -1;
}
