int binarySearch(int *arr, int key, int low, int high)
{
	if (low >= high)
		return (key > arr[low]) ? (low + 1) : low;
	int mid = low + (high - 1) / 2;
	if (arr[mid] == key)
		return mid + 1;
	else if (arr[mid] > key)
		return binarySearch(arr, key, low, mid - 1);
	else
		return binarySearch(arr, key, mid + 1, high);
}
/*This is where the sorting of the array takes place
 arr[] --- Array to be sorted
 size --- Array Size
 */
void insertionSort(int *arr, int size)
{
	int i, j, key, index;
	for (i = 0; i < size; i++)
	{
		j = i - 1;
		key = arr[i];
		/* Use binrary search to find exact key's index */
		index = binarySearch(arr, key, 0, j);
		/* Move all elements greater than key from [index...j]
			 to one position */
		while (j >= index)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		/* Insert key value in right place */
		arr[j + 1] = key;
	}
}
