#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to head
 *
 * Return: number of nodes printed
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t count = 0;
    const listint_t *current, *check;

    current = head;

    while (current != NULL)
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
