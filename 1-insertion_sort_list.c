#include "sort.h"

void exchange(listint_t **, listint_t **, listint_t *);

/**
 * insertion_sort_list - sort a doubly linked list
 * @list: a reference pointer to the first node of the doubly
 * linked list
 *
 * Description: This function sorts a doubly linked list of integers
 * in ascending order using the insortion sort algorithm. The
 * insertion sort algorithm builds a sorted array one item at a time
 * by comparison.
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *node, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (ptr = (*list)->next; ptr != NULL; ptr = temp)
	{
		temp = ptr->next;
		node = ptr->prev;
		while (node != NULL && ptr->n < node->n)
		{
			exchange(list, &node, ptr);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * exchange - swap two values
 * @h: a reference to the head of the linked list
 * @n1: a reference to the first value
 * @n2: a reference to the second value
 *
 * Description: this function swaps the positions of two values
 * passed to it via its arguments. It actually works with the
 * copies of the values without changing the original values
 *
 * Return: void
 */

void exchange(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
