#!/usr/bin/python3
"""Function that replaces all occurrences of an element in a new list."""


def search_replace(my_list, search, replace):
    """Replace all occurrences of search with replace in a new list."""
    new_list = []

    for item in my_list:
        if item == search:
            new_list.append(replace)
        else:
            new_list.append(item)

    return new_list
