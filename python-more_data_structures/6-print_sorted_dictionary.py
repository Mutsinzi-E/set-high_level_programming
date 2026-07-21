#!/usr/bin/python3
"""Function that prints a dictionary by ordered keys."""


def print_sorted_dictionary(a_dictionary):
    """Print dictionary keys sorted alphabetically."""
    for key in sorted(a_dictionary):
        print("{}: {}".format(key, a_dictionary[key]))
