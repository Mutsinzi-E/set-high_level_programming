#!/usr/bin/python3
"""Function that deletes keys with a specific value in a dictionary."""


def complex_delete(a_dictionary, value):
    """Delete all keys with the given value."""
    keys_to_delete = []

    for key in a_dictionary:
        if a_dictionary[key] == value:
            keys_to_delete.append(key)

    for key in keys_to_delete:
        del a_dictionary[key]

    return a_dictionary
