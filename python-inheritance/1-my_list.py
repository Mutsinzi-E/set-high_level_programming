#!/usr/bin/python3
"""Defines a MyList class."""


class MyList(list):
    """A class that inherits from list."""

    def print_sorted(self):
        """Prints the list in sorted ascending order."""
        print(sorted(self))
