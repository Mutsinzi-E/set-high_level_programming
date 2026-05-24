#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - prints list safely (handles loops)
 * @head: pointer to head
 *
 * Return: number of nodes printed
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *current, *check;
    size_t count = 0;

    current = head;

    while (current)
    {
        check = head;

        while (check != current)
        {
            if (check == current->next)
            {
                printf("-> [%p] %d\n", (void *)current->next,
                       current->next->n);
                return (count);
            }
            check = check->next;
        }

        printf("[%p] %d\n", (void *)current, current->n);
        count++;
        current = current->next;
    }

    return (count);
}
