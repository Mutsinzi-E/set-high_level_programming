#include "lists.h"

/**
 * sum_listint - returns the sum of all n values in a listint_t list
 * @head: pointer to the head of the list
 *
 * Return: sum of all node data, or 0 if list is empty
 */
int sum_listint(listint_t *head)
{
    int sum = 0;
    listint_t *current = head;

    while (current != NULL)
    {
        sum += current->n;
        current = current->next;
    }

    return (sum);
}
