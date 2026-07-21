#!/usr/bin/python3
"""Function that returns the number of keys in a dictionary."""


def number_keys(a_dictionary):
    """Return the number of keys in a dictionary."""
    count = 0

    for key in a_dictionary:
        count += 1

    return count
