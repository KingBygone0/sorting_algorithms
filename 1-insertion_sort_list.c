#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list with insertion sort
 * @list: double pointer to the head of the list
 **/
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current, *prev, *temp;
	current = (*list)->next;

	while (current != NULL)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			temp = current->prev;
			current->prev = temp->prev;
			temp->next = current->next;
			current->next = temp;

			if (temp->prev != NULL)
				temp->prev->next = current;
			else
				*list = current;
			if (temp->next != NULL)
				temp->next->prev = temp;
			print_list(*list);
			current = temp;
		}
		current = current->next;
	}
}
