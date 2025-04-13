#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Double pointer to head of list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *insert, *swap;

	if (!list || !*list || !(*list)->next)
		return;

	node = (*list)->next;
	while (node)
	{
		insert = node->prev;
		swap = node;
		node = node->next;

		while (insert && swap->n < insert->n)
		{
			insert->next = swap->next;
			if (swap->next)
				swap->next->prev = insert;

			swap->prev = insert->prev;
			swap->next = insert;

			if (insert->prev)
				insert->prev->next = swap;
			else
				*list = swap;

			insert->prev = swap;
			insert = swap->prev;

			print_list(*list);
		}
	}
}

