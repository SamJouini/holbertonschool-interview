#include <stddef.h>
#include "lists.h"

/**
 * reverse_list - reverses a singly linked list
 * @head: pointer to head of list
 *
 * Return: pointer to new head
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev;
	listint_t *next;

	prev = NULL;

	while (head != NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	return (prev);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of list
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow;
	listint_t *fast;
	listint_t *second_half;
	listint_t *copy_second;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return (1);

	slow = *head;
	fast = *head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	if (fast != NULL)
		slow = slow->next;

	second_half = reverse_list(slow);
	copy_second = second_half;
	slow = *head;

	while (second_half != NULL)
	{
		if (slow->n != second_half->n)
		{
			reverse_list(copy_second);
			return (0);
		}

		slow = slow->next;
		second_half = second_half->next;
	}

	reverse_list(copy_second);

	return (1);
}