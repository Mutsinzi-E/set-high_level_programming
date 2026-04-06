#include <unistd.h>

/**
 * main - Entry point
 *
 * Description: prints "_putchar" using write
 *
 * Return: 0 on success
 */
int main(void)
{
    write(1, "_putchar\n", 9);
    return (0);
}
