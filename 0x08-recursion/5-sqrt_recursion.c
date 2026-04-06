#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: input number
 *
 * Return: natural square root of n
 *         -1 if n does not have a natural square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_sqrt_helper(n, 0));
}

/**
 * _sqrt_helper - helps to find the square root recursively
 * @n: number
 * @i: current guess
 *
 * Return: square root or -1
 */
int _sqrt_helper(int n, int i)
{
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);
	return (_sqrt_helper(n, i + 1));
}
