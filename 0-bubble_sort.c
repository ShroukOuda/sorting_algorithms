#include "sort.h"
/**
 * bubble_sort - check the code.
 * @array: ---
 * @size: ---
 * Return: ----.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, flag, temp;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
