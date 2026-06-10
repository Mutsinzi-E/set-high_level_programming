#include <stdio.h>
#include <string.h>

/**
 * main - keygen for crackme5
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
    char *username;
    int i, sum = 0;
    char key[7];

    if (argc != 2)
    {
        printf("Usage: %s username\n", argv[0]);
        return (1);
    }

    username = argv[1];

    for (i = 0; username[i]; i++)
        sum += (username[i] ^ (i + 1));

    for (i = 0; i < 6; i++)
        key[i] = 33 + ((sum * (i + 13)) % 94);

    key[6] = '\0';

    printf("%s\n", key);

    return (0);
}
