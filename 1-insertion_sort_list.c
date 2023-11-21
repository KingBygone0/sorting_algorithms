#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node;
	
	if (list == NULL || *list == NULL)
		return;
	
	current = (*list)->next;
	while (current != NULL)
	{
		next_node = current->next;
		while (current->prev != NULL && current->prev->n > current->n)
		{
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;
			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;
			print_list(*list);
		}
		current = next_node;
	}
}
