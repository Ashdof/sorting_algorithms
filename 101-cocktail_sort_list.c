#include "sort.h"

/**
 * exchange - exchange the positions of two nodes
 * @list: a reference pointer to the beginning of the list
 * @node: node to exchange
 *
 * Description: this function exchanges the positions of two nodes
 *
 * Return: void
 */

void exchange(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;

	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;

	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - sorts a doubly linked list
 * order using the Cocktail shaker sort algorithm
 * @list: a reference pointer to the head of the doubly linked list
 *
 * Description: this function sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm. It
 * invokes the exchange function to swap two nodes
 *
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	char swapped = 1;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;
	temp = *list;
	while (swapped != 0)
	{
		swapped = 0;
		while (temp->next != NULL)
		{
			if (temp->next->n < temp->n)
			{
				exchange(list, temp);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				exchange(list, temp->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
	}
}
