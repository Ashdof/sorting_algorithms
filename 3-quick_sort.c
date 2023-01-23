#include "sort.h"

void exchange(int *x, int *y);

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

