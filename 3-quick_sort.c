#include "sort.h"

void lomuto_sort(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_sort(array, 0, size - 1, size);
}

/**
 * lomuto_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm and Lomuto partition scheme
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 */
void lomuto_sort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = lomuto_partition(array, low, high, size);

        lomuto_sort(array, low, pi - 1, size);
        lomuto_sort(array, pi + 1, high, size);
    }
}

/**
 * lomuto_partition - partitions an array using Lomuto partition scheme
 * @array: array to partition
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 *
 * Return: final partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = (low - 1);
    int j, temp;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            if (i != j)
                print_array(array, size);
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    if (high != (i + 1))
        print_array(array, size);

    return (i + 1);
}
