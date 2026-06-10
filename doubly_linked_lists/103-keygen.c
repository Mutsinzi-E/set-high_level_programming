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
    unsigned long int hash = 5381;
    int i;
    char key[7];

    if (argc != 2)
    {
        printf("Usage: %s username\n", argv[0]);
        return (1);
    }

    username = argv[1];

    for (i = 0; username[i]; i++)
        hash = ((hash << 5) + hash) + username[i];

    for (i = 0; i < 6; i++)
        key[i] = 33 + ((hash >> (i * 5)) % 94);

    key[6] = '\0';

    printf("%s\n", key);

    return (0);
}
