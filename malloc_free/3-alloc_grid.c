#include <stdlib.h>
#include "main.h"

/**
 * alloc_grid - Allocates a two-dimensional array of integers
 * @width: Number of columns
 * @height: Number of rows
 *
 * Return: Pointer to the grid, or NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i;

	grid = calloc(height, sizeof(int));

	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
		grid[i] = calloc(width, sizeof(int));

	return (grid);
}
