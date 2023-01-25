#include "sort.h"

/**
 * shell_sort - sorts an array of integers
 * @array: array to sort
 * @size: size of the array to sort
 *
 * Description: this function sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 *
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j = j - gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
