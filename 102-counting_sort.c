#include "sort.h"
/**
 * counting_sort - Entry point
 * @array: ---
 * @size:---
 * Return: ----
 */
void counting_sort(int *array, size_t size)
{
	int i, max = array[0];
	int *count, *b;

	if (!array || size < 2)
		return;
	for (i = 0; i < (int)size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		++count[array[i]];
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	b = malloc(sizeof(int) * size);
	if (!b)
	{
		free(count);
		return;
	}
	for (i = (int)size - 1; i >= 0; i--)
		b[--count[array[i]]] = array[i];
	for (i = 0; i < (int)size; i++)
		array[i] = b[i];
	free(count);
	free(b);
}
