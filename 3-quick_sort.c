#include "sort.h"


void quick_sort_recursion(int *array, int low, int high, int size);
int partition(int *array, int low, int high, int size);
void swap(int *x, int *y, int *array, int size);
/**
 * quick_sort - An implementation of the quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursion(array, 0, size - 1, (int) size);
}


/**
 * quick_sort_recursion - The function to implement the recursion
 * @array: array to be sorted
 * @low: lowest point of the partition
 * @high: high point of the partition
 * @size: size of the array
 * Return: Nothing
 */
void quick_sort_recursion(int *array, int low, int high, int size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_recursion(array, low, pivot - 1, size);
		quick_sort_recursion(array, pivot + 1, high, size);
	}
}

/**
 * partition - An implementation of the lomuto patition
 * @array: array to be sorted
 * @low: lowest point of the partition
 * @high: high point of the partition
 * @size: size of the array
 * Return: The new index of the pivot
 */
int partition(int *array, int low, int high, int size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[j], &array[i], array, size);
		}
	}
	swap(&array[i + 1], &array[high], array, size);
	return (i + 1);
}


/**
 * swap - Function to swap the value at two positions in an array
 * @x: A value to be swaped
 * @y: A value to be swaped
 * @array: array to be sorted
 * @size: size of the array
 * Note the reason the array and size are here is because we are
 * supposed to print the array after any value is swapped
 * Return: Nothing
 */
void swap(int *x, int *y, int *array, int size)
{
	int b = *x;
	*x = *y;
	*y = b;
	if (*x != *y)
		print_array(array, (size_t) size);
}
