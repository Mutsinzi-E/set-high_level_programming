#include <stdio.h>
#include "main.h"

/**
 * print_remaining_days - prints day of year and remaining days
 * @month: month number (1-12)
 * @day: day of month
 * @year: year
 *
 * Description: Calculates the day of the year and the number of
 * remaining days in the year, taking leap years into account.
 */
void print_remaining_days(int month, int day, int year)
{
	int leap = 0;

	/* Check if leap year */
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		leap = 1;

	/* Invalid Feb 29 in non-leap year */
	if (!leap && month == 2 && day == 60)
	{
		printf("Invalid date: %02d/%02d/%04d\n", month, day - 31, year);
		return;
	}

	/* If leap year and month after February, add 1 day */
	if (leap && month > 2)
		day++;

	printf("Day of the year: %d\n", day);

	if (leap)
		printf("Remaining days: %d\n", 366 - day);
	else
		printf("Remaining days: %d\n", 365 - day);
}
