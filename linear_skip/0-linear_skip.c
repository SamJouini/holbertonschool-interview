#include <stdio.h>
#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express, *start, *last;

	if (list == NULL)
		return (NULL);
	express = list->express;
	start = list;
	while (express != NULL && express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
		start = express;
		express = express->express;
	}
	if (express != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
		       start->index, express->index);
		last = express;
	}
	else
	{
		last = start;
		while (last->next != NULL)
			last = last->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
		       start->index, last->index);
	}
	while (start != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n", start->index, start->n);
		if (start->n == value)
			return (start);
		if (start == last)
			break;
		start = start->next;
	}
	return (NULL);
}
