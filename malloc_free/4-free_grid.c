#include <stdlib.h>
#include "main.h"

/**
 * free_grid - Frees a two-dimensional array of integers
 * @grid: Pointer to the grid
 * @height: Number of rows
 *
 * Return: Nothing
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}
