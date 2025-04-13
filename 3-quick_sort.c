#include "sort.h"
#include <stdlib.h>

/**
 * swap_values - Swaps two values in an array and prints the array
 * @array: The array of integers
 * @i: Index of the first value
 * @j: Index of the second value
 * @size: Total number of elements in the array
 */
void swap_values(int *array, int i, int j, size_t size)
{
	int temp;

	if (array[i] != array[j])
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Partitions the array using the Lomuto scheme
 * @array: The array to partition
 * @low: The starting index of the segment
 * @high: The ending index (pivot) of the segment
 * @size: The total number of elements in the array
 * Return: The final pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap_values(array, i, j, size);
			i++;
		}
	}
	swap_values(array, i, high, size);
	return (i);
}

/**
 * recursive_quick_sort - Recursively applies Quick Sort
 * @array: The array of integers
 * @low: The starting index of the current segment
 * @high: The ending index of the current segment
 * @size: The total number of elements in the array
 */
void recursive_quick_sort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);

		recursive_quick_sort(array, low, pivot_index - 1, size);
		recursive_quick_sort(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Initializes the Quick Sort algorithm
 * @array: The array of integers to be sorted
 * @size: The number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recursive_quick_sort(array, 0, size - 1, size);
}

