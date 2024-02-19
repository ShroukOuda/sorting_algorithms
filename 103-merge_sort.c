#include "sort.h"
/**
 * merge - check the code.
 * @array:---
 * @lb:---
 * @mid:---
 * @ub:---
 * Return: ---.
 */
void merge(int *array, size_t lb, size_t mid, size_t ub, size_t size)
{
	size_t i = lb;
	size_t j = ub;
	size_t k = lb;
	int *arr = malloc((ub + 1) * sizeof(int));

	while (i <= mid && j <= ub)
	{
		if (array[i] <= array[j])
		{
			arr[k] = array[i];
			i++;
		}
		else
		{
			arr[k] = array[j];
			j++;
		}
		k++;
	}
	if (i > mid)
	{
		while (j <= ub)
		{
			arr[k] = array[j];
			j++;
			k++;
		}
	}
	else
	{
		while (i <= mid)
		{
			arr[k] = array[i];
			i++;
			k++;
		}
	}
	for (k = lb; k <= ub; k++)
		array[k] = arr[k];
	printf("[Done]: ");
	print_array(array, size);
	free(arr);
}
/**
 * mergesort - check the code.
 * @array:---
 * @lb:---
 * @ub:---
 * Return:----.
 */
void mergesort(int *array, size_t lb, size_t ub, size_t size)
{
	if (lb < ub)
	{
		size_t mid = (lb + ub) / 2;

		mergesort(array, lb, mid, size);
		printf("[left]: ");
		print_array(array, mid);
		mergesort(array, mid + 1, ub, size);
		printf("[right]: ");
		print_array(array, size);
		merge(array, lb, mid, ub, size);
	}
}
/**
 * merge_sort - check the code.
 * @array:----
 * @size:----
 * Return: ----.
 */
void merge_sort(int *array, size_t size)
{
	mergesort(array, 0, size - 1, size);
}
