#include <stdlib.h>
#include "binary_trees.h"

/**
 * build_avl - Recursively builds an AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the array to be converted
 * @start: Index of the first element of the current subarray
 * @end: Index of the last element of the current subarray
 * @parent: Pointer to the parent node of the current subtree
 *
 * Return: Pointer to the root node of the created subtree, or NULL on
 * failure
 */
static avl_t *build_avl(int *array, int start, int end, avl_t *parent)
{
	avl_t *node;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = array[mid];
	node->parent = parent;
	node->left = build_avl(array, start, mid - 1, node);
	node->right = build_avl(array, mid + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on
 * failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (build_avl(array, 0, (int)size - 1, NULL));
}
