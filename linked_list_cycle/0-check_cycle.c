#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle
 * @list: pointer to head of list
 *
 * Return: 0 if no cycle, 1 if cycle exists
 */
int check_cycle(listint_t *list)
{
    listint_t *slow;
    listint_t *fast;

    if (list == NULL)
        return (0);

    slow = list;
    fast = list;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return (1);
    }

    return (0);
}