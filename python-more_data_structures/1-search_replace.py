#!/usr/bin/python3
"""Function to replace all occurrences of an element in a new list."""


def search_replace(my_list, search, replace):
    """Replace search with replace in a copy of my_list."""
    return [replace if item == search else item for item in my_list]
