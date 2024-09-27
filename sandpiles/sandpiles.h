#ifndef _SANDPILES_H_
#define _SANDPILES_H_

#include <stdio.h>
#include <stdlib.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int is_stable(int grid[3][3]);
void grid_toppler(int grid[3][3]);
void no_static_print_grid(int grid[3][3]);

#endif
