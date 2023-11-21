#include "sort.h"
/**
 * bubble_sort - sort an array with bubble sort
 * @array: array
 * @size: amount of array's elements
 */
void bubble_sort(int *array, size_t size)
{
	int next, prev, flag = 0;
	size_t cont, j, i;

	if (array == NULL || size <= 1)
		return;

	for (j = 0, cont = 0; j < size; j++)
	{
		if (j > 0 && (array[j] == array[j - 1]))
			cont += 1;
	}
	if (cont == size - 1)
		return;
	if (size > 1)
	{
		for (i = 0; flag == 0; i++)
		{
			if (i > 0)
			{
				if (array[i] < array[i - 1])
				{
					next = array[i];
					prev = array[i - 1];
					array[i] = prev;
					array[i - 1] = next;
					print_array(array, size);
				}
				for (j = 0, cont = 0; j < size; j++)
				{
					if (j > 0 && (array[j] > array[j - 1]))
						cont += 1;
				}
				if (cont == size - 1)
					flag = 1;
				if (cont != size - 1)
					flag = 0;
				if (i == size - 1)
					i = 0;
			}
		}
	}
}
