#include "binary_trees.h"

/* Function prototypes */
static size_t tree_size(const binary_tree_t *tree);
static binary_tree_t *get_parent(binary_tree_t *root, size_t index);
static heap_t *heapify_up(heap_t *node);

/**
 * heap_insert - Inserts a value in a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	size_t size;
	heap_t *parent, *new_node;

	if (!root)
		return (NULL);

	/* If heap is empty */
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = tree_size(*root);

	/* Get parent for new node (next available position) */
	parent = get_parent(*root, size + 1);
	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if ((size + 1) % 2 == 0)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (heapify_up(new_node));
}

/**
 * tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Number of nodes
 */
static size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * get_parent - Gets parent node for insertion using index
 * @root: Pointer to root
 * @index: Index of node to insert (1-based indexing)
 *
 * Return: Pointer to parent node
 */

static binary_tree_t *get_parent(binary_tree_t *root, size_t index)
{
	size_t mask = 1;
	binary_tree_t *current = root;

	/* Find highest bit*/
	while (mask <= index)
		mask <<= 1;
	mask >>= 2;

	while (mask > 1)
	{
		if (index & mask)
			current = current->right;
		else
			current = current->left;

		mask >>= 1;
	}

	return (current);
}

/**
 * heapify_up - Restores Max-Heap property after insertion
 * @node: Pointer to inserted node
 *
 * Return: Pointer to biggest node
 */
static heap_t *heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
	return (node);
}
