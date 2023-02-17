#include "sort.h"

/**
 * bubble_sort - A function that implements the bubble sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * Returns: Nothing (since it is a pointer the array will be changed in memory
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int change;
	int end_algorithm = 1;

	while (end_algorithm > 0)
	{
		end_algorithm = 0;
		for (i = 0; i < size - 1; i++)
		{
			/* 'i < size - 1' because we won't use the last index */
			if (array[i] > array[i + 1])
			{
				change = array[i + 1];
				array[i + 1] = array[i];
				array[i] = change;
				end_algorithm++;
				print_array(array, size);
			}
		}
	}
}
