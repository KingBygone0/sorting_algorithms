#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, m_idx;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		m_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[m_idx])
				m_idx = j;
		}
		if (m_idx != i)
		{
			temp = array[i];
			array[i] = array[m_idx];
			array[m_idx] = temp;
			print_array(array, size);
		}
	}
}
