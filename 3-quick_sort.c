#include "sort.h"
/**
 * partition - check the code.
 * @lb:----
 * @ub:---
 * @array:---
 * @size:----
 * Return: ---.
 */
size_t partition(int *array, size_t lb, size_t ub, size_t size)
{
	int pivot = array[ub], temp;
	size_t i = lb - 1, j;

	for (j = lb; j < ub; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	temp = array[ub];
	array[ub] = array[i + 1];
	array[i + 1] = temp;
	print_array(array, size);
	return (i + 1);
}
/**
 * Quick - check the code.
 * @lb:---
 * @ub:---
 * @array:---
 * @size:----
 * Return: -----.
 */
void Quick(int *array, size_t lb, size_t ub, size_t size)
{
	if (lb < ub)
	{
		size_t loc = partition(array, lb, ub, size);

		if (loc > 0)
			Quick(array, lb, loc - 1, size);
		if (loc < size - 1)
			Quick(array, loc + 1, ub, size);
	}
}
/**
 * quick_sort - check the code.
 * @array:---
 * @size:----
 * Return:---.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	Quick(array, 0, size - 1, size);
}
