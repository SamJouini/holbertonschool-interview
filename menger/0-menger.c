#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "menger.h"

/**
 * is_hash - check if the character to print should be an hash or not
 *
 * @size: size of the current sponge
 * @i: row index
 * @j: column index
 *
 * Return: 1 if the character to print is an hash or 0 is it's a space
 */
int is_hash(int size, int i, int j)
{
	int third = 0;
	int row_block = 0;
	int col_block = 0;
	int local_i = 0;
	int local_j = 0;

	if (size == 1)
	{
		return (1);
	}

	third = size / 3;
	/*Identify which "block" we are in */
	row_block = i / third;
	col_block = j / third;

	/*If we are in the center block, it's empty */
	if (row_block == 1 && col_block == 1)
	{
		return (0);
	}
	/* Calculate local coordinates explicitly */
	local_i = i - (row_block * third);
	local_j = j - (col_block * third);

	/* Recurse with the new smaller size and local coordinates */
	return (is_hash(third, local_i, local_j));
}

/**
 * print_sponge - print sponge
 *
 * @size: size of the sponge to print
 */

void print_sponge(int size)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (is_hash(size, i, j) == 1)
			{
				printf("%c", '#');
			}
			else
			{
				printf("%c", ' ');
			}
		}
		printf("\n");
	}
}

/**
 * menger - draws a 2D Menger Sponge
 *
 * @level: level of the menger sponge to draw
 */
void menger(int level)
{
	int size = 0;

	if (level < 0)
	{
		return;
	}

	size = pow(3, level);

	if (level == 0)
	{
		printf("%c\n", '#');
		return;
	}
	else
	{
		print_sponge(size);
	}
}
