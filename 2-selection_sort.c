#include "sort.h"

void exchange(int *x, int *y);

/**
 * selection_sort - Sort an array of integers
 * @array: An array of integers
 * @size: The size of the array
 *
 * Description: this function sorts the elements of an array
 * by selection sort method. It divides the input list into two parts
 * a sorted sublist of items which is built up from left to right at
 * the front (left) of the list and a sublist of the remaining
 * unsorted items that occupy the rest of the list. Initially, the
 * sorted sublist is empty and the unsorted sublist is the entire
 * input list. The algorithm proceeds by finding the smallest (or
 * largest, depending on sorting order) element in the unsorted
 * sublist, exchanging (swapping) it with the leftmost unsorted
 * element (putting it in sorted order), and moving the sublist
 * boundaries one element to the right.
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min)
				min = array + j;
		}

		if ((array + i) != min)
		{
			exchange(array + i, min);
			print_array(array, size);
		}
	}
}

/**
 * exchange - swap two values
 * @x: The first value
 * @y: The second value
 *
 * Description: this function exchanges the positions of two
 * integer values via a reference to the actual values
 *
 * Return: void
 */

void exchange(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
