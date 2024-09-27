#include "slide_line.h"

/**
 * slide_line - Slides and merges a line of integers to the left or right
 * @line: Pointer to the array of integers to be slid and merged
 * @size: Number of elements in the array
 * @direction: Direction to slide and merge line (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i, cursor = 0;
	int temp_line[size];
	int last_merged = -1;

	/* Initialize temp_line to 0 */
	for (i = 0; i < size; i++)
		temp_line[i] = 0;

	/* Check direction and slide accordingly */
	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size; i++)
		{
			if (line[i] == 0)
				continue;

			if (last_merged != -1 && temp_line[last_merged] == line[i])
			{
				temp_line[last_merged] *= 2;
				last_merged = -1;
			}
			else
			{
				temp_line[cursor++] = line[i];
				last_merged = cursor - 1;
			}
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		cursor = size - 1;
		for (i = size; i-- > 0;)
		{
			if (line[i] == 0)
				continue;

			if (last_merged != -1 && temp_line[last_merged] == line[i])
			{
				temp_line[last_merged] *= 2;
				last_merged = -1;
			}
			else
			{
				temp_line[cursor--] = line[i];
				last_merged = cursor + 1;
			}
		}
	}
	else
		return (0);

	/* Copy temp_line back to the original line */
	for (i = 0; i < size; i++)
		line[i] = temp_line[i];

	return (1);
}
