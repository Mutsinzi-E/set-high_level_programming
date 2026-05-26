#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * check_loop - checks if node was already visited
 * @node: current node
 * @visited: array of visited nodes
 * @size: number of visited nodes
 *
 * Return: 1 if loop found, 0 otherwise
 */
int check_loop(const listint_t *node, const listint_t **visited, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (visited[i] == node)
			return (1);
	}
	return (0);
}

/**
 * print_listint_safe - prints a listint_t list safely
 * @head: pointer to head
 *
 * Return: number of nodes printed
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *visited[1024];
	size_t count = 0;
	size_t i = 0;

	while (head)
	{
		if (check_loop(head, visited, i))
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			return (count);
		}

		visited[i++] = head;

		printf("[%p] %d\n", (void *)head, head->n);
		count++;

		head = head->next;
	}

	return (count);
}
