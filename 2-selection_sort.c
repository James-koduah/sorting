#include "sort.h"


/**
 * selection_sort - Sorting algorithm
 * @array: array to be sortde
 * @size: size of array to be sorted
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min, hold;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i; j < size; j++)
		{
			if (array[min] > array[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			hold = array[i];
			array[i] = array[min];
			array[min] = hold;
			print_array(array, size);
		}
	}

}
