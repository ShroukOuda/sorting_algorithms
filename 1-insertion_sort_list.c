#include "sort.h"
/**
 * insertion_sort_list - check the code.
 * @list: ------
 * Return: ----.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur = *list, *temp, *insert;

	if (*list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	cur = cur->next;
	while (cur)
	{
		insert = cur->prev;
		temp = cur;
		while (insert && insert->n > temp->n)
		{
			insert->next->n = insert->n;
			insert = insert->prev;
		}
		if (!insert)
			(*list)->n = cur->n;
		else
			insert->next->n = cur->n;
		cur = temp;
		print_list(*list);
	}
}
