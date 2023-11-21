#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm
 * @list: doubly linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL, *tmp = NULL;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	start = *list;
	end = NULL;

	do {
		swapped = 0;
		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				tmp = start->next;
				if (start->prev != NULL)
					start->prev->next = tmp;
				else
					*list = tmp;
				tmp->prev = start->prev;
				start->next = tmp->next;
				if (tmp->next != NULL)
					tmp->next->prev = start;
				start->prev = tmp;
				tmp->next = start;
				swapped = 1;
				print_list(*list);
			}
			else
				start = start->next;
		}
		end = start;
		while (end->prev != NULL)
		{
			if (end->n < end->prev->n)
			{
				tmp = end->prev;
				if (tmp->prev != NULL)
					tmp->prev->next = end;
				else
					*list = end;
				end->prev = tmp->prev;
				tmp->next = end->next;
				if (end->next != NULL)
					end->next->prev = tmp;
				end->next = tmp;
				tmp->prev = end;
				swapped = 1;
				print_list(*list);
			}
			else
				end = end->prev;
		}
		start = (*list)->next;
	} while (swapped);
}
