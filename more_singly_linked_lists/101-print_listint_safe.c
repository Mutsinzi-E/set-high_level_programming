#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listp_s - linked list of pointers
 * @p: pointer to node
 * @next: points to next node
 */
typedef struct listp_s
{
	const void *p;
	struct listp_s *next;
} listp_t;

/**
 * free_listp - frees a listp_t list
 * @head: pointer to head
 */
void free_listp(listp_t *head)
{
	listp_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * add_nodep - adds new node address
 * @head: pointer to head
 * @p: pointer to save
 *
 * Return: address of new node or NULL
 */
listp_t *add_nodep(listp_t **head, const void *p)
{
	listp_t *new;

	new = malloc(sizeof(listp_t));
	if (!new)
		exit(98);

	new->p = p;
	new->next = *head;
	*head = new;

	return (new);
}

/**
 * print_listint_safe - prints a listint_t list safely
 * @head: pointer to list head
 *
 * Return: number of nodes printed
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	listp_t *visited = NULL;
	listp_t *check;

	while (head)
	{
		check = visited;

		while (check)
		{
			if (head == check->p)
			{
				printf("-> [%p] %d\n",
					(void *)head, head->n);
				free_listp(visited);
				return (count);
			}
			check = check->next;
		}

		add_nodep(&visited, head);

		printf("[%p] %d\n", (void *)head, head->n);
		count++;

		head = head->next;
	}

	free_listp(visited);

	return (count);
}
