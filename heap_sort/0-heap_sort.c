#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers and prints the array
 * @array: The array
 * @size: Full size of the array (for printing)
 * @a: Index of the first element
 * @b: Index of the second element
 */
static void swap(int *array, size_t size, size_t a, size_t b)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
	print_array(array, size);
}

/**
 * sift_down - Restores the max-heap property from a given root downward
 * @array: The array
 * @size: Full size of the array (for printing)
 * @heap_size: Current size of the heap
 * @root: Index to start sifting down from
 */
static void sift_down(int *array, size_t size, size_t heap_size, size_t root)
{
	size_t largest, left, right;

	while (1)
	{
		largest = root;
		left = 2 * root + 1;
		right = 2 * root + 2;

		if (left < heap_size && array[left] > array[largest])
			largest = left;
		if (right < heap_size && array[right] > array[largest])
			largest = right;
		if (largest == root)
			return;

		swap(array, size, root, largest);
		root = largest;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the sift-down heap sort algorithm
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (!array || size < 2)
		return;

	/* Build the max heap */
	for (i = size / 2; i > 0; i--)
		sift_down(array, size, size, i - 1);

	/* Move the max to the end, then re-heapify the rest */
	for (i = size - 1; i > 0; i--)
	{
		swap(array, size, 0, i);
		sift_down(array, size, i, 0);
	}
}
