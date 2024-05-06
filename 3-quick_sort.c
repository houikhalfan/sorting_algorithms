#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - Sorts an arra
 * @array: The array
 * @size: Number
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive function
 * @array: array
 * @low: starting ind
 * @high: index
 * @size: Number
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    int pivot;
    if (low < high)
    {
        pivot = partition(array, low, high, size);

        quick_sort_recursive(array, low, pivot - 1, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * partition - Lomuto partition
 * @array: The array
 * @low: Starting
 * @high: Ending index
 * @size: Number
 *
 * Return: Index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            print_array(array, size);
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    print_array(array, size);
    return (i + 1);
}