#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

void binary_tree_print(const binary_tree_t *tree);

static int _height(const binary_tree_t *tree)
{
	int l, r;

	if (!tree)
		return (0);
	l = tree->left ? 1 + _height(tree->left) : 0;
	r = tree->right ? 1 + _height(tree->right) : 0;
	return (l > r ? l : r);
}

static int _pow(int base, int exp)
{
	int r = 1, i;

	for (i = 0; i < exp; i++)
		r *= base;
	return (r);
}

static void _fill(const binary_tree_t *tree, char **buf, int row, int col,
	int width, int height)
{
	int mid;
	char numstr[16];

	(void)height;
	if (!tree)
		return;
	mid = col + width / 2;
	sprintf(numstr, "(%03d)", tree->n);
	memcpy(&buf[row][mid - 2], numstr, strlen(numstr));

	if (tree->left)
	{
		int i, lmid = mid - width / 4 - 1;

		for (i = lmid + 1; i < mid - 2; i++)
			buf[row + 1][i] = '-';
		buf[row + 1][lmid] = '.';
		_fill(tree->left, buf, row + 2, col, width / 2, height);
	}
	if (tree->right)
	{
		int i, rmid = mid + width / 4 + 3;

		for (i = mid + 3; i < rmid; i++)
			buf[row + 1][i] = '-';
		buf[row + 1][rmid] = '.';
		_fill(tree->right, buf, row + 2, col + width / 2, width / 2, height);
	}
}

void binary_tree_print(const binary_tree_t *tree)
{
	int height, width, rows, cols, i;
	char **buf;

	if (!tree)
		return;
	height = _height(tree) + 1;
	rows = height * 2;
	width = _pow(2, height + 2);
	cols = width;

	buf = malloc(sizeof(char *) * rows);
	for (i = 0; i < rows; i++)
	{
		buf[i] = malloc(cols + 1);
		memset(buf[i], ' ', cols);
		buf[i][cols] = '\0';
	}
	_fill(tree, buf, 0, 0, width, height);
	for (i = 0; i < rows; i++)
	{
		int j, last = 0;

		for (j = 0; j < cols; j++)
			if (buf[i][j] != ' ')
				last = j;
		buf[i][last + 1] = '\0';
		if (buf[i][0] || last)
			printf("%s\n", buf[i]);
		free(buf[i]);
	}
	free(buf);
}
