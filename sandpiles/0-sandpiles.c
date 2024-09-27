#include "sandpiles.h"

/**
 * is_stable - Checks if a sandpile is stable
 * @grid: 3x3 grid to check
 *
 * Return: 1 if stable, 0 if not stable
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * grid_toppler - Stabilizes a 3x3 sandpile by toppling cells
 * @grid: 3x3 grid to stabilize
 *
 * Description: Topple cells in a sandpile that have more than 3 grains.
 * Distribute the excess grains to the neighboring cells.
 */
void grid_toppler(int grid[3][3])
{
	int i, j;
	int temp_grid[3][3] = {0};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				temp_grid[i][j] -= 4;
				if (i + 1 < 3)
					temp_grid[i + 1][j]++;
				if (i - 1 >= 0)
					temp_grid[i - 1][j]++;
				if (j + 1 < 3)
					temp_grid[i][j + 1]++;
				if (j - 1 >= 0)
					temp_grid[i][j - 1]++;
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid[i][j] += temp_grid[i][j];
	}
}

/**
 * no_static_print_grid - Print a 3x3 grid
 * @grid: 3x3 grid to print
 *
 * Description: Prints the grid with space-separated values, row by row.
 */
void no_static_print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - Sum of two 3x3 sandpiles and stabilizes the result
 * @grid1: First 3x3 grid (result will be stored here)
 * @grid2: Second 3x3 grid to add to the first
 *
 * Description: Adds the two grids and stabilizes the result using toppling
 * operations until the grid is stable. Prints the grid after each toppling.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}

	while (!is_stable(grid1))
	{
		no_static_print_grid(grid1);
		grid_toppler(grid1);
	}
}
