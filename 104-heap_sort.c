#include "sort.h"
/**
 * heapify - check the code.
 * @array:---
 * @size:---
 * @n:---
 * @i:---
 * Return: ----.
 */
void heapify(int *array, size_t size, size_t n, size_t i)
{
	size_t p = i;
	size_t l = (2 * i) + 1;
	size_t r = (2 * i) + 2;

	while (l < n && array[l] > array[p])
		p = l;
	while (r < n && array[r] > array[p])
		p = r;
	if (p != i)
	{
		_swap(&array[p], &array[i]);
		print_array(array, size);
		heapify(array, size, n, p);
	}
}
/**
 * heap_sort - check the code.
 * @array:---
 * @size:----
 * Return: ----.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;
	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);
	for (i = size - 1; i > 0; i--)
	{
		_swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
