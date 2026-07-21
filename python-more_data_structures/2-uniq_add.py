#!/usr/bin/python3
"""Function that adds unique integers in a list."""


def uniq_add(my_list=[]):
    """Add all unique integers in my_list only once."""
    total = 0
    unique_numbers = []

    for number in my_list:
        if number not in unique_numbers:
            unique_numbers.append(number)
            total += number

    return total
