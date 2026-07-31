#!/usr/bin/python3
"""Module that defines the MyList class."""


class MyList(list):
    """A class that inherits from list."""

    def print_sorted(self):
        """Print a sorted copy of the list and return it."""
        sorted_list = sorted(self)
        print(sorted_list)
        return sorted_list
