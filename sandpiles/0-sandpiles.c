#include "sandpiles.h"


/**
 * 
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
 * 
 */
void grid_toppler(int grid[3][3])
{
  int i, j;

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      if (grid[i][j] > 3)
      {
        grid[i][j] -= 4;
        if (i + 1 < 3)
					grid[i + 1][j]++;
				if (i - 1 >= 0)
					grid[i - 1][j]++;
				if (j + 1 < 3)
					grid[i][j + 1]++;
				if (j - 1 >= 0)
					grid[i][j - 1]++;
      }
    }
  }
}


/**
 * no_static_print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
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
 * 
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
