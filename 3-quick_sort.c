#include "sort.h"

/**
 * partition - compute partition
 * @data: array to sort
 * @left: lowest index of the partition to sort
 * @right: highest index of the partition to sort
 * @size: size of the array
 *
 * Description: computes for the partition for quicksort
 * operation
 *
 * Return: index of the partition
 */
size_t partition(int *data, ssize_t left, ssize_t right, size_t size)
{
	ssize_t i, j;
	int temp, pivot;

	pivot = data[right];
	i = left - 1;
	for (j = left; j < right; j++)
	{
		if (data[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
				print_array(data, size);
			}
		}
	}
	if (data[right] < data[i + 1])
	{
		temp = data[i + 1];
		data[i + 1] = data[right];
		data[right] = temp;
		print_array(data, size);
	}
	return (i + 1);
}

/**
 * quicksort - sorts a partition of data
 * @array: array to sort
 * @lo: lowest index of the partition to sort
 * @hi: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: void
 */
void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quicksort(array, lo, pivot - 1, size);
		quicksort(array, pivot + 1, hi, size);

	}
}

/**
 * quick_sort - sorts an data in ascending order using the
 * Quick sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
