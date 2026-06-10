#include <stdio.h>

/**
 * main - keygen for crackme5
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *u;
	unsigned int i = 0, sum = 0;
	char key[7];

	if (argc != 2)
	{
		printf("Usage: %s username\n", argv[0]);
		return (1);
	}

	u = argv[1];

	while (u[i])
	{
		sum += u[i] * (i + 1);
		i++;
	}

	for (i = 0; i < 6; i++)
		key[i] = 33 + ((sum * (i + 3)) % 94);

	key[6] = '\0';

	printf("%s\n", key);

	return (0);
}
