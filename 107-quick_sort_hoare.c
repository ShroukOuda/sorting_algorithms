#include "sort.h"
/**
 * swap - check the code.
 * @a:--
 * @b:---
 * Return:--.
 */
void _swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * partition - check the code.
 * @array:---
 * @lb:---
 * @ub:----
 * Return: ---.
 */
size_t partition(int *array, size_t lb, size_t ub)
{
    int pivot = array[ub];
    size_t start = lb;
    size_t end = ub;
    while (start < end)
    {
        while (array[start] < pivot)
        start++;
        while (array[end] >= pivot)
        end--;
        if (start < end)
        _swap(&array[start], &array[end]);
    }
    _swap(&array[ub], &array[start]);
    return (start);
}
/**
 * quick - check the code.
 * @array:---
 * @ub:----
 * @lb:---
 * @size:---
 * Return: ----.
 */
void quick(int *array, size_t lb, size_t ub, size_t size)
{
    if (lb < ub)
    {
        size_t loc = partition(array, lb, ub);
        print_array(array, size);
	if (loc > 0)
		quick(array, lb, loc - 1, size);
	if (loc < size - 1)
		quick(array, loc + 1, ub, size);
    }
}
/**
 * quick_sort_hoare - check the code.
 * @array:--
 * @size:---
 * Return: ---.
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (!array || size < 2)
    return;
    quick(array, 0, size - 1, size);
}
