#include <stdlib.h>
#include "main.h"

/**
 * create_array - Creates an array filled with a specific character
 * @size: Number of elements in the array
 * @c: Character to fill the array with
 *
 * Return: Pointer to the array, or NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i;

	grid = malloc(sizeof(int) * height);

	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
		grid[i] = malloc(sizeof(int) * width);

	return (grid);
}
