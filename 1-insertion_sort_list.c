#include "sort.h"
/**
 * insertion_sort_list - check the code.
 * @list: ------
 * Return: ----.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = *list, *min, *res;
	int x;

	if (*list == NULL)
		return;

	while (temp)
	{
		min = temp;
		res = temp->next;
		while (res)
		{
			print_list(*list);
			if (min->n > res->n)
			{
				min = res;
			}
			res = res->next;
		}
		x = temp->n;
		temp->n = min->n;
		min->n = x;
		temp = temp->next;
	}
}
