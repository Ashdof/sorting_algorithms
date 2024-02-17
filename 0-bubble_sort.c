#include "sort.h"

void exchange(int *, int *);

/**
 * bubble_sort - a bubble sort function
 * @array: a reference to the array object
 * @size: the size of the array object
 *
 * Description: this function sorts an array of elements by
 * swapping the positions of the smaller values with the larger
 * values. It repeatedly steps through the input list element by
 * element, comparing the current element with the one after it,
 * swapping their values if needed. Hence it's name bubble as the
 * largest elements bubble to the surface.
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool exchanged;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		exchanged = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				exchange(&array[j], &array[j + 1]);
				exchanged = true;
				print_array(array, size);
			}
		}

		if (exchanged == false)
			break;
	}
}

/**
 * exchange - swap two values
 * @x: a reference to the first value
 * @y: a reference to the second value
 *
 * Description: this function swaps the positions of two values
 * passed to it via its arguments. It actually works with the
 * copies of the values without changing the original values
 *
 * Return: void
 */

void exchange(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
